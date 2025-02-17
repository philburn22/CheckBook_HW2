/*************************************************************************
** Author             : Nathan Philburn
** Program            : Philburn_HW2_Q1.cpp
** Date Created       : February 16, 2025
** Date Last Modified : February 16, 2025
** Usage              : No command line arguments
** Problem:
Implement a Check struct with an overloaded operator (>) that compares
a Check’s amount with a float and an overloaded << operator to print all
check details in one line. Also, implement a CheckBook class that maintains
a dynamic array of Checks with functions to deposit money, write checks (with
dynamic array doubling when half full), and display all checks (most recent first).
Additionally, write a test function that ** calls writeCheck until the balance is
exhausted.
*************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct Check {
    int checkNum;
    string checkMemo;
    float checkAmount;
};
class CheckBook {
private:
    float balance;
    Check *chkPtr;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;
public:
    CheckBook():balance(0), lastDeposit(0), numOfChecks(0), checkBookSize(4){}      //default constructor
    CheckBook(float initialBalance):balance(initialBalance), numOfChecks(0), checkBookSize(2){}     //2nd constructor
    CheckBook(const CheckBook){}                    //copy constructor
    //An overloaded=assignment operator
    //destructor
    void deposit();                 //deposit function
    float getBalance()const{};                 //getters
    float getLastDeposit()const{};
    int getNumOfChecks()const{};
    bool writeCheck(check c_amount);
};
int main(){
    return 0;
};
