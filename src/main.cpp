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

void addTask (std::vector<Task>& tasks) {
    std::cout<<"Enter the task to be added: " ;
    std::string added_task{};
    std::getline(std::cin, added_task);
    int id = tasks.size() + 1;

    if (added_task.empty()) {
        std::cout<<"The added task cannot be empty, try again \n";
        addTask(tasks);
        return;
    }

    tasks.push_back({id, added_task, false});


    std::cout<<"Task has been added \n";

}

void completeTask (std::vector<Task>& tasks) {

    if (tasks.empty()) {
        std::cout<<"No tasks to be completed \n";
        return;
    }

    std::cout<<"Enter the id of task completed: ";
    int task_id{};
    std::cin>>task_id;

    if (std::cin.fail()) {
        std::cout << "Not a valid number, try again \n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        completeTask(tasks);
        return;
    }

    std::cin.ignore(10000, '\n');

    if (task_id <= 0 || task_id > tasks.size()) {
        std::cout << "Not a valid number, try again \n";
        completeTask(tasks);
        return;
    }

    for (Task& task : tasks) {
        if (task.id == task_id) {
            task.completed = true;
        }
    }

    std::cout<<"Task marked as completed \n";
    
}

void deleteTask (std::vector<Task>& tasks) {

    if (tasks.empty()) {
        std::cout<<"No tasks to be deleted \n";
        return;
    }

    std::cout<<"Enter the id of task to be deleted: ";
    int task_id{};
    std::cin>>task_id;


    if (std::cin.fail()) {
        std::cout << "Not a valid number, try again \n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        deleteTask(tasks);
        return;
    }

    std::cin.ignore(10000, '\n');

    if (task_id <= 0 || task_id > tasks.size()) {
        std::cout << "Not a valid id, try again \n";
        deleteTask(tasks);
        return;
    }


    for (Task& task : tasks) {
        if (task.id > task_id) {
            task.id -= 1;
        }
    }

    tasks.erase(tasks.begin() + task_id - 1); 

    std::cout<<"Task Deleted successfully \n";

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
            addTask(tasks);
        }

        else if (user_command == "2") {
            listTasks(tasks);
        }

        else if (user_command == "3") {
            completeTask(tasks);
        }

        else if (user_command == "4") {
            deleteTask(tasks);
        }

        else if (user_command == "5") {
            break;
        }
        else {std::cout << "Invalid Command, Enter Again \n";}

    }



    return 0;
}