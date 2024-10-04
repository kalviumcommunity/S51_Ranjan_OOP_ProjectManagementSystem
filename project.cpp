#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base Task Class
class Task {
private:
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

    void displayTask() const {
        cout << "Title: " << this->title << "\n"
             << "Description: " << this->description << "\n"
             << "Deadline: " << this->deadline << "\n"
             << "Status: " << (this->completed ? "Completed" : "Pending") << "\n";
    }

    static int getTaskCount() {
        return taskCount;
    }
};

int Task::taskCount = 0;

// Derived Milestone Class (Single Inheritance)
class Milestone : public Task {
private:
    string milestoneDate;

public:
    Milestone(const string& title, const string& description, const string& deadline, const string& milestoneDate)
        : Task(title, description, deadline), milestoneDate(milestoneDate) {}

    string getMilestoneDate() const {
        return milestoneDate;
    }

    void setMilestoneDate(const string& milestoneDate) {
        this->milestoneDate = milestoneDate;
    }

    void displayTask() const override {
        Task::displayTask();
        cout << "Milestone Date: " << this->milestoneDate << "\n";
    }
};

// Project Class (As before)
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

    void addTask(Task* task) {
        this->tasks.push_back(task);
    }

    void listTasks() const {
        cout << "Tasks for Project: " << this->projectName << "\n";
        for (const auto& task : this->tasks) {
            task->displayTask();
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

    static int getProjectCount() {
        return projectCount;
    }
};

int Project::projectCount = 0;

// TeamLead Class (Multiple Inheritance)
class TeamLead : public Task, public Project {
public:
    TeamLead(const string& title, const string& description, const string& deadline, const string& projectName)
        : Task(title, description, deadline), Project(projectName) {}

    void displayDetails() const {
        cout << "Team Lead: " << Task::getTitle() << "\n";
        cout << "Project: " << Project::getProjectName() << "\n";
        Project::listTasks();
    }
};

int main() {
    // Manager object and Project setup
    Project* project1 = new Project("Website Development");

    Task* task1 = new Task("Design Mockup", "Create design mockups for the new website", "2024-10-10");
    Milestone* milestone1 = new Milestone("Code Base Setup", "Set up the basic project structure", "2024-10-05", "2024-10-15");

    project1->addTask(task1);
    project1->addTask(milestone1);

    // TeamLead setup (Multiple Inheritance)
    TeamLead* lead = new TeamLead("Ranjan", "Lead Developer", "2024-10-20", "Website Development");
    lead->addTask(task1);
    lead->addTask(milestone1);

    // Displaying details
    cout << "Project Details:\n";
    project1->listTasks();
    
    cout << "\nTeam Lead Details:\n";
    lead->displayDetails();

    delete project1;
    delete lead;

    return 0;
}
