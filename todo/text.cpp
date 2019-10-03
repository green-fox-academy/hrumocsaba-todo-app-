#include <fstream>
#include <iostream>
#include <vector>
#include "text.h"
using namespace std;

void text::add(string input){

    ofstream addedtasks;
    addedtasks.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt",ios_base::app);

    addedtasks<<"[ ] "<<input<<endl;
    addedtasks.close();
}
void text::printUsage(){
    cout<<"Command Line Todo application"<<endl;
    cout<<"============================="<<endl;
    cout<<endl;
    cout<<"Command line arguments:"<<endl;
    cout<<"    -l   Lists all the tasks"<<endl;
    cout<<"    -a   Adds a new task"<<endl;
    cout<<"    -r   Removes a task"<<endl;
    cout<<"    -c   Completes a task"<<endl;
}

void text::list() {
    ifstream listing;
    listing.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");
    string text;
    int line=1;
    while (getline(listing,text)){
        cout<<line<<" - "<<text<<endl;
        line++;
    }
    if (line==1 && text==""){
        cout<<"No todos for today XD!"<<endl;
    }
    listing.close();
}

void text::removeline(int rline) {
    ifstream removeing;
    ofstream rewriting;
    removeing.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");
    string text;
    vector<string>templines;

    int line=1;
    while (getline(removeing,text)){
        if (line!=rline){
            templines.push_back(text);
        }
        line++;
    }
    removeing.close();
    try {
        if(rline > line-1 || rline<1){
            throw string("Unable to remove: index is out of bound.");
        }

        rewriting.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");

        for (int i = 0; i < templines.size(); ++i) {
            rewriting << templines[i] << endl;
        }

        rewriting.close();
    }catch(string err){
        cout<<err<<endl;
    }
}

void text::argerr(string argument) {
    if (argument != "-l") {
        if (argument != "-a") {
            if (argument != "-r") {
                if (argument != "-c") {
                    if (argument != "-uc") {
                        cout << "Unsupported argument" << endl;
                        printUsage();
                    }
                }
            }
        }
    }
}

void text::check(int cline){
    ifstream checking;
    ofstream checked;
    checking.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");
    string text;
    vector<string>templines;

    int line=1;

    while (getline(checking,text)){
        if (line==cline){
            text.replace(0,3,"[X]");
        }
        templines.push_back(text);
        line++;
    }
    checking.close();
    try {
        if(cline > line-1 || cline<1){
            throw string("Unable to check: index is out of bound.");
        }

        checked.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");
        for (int i = 0; i < templines.size() ; ++i) {
            checked<<templines[i]<<endl;
        }

        checking.close();
    }catch(string err){
        cout<<err<<endl;
    }
}

void text::uncheck(int cline){
    ifstream checking;
    ofstream checked;
    checking.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");
    string text;
    vector<string>templines;

    int line=1;

    while (getline(checking,text)){
        if (line==cline){
            text.replace(0,3,"[ ]");
            cout<<text<<endl;
        }
        templines.push_back(text);
        line++;
    }
    checking.close();
    try {
        if(cline > line-1 || cline<1){
            throw string("Unable to uncheck: index is out of bound.");
        }

        checked.open("C:/Users/HP/CLionProjects/TodoApp/Todos.txt");
        for (int i = 0; i < templines.size() ; ++i) {
            checked<<templines[i]<<endl;
        }
        checking.close();
    }catch(string err){
        cout<<err<<endl;
    }
}
