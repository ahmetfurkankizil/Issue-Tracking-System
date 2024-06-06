#include <iostream>
#include <string>

#include "IssueTrackingSystem.h"
using namespace std;

IssueTrackingSystem::IssueTrackingSystem(){
    employees = nullptr;
    numberOfEmployees = 0;
}

IssueTrackingSystem::~IssueTrackingSystem(){
    if(employees!= nullptr) {
        for (int i = 0; i < numberOfEmployees; ++i) {
            delete [] employees[i].getIssues();
        }
        delete [] employees;
    }
}

void IssueTrackingSystem::addEmployee( const string name, const string title ){
    //No employees in the system
    if (numberOfEmployees == 0){
        numberOfEmployees++;
        Employee* newEmployees = new Employee[numberOfEmployees];
        newEmployees[0] = Employee(name, title);
        employees = newEmployees;
        std::cout << "Added employee " + name + "." << std::endl;
    }
    else{
        for (int i = 0; i<numberOfEmployees; i++){
            if (employees[i].getName() == name)
            {
                std::cout << "Cannot add employee. Employee with name " + name + " already exists." << std::endl;
                return;
            }
        }
        // When it is okay to add the employee
        //Cooking the next array
        numberOfEmployees++;
        Employee* newEmployees = new Employee[numberOfEmployees];
        int endIndex = -1;
        for (int i = 0; i < (numberOfEmployees-1); i++)
        {
            newEmployees[i] = employees[i];
            endIndex = i;
        }
        newEmployees[endIndex+1] = Employee(name,title);
        delete[] employees;
        employees =  newEmployees;
        std::cout << "Added employee " + name + "." << std::endl;
    }
}

void IssueTrackingSystem::removeEmployee( const string name ){
    //Checking whether the employee exists in the system or not.
    bool exists = false;
    int index = -1;
    for (int i=0; i<numberOfEmployees; i++){
        if(name == employees[i].getName()){
            exists = true;
            index = i;
        }
    }
    // If the employee exists in the system
    if(exists){
        //If the employee has assigned issues
        if(employees[index].getNoOfIssues() != 0){
            std::cout << "Cannot remove employee. " + name + " has assigned issues." << std::endl;
        }
        else{
            //Removing the employee
            delete[] employees[index].getIssues();
            //Cooking the next array
            numberOfEmployees--;
            Employee* newEmployees = new Employee[numberOfEmployees];
            for (int i = 0; i < index ; i++){
                newEmployees[i] = employees[i];
            }
            for (int i=index; i<numberOfEmployees; i++){
                newEmployees[i] = employees[i+1];
            } 
            delete [] employees;
            employees = newEmployees;
            std::cout << "Removed employee " + name + "." << std::endl;
        }
    }
    //If the employee doesn't exist in the system
    else{
        std::cout << "Cannot remove employee. There is no employee with name " + name + "." << std::endl;
    } 
}

void IssueTrackingSystem::addIssue( const int issueId, const string description, const string assigneeName ){
    //Issue shouldn't be added
    if(issueCheck(issueId, assigneeName) == -1){
        return;
    }
    //Issue is feasible to be added
    else{
        employees[issueCheck(issueId, assigneeName)].addIssue(issueId, description, assigneeName);
        std::cout << "Added issue " + std::to_string(issueId) + "." << std::endl;
    }
}


void IssueTrackingSystem::removeIssue( const int issueId ){
    bool idExists = false;
    int employeeIndex = -1;
    for (int i = 0; i < numberOfEmployees; i++)
    {
        if(employees[i].scanForTheId(issueId)){
            idExists = true;
            employeeIndex = i;
        }
    }

    if(idExists){
        employees[employeeIndex].removeIssue(issueId);
        std::cout << "Removed issue " + std::to_string(issueId) + "." << std::endl;
    }
    else{
        std::cout << "Cannot remove issue. There is no issue with ID " + std::to_string(issueId) + "." << std::endl;
    }
}
void IssueTrackingSystem::changeAssignee( const string previousAssignee, const string newAssignee ){
    bool previousExists = false;
    int prevIndex = -1;
    bool newExists = false;
    int newIndex = -1;
    for (int i = 0; i < numberOfEmployees; i++) {
        if(employees[i].getName() == previousAssignee) {
            previousExists = true;
            prevIndex = i;
        }
    }
    for (int i = 0; i < numberOfEmployees; i++) {
        if(employees[i].getName() == newAssignee) {
            newExists = true;
            newIndex = i;
        }
    }
    //It is suitable to change assignee
    if(previousExists && newExists){
        for (int i = 0; i < employees[prevIndex].getNoOfIssues(); i++) {
            employees[newIndex].addIssue(employees[prevIndex].giveIssue(i).getId(), employees[prevIndex].giveIssue(i).getDescription(), employees[newIndex].giveIssue(i).getHolder());
            employees[prevIndex].removeIssue(employees[prevIndex].giveIssue(i).getId());
        }
        std::cout << previousAssignee + "'s issues are transferred to " + newAssignee + "." << std::endl;
    }
    else{
        std::cout << "Cannot change assignee. Previous or/and new assignee does not exist." << std::endl;
    }
}

void IssueTrackingSystem::showAllEmployees() const{
    std::cout << "Employees in the system:" << std::endl;
    //If there is no employees
    if(numberOfEmployees == 0){
        std::cout << "None" << std::endl;
    }
    else{
        for (int i = 0; i < numberOfEmployees; i++)
        {
            std::cout << "" + employees[i].getName() + ", " + employees[i].getTitle() + ", " + std::to_string(employees[i].getNoOfIssues()) + " issue(s)." << std::endl;
        }
    }
}

void IssueTrackingSystem::showAllIssues() const{
    std::cout << "Issues in the system:" << std::endl;
    int noneCheck = 0;
    for (int i = 0; i < numberOfEmployees; i++)
    {
        noneCheck += employees[i].showAllIssues();
    }
    if(noneCheck == 0){
        std::cout << "None" << std::endl;
    }
    
}
void IssueTrackingSystem::showEmployee( const string name ) const{
    for (int i=0; i<numberOfEmployees; i++){
        if(name == employees[i].getName()){
            std::cout << "" + employees[i].getName() + ", " + employees[i].getTitle() + ", " + std::to_string(employees[i].getNoOfIssues()) + " issue(s)." << std::endl; 
            return;   
        }
    }
    std::cout << "Cannot show employee. There is no employee with name " + name + "." << std::endl;
}
void IssueTrackingSystem::showIssue( const int issueId ) const{
    for (int i = 0; i < numberOfEmployees; i++)
    {
        if(employees[i].scanForTheId(issueId)){
            employees[i].showIssue(issueId);
            return;
        }
    }
    std::cout << "Cannot show issue. There is no issue with ID " + std::to_string(issueId) + "." << std::endl;
    
}

int IssueTrackingSystem::issueCheck(const int id, const string name){
    bool employeeExists = false;
    for (int i = 0; i < numberOfEmployees; i++)
    {
        if(employees[i].getName() == name){
            employeeExists = true;
        }
    }
    if(!employeeExists){
        std::cout << "Cannot add issue. There is no employee with name " + name + "." << std::endl;
        return -1;
    }
    else{
        bool idExists = false;
        for (int i = 0; i < numberOfEmployees; i++)
        {
            if(employees[i].scanForTheId(id)){
                idExists = true;
            }
        }

        if(idExists){
            std::cout << "Cannot add issue. Issue with ID " + std::to_string(id) + " already exists." << std::endl;
            return -1;
        }
        else{
            for (int i = 0; i < numberOfEmployees; i++)
            {
                if(employees[i].getName() == name){
                    return i;
                }
            }
            return -1;
        }
    }
}