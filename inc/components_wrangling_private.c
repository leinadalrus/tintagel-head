#include "components_wrangler_private.h"

int init_database_config(DatabaseConfig database_config) { return 0; }

void *result_into_virtual_table(char *cloned_self) { return cloned_self; }

void handle_resulting_vtable(Result const* copied_trait) {}

void (*ResultVirtualTable[/* Undefined size? */])() = {[EmplaceCallback] = handle_resulting_vtable};