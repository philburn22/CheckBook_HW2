/*************************************************************************
** Author             : Nathan Philburn
** Program            : Philburn_HW2_Q1.cpp
** Date Created       : February 16, 2025
** Date Last Modified : February 19, 2025
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
#include <cstdlib>          //for rand functions
#include <ctime>
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
    os<<"Check number: "<<c.checkNum<<", Amount: "<<c.checkAmount<<", Memo: "<<c.checkMemo;
    return os;
}
class CheckBook {
private:
    float balance;              //current balance
    Check *chkPtr;              //pointer
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;
    void resizeCheckBook() {                //function to double size of check array
        int newSize=checkBookSize*2;
        Check *newArray=new Check[newSize];
        for (int i=0;i<numOfChecks;i++) {
            newArray[i]=chkPtr[i];
        }
        delete[]chkPtr;
        chkPtr=newArray;
        checkBookSize=newSize;
        cout<<"Warning: Checkbook half used. New size: "<<checkBookSize<<endl;
    }
public:
    CheckBook():balance(0.0f), lastDeposit(0.0f), numOfChecks(0), checkBookSize(4) {              //default constructor
        chkPtr=new Check[checkBookSize];
    }
    CheckBook(float initialBalance):balance(initialBalance), lastDeposit(0.0f), numOfChecks(0), checkBookSize(2) {         //2nd constructor
        chkPtr=new Check[checkBookSize];
    }
    CheckBook(const CheckBook &other) {                //copy constructor
        balance=other.balance;
        lastDeposit=other.lastDeposit;
        numOfChecks=other.numOfChecks;
        checkBookSize=other.checkBookSize;
        chkPtr=new Check[checkBookSize];
        for (int i=0;i<numOfChecks;i++) {
            chkPtr[i]=other.chkPtr[i];
        }
    }
    CheckBook& operator=(const CheckBook &other) {          //An overloaded=assignment operator
        if (this!=&other) {
            delete[]chkPtr;
            balance=other.balance;
            lastDeposit=other.lastDeposit;
            numOfChecks=other.numOfChecks;
            checkBookSize=other.checkBookSize;
            chkPtr=new Check[checkBookSize];
            for (int i=0;i<numOfChecks;i++) {
                chkPtr[i]=other.chkPtr[i];
            }
        }
        return *this;
    }
    ~CheckBook() {                         //destructor
        delete[]chkPtr;
    }
    void deposit(float amount) {        //deposit function
        balance+=amount;
        lastDeposit=amount;
        cout<<"Deposited: "<<amount<<". New balance: "<<balance<<endl;
    }
    float getBalance()const{return balance;};                 //getters
    float getLastDeposit()const{return lastDeposit;}
    int getNumOfChecks()const{return numOfChecks;}
    int getCheckBookSize()const{return checkBookSize;}
    bool writeCheck(Check c) {              //function that writes the check
        if (c>balance) {
            cout<<"Insufficient funds for check amount: "<<c.checkAmount<<endl;
            return false;
        }
        if (numOfChecks==checkBookSize/2) {
            resizeCheckBook();
        }
        c.checkNum=numOfChecks+1;
        const int numMemos=9;
        string memos[numMemos]={"utilities", "baby shower", "pizza", "barber shop", "hobbies", "home renovations", "tuition", "car payment", "rent"};
        int randomIndex=rand()%numMemos;                //generates random memos
        c.checkMemo=memos[randomIndex];
        balance-=c.checkAmount;
        chkPtr[numOfChecks]=c;
        numOfChecks++;
        cout<<"Check Written: "<<c<<endl;
        return true;
    }
    void displayChecks()const {             //display checks function
        cout<<"\nDisplaying all checks(most recent first):"<<endl;
        for (int i=numOfChecks-1;i>=0;i--) {
            cout<<chkPtr[i]<<endl;
        }
    }
};
    void checkTest(CheckBook &cb, float checkAmount) {                  //writes checks until funds run out
        cout<<"\nStarting check test. Writing checks of amount: "<<checkAmount<<"until balance is exhausted."<<endl;
        while (cb.getBalance()>=checkAmount) {
            Check c(checkAmount);
            if (!cb.writeCheck(c))
                break;
        }
        cout<<"\nFinal balance: "<<cb.getBalance()<<endl;
        cb.displayChecks();
    }
int main(){
    srand(static_cast<unsigned int>(time(0)));
    CheckBook myCheckBook(100.0f);
    myCheckBook.deposit(50.0f);
    checkTest(myCheckBook,10.0f);
    return 0;
};
