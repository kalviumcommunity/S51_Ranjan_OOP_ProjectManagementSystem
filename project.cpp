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
    // Default constructor
    Task() : title(""), description(""), completed(false), deadline("") {}

    // Parameterized constructor
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

    string getProjectName() const {
        return this->projectName;
    }
};

class Manager {
private:
    vector<Project> projects;

public:
    void addProject(const Project& project) {
        projects.push_back(project);
    }

    void listProjects() const {
        cout << "Projects:\n";
        for (const auto& project : projects) {
            cout << "Project: " << project.getProjectName() << "\n";
            project.listTasks();
            project.listTeamMembers();
            cout << "====================\n";
        }
    }
};

int main() {
    Manager manager;

    string projectName;
    cout << "Enter the project name: ";
    getline(cin, projectName);

    Project project1(projectName);

    int numTasks;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;
    cin.ignore();

    // Used  array to create tasks
    Task* tasks = new Task[numTasks];

    for (int i = 0; i < numTasks; ++i) {
        string title, description, deadline;
        cout << "Enter title for task " << i + 1 << ": ";
        getline(cin, title);
        cout << "Enter description for task " << i + 1 << ": ";
        getline(cin, description);
        cout << "Enter deadline for task " << i + 1 << ": ";
        getline(cin, deadline);

        tasks[i] = Task(title, description, deadline);
        project1.addTask(tasks[i]);
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

    manager.addProject(project1);

    cout << "\nProject Details:\n";
    manager.listProjects();

    delete[] tasks; 

    return 0;
}
