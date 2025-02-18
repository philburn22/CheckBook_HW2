/*************************************************************************
** Author             : Nathan Philburn
** Program            : Philburn_HW2_Q1.cpp
** Date Created       : February 16, 2025
** Date Last Modified : February 18, 2025
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
    Check():checkNum(0),checkMemo(" "), checkAmount(0.0f){}         //default constructor initialization
    Check(float amt):checkNum(0), checkMemo(" "), checkAmount(amt){}
};
bool operator>(const Check &c, float amount) {          //overloaded operators
    return c.checkAmount>amount;
}
ostream& operator<<(ostream &os, const Check &c) {
    os<<"Check number: "<<c.checkNum
    <<", Amount: "<<c.checkAmount
    <<", Memo: "<<c.checkMemo;
    return os;
}
class CheckBook {
private:
    float balance;
    Check *chkPtr;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;
public:
    CheckBook():balance(0), lastDeposit(0), numOfChecks(0), checkBookSize(4) {}          //default constructor
    CheckBook(float initialBalance):balance(initialBalance), numOfChecks(0), checkBookSize(2) {}    //2nd constructor
    CheckBook(const CheckBook) {}           //copy constructor
    //An overloaded=assignment operator
    //destructor
    void deposit(float amount) {        //deposit function
        balance+=amount;
        cout<<"Deposited: "<<amount<<". New balance: "<<balance<<endl;
    }
    float getBalance()const{return balance;};                 //getters
    float getLastDeposit()const{};
    int getNumOfChecks()const{};
    bool writeCheck(Check c_amount);
};
int main(){
    CheckBook cb(50.0f);        //creates a checkbook object
    cb.deposit(25.0f);
    Check c(10.0f);
    cout<<c<<endl;
    return 0;
};
