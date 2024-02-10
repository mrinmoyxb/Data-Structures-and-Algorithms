#include <iostream>
using namespace std;

class BankingSystem{
    private:
    float bank_balance = 0.0;
    string account_pin = "";

    public:
    string firstName = "";
    string lastName = "";

    BankingSystem(){
        cout<<"          **********************          "<<endl;
        cout<<"          **********************          "<<endl;
        cout<<"          Welcome to Bank System          "<<endl;
        cout<<"          **********************          "<<endl;
        cout<<"          **********************          "<<endl;
    }
};

int main(){
    BankingSystem b1 = BankingSystem();
    return 0;
}