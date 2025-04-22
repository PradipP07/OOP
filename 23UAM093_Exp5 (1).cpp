#include <iostream>
#include <string>
using namespace std;

class Bank{
public:
    void deposit(int amount){
        cout<<"Depositing: "<<amount<<" in cash."<<endl;
    }
    void deposit(float amount){
        cout<<"Depositing: "<< amount <<" via digital payment."<<endl;
    }
    void deposit(string upiID,int amount=0){
        cout<<"Depositing: "<<amount<<" using UPI("<<upiID<<")."<<endl;
    }
};
class Account{
private:
    int accountNumber;
    float balance;

public:
    Account(int accNo,float initialBalance){
        accountNumber=accNo;
        balance=initialBalance;
    }
    void display(){
        cout<<"Account"<<accountNumber<<" Balance:"<<balance<<endl;
    }
    void operator+(Account&other){
        float transferAmount=3000; 
        if (balance>=transferAmount){
            balance-=transferAmount;
            other.balance+=transferAmount;
            cout<<"Transferring "<<transferAmount<<" from Account"<<accountNumber
                 <<" to Account "<<other.accountNumber<<"..."<<endl;
            cout<<"New Account"<<accountNumber<<" Balance: "<<balance<<endl;
            cout<<"New Account"<<other.accountNumber<<" Balance: "<<other.balance<<endl;
        }else{
            cout<<"Insufficient funds for transfer!"<<endl;
        }
    }
    void operator-(float amount){
        if (balance>=amount) {
            balance-=amount;
            cout<<"Withdrawing "<<amount<<" from Account"<<accountNumber<<"..."<<endl;
            cout<<"Remaining Balance: "<<balance<<endl;
        }else{
            cout<<"Insufficient funds for withdrawal!"<<endl;
        }
    }
};

int main() {
    Bank bank;
    bank.deposit(5000); 
    bank.deposit(1500.75f);      
    bank.deposit("gpay@upi", 2500); 
	cout<<"\n" ;
    Account acc1(1, 10000); 
    Account acc2(2, 5000); 
    acc1.display();
    acc2.display();
    cout<<"\n" ;
    acc1+acc2;  
    acc1-2000;
    return 0;
}

