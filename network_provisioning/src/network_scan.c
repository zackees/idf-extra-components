/*
 * SPDX-FileCopyrightText: 2019-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <esp_log.h>
#include <string.h>
#include <esp_err.h>
#include <esp_wifi.h>

#include "network_scan.pb-c.h"

#include <network_provisioning/network_scan.h>

static const char *TAG = "proto_network_scan";

typedef struct network_prov_scan_cmd {
    int cmd_num;
    esp_err_t (*command_handler)(NetworkScanPayload *req,
                                 NetworkScanPayload *resp, void *priv_data);
} network_prov_scan_cmd_t;

static esp_err_t cmd_scan_start_handler(NetworkScanPayload *req,
                                        NetworkScanPayload *resp,
                                        void *priv_data);

static esp_err_t cmd_scan_status_handler(NetworkScanPayload *req,
        NetworkScanPayload *resp,
        void *priv_data);

static esp_err_t cmd_scan_result_handler(NetworkScanPayload *req,
        NetworkScanPayload *resp,
        void *priv_data);

static network_prov_scan_cmd_t cmd_table[] = {
    {
        .cmd_num = NETWORK_SCAN_MSG_TYPE__TypeCmdScanStart,
        .command_handler = cmd_scan_start_handler
    },
    {
        .cmd_num = NETWORK_SCAN_MSG_TYPE__TypeCmdScanStatus,
        .command_handler = cmd_scan_status_handler
    },
    {
        .cmd_num = NETWORK_SCAN_MSG_TYPE__TypeCmdScanResult,
        .command_handler = cmd_scan_result_handler
    }
};

static esp_err_t cmd_scan_start_handler(NetworkScanPayload *req,
                                        NetworkScanPayload *resp, void *priv_data)
{
    network_prov_scan_handlers_t *h = (network_prov_scan_handlers_t *) priv_data;
    if (!priv_data) {
        ESP_LOGE(TAG, "Command invoked without handlers");
        return ESP_ERR_INVALID_STATE;
    }

    RespScanStart *resp_payload = (RespScanStart *) malloc(sizeof(RespScanStart));
    if (!resp_payload) {
        ESP_LOGE(TAG, "Error allocating memory");
        return ESP_ERR_NO_MEM;
    }

    resp_scan_start__init(resp_payload);
    if (req->cmd_scan_start->net_type == NETWORK_TYPE__WifiNetwork) {
#if CONFIG_ESP_WIFI_ENABLED
        if (h->wifi_scan_start) {
            resp->status = (h->wifi_scan_start(req->cmd_scan_start->wifi_scan_start->blocking,
                                               req->cmd_scan_start->wifi_scan_start->passive,
                                               req->cmd_scan_start->wifi_scan_start->group_channels,
                                               req->cmd_scan_start->wifi_scan_start->period_ms,
                                               &h->ctx) == ESP_OK ? STATUS__Success : STATUS__InternalError);
        } else {
            resp->status = STATUS__InternalError;
        }
#else
        resp->status = STATUS__InvalidArgument;
#endif
    } else if (req->cmd_scan_start->net_type == NETWORK_TYPE__ThreadNetwork) {
#if CONFIG_OPENTHREAD_ENABLED
        if (h->thread_scan_start) {
            resp->status = (h->thread_scan_start(req->cmd_scan_start->thread_scan_start->blocking,
                                                 req->cmd_scan_start->thread_scan_start->channel_mask,
                                                 &h->ctx) == ESP_OK ? STATUS__Success : STATUS__InternalError);
        } else {
            resp->status = STATUS__InternalError;
        }
#else
        resp->status = STATUS__InvalidArgument;
#endif
    }
    resp_payload->net_type = req->cmd_scan_start->net_type;
    resp->payload_case = NETWORK_SCAN_PAYLOAD__PAYLOAD_RESP_SCAN_START;
    resp->resp_scan_start = resp_payload;
    return ESP_OK;
}

static esp_err_t cmd_scan_status_handler(NetworkScanPayload *req,
        NetworkScanPayload *resp, void *priv_data)
{
    bool scan_finished = false;
    uint16_t result_count = 0;

    network_prov_scan_handlers_t *h = (network_prov_scan_handlers_t *) priv_data;
    if (!h) {
        ESP_LOGE(TAG, "Command invoked without handlers");
        return ESP_ERR_INVALID_STATE;
    }

    RespScanStatus *resp_payload = (RespScanStatus *) malloc(sizeof(RespScanStatus));
    if (!resp_payload) {
        ESP_LOGE(TAG, "Error allocating memory");
        return ESP_ERR_NO_MEM;
    }

    resp_scan_status__init(resp_payload);
    if (req->cmd_scan_status->net_type == NETWORK_TYPE__WifiNetwork) {
#if CONFIG_ESP_WIFI_ENABLED
        if (h->wifi_scan_status) {
            resp->status = (h->wifi_scan_status(&scan_finished, &result_count, &h->ctx) == ESP_OK ?
                            STATUS__Success : STATUS__InternalError);
        } else {
            resp->status = STATUS__InternalError;
        }
#else
        resp->status = STATUS__InvalidArgument;
#endif
    } else if (req->cmd_scan_status->net_type == NETWORK_TYPE__ThreadNetwork) {
#if CONFIG_OPENTHREAD_ENABLED
        if (h->thread_scan_status) {
            resp->status = (h->thread_scan_status(&scan_finished, &result_count, &h->ctx) == ESP_OK ?
                            STATUS__Success : STATUS__InternalError);
        } else {
            resp->status = STATUS__InternalError;
        }
#else
        resp->status = STATUS__InvalidArgument;
#endif
    }
    resp_payload->net_type = req->cmd_scan_status->net_type;
    resp_payload->scan_finished = scan_finished;
    resp_payload->result_count = result_count;
    resp->payload_case = NETWORK_SCAN_PAYLOAD__PAYLOAD_RESP_SCAN_STATUS;
    resp->resp_scan_status = resp_payload;
    return ESP_OK;
}

static esp_err_t cmd_scan_result_handler(NetworkScanPayload *req,
        NetworkScanPayload *resp, void *priv_data)
{
    esp_err_t err;
    ScanResult **results = NULL;
    network_prov_scan_handlers_t *h = (network_prov_scan_handlers_t *) priv_data;
    if (!priv_data) {
        ESP_LOGE(TAG, "Command invoked without handlers");
        return ESP_ERR_INVALID_STATE;
    }

    RespScanResult *resp_payload = (RespScanResult *) malloc(sizeof(RespScanResult));
    if (!resp_payload) {
        ESP_LOGE(TAG, "Error allocating memory");
        return ESP_ERR_NO_MEM;
    }
    resp_scan_result__init(resp_payload);

    resp->status = STATUS__Success;
    resp->payload_case = NETWORK_SCAN_PAYLOAD__PAYLOAD_RESP_SCAN_RESULT;
    resp_payload->net_type = req->cmd_scan_result->net_type;
    resp->resp_scan_result = resp_payload;
    if (req->cmd_scan_result->net_type == NETWORK_TYPE__WifiNetwork) {
#if CONFIG_ESP_WIFI_ENABLED
        network_prov_scan_wifi_result_t scan_result = {{0}, {0}, 0, 0, 0};

        /* Allocate memory only if there are non-zero scan results */
        if (req->cmd_scan_result->count) {
            results = (ScanResult **) calloc(req->cmd_scan_result->count,
                                             sizeof(ScanResult *));
            if (!results) {
                ESP_LOGE(TAG, "Failed to allocate memory for results array");
                return ESP_ERR_NO_MEM;
            }
        }
        resp_payload->entries = results;
        resp_payload->n_entries = req->cmd_scan_result->count;

        /* If req->cmd_scan_result->count is 0, the below loop will
        * be skipped.
        */
        for (uint16_t i = 0; i < req->cmd_scan_result->count; i++) {
            if (!h->wifi_scan_result) {
                resp->status = STATUS__InternalError;
                break;
            }
            err = h->wifi_scan_result(i + req->cmd_scan_result->start_index,
                                      &scan_result, &h->ctx);
            if (err != ESP_OK) {
                resp->status = STATUS__InternalError;
                break;
            }

            results[i] = (ScanResult *) malloc(sizeof(ScanResult));
            if (!results[i]) {
                ESP_LOGE(TAG, "Failed to allocate memory for result entry");
                return ESP_ERR_NO_MEM;
            }
            scan_result__init(results[i]);
            results[i]->result_case = SCAN_RESULT__RESULT_WIFI_RESULT;

            results[i]->wifi_result = (WifiScanResult *) malloc(sizeof(WifiScanResult));
            if (!results[i]->wifi_result) {
                ESP_LOGE(TAG, "Failed to allocate memory for WiFi scan result");
                return ESP_ERR_NO_MEM;
            }
            wifi_scan_result__init(results[i]->wifi_result);

            results[i]->wifi_result->ssid.len = strnlen(scan_result.ssid, 32);
            results[i]->wifi_result->ssid.data = (uint8_t *) strndup(scan_result.ssid, 32);
            if (!results[i]->wifi_result->ssid.data) {
                ESP_LOGE(TAG, "Failed to allocate memory for scan result entry SSID");
                return ESP_ERR_NO_MEM;
            }

            results[i]->wifi_result->channel = scan_result.channel;
            results[i]->wifi_result->rssi = scan_result.rssi;
            results[i]->wifi_result->auth = scan_result.auth;

            results[i]->wifi_result->bssid.len = sizeof(scan_result.bssid);
            results[i]->wifi_result->bssid.data = malloc(results[i]->wifi_result->bssid.len);
            if (!results[i]->wifi_result->bssid.data) {
                ESP_LOGE(TAG, "Failed to allocate memory for scan result entry BSSID");
                return ESP_ERR_NO_MEM;
            }
            memcpy(results[i]->wifi_result->bssid.data, scan_result.bssid, results[i]->wifi_result->bssid.len);
        }
#else
        resp->status = STATUS__InvalidArgument;
#endif // CONFIG_ESP_WIFI_ENABLED
    } else if (req->cmd_scan_result->net_type == NETWORK_TYPE__ThreadNetwork) {
#if CONFIG_OPENTHREAD_ENABLED
        network_prov_scan_thread_result_t scan_result;
        memset(&scan_result, 0, sizeof(scan_result));

        /* Allocate memory only if there are non-zero scan results */
        if (req->cmd_scan_result->count) {
            results = (ScanResult **) calloc(req->cmd_scan_result->count,
                                             sizeof(ScanResult *));
            if (!results) {
                ESP_LOGE(TAG, "Failed to allocate memory for results array");
                return ESP_ERR_NO_MEM;
            }
        }
        resp_payload->entries = results;
        resp_payload->n_entries = req->cmd_scan_result->count;

        /* If req->cmd_scan_result->count is 0, the below loop will
        * be skipped.
        */
        for (uint16_t i = 0; i < req->cmd_scan_result->count; i++) {
            if (!h->thread_scan_result) {
                resp->status = STATUS__InternalError;
                break;
            }
            err = h->thread_scan_result(i + req->cmd_scan_result->start_index,
                                        &scan_result, &h->ctx);
            if (err != ESP_OK) {
                resp->status = STATUS__InternalError;
                break;
            }

            results[i] = (ScanResult *) malloc(sizeof(ScanResult));
            if (!results[i]) {
                ESP_LOGE(TAG, "Failed to allocate memory for result entry");
                return ESP_ERR_NO_MEM;
            }
            scan_result__init(results[i]);
            results[i]->result_case = SCAN_RESULT__RESULT_THREAD_RESULT;

            results[i]->thread_result = (ThreadScanResult *) malloc(sizeof(ThreadScanResult));
            if (!results[i]->thread_result) {
                ESP_LOGE(TAG, "Failed to allocate memory for Thread scan result");
                return ESP_ERR_NO_MEM;
            }
            thread_scan_result__init(results[i]->thread_result);

            results[i]->thread_result->pan_id = scan_result.pan_id;
            results[i]->thread_result->channel = scan_result.channel;
            results[i]->thread_result->rssi = scan_result.rssi;
            results[i]->thread_result->lqi = scan_result.lqi;

            results[i]->thread_result->ext_addr.len = sizeof(scan_result.ext_addr);
            results[i]->thread_result->ext_addr.data = (uint8_t *)malloc(results[i]->thread_result->ext_addr.len);
            if (!results[i]->thread_result->ext_addr.data) {
                ESP_LOGE(TAG, "Failed to allocate memory for scan result entry extended address");
                return ESP_ERR_NO_MEM;
            }
            memcpy(results[i]->thread_result->ext_addr.data, scan_result.ext_addr, results[i]->thread_result->ext_addr.len);

            results[i]->thread_result->ext_pan_id.len = sizeof(scan_result.ext_pan_id);
            results[i]->thread_result->ext_pan_id.data = (uint8_t *)malloc(results[i]->thread_result->ext_pan_id.len);
            if (!results[i]->thread_result->ext_pan_id.data) {
                ESP_LOGE(TAG, "Failed to allocate memory for scan result entry extended PAN ID");
                return ESP_ERR_NO_MEM;
            }
            memcpy(results[i]->thread_result->ext_pan_id.data, scan_result.ext_pan_id, results[i]->thread_result->ext_pan_id.len);

            results[i]->thread_result->network_name = (char *)malloc(sizeof(scan_result.network_name));
            if (!results[i]->thread_result->network_name) {
                ESP_LOGE(TAG, "Failed to allocate memory for scan result entry networkname");
            }
            memcpy(results[i]->thread_result->network_name, scan_result.network_name, sizeof(scan_result.network_name));
        }
#else
        resp->status = STATUS__InvalidArgument;
#endif // CONFIG_ESP_WIFI_ENABLED

    }
    return ESP_OK;
}


static int lookup_cmd_handler(int cmd_id)
{
    for (size_t i = 0; i < sizeof(cmd_table) / sizeof(network_prov_scan_cmd_t); i++) {
        if (cmd_table[i].cmd_num == cmd_id) {
            return i;
        }
    }

    return -1;
}

static void network_prov_scan_cmd_cleanup(NetworkScanPayload *resp, void *priv_data)
{
    switch (resp->msg) {
    case NETWORK_SCAN_MSG_TYPE__TypeRespScanStart: {
        free(resp->resp_scan_start);
    }
    break;
    case NETWORK_SCAN_MSG_TYPE__TypeRespScanStatus: {
        free(resp->resp_scan_status);
    }
    break;
    case NETWORK_SCAN_MSG_TYPE__TypeRespScanResult: {
        if (!resp->resp_scan_result) {
            return;
        }
        if (resp->resp_scan_result->net_type == NETWORK_TYPE__WifiNetwork) {
#if CONFIG_ESP_WIFI_ENABLED
            if (resp->resp_scan_result->entries) {
                for (uint16_t i = 0; i < resp->resp_scan_result->n_entries; i++) {
                    if (!resp->resp_scan_result->entries[i]) {
                        continue;
                    }
                    if (!resp->resp_scan_result->entries[i]->wifi_result) {
                        continue;
                    }
                    free(resp->resp_scan_result->entries[i]->wifi_result->ssid.data);
                    free(resp->resp_scan_result->entries[i]->wifi_result->bssid.data);
                    free(resp->resp_scan_result->entries[i]->wifi_result);
                    free(resp->resp_scan_result->entries[i]);
                }
                free(resp->resp_scan_result->entries);
            }
#endif // CONFIG_ESP_WIFI_ENABLED
        } else if (resp->resp_scan_result->net_type == NETWORK_TYPE__ThreadNetwork) {
#if CONFIG_OPENTHREAD_ENABLED
            if (resp->resp_scan_result->entries) {
                for (uint16_t i = 0; i < resp->resp_scan_result->n_entries; i++) {
                    if (!resp->resp_scan_result->entries[i]) {
                        continue;
                    }
                    if (!resp->resp_scan_result->entries[i]->thread_result) {
                        continue;
                    }
                    free(resp->resp_scan_result->entries[i]->thread_result->ext_addr.data);
                    free(resp->resp_scan_result->entries[i]->thread_result->network_name);
                    free(resp->resp_scan_result->entries[i]->thread_result);
                    free(resp->resp_scan_result->entries[i]);
                }
                free(resp->resp_scan_result->entries);
            }
#endif //CONFIG_OPENTHREAD_ENABLED
        }
        free(resp->resp_scan_result);
    }
    break;
    default:
        ESP_LOGE(TAG, "Unsupported response type in cleanup_handler");
        break;
    }
    return;
}

static esp_err_t network_prov_scan_cmd_dispatcher(NetworkScanPayload *req,
        NetworkScanPayload *resp, void *priv_data)
{
    esp_err_t ret;

    ESP_LOGD(TAG, "In network_prov_scan_cmd_dispatcher Cmd=%d", req->msg);

    int cmd_index = lookup_cmd_handler(req->msg);
    if (cmd_index < 0) {
        ESP_LOGE(TAG, "Invalid command handler lookup");
        return ESP_FAIL;
    }

    ret = cmd_table[cmd_index].command_handler(req, resp, priv_data);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error executing command handler");
        return ESP_FAIL;
    }

    return ESP_OK;
}

esp_err_t network_prov_scan_handler(uint32_t session_id, const uint8_t *inbuf, ssize_t inlen,
                                    uint8_t **outbuf, ssize_t *outlen, void *priv_data)
{
    NetworkScanPayload *req;
    NetworkScanPayload resp;
    esp_err_t ret = ESP_OK;

    req = network_scan_payload__unpack(NULL, inlen, inbuf);
    if (!req) {
        ESP_LOGE(TAG, "Unable to unpack scan message");
        return ESP_ERR_INVALID_ARG;
    }

    network_scan_payload__init(&resp);
    ret = network_prov_scan_cmd_dispatcher(req, &resp, priv_data);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Command dispatcher error %d", ret);
        ret = ESP_FAIL;
        goto exit;
    }

    resp.msg = req->msg + 1; /* Response is request + 1 */
    *outlen = network_scan_payload__get_packed_size(&resp);
    if (*outlen <= 0) {
        ESP_LOGE(TAG, "Invalid encoding for response");
        ret = ESP_FAIL;
        goto exit;
    }

    *outbuf = (uint8_t *) malloc(*outlen);
    if (!*outbuf) {
        ESP_LOGE(TAG, "System out of memory");
        ret = ESP_ERR_NO_MEM;
        goto exit;
    }
    network_scan_payload__pack(&resp, *outbuf);
    ESP_LOGD(TAG, "Response packet size : %d", *outlen);
exit:

    network_scan_payload__free_unpacked(req, NULL);
    network_prov_scan_cmd_cleanup(&resp, priv_data);
    return ret;
}
