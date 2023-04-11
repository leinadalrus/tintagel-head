#include "../inc/ragui_model_view_ctld.hpp"

class RaguiCommand
{
public:
  void execute_command();
};

class RaguiHandler : public RaguiCommand
{
  RaguiCommand *ragui_command = nullptr;

public:
  void execute_command()
  {
    handle_command();
  }

  void handle_command();
};

class ApplicationService
{
  class WindowPrototype {};
  
public:
  WindowPrototype retrieve_prototype();
};

class NullApplicationService : public ApplicationService
{
public:
  void run_application_service()
  { // DO nothing...
  }

  void stop_application_service()
  { // Do NOTHING!
  }
};

class MenuService
{
public:
  void init_menu_context();
  void defer_menu_context();
};

class ItemObserver
{
public:
  void on_notify(const RaguiHandler handler, int event) = 0;
};

class ItemSubject
{
public:
  void add_observer(ItemObserver *item_observer);
  void remove_observer(ItemObserver *item_observer);
};