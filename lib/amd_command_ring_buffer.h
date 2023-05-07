#ifndef AMD_COMMAND_RING_BUFFER_H
#define AMD_COMMAND_RING_BUFFER_H

#include "amd_command_buffer_handler.h"

enum RbStatusCodes {
  SUCCESS = 0x0000, // possibly change bytecode for bitwise ops
  INVALID_PLATFORM_STATE = 0x0001,
  INVALID_GUEST_STATE = 0x0002,
  INVALID_CONFIG = 0x0003,
  INVALID_LENGTH = 0x0004,
  ALREADY_OWNED = 0x0005,
  INVALID_CERTIFICATE = 0x0006,
  POLICY_FEATURE = 0x0007,
  INACTIVE = 0x008,
  INVALID_ADDRESS = 0x009,
  BAD_SIGNATURE = 0x000A,
  BAD_MEASUREMENT = 0x000B,
  ASID_OWNED = 0x000C,
  INVALID_ASID = 0x000D,
  WBINVD_REQUIRED = 0x000E,
  DF_FLUSH_REQUIRED = 0x000F,
  INVALID_GUEST = 0x0010,
  INVALID_COMMAND = 0x0011,
  ACTIVE = 0x0012,
  HWERROR_PLATFORM = 0x0013,
  HWERROR_UNSAFE = 0x0014,
  UNSUPPORTED = 0x0015,
  INVALID_PARAM = 0x0016,
  RESOURCE_LIMIT = 0x0017,
  SECURE_DATA_INVALID = 0x0018,
  RB_MODE_EXITED = 0x001F
};

typedef struct CommandRingBuffer {
  int *head;
  int *next;
} CommandRingBuffer;

typedef struct IntervalMatrix {
  int intervals[sizeof(char)][sizeof(char)];
} IntervalMatrix;

typedef struct DistributedHashkeys {
  int keys[];
} DistributedHashkeys;

typedef struct DistributedHashtable {
  struct IntervalMatrix *interval_matrix;
  struct DistributedHashkeys hashkeys[];
} DistributedHashtable;

typedef struct Chord_t {
  struct CommandRingBuffer *ring_buffer;
} Chord_t;

typedef struct ArbitraryNetwork {
  struct Chord_t *chord_t;
} ArbitraryNetwork;

#endif // AMD_COMMAND_RING_BUFFER_H
