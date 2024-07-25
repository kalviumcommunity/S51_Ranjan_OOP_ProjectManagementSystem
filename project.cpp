#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Task {
private:
    string title;
    string description;
    bool completed;
    string deadline;

public:
    
    Task(const string& title, const string& description, const string& deadline)
        : title(title), description(description), completed(false), deadline(deadline) {}

    
    void markComplete() {
        completed = true;
    }

    
    void displayTask() const {
        cout << "Title: " << title << "\n"
                  << "Description: " << description << "\n"
                  << "Deadline: " << deadline << "\n"
                  << "Status: " << (completed ? "Completed" : "Pending") << "\n";
    }

    
    string getTitle() const {
        return title;
    }
};


class Project {
private:
    string projectName;
    vector<Task> tasks;
    vector<string> teamMembers;

public:
    
    Project(const string& name) : projectName(name) {}

    
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    
    void listTasks() const {
        cout << "Tasks for Project: " << projectName << "\n";
        for (const auto& task : tasks) {
            task.displayTask();
            cout << "----------------\n";
        }
    }

    
    void addTeamMember(const string& member) {
        teamMembers.push_back(member);
    }

    
    void listTeamMembers() const {
        cout << "Team Members for Project: " << projectName << "\n";
        for (const auto& member : teamMembers) {
            cout << "- " << member << "\n";
        }
    }
};


int main() {
    
    Task task1("Design Layout", "Create mockups for the new website", "2024-08-15");
    Task task2("Develop Frontend", "Implement the frontend using React", "2024-09-15");

    
    Project project1("Website Redesign");

    
    project1.addTask(task1);
    project1.addTask(task2);

    
    project1.addTeamMember("Alice");
    project1.addTeamMember("Bob");

    
    project1.listTasks();
    project1.listTeamMembers();

    
    task1.markComplete();
    cout << "\nUpdated Task Details:\n";
    task1.displayTask();

    return 0;
}

