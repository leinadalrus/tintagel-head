#ifndef AMD64_COMMAND_BUFFER_HANDLER_H
#define AMD64_COMMAND_BUFFER_HANDLER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct PhantomMarker {
  char *token_byte;
  char *heap_slice;
  signed int cursor_position;
  signed int read_position;
} PhantomMarker;

typedef struct DecryptedCommandBufferCursor {
  PhantomMarker phantom_marker[sizeof(char)][sizeof(char)]; // reference-based
                                                            //
} DecryptedCommandBufferCursor;

typedef struct DecryptedCommandBufferTree {
  PhantomMarker phantom_sizes[sizeof(char)][sizeof(char)]; // note: need matrix
                                                           //
} DecryptedCommandBufferTree;

typedef struct DecryptedCommandHandler {
  DecryptedCommandBufferTree *lint_command_buffer_tree;
} DecryptedCommandHandler;

typedef struct DecryptedCommandContext {
  void *lint_command_context;
} DecryptedCommandContext;

typedef struct DecryptedServiceLocator {
  DecryptedCommandBufferTree *lint_command_buffer_tree;
  DecryptedCommandHandler *lint_command_handler;
} DecryptedServiceLocator;

const int defer_context(DecryptedCommandContext *lint_command_context);
int handled_deferred_context(int (*defer_context_callback)(), void *user_data,
                             void *iomem_source, void *table_data,
                             uint64_t data_size);

typedef struct DecryptedAnnulService {
  DecryptedCommandBufferTree *lint_command_buffer_tree;
  DecryptedCommandHandler *lint_command_handler;
} DecryptedAnnulService;

// `handle_context` of singleton strategy function pointers/contexts
const int handle_context(char *destination, char *source, uint8_t data_size,
                         char *user_data);
int read_handled_context_argument(int (*interface_handle_callback)(),
                                  char *user_data_header,
                                  signed int status_flag, uint64_t data_size);

#endif // AMD64_COMMAND_BUFFER_HANDLER_H
