#ifndef TODOAPP_TEXT_H
#define TODOAPP_TEXT_H
using namespace std;
class text {
public:
    void list();
    void add(string addedtask);
    void removeline(int rline);
    void check(int checkedline);
    void printUsage();
    void argerr(string argument);
    void uncheck(int uncheckedline);
};
#endif //TODOAPP_TEXT_H