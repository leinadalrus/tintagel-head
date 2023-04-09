#include "../inc/ragui_model_view_ctld.hpp"

class RaguiCommand {
public:
  void execute_command();
};

class RaguiHandler : public RaguiCommand {
  RaguiCommand *ragui_command = nullptr;

public:
  void execute_command() {
    handle_command();
  }

  void handle_command();
};

class WindowService {};

class NullService {};

class MenuService {};

class ItemObserver {};

class ItemSubject {};