#ifndef TASK_H
#define TASK_H

#include <string_view>
#include <string>
#include <iostream>
#include <map>

class Task {
public:
  enum TaskPriority {
    high,
    medium,
    low
  };

  using TaskMap = std::map<std::string, std::string>;

  Task(std::string_view title, std::string_view description, TaskPriority priority)
  :id{s_idGenerator++}, title{title}, description{description}, priority{priority}
  {}

  int getId()const { return id; }
  const std::string& getTitle() const { return title; }
  const std::string& getDescription() const { return description; }
  TaskPriority getPriority() const { return priority; };

  std::string_view getPriorityAsStr() const;

  void updateTitle(std::string_view value) { title = value; }
  void updateDesctipion(std::string_view value) { description = value; }
  void updatePriority(TaskPriority value) { priority = value; }

  TaskMap toJson() const;

  friend std::ostream& operator<<(std::ostream& out, const Task& task);


private:
  static inline int s_idGenerator { 1 };
  int id {};
  std::string title{};
  std::string description{};
  TaskPriority priority{};
};

#endif