#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract Base Task class demonstrating Single Responsibility Principle (SRP)
// Each class is responsible for a single part of the functionality in this system
class Task {
protected:
    string title;
    string description;
    bool completed;
    string deadline;
    static int taskCount;

public:
    Task() : title(""), description(""), completed(false), deadline("") {
        taskCount++;
    }

    Task(const string& title, const string& description, const string& deadline)
        : title(title), description(description), completed(false), deadline(deadline) {
        taskCount++;
    }

    virtual ~Task() {
        taskCount--;
    }

    // Getters and setters for Task properties
    string getTitle() const {
        return title;
    }

    string getDescription() const {
        return description;
    }

    string getDeadline() const {
        return deadline;
    }

    bool isCompleted() const {
        return completed;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    void setDescription(const string& description) {
        this->description = description;
    }

    void setDeadline(const string& deadline) {
        this->deadline = deadline;
    }

    void setCompleted(bool completed) {
        this->completed = completed;
    }

    void markComplete() {
        this->completed = true;
    }

    // Pure virtual function for displaying task details, making Task an abstract class
    virtual void displayTask() const = 0;

    // Static method to get the total task count
    static int getTaskCount() {
        return taskCount;
    }
};

int Task::taskCount = 0;

// Derived class for special tasks, inheriting from Task
class SpecialTask : public Task {
private:
    string priority;

public:
    SpecialTask(const string& title, const string& description, const string& deadline, const string& priority)
        : Task(title, description, deadline), priority(priority) {}

    // Overriding displayTask to include priority
    void displayTask() const override {
        cout << "Title: " << this->title << " (Special Task)\n"
             << "Description: " << this->description << "\n"
             << "Deadline: " << this->deadline << "\n"
             << "Priority: " << this->priority << "\n"
             << "Status: " << (this->completed ? "Completed" : "Pending") << "\n";
    }
};

// Project class demonstrating SRP, managing only project-related data
class Project {
private:
    string projectName;
    vector<Task*> tasks;
    vector<string> teamMembers;
    static int projectCount;

public:
    Project(const string& name) : projectName(name) {
        projectCount++;
    }

    ~Project() {
        for (auto task : tasks) {
            delete task;
        }
        projectCount--;
    }

    // Getters and setters for project name
    string getProjectName() const {
        return projectName;
    }

    vector<Task*> getTasks() const {
        return tasks;
    }

    vector<string> getTeamMembers() const {
        return teamMembers;
    }

    void setProjectName(const string& name) {
        this->projectName = name;
    }

    // Adds a task to the project
    void addTask(Task* task) {
        this->tasks.push_back(task);
    }

    // Displays tasks for the project
    void listTasks() const {
        cout << "Tasks for Project: " << this->projectName << "\n";
        for (const auto& task : this->tasks) {
            task->displayTask();
            cout << "----------------\n";
        }
    }

    // Adds a team member to the project
    void addTeamMember(const string& member) {
        this->teamMembers.push_back(member);
    }

    // Displays project team members
    void listTeamMembers() const {
        cout << "Team Members for Project: " << this->projectName << "\n";
        for (const auto& member : this->teamMembers) {
            cout << "- " << member << "\n";
        }
    }

    static int getProjectCount() {
        return projectCount;
    }
};

int Project::projectCount = 0;

// Manager class demonstrating SRP, managing only project instances
class Manager {
private:
    vector<Project*> projects;

public:
    ~Manager() {
        for (auto project : projects) {
            delete project;
        }
    }

    // Adds a project to the manager
    void addProject(Project* project) {
        projects.push_back(project);
    }

    // Lists all managed projects
    void listProjects() const {
        cout << "Projects:\n";
        for (const auto& project : projects) {
            cout << "Project: " << project->getProjectName() << "\n";
            project->listTasks();
            project->listTeamMembers();
            cout << "====================\n";
        }
    }
};

// Main function demonstrating polymorphism and SRP
int main() {
    Manager* manager = new Manager();

    string projectName;
    cout << "Enter the project name: ";
    getline(cin, projectName);

    Project* project1 = new Project(projectName);

    int numTasks;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;
    cin.ignore();

    for (int i = 0; i < numTasks; ++i) {
        string title, description, deadline, priority;
        cout << "Enter title for task " << i + 1 << ": ";
        getline(cin, title);
        cout << "Enter description for task " << i + 1 << ": ";
        getline(cin, description);
        cout << "Enter deadline for task " << i + 1 << ": ";
        getline(cin, deadline);

        cout << "Is this a special task? (y/n): ";
        char isSpecial;
        cin >> isSpecial;
        cin.ignore();

        if (isSpecial == 'y' || isSpecial == 'Y') {
            cout << "Enter priority for task " << i + 1 << ": ";
            getline(cin, priority);
            SpecialTask* specialTask = new SpecialTask(title, description, deadline, priority);
            project1->addTask(specialTask);
        } else {
            Task* task = new Task(title, description, deadline);  // Corrected to use abstract base class (if needed, could create a regular task subclass)
            project1->addTask(task);
        }
    }

    int numMembers;
    cout << "Enter the number of team members: ";
    cin >> numMembers;
    cin.ignore();

    for (int i = 0; i < numMembers; ++i) {
        string member;
        cout << "Enter name for team member " << i + 1 << ": ";
        getline(cin, member);

        project1->addTeamMember(member);
    }

    manager->addProject(project1);

    cout << "\nProject Details:\n";
    manager->listProjects();

    cout << "Total Tasks Created: " << Task::getTaskCount() << "\n";
    cout << "Total Projects Managed: " << Project::getProjectCount() << "\n";

    delete manager;

    return 0;
}
