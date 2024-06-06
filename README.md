# Issue Tracking System

## Project Overview

This project implements a simple issue-tracking system for an imaginary company. The system allows the company to manage employees and issues dynamically, including functionalities such as adding and removing employees, creating and assigning issues, changing issue assignees, and displaying detailed information about employees and issues. The system ensures the unique identification of employees and issues and handles the reallocation of memory efficiently using dynamically allocated arrays.

## Features

The issue tracking system supports the following functionalities:

1. **Add a New Employee**: Hire a new employee with a unique name and title.
2. **Remove an Employee**: Remove an existing employee if they have no assigned issues.
3. **Create an Issue**: Create a new issue with a unique ID and assign it to an employee.
4. **Remove an Issue**: Remove an existing issue by its ID.
5. **Change Assignee**: Transfer all issues from one employee to another.
6. **Show All Employees**: Display a list of all employees with their names, titles, and number of issues assigned.
7. **Show All Issues**: Display a list of all issues with their IDs, descriptions, and names of assignees.
8. **Show Detailed Information About an Employee**: Display detailed information about a specified employee.
9. **Show Detailed Information About an Issue**: Display detailed information about a specified issue.

## Installation

To compile and run the program, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/issue-tracking-system.git
    cd issue-tracking-system
    ```

2. Ensure you have a C++ compiler installed (e.g., `g++`).

3. Compile the code:
    ```bash
    g++ -o IssueTrackingSystem main.cpp IssueTrackingSystem.cpp
    ```

4. Run the program:
    ```bash
    ./IssueTrackingSystem
    ```

## Usage

The class `IssueTrackingSystem` can be used to manage employees and issues dynamically. Here are the primary operations provided by the system:

- **Adding an Employee**: `addEmployee("John Doe", "Software Engineer");`
- **Removing an Employee**: `removeEmployee("John Doe");`
- **Creating an Issue**: `addIssue(1, "Fix bug in login module", "Jane Smith");`
- **Removing an Issue**: `removeIssue(1);`
- **Changing Assignee**: `changeAssignee("Jane Smith", "John Doe");`
- **Displaying All Employees**: `showAllEmployees();`
- **Displaying All Issues**: `showAllIssues();`
- **Displaying Employee Details**: `showEmployee("Jane Smith");`
- **Displaying Issue Details**: `showIssue(1);`

## Example

Below is an example test program using the `IssueTrackingSystem` class:

```cpp
#include <iostream>
#include "IssueTrackingSystem.h"

int main() {
    IssueTrackingSystem ITS;

    ITS.showAllEmployees();
    std::cout << std::endl;

    ITS.addEmployee("Alper", "Software Engineer");
    ITS.addEmployee("Enes", "Software Engineer");
    ITS.addEmployee("Ayse", "Software Engineer");
    ITS.addEmployee("Salih", "Software Engineer");
    ITS.addEmployee("Salih", "ML Engineer");
    ITS.addEmployee("Fatma", "Software Engineer");
    ITS.addEmployee("Yusuf", "Cook");
    ITS.removeEmployee("Kamil");
    ITS.removeEmployee("Enes");
    ITS.addEmployee("Merve", "Researcher");
    ITS.addEmployee("Ali", "DevOps Engineer");
    ITS.removeEmployee("Ali");

    std::cout << std::endl;

    ITS.addIssue(1, "Code payment module", "Ayse");
    ITS.addIssue(2, "Code login page", "Salih");
    ITS.addIssue(3, "Code logout page", "Fatma");
    ITS.addIssue(4, "Code search engine", "Ayse");
    ITS.addIssue(5, "Create algorithm for new recommendation engine", "Merve");
    ITS.addIssue(6, "Create robots.txt to inform crawlers", "Alper");
    ITS.addIssue(7, "Code profile pages", "Alper");
    ITS.addIssue(1, "Fix image not found bug", "Merve");
    ITS.addIssue(2, "Fix login bug", "Salih");
    ITS.removeIssue(8);
    ITS.removeIssue(1);

    std::cout << std::endl;

    ITS.changeAssignee("Hasan", "Huseyin");
    ITS.changeAssignee("Hasan", "Salih");
    ITS.changeAssignee("Salih", "Fatma");
    ITS.removeEmployee("Salih");
    ITS.removeEmployee("Fatma");
    ITS.removeIssue(4);
    ITS.removeEmployee("Ayse");

    std::cout << std::endl;

    ITS.showAllEmployees();
    std::cout << std::endl;

    ITS.showEmployee("Fatma");
    std::cout << std::endl;

    ITS.showEmployee("John");
    std::cout << std::endl;

    ITS.showAllIssues();
    std::cout << std::endl;

    ITS.showIssue(1);
    std::cout << std::endl;

    ITS.showIssue(3);

    return 0;
}
```


## Development

This project is developed using C++ and dynamically allocated arrays to manage memory efficiently. Ensure all additional classes, if any, are implemented in separate files.

## Creator

Ahmet Furkan KIZIL
furkan.kizil@ug.bilkent.edu.tr

---
