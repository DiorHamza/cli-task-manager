#include <iostream>
#include <string>
#include <vector>

struct Task {
    int id;
    std::string description;
    bool completed;
};

int main() {

    std::vector<Task> tasks{{1, "Meditate", false}, {2, "Stretch", true}, {3, "Read Book", false}};

    for ( Task task : tasks) {
        std::cout<<task.id<< ". " <<((task.completed) ? "[X]" : "[ ]") << " " << task.description << "\n";
    }

    

    std::cout << "\n=== Task Manager ===\n";
    std::cout << "1. Add task\n";
    std::cout << "2. List tasks\n";
    std::cout << "3. Complete task\n";
    std::cout << "4. Delete task\n";
    std::cout << "5. Quit\n";


    return 0;
}