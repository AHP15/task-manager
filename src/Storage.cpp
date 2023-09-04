#include "Storage.h"

#include <iostream>

void Storage::writeTasks(const Storage::Tasks& appTasks) {
  tasksFile.open(filename, std::ios::out);
  if(!tasksFile) {
    return;
  }

  json data;
  for(auto& task: appTasks) {
    data.push_back(task.toJson());
  }

  tasksFile << data;
}

Storage::Tasks Storage::loadTasks() {
  tasksFile.open(filename, std::ios::in);

  if(!tasksFile) {
    return Storage::Tasks {};
  }

  Storage::Tasks tasks{};
  json data;
  tasksFile >> data;

  Task::TaskPriority priority {};

  for(auto& obj: data) {
    std::cout << obj << '\n';
  };
  return Storage::Tasks {};
}
