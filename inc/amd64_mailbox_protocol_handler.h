#ifndef AMD_MAILBOX_PROTOCOL_HANDLER_H
#define AMD_MAILBOX_PROTOCOL_HANDLER_H

#include "amd64_hypervisor_guest_policy.h"
#include "function_offload_model_hook.h"

typedef struct Amd64MailboxProtocol {
  enum Amd64GuestPolicy guest_policy;
} Amd64MailboxProtocol;

#endif // AMD_MAILBOX_PROTOCOL_HANDLER_H
