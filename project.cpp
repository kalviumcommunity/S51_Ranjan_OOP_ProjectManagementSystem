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
        this->completed = true;
    }

    
    void displayTask() const {
        cout << "Title: " << this->title << "\n"
             << "Description: " << this->description << "\n"
             << "Deadline: " << this->deadline << "\n"
             << "Status: " << (this->completed ? "Completed" : "Pending") << "\n";
    }

    
    string getTitle() const {
        return this->title;
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
        this->tasks.push_back(task);
    }

    
    void listTasks() const {
        cout << "Tasks for Project: " << this->projectName << "\n";
        for (const auto& task : this->tasks) {
            task.displayTask();
            cout << "----------------\n";
        }
    }

    
    void addTeamMember(const string& member) {
        this->teamMembers.push_back(member);
    }

    
    void listTeamMembers() const {
        cout << "Team Members for Project: " << this->projectName << "\n";
        for (const auto& member : this->teamMembers) {
            cout << "- " << member << "\n";
        }
    }
};

int main() {
    string projectName;
    cout << "Enter the project name: ";
    getline(cin, projectName);

    Project project1(projectName);

    int numTasks;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;
    cin.ignore(); 

    for (int i = 0; i < numTasks; ++i) {
        string title, description, deadline;
        cout << "Enter title for task " << i + 1 << ": ";
        getline(cin, title);
        cout << "Enter description for task " << i + 1 << ": ";
        getline(cin, description);
        cout << "Enter deadline for task " << i + 1 << ": ";
        getline(cin, deadline);

        Task task(title, description, deadline);
        project1.addTask(task);
    }

    int numMembers;
    cout << "Enter the number of team members: ";
    cin >> numMembers;
    cin.ignore(); 

    for (int i = 0; i < numMembers; ++i) {
        string member;
        cout << "Enter name for team member " << i + 1 << ": ";
        getline(cin, member);

        project1.addTeamMember(member);
    }

    cout << "\nProject Details:\n";
    project1.listTasks();
    project1.listTeamMembers();

    return 0;
}
