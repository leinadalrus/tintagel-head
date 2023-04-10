#ifndef CORE_DEVISOR_ATTACHE_PRIVATE
#define CORE_DEVISOR_ATTACHE_PRIVATE

typedef struct DevisorAttache
{
} DevisorAttache;

typedef struct AudioService
{
} AudioService;

typedef struct NullService
{
} NullService;

typedef struct LocatorService
{
  DevisorAttache *devisor_attache = nullptr;
  NullService *null_service = 0;
} LocatorService;

#endif // CORE_DEVISOR_ATTACHE_PRIVATE