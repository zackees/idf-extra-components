/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: network_ctrl.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "network_ctrl.pb-c.h"
void   cmd_ctrl_reset__init
                     (CmdCtrlReset         *message)
{
  static const CmdCtrlReset init_value = CMD_CTRL_RESET__INIT;
  *message = init_value;
}
size_t cmd_ctrl_reset__get_packed_size
                     (const CmdCtrlReset *message)
{
  assert(message->base.descriptor == &cmd_ctrl_reset__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cmd_ctrl_reset__pack
                     (const CmdCtrlReset *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cmd_ctrl_reset__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cmd_ctrl_reset__pack_to_buffer
                     (const CmdCtrlReset *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cmd_ctrl_reset__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
CmdCtrlReset *
       cmd_ctrl_reset__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CmdCtrlReset *)
     protobuf_c_message_unpack (&cmd_ctrl_reset__descriptor,
                                allocator, len, data);
}
void   cmd_ctrl_reset__free_unpacked
                     (CmdCtrlReset *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cmd_ctrl_reset__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   resp_ctrl_reset__init
                     (RespCtrlReset         *message)
{
  static const RespCtrlReset init_value = RESP_CTRL_RESET__INIT;
  *message = init_value;
}
size_t resp_ctrl_reset__get_packed_size
                     (const RespCtrlReset *message)
{
  assert(message->base.descriptor == &resp_ctrl_reset__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t resp_ctrl_reset__pack
                     (const RespCtrlReset *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &resp_ctrl_reset__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t resp_ctrl_reset__pack_to_buffer
                     (const RespCtrlReset *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &resp_ctrl_reset__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
RespCtrlReset *
       resp_ctrl_reset__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (RespCtrlReset *)
     protobuf_c_message_unpack (&resp_ctrl_reset__descriptor,
                                allocator, len, data);
}
void   resp_ctrl_reset__free_unpacked
                     (RespCtrlReset *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &resp_ctrl_reset__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   cmd_ctrl_reprov__init
                     (CmdCtrlReprov         *message)
{
  static const CmdCtrlReprov init_value = CMD_CTRL_REPROV__INIT;
  *message = init_value;
}
size_t cmd_ctrl_reprov__get_packed_size
                     (const CmdCtrlReprov *message)
{
  assert(message->base.descriptor == &cmd_ctrl_reprov__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cmd_ctrl_reprov__pack
                     (const CmdCtrlReprov *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cmd_ctrl_reprov__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cmd_ctrl_reprov__pack_to_buffer
                     (const CmdCtrlReprov *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cmd_ctrl_reprov__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
CmdCtrlReprov *
       cmd_ctrl_reprov__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CmdCtrlReprov *)
     protobuf_c_message_unpack (&cmd_ctrl_reprov__descriptor,
                                allocator, len, data);
}
void   cmd_ctrl_reprov__free_unpacked
                     (CmdCtrlReprov *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cmd_ctrl_reprov__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   resp_ctrl_reprov__init
                     (RespCtrlReprov         *message)
{
  static const RespCtrlReprov init_value = RESP_CTRL_REPROV__INIT;
  *message = init_value;
}
size_t resp_ctrl_reprov__get_packed_size
                     (const RespCtrlReprov *message)
{
  assert(message->base.descriptor == &resp_ctrl_reprov__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t resp_ctrl_reprov__pack
                     (const RespCtrlReprov *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &resp_ctrl_reprov__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t resp_ctrl_reprov__pack_to_buffer
                     (const RespCtrlReprov *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &resp_ctrl_reprov__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
RespCtrlReprov *
       resp_ctrl_reprov__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (RespCtrlReprov *)
     protobuf_c_message_unpack (&resp_ctrl_reprov__descriptor,
                                allocator, len, data);
}
void   resp_ctrl_reprov__free_unpacked
                     (RespCtrlReprov *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &resp_ctrl_reprov__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   network_ctrl_payload__init
                     (NetworkCtrlPayload         *message)
{
  static const NetworkCtrlPayload init_value = NETWORK_CTRL_PAYLOAD__INIT;
  *message = init_value;
}
size_t network_ctrl_payload__get_packed_size
                     (const NetworkCtrlPayload *message)
{
  assert(message->base.descriptor == &network_ctrl_payload__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t network_ctrl_payload__pack
                     (const NetworkCtrlPayload *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &network_ctrl_payload__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t network_ctrl_payload__pack_to_buffer
                     (const NetworkCtrlPayload *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &network_ctrl_payload__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
NetworkCtrlPayload *
       network_ctrl_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (NetworkCtrlPayload *)
     protobuf_c_message_unpack (&network_ctrl_payload__descriptor,
                                allocator, len, data);
}
void   network_ctrl_payload__free_unpacked
                     (NetworkCtrlPayload *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &network_ctrl_payload__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor cmd_ctrl_reset__field_descriptors[1] =
{
  {
    "net_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(CmdCtrlReset, net_type),
    &network_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cmd_ctrl_reset__field_indices_by_name[] = {
  0,   /* field[0] = net_type */
};
static const ProtobufCIntRange cmd_ctrl_reset__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor cmd_ctrl_reset__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "CmdCtrlReset",
  "CmdCtrlReset",
  "CmdCtrlReset",
  "",
  sizeof(CmdCtrlReset),
  1,
  cmd_ctrl_reset__field_descriptors,
  cmd_ctrl_reset__field_indices_by_name,
  1,  cmd_ctrl_reset__number_ranges,
  (ProtobufCMessageInit) cmd_ctrl_reset__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor resp_ctrl_reset__field_descriptors[1] =
{
  {
    "net_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(RespCtrlReset, net_type),
    &network_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned resp_ctrl_reset__field_indices_by_name[] = {
  0,   /* field[0] = net_type */
};
static const ProtobufCIntRange resp_ctrl_reset__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor resp_ctrl_reset__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "RespCtrlReset",
  "RespCtrlReset",
  "RespCtrlReset",
  "",
  sizeof(RespCtrlReset),
  1,
  resp_ctrl_reset__field_descriptors,
  resp_ctrl_reset__field_indices_by_name,
  1,  resp_ctrl_reset__number_ranges,
  (ProtobufCMessageInit) resp_ctrl_reset__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor cmd_ctrl_reprov__field_descriptors[1] =
{
  {
    "net_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(CmdCtrlReprov, net_type),
    &network_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cmd_ctrl_reprov__field_indices_by_name[] = {
  0,   /* field[0] = net_type */
};
static const ProtobufCIntRange cmd_ctrl_reprov__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor cmd_ctrl_reprov__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "CmdCtrlReprov",
  "CmdCtrlReprov",
  "CmdCtrlReprov",
  "",
  sizeof(CmdCtrlReprov),
  1,
  cmd_ctrl_reprov__field_descriptors,
  cmd_ctrl_reprov__field_indices_by_name,
  1,  cmd_ctrl_reprov__number_ranges,
  (ProtobufCMessageInit) cmd_ctrl_reprov__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor resp_ctrl_reprov__field_descriptors[1] =
{
  {
    "net_type",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(RespCtrlReprov, net_type),
    &network_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned resp_ctrl_reprov__field_indices_by_name[] = {
  0,   /* field[0] = net_type */
};
static const ProtobufCIntRange resp_ctrl_reprov__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor resp_ctrl_reprov__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "RespCtrlReprov",
  "RespCtrlReprov",
  "RespCtrlReprov",
  "",
  sizeof(RespCtrlReprov),
  1,
  resp_ctrl_reprov__field_descriptors,
  resp_ctrl_reprov__field_indices_by_name,
  1,  resp_ctrl_reprov__number_ranges,
  (ProtobufCMessageInit) resp_ctrl_reprov__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor network_ctrl_payload__field_descriptors[6] =
{
  {
    "msg",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(NetworkCtrlPayload, msg),
    &network_ctrl_msg_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "status",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(NetworkCtrlPayload, status),
    &status__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "cmd_ctrl_reset",
    11,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(NetworkCtrlPayload, payload_case),
    offsetof(NetworkCtrlPayload, cmd_ctrl_reset),
    &cmd_ctrl_reset__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "resp_ctrl_reset",
    12,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(NetworkCtrlPayload, payload_case),
    offsetof(NetworkCtrlPayload, resp_ctrl_reset),
    &resp_ctrl_reset__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "cmd_ctrl_reprov",
    13,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(NetworkCtrlPayload, payload_case),
    offsetof(NetworkCtrlPayload, cmd_ctrl_reprov),
    &cmd_ctrl_reprov__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "resp_ctrl_reprov",
    14,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(NetworkCtrlPayload, payload_case),
    offsetof(NetworkCtrlPayload, resp_ctrl_reprov),
    &resp_ctrl_reprov__descriptor,
    NULL,
    0 | PROTOBUF_C_FIELD_FLAG_ONEOF,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned network_ctrl_payload__field_indices_by_name[] = {
  4,   /* field[4] = cmd_ctrl_reprov */
  2,   /* field[2] = cmd_ctrl_reset */
  0,   /* field[0] = msg */
  5,   /* field[5] = resp_ctrl_reprov */
  3,   /* field[3] = resp_ctrl_reset */
  1,   /* field[1] = status */
};
static const ProtobufCIntRange network_ctrl_payload__number_ranges[2 + 1] =
{
  { 1, 0 },
  { 11, 2 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor network_ctrl_payload__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "NetworkCtrlPayload",
  "NetworkCtrlPayload",
  "NetworkCtrlPayload",
  "",
  sizeof(NetworkCtrlPayload),
  6,
  network_ctrl_payload__field_descriptors,
  network_ctrl_payload__field_indices_by_name,
  2,  network_ctrl_payload__number_ranges,
  (ProtobufCMessageInit) network_ctrl_payload__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue network_ctrl_msg_type__enum_values_by_number[5] =
{
  { "TypeCtrlReserved", "NETWORK_CTRL_MSG_TYPE__TypeCtrlReserved", 0 },
  { "TypeCmdCtrlReset", "NETWORK_CTRL_MSG_TYPE__TypeCmdCtrlReset", 1 },
  { "TypeRespCtrlReset", "NETWORK_CTRL_MSG_TYPE__TypeRespCtrlReset", 2 },
  { "TypeCmdCtrlReprov", "NETWORK_CTRL_MSG_TYPE__TypeCmdCtrlReprov", 3 },
  { "TypeRespCtrlReprov", "NETWORK_CTRL_MSG_TYPE__TypeRespCtrlReprov", 4 },
};
static const ProtobufCIntRange network_ctrl_msg_type__value_ranges[] = {
{0, 0},{0, 5}
};
static const ProtobufCEnumValueIndex network_ctrl_msg_type__enum_values_by_name[5] =
{
  { "TypeCmdCtrlReprov", 3 },
  { "TypeCmdCtrlReset", 1 },
  { "TypeCtrlReserved", 0 },
  { "TypeRespCtrlReprov", 4 },
  { "TypeRespCtrlReset", 2 },
};
const ProtobufCEnumDescriptor network_ctrl_msg_type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "NetworkCtrlMsgType",
  "NetworkCtrlMsgType",
  "NetworkCtrlMsgType",
  "",
  5,
  network_ctrl_msg_type__enum_values_by_number,
  5,
  network_ctrl_msg_type__enum_values_by_name,
  1,
  network_ctrl_msg_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
