#include "../inc/ragui_model_view_ctld.hpp"

void ViewComponentSubject::add_observer(ViewComponentObserver *mvc_observer) {
  mvc_observer->next = this->head;
  this->head = mvc_observer;
}

void ViewComponentSubject::remove_observer(
    ViewComponentObserver *mvc_observer) {
  if (this->head == mvc_observer) {
    this->head = mvc_observer->next;
    mvc_observer->next = nullptr;
  }

  ViewComponentObserver *current_observer = this->head;
  while (current_observer != 0) {
    if (current_observer->next == mvc_observer) {
      current_observer->next = mvc_observer->next;
      mvc_observer->next = nullptr;
    }

    current_observer = current_observer->next;
  }
}
