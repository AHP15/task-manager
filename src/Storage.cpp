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

  for(auto& obj: data) {

    std::string title { obj["title"] };
    std::string description { obj["description"] };

    Task::TaskPriority priority {};
    if(obj["priority"] == "low") priority = Task::low;
    else if(obj["priority"] == "medium") priority = Task::medium;
    else if(obj["priority"] == "high") priority = Task::high;

    tasks.push_back(
      Task{ title, description, priority }
    );
  };

  tasksFile.close();
  return tasks;
}
