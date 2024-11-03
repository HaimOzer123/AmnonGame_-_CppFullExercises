#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit(double &balance, double amount);
double withdraw(double &balance, double amount);

int main(){

    double balance = 0.0;
    int choice=0;
    do{
    std::cout<< "**********Welcome to the ATM**********"<<'\n';
    std::cout<<"Enter your choice: "<<'\n';
    std::cout<<"1. Show Balance"<<'\n';
    std::cout<<"2. Deposit"<<'\n';
    std::cout<<"3. Withdraw"<<'\n';
    std::cout<<"4. Exit"<<'\n';
    std::cin>>choice;

    std::cin.clear();
    fflush(stdin);

    switch(choice){
        case 1:
            showBalance(balance);
            break;
        case 2:
            double depositAmount;
            std::cout<<"Enter the amount you want to deposit: ";
            std::cin>>depositAmount;
            deposit(balance, depositAmount);
            showBalance(balance);
            break;
        case 3:
            double withdrawAmount;
            std::cout<<"Enter the amount you want to withdraw: ";
            std::cin>>withdrawAmount;
            withdraw(balance, withdrawAmount);
            showBalance(balance);
            break;
        case 4:
            break;
        default:
            std::cout<<"Invalid choice!"<<'\n';
            break;
    }
    }while(choice!=4);
    std::cout<<'\n'<<"**********Thank you for using the ATM**********"<<'\n';
    std::cout<<'\n'<<"**********Have a nice day!**********"<<'\n';
    std::cout<<'\n'<<"**********Goodbye!**********"<<'\n';
    return 0;
}

void showBalance(double balance){
    std::cout<<"Your balance is: $"<< std::setprecision(2) << std::fixed << balance<<'\n';
}
double deposit(double &balance, double amount){   //make sure it cant be negative amount 
    if (amount<0){
        std::cout<<"Invalid amount!"<<'\n';
        return balance;
    }else{
    balance += amount;
    return balance;
    }
}

double withdraw(double &balance, double amount){
    balance -= amount;
    return balance;
}
