#include <iostream>
#include "text.h"
using namespace std;


int main(int argc,char* argv[]) {
    text file;

        if (argc == 1) {
            file.printUsage();

        } else {
            if (argc == 2 || argc == 3){
                file.argerr(string(argv[1]));
            }
            if (argc == 2 && string(argv[1]) == "-a") {
                cout<<"Unable to add: no task provided"<<endl;
            }
            if (argc == 3 && string(argv[1]) == "-a") {
                file.add(string(argv[2]));
            }


            if(argc == 2 && string(argv[1]) == "-l"){
                file.list();
            }


            if (argc == 2 && string(argv[1]) == "-r") {
                cout<<"Unable to remove: no index provided"<<endl;
            }
            if(argc == 3 && string(argv[1]) == "-r"){
                int number;
                try {
                    number= stoi(string(argv[2]));
                    file.removeline(number);
                } catch(const invalid_argument& e) {
                    cout << "Unable to remove: index is not a number." << endl;
                }
            }

            if (argc == 2 && string(argv[1]) == "-c") {
                cout<<"Unable to check: no index provided"<<endl;
            }
            if(argc == 3 && string(argv[1]) == "-c"){
                int number;
                try {
                    number= stoi(string(argv[2]));
                    file.check(number);
                } catch(const invalid_argument& e) {
                    cout << "Unable to check: index is not a number." << endl;
                }
            }
            if(argc == 3 && string(argv[1]) == "-uc"){
                int number;
                try {
                    number= stoi(string(argv[2]));
                    file.uncheck(number);
                } catch(const invalid_argument& e) {
                    cout << "Unable to uncheck: index is not a number." << endl;
                }
            }
        }
    return 0;
}