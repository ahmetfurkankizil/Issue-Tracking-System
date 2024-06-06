#ifndef __ISSUETRACKINGSYSTEM_H
#define __ISSUETRACKINGSYSTEM_H
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

class IssueTrackingSystem {
    public:
        IssueTrackingSystem();
        ~IssueTrackingSystem();
        void addEmployee( const string name, const string title );
        void removeEmployee( const string name );
        void addIssue( const int issueId, const string description, const string assigneeName );
        void removeIssue( const int issueId );
        void changeAssignee( const string previousAssignee, const string newAssignee );
        void showAllEmployees() const;
        void showAllIssues() const;
        void showEmployee( const string name ) const;
        void showIssue( const int issueId ) const;
        int issueCheck(const int id, const string name);

    private:
        Employee* employees;
        int numberOfEmployees;
    };

    #endif