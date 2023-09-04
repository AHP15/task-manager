#include "Task.h"

std::ostream& operator<<(std::ostream& out, const Task& task) {
  out << "===== " << task.title << " =====\n";
  out << "  ID: " << task.id << '\n';
  out << "  Priority: " << task.getPriorityAsStr() << '\n';
  out << "  Description: " << task.description << '\n';
  return out;
}

std::string_view Task::getPriorityAsStr() const {
  switch(priority) {
    case Task::low: return "Low";
    case Task::medium: return "Medium";
    case Task::high: return "High";
    default: return "Unknown priority";
  }
}

Task::TaskMap Task::toJson() const {
  Task::TaskMap map {
    {"title", ""},
    {"description", ""},
    {"priority", ""}
  };

  map["title"] = title;
  map["description"] = description;
  map["priority"] = getPriorityAsStr();
  return map;
}