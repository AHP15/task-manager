#include <algorithm>

#include "App.h"

void App::addTask(Task task) {
  tasks.push_back(task);
}

void App::deleteTask(int taskId) {
  tasks.erase(
    std::remove_if(
      tasks.begin(),
      tasks.end(),
      [=](const Task& task) { return task.getId() == taskId; }
    )
  );
}


void App::editTask(int taskId, const Task& EditedTask) {

  auto found {
    std::find_if(
      tasks.begin(),
      tasks.end(),
      [=](const Task& task) { return taskId == task.getId(); }
    )
  };

  if(found == tasks.end()) {
    std::cout << "Task is id: " << taskId << "does not exist!\n";
    return;
  }
  
  found->updateTitle(EditedTask.getTitle());
  found->updateDesctipion(EditedTask.getDescription());
  found->updatePriority(EditedTask.getPriority());
}

App::Tasks& App::filterTasks(const std::function<bool(const Task& task)>&  predicate) const {
  static App::Tasks filteredTasks {};
  filteredTasks = {};
  for(auto& task: tasks) {
    if(predicate(task)) {
      filteredTasks.push_back(task);
    }
  }
  return filteredTasks;
}
