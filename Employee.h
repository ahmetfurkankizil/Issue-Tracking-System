#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;
#include "Issue.h"

class Employee{
    public:
        Employee(const string nameOfEmployee, const string titleOfEmployee);
        Employee();
        string getName();
        string getTitle();
        int getNoOfIssues();
        void addIssue( const int issueId, const string description, const string assigneeName );
        void removeIssue(const int issueId);
        bool scanForTheId(const int id);
        void showIssue(const int issueId);
        Issue giveIssue(const int issueId);
        int showAllIssues();
        Issue* getIssues();

    private:
        string name;
        string title;
        int noOfIssues;
        Issue* issues = nullptr;
};
#endif
