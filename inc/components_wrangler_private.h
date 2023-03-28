#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct Result {

} Result, *ResultPtr;

enum Errors {
    None = 0,
    Found = 1,
};

typedef struct DatabaseConfig {
    // private
    const char *database_url;
    unsigned int database_port;
} DatabaseConfig;

// public
int init_database_config(DatabaseConfig database_config_self);

#endif // COMPONENTS_H