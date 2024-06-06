#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

Employee::Employee(const string nameOfEmployee, const string titleOfEmployee){
    name = nameOfEmployee;
    title = titleOfEmployee;
    noOfIssues = 0;
}

Employee::Employee(){
    name = "";
    title = "";
    noOfIssues = 0;
}

string Employee::getName(){
    return name;
}

string Employee::getTitle(){
    return title;
}

int Employee::getNoOfIssues(){
    return noOfIssues;
}

void Employee::addIssue( const int issueId, const string description, const string assigneeName ){
    //If there is no issues in the system
    if(noOfIssues == 0){
        noOfIssues++;
        Issue* newIssues = new Issue[noOfIssues];
        //Create the issue and add it
        newIssues[0] = Issue(issueId, description, assigneeName);
        issues = newIssues;
    }
    else{
        noOfIssues++;
        Issue* newIssues = new Issue[noOfIssues];
        for (int i = 0; i < (noOfIssues-1); i++)
        {
            newIssues[i] = issues[i];
        }
        newIssues[noOfIssues-1] = Issue(issueId, description, assigneeName);
        delete[] issues;
        issues = newIssues;
    }
}

Issue* Employee::getIssues(){
    return issues;
}



void Employee::removeIssue(const int issueId){
    //Finding the index number of the issue first
    int index = -1;
    for (int i = 0; i < noOfIssues; i++)
    {
        if(issues[i].getId() == issueId){
            index = i;
        }
    }
    //Catching the exception if the program works incorrectly
    if(index == -1){
        std::cout << "Index exception" << std::endl;
        return;
    }

    noOfIssues--;
    Issue* newIssues = new Issue[noOfIssues];
    for (int i = 0; i < index; i++)
    {
        newIssues[i] = issues[i];
    }
    for (int i=index; i<noOfIssues; i++){
        newIssues[i] = issues[i+1];
    }
    delete [] issues;
    issues = newIssues;

}

bool Employee::scanForTheId(int id){
    bool exists = false;
    for (int i = 0; i < noOfIssues; i++)
    {
        if(issues[i].getId() == id){
            exists = true;
        }
    }
    return exists;
}

void Employee::showIssue(const int issueId){
    for (int i=0; i<noOfIssues; i++){
        if(issueId == issues[i].getId()){
            std::cout << "" + std::to_string(issues[i].getId()) + ", " + issues[i].getDescription() + ", " + issues[i].getHolder() + "." << std::endl;
            return;   
        }
    }
}

int Employee::showAllIssues(){
    for (int i = 0; i < noOfIssues; i++)
    {
        std::cout << std::to_string(issues[i].getId()) + ", " + issues[i].getDescription() + ", " + issues[i].getHolder() + "." << std::endl;
    }
    return noOfIssues;
}



Issue Employee::giveIssue(const int issueIndex) {
   return issues[issueIndex];
}


