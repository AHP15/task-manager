#include "Storage.h"

void Storage::writeNewTask(const Task& task) {
  json data;

  data["title"] = task.getTitle();
  data["description"] = task.getDescription();
  data["priority"] = task.getPriorityAsStr();
  tasks << data << '\n';
}