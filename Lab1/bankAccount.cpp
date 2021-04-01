//Yumna Rahman, yr6by
//Sept. 9 2020
//file bankAccount.cpp

#include "bankAccount.h"
#include <iostream>
using namespace std;

//constructors and destructor
bankAccount::bankAccount() {
  balance = 0.0;
}

bankAccount::bankAccount(double amount) {
  balance = amount;
}

bankAccount::~bankAccount() {
  //leave implementation empty
}

//Regular methods with return types
double bankAccount::withdraw(double amount) {
  if (amount > balance) {
    return balance;
  }
  else {
    balance = balance - amount;
    return balance;
  }
}

double bankAccount::deposit(double amount) {
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance() {
  return balance;
}
