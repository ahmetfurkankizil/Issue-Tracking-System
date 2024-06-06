#ifndef __ISSUE_H
#define __ISSUE_H
#include <iostream>
#include <string>
using namespace std;


class Issue{
    public:
        Issue(int issueId, string issueDescription, string issueHolder);
        Issue();

        int getId();
        string getDescription();
        string getHolder();
    private:
        int id;
        string description;
        string holder;
};

#endif