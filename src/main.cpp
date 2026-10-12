#include <iostream>

struct Task {
    int id;
    std::string description;
    bool completed;
};

int main() {

    Task t{1, "Buy groceries", false};

    std::cout << "ID: " << t.id << "\n";
    std::cout << "Description: " << t.description << "\n";
    std::cout << "Completed: " << t.completed << "\n";

    std::cout << "\n=== Task Manager ===\n";
    std::cout << "1. Add task\n";
    std::cout << "2. List tasks\n";
    std::cout << "3. Complete task\n";
    std::cout << "4. Delete task\n";
    std::cout << "5. Quit\n";


    return 0;
}