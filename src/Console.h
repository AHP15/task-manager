#ifndef CONSOLE_H
#define CONSOLE_H

#include "App.h"

class Console {
public:
  enum Option {
    list,
    add,
    remove,
    highPriorityTasks,
    mediumPriorityTasks,
    lowPriorityTasks,
    quit,

    maxOption,
  };
  void run();


private:
  App app{};
  int userOption{};
  static constexpr int numberOfOptions { 7 };
  using Options = std::array<std::string_view, numberOfOptions>;
  static constexpr Options options{
    "1- List All Tasks",
    "2- Add Task",
    "3- Delete Task",
    "4- List All high priority tasks",
    "5- List All medium priority tasks",
    "6- List All low priority tasks",
    "7- Quit the app"
  };

  std::string getStringInput() const;
  int getInteger(int min, long max);
  void printUserOptions() const;
  void getUserOption();
  void printTasks() const;
  void printFilteredTasks(const std::function<bool(const Task& task)>&  predicate) const;
  void addTask();
  void deleteTask();
  void printMessage(std::string_view message) const {
    std::cout << message << '\n';
  }
};

#endif