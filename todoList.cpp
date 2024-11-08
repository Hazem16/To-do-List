#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

void add_task(std::vector<std::string> &tasks, std::vector<bool> &completed)
{
    std::string task;
    std::cout << "Enter Task Description: ";
    getline(std::cin, task);
    std::cout << task;
    tasks.push_back(task);
    completed.push_back(false);
}

void view_task(std::vector<std::string> &tasks, std::vector<bool> &completed)
{
    std::cout << "\nTo-do List: " << std::endl;

    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". " << tasks[i] << " - ";
        std::cout << (completed[i] ? "Completed" : "Not Completed") << std::endl;
    }
}

void markCompleted(std::vector<std::string> &tasks, std::vector<bool> &completed)
{
    int taskNumber;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= completed.size()) {
        completed[taskNumber - 1] = true;
        std::cout << "Task marked as completed\n";
    }
    else {
        std::cout << "Invalid task number.\n";
    }
}

int main()
{
    std::vector<std::string> tasks;
    std::vector<bool> completed;

    std::string choice;

    while (true) {
        std::cout << "\nTo-Do List Options:\n";
        std::cout << "1. Add a task\n";
        std::cout << "2. View tasks\n";
        std::cout << "3. Mark a task as completed\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore();

        if (choice == "1") {
            add_task(tasks, completed);
        }
        else if (choice == "2") {
            view_task(tasks, completed);
        }
        else if (choice == "3") {
            markCompleted(tasks, completed);
        }
        else if (choice == "4") {
            break;
        }
        else {
            std::cout << "Invalid option\n";
        }
    }
}
