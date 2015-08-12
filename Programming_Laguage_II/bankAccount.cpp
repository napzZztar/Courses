//If you are not running C++11 this code is not gonna work... 

#include <iostream>

using namespace std;


class BankAccount{
    private:
        string holderName;
        float currentBalance;
        float deposit;
        float withdraw;

    public:
        BankAccount(string name, float balance){
            holderName = name;
            currentBalance = balance;
        }

        void depositMoney(float amount){
            if (amount < 0) {
                cout<<"Deposit not possible"<<endl;
                return;
            }

            deposit = amount;

            currentBalance += amount;
        }

        void withdrawMoney(float amount){
            if (amount < 0) {
                cout<<"Withdrawal not possible"<<endl;
            }else if(currentBalance >= amount){
                withdraw = amount;
                currentBalance -= amount;
                cout<<"Successful withdraw"<<endl;
            }else{
                cout<<"Balance is too low."<<endl;
            }

        }

        void showData(){
            cout<<"Account holder name \t:\t"<<this->holderName<<endl;
            cout<<"Current balance \t:\t"<<this->currentBalance<<endl;
            cout<<"Last withdrawal \t:\t"<<this->withdraw<<endl;
            cout<<"Last deposit \t\t:\t"<<this->deposit<<endl;
        }


        ~BankAccount(){
            cout<<"Calling the destructor"<<endl;
        }

};


int main(){

    BankAccount *accounts;
    accounts = new BankAccount[5]{{"Name 1", 100.5},{"Name 2", 483}, {"Name 3", 894}, {"Name 4", 487}, {"Name 5", 874}};

    for (int i = 0; i < 5; i++) {
        accounts[i].showData();

        cout<<"=============================="<<endl<<endl;
    }

    return 0;
}
