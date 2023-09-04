#ifndef STORAGE_H
#define STORAGE_H

#include  "json.hpp"
#include "Task.h"

#include <fstream>
#include <string_view>

class Storage {
public:
  using Tasks = std::vector<Task>;

  Storage(std::string_view file): filename{ file }{};
  void writeTasks(const Tasks& appTasks);
  Tasks loadTasks();

private:
  using json = nlohmann::json;
  std::fstream tasksFile{};
  std::string filename{};
};
#endif