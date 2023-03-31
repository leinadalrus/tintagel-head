#ifndef COMPONENTS_H
#define COMPONENTS_H

enum class Errors
{
  None = 0,
  Found = 1,
};

template <typename T, typename E>
class Result
{
  Result(T type, E expected);
};

class DatabaseConfig
{
public:
  int init_database_config(DatabaseConfig database_config_self);

private:
  const char *database_url;
  unsigned int database_port;
};

#endif // COMPONENTS_H