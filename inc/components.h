#ifndef COMPONENTS_H
#define COMPONENTS_H

class DatabaseConfig {
public:
    DatabaseConfig() {}

private:
    const char *database_url;
    unsigned int database_port;
};

#endif // COMPONENTS_H