#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Task {  
    int id;
    std::string description;
    bool completed;
};

void listTasks (const std::vector<Task>& tasks) {

    if (tasks.empty()) {
        std::cout<<"No tasks currently listed \n";
        return;
    }

    for (const Task& task : tasks) {
        std::cout<< task.id<< ". " <<((task.completed) ? "[X]" : "[ ]") << " " << task.description << "\n";
    }
}

void addTask (std::vector<Task>& tasks) {
    std::cout<<"Enter the task to be added: " ;
    std::string added_task{};

    if (!std::getline(std::cin, added_task)) {
        return;
    }

    int id = static_cast<int>(tasks.size() + 1);

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

    if (task_id <= 0 || task_id > static_cast<int>(tasks.size())) {
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

    if (task_id <= 0 || task_id > static_cast<int>(tasks.size())) {
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

void saveTasks(const std::vector<Task>& tasks) {
    std::ofstream outFile("tasks.txt");

    if (!outFile.is_open()) {
        std::cout << "Error: could not save tasks to tasks.txt \n";
        return;
    }

    for (const Task& task : tasks) {
        outFile << task.id<< "|" <<((task.completed) ? "1" : "0") << "|" << task.description << "\n";
    }
    
}

void loadTasks(std::vector<Task>& tasks) {
    std::ifstream file("tasks.txt");

    if (!file.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string id_text{};
        std::string completed_text{};
        std::string description{};

        std::getline(ss, id_text, '|');
        std::getline(ss, completed_text, '|');
        std::getline(ss, description);

        int id{};
        try {
            id = std::stoi(id_text);
        }
        catch (const std::exception&) {
            continue;
        }

        bool completed{(completed_text == "1")};
    
        tasks.push_back({id, description, completed});

    }
        
}


int main() {

    std::vector<Task> tasks{};

    loadTasks(tasks);

    std::string user_command{};

    while (true) {

        std::cout << "\n=== Task Manager ===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. List tasks\n";
        std::cout << "3. Complete task\n";
        std::cout << "4. Delete task\n";
        std::cout << "5. Quit\n\n";

        std::cout << "Enter a choice: ";

        if (!std::getline(std::cin, user_command)) {
            break;
        };

        if (user_command == "1") {
            addTask(tasks);
            saveTasks(tasks);
        }

        else if (user_command == "2") {
            listTasks(tasks);
        }

        else if (user_command == "3") {
            completeTask(tasks);
            saveTasks(tasks);
        }

        else if (user_command == "4") {
            deleteTask(tasks);
            saveTasks(tasks);
        }

        else if (user_command == "5") {
            break;
        }
        else {std::cout << "Invalid Command, Enter Again \n";}

    }



    return 0;
}