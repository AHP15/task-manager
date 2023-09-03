#ifndef STORAGE_H
#define STORAGE_H

#include  "json.hpp"
#include "Task.h"

#include <fstream>
#include <string_view>

class Storage {
public:

  void writeNewTask(const Task& task);
private:
  using json = nlohmann::json;
  std::ofstream tasks{ "tasks.json" };
};
#endif