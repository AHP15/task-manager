#ifndef APP_H
#define APP_H

#include <functional>
#include <vector>
#include <memory>
#include <utility>

#include "Task.h"
#include "Storage.h"

class App {
public:
  using Tasks = std::vector<Task>;
  
  void addTask(Task task);
  void deleteTask(int taskId);
  void editTask(int taskId, const Task& task);

  Tasks& filterTasks(const std::function<bool(const Task& task)>& predicate) const;
  const Tasks& getTasks() const { return tasks; }

private:
  Tasks tasks{};
  Storage tasksFile{};
};

#endif