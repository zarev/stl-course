#ifndef _TRANSACTION_HPP_
#define _TRANSACTION_HPP_

#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std; 

#define BEGIN_TRANSACTION "BTRANS"

string& trim(string& s){
  s.erase(0, s.find_first_not_of(" \t\n"));
  s.erase(s.find_last_not_of(" \t\n") + 1);
  return s;
}

class Transaction{
  private:
    string accountName;
    long double amount;
    string memo;
    time_t timeStamp;
  
  public:
    Transaction() : accountName{}, amount({}), memo({}), timeStamp(time(0)) {}

    Transaction(const string &accountName, long double amount, const string& memo):
      accountName(accountName), amount(amount), memo(memo), timeStamp(time(0)){}
    
    const string& getAccountname() const      {return accountName;}
    long double   getAmount()     const       {return amount;}
    const string& getMemo()       const       {return memo;}
    time_t        getTimeStamp()  const       {return timeStamp;}

  friend ostream& operator<<(ostream& os, const Transaction& t){
    os << BEGIN_TRANSACTION << " "
      << t.accountName << " "
      << t.timeStamp << " "
      << t.amount << " "
      << t.memo << endl;
    return os; 
  }

  friend istream& operator>>(istream& is, Transaction& t){
    is >> t.accountName;
    is >> t.timeStamp;
    is >> t.amount;
    getline(is, t.memo);
    trim(t.memo);
    return is;
  }

};

#endif