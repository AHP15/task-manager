#include <iostream>
#include <limits>
#include <functional>

#include "Console.h"
#include "App.h"

void Console::printUserOptions() const {
  std::cout << "=====<Welcome to Task Manager App>=====\n"
            << "Select your option by number:\n";
  
  for(auto option: options) {
    std::cout << option << '\n';
  }
}


template <typename T>
T getInput(const std::function<bool(T)>& predicate = [](T){ return true; }) {
  T input {};
  while(true) {
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Invalid Input! \n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if(!predicate(input)) {
      std::cin.clear();
      std::cout << "Invalid Input! \n";
      continue;
    }

    return input;
  }
}

void Console::printTasks() const {
  for(auto& task: app.getTasks()) std::cout << task;
}

void Console::getUserOption() {
  userOption = getInput<int>(
    [](int input) {
      return  input >= 1 || input <= numberOfOptions;
    }
  );
}

void Console::addTask() {
  std::cout << "Enter your task's title:\n";
  std::string title { getInput<std::string>() };

  std::cout << "Enter your task's description:\n";
  std::string description { getInput<std::string>() };

  std::cout << "Shoose your task's priority by number:\n"
            << "1- Low\n"
            << "2- Medium\n"
            << "3- High\n";
  int priority { getInput<int>([](int input){ return input >= 1 && input <= 3; }) };

  std::cout << title << description << priority << '\n';
}

void Console::run() {

  printUserOptions();
  getUserOption();

  switch(userOption - 1) {
    case listTasks:
      printTasks();
      break;
    case addNewTask:
      addTask();
      break;
    default:
      break;
  }
}
