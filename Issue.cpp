#include <iostream>
#include <string>
#include <utility>
using namespace std;
#include "Issue.h"

Issue::Issue(){
    id = 0;
    description = "";
    holder = "";
}

Issue::Issue(int issueId, string issueDescription, string issueHolder){
    id = issueId;
    description = issueDescription;
    holder = issueHolder;
}

int Issue::getId(){
    return id;
}

string Issue::getDescription(){
    return description;
}

string Issue::getHolder(){
    return holder;
}

