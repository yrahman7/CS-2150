//Yumna Rahman, yr6by
//Sept. 9 2020
//file bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {
 public:
  bankAccount();              //default constructor
  bankAccount(double amount); //constructor
  ~bankAccount();             //destructor
  
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();

 private:
  double balance;
  
};

#endif
