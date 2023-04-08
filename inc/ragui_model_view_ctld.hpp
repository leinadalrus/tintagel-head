#ifndef RAGUI_MODEL_VIEW_CTLD_HPP
#define RAGUI_MODEL_VIEW_CTLD_HPP

#include <array>

template<typename Datatype>
class ObserverSoA 
{
public:
  std::array<Datatype, 1> observers = {0};
};

class ViewComponentEntity 
{
};

class ModelViewCommand 
{
public:
  void execute_command_model_view();
};

class ModelViewController : public ModelViewCommand 
{
  ModelViewCommand model_view_command = ModelViewCommand{}; // need a copy constructor
public:
  void execute_command_model_view() {
    this->handle_controller_model_view();
  }

  void handle_controller_model_view();
};

enum class ViewObservedEvents
{
  SubjectedTo,
  Observed,
};

class ViewComponentObserver 
{
  friend class ViewComponentSubject;
  ViewComponentObserver *next;

public:
  ViewComponentObserver() : next(nullptr) {}
  ~ViewComponentObserver();
  const bool update_onevent_usesignal(const ViewComponentEntity &entity_component, ViewObservedEvents observed_events);
};

class ViewComponentSubject 
{
  ViewComponentSubject() : head(nullptr) {}
  ViewComponentObserver *head;

  ViewComponentObserver *observers[1] = {0};
  int observer_iterator = 0;
  
public:
  constexpr ObserverSoA<ViewComponentObserver> add_observer(ViewComponentObserver *mvc_observer);
  constexpr ObserverSoA<ViewComponentObserver> remove_observer(ViewComponentObserver *mvc_observer);
};

#endif // RAGUI_MODEL_VIEW_CTLD_HPP