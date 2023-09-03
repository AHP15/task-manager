#include <iostream>
#include <limits>
#include <functional>

#include "Console.h"
#include "App.h"

void Console::printUserOptions() const {
  printMessage("=====<Welcome to Task Manager App>=====\nSelect your option by number:");
  
  for(auto option: options) {
    printMessage(option);
  }
}



int Console::getInteger(int min, long max) {
  int input {};
  while(true) {
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      printMessage("Invalid Input!");
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if(input < min || input > max) {
      std::cin.clear();
      printMessage("Invalid Input!");
      continue;
    }

    return input;
  }
}

void Console::printTasks() const {
  for(auto& task: app.getTasks()) std::cout << task;
}

void Console::printFilteredTasks(const std::function<bool(const Task& task)>&  predicate) const {
  App::Tasks filteredTasks { app.filterTasks(predicate) };
  for(auto& task: filteredTasks) std::cout << task;
}

void Console::getUserOption() {
  userOption = getInteger(1, numberOfOptions);
}

std::string Console::getStringInput() const {
  std::string input{};

  while (true) {
    std::getline(std::cin >> std::ws, input);

    if (std::cin.fail()) {
      std::cin.clear();
      printMessage("Invalid Input!");
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    return input;
  }
  
}

void Console::addTask() {
  printMessage("Enter your task's title:");
  std::string title { getStringInput() };

  printMessage("Enter your task's description:");
  std::string description { getStringInput() };

  printMessage(
    "Shoose your task's priority by number:\n1- Low\n2- Medium\n3- High"
  );
  int Integer { getInteger(1, 3) };

  Task::TaskPriority priority {};
  switch (Integer) {
  case 1:
    priority = Task::low;
    break;
  case 2:
    priority = Task::medium;
    break;
  case 3:
    priority = Task::high;
    break;
  default:
    break;
  }
  app.addTask(
    Task{ title, description, priority }
  );
}

void Console::deleteTask() {
  printMessage("Enter the task's id:");
  app.deleteTask(
    getInteger(1, std::numeric_limits<std::streamsize>::max())
  );
}

void Console::run() {

  while (true) {
    printUserOptions();
    getUserOption();
    
    // I subtracted 1 from priority because TaskPriority enum type start from 0
    switch(userOption - 1) {
    case list:
      printTasks();
      break;
    case add:
      addTask();
      printMessage("Task added");
      break;
    case remove:
      deleteTask();
      break;
    case quit:
      printMessage("Thanks for using task manager app");
      return;
    case highPriorityTasks:
      printFilteredTasks([](const Task& task){
        return task.getPriority() == Task::high;
      });
      break;
    case mediumPriorityTasks:
      printFilteredTasks([](const Task& task){
        return task.getPriority() == Task::medium;
      });
      break;
    case lowPriorityTasks:
      printFilteredTasks([](const Task& task){
        return task.getPriority() == Task::low;
      });
      break;
    default:
      break;
    }
  }
  
}
