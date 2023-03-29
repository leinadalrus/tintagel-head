#ifndef COMPONENTS_H
#define COMPONENTS_H

enum Errors {
  None = 0,
  Found = 1,
};

enum EmplaceCallback { EmplaceCallback };

typedef struct Result {
  void (*result_into_virtual_table)(
      char *cloned_self); // char is equal to u8. char* is like void*
} Result, *ResultPtr;

typedef struct DatabaseConfig {
  // private
  const char *database_url;
  unsigned int database_port;
} DatabaseConfig;

// public
int init_database_config(DatabaseConfig database_config_self);

#endif // COMPONENTS_H