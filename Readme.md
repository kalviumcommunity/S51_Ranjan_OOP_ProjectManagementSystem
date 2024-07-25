# Project Management System

The Project Management System is a software tool designed to help teams manage projects, tasks, and collaboration. It provides features for project creation, task tracking, team communication, and reporting, all within a desktop or console application built using C++.

## Key Components

### User Authentication

- **Functionality:** Secure login and registration system to manage user access.
- **Implementation:** Uses a custom or third-party authentication library. Passwords are stored securely (hashed and salted).

### Project Management

- **Functionality:** Allows users to create, update, and delete projects.
- **Implementation:** Provides a user interface (CLI or GUI) to manage project details such as name, description, and deadlines.

### Task Tracking

- **Functionality:** Users can assign tasks to team members, set deadlines, and track the status of each task.
- **Implementation:** Each task is associated with a project and includes fields for status (e.g., Not Started, In Progress, Completed), priority, and due dates.

### Team Collaboration

- **Functionality:** Enables communication between team members.
- **Implementation:** Includes a messaging feature or integrates with a communication library for real-time updates and notifications.

### Reporting and Analytics

- **Functionality:** Generates reports and visualizes project metrics.
- **Implementation:** Provides summaries of project progress, task completion rates, and other relevant statistics. Reports can be generated in various formats (e.g., text, CSV).

## Technical Details

### Programming Language

- **C++** is used to implement the core functionality. It provides performance and control over system resources.



## How It Works

### Starting the Application

- Launch the application from the command line or by executing the compiled binary.

### User Authentication

- Users can register or log in. Upon successful authentication, they gain access to the project management features.

### Project Management

- Users create projects, which can then be populated with tasks. Projects can be updated or removed as needed.

### Task Management

- Tasks are assigned to team members with deadlines and priorities. Progress can be tracked and updated.



## Installation and Configuration

### Clone the Repository

- Obtain the source code from the GitHub repository:

  git clone https://github.com/kalviumcommunity/S51_Ranjan_OOP_ProjectManagementSystem
  cd project-management-system
