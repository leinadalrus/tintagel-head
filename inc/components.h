#ifndef COMPONENTS_H
#define COMPONENTS_H

template<typename T>
class Result {
public:
    Result(T comptime_typeval...);
};

enum class Error {
    None = 0,
    Found = 1,
};

class DatabaseConfig {
public:
    DatabaseConfig();

    Result<Error>init_database_config();

private:
    const char *database_url;
    unsigned int database_port;
};

#endif // COMPONENTS_H