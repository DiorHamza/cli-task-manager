#include <iostream>
#include <string>
#include <vector>

struct Task {
    int id;
    std::string description;
    bool completed;
};

void listTasks (const std::vector<Task>& tasks) {
    for (const Task& task : tasks) {
        std::cout<< task.id<< ". " <<((task.completed) ? "[X]" : "[ ]") << " " << task.description << "\n";
    }
}



int main() {

    std::vector<Task> tasks{{1, "Meditate", false}, {2, "Stretch", true}, {3, "Read Book", false}};

    std::string user_command{};

    while (true) {

        std::cout << "\n=== Task Manager ===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. List tasks\n";
        std::cout << "3. Complete task\n";
        std::cout << "4. Delete task\n";
        std::cout << "5. Quit\n\n";

        std::cout << "Enter a choice: ";

        std::getline(std::cin, user_command);

        if (user_command == "1") {
            // addTask function
        }

        else if (user_command == "2") {
            listTasks(tasks);
        }

        else if (user_command == "3") {
            // completeTask function
        }

        else if (user_command == "4") {
            // deleteTask function
        }

        else if (user_command == "5") {
            break;
        }
        else {std::cout << "Invalid Command, Enter Again \n";}

    }



    return 0;
}