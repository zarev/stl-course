#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

#include "transaction.hpp"

#define BEGIN_ACCOUNT "BACCT"

using namespace std;

class Account {
  string name;
  vector<Transaction> transactions;
  
  public:
    Account() : name({}), transactions({}){}
    Account(const string& name) : name(name), transactions({}) {}

    const string& getName() const { return name;}
    const vector<Transaction>& getTransactions() const { return transactions;}
    
    void addTransaction(Transaction& t){transactions.push_back(t);}

    long double balance() const{
      long double sum = 0;
      sum = accumulate(begin(transactions), end(transactions), sum, [](const double& a, const Transaction& b){
        return a + b.getAmount();
      });
      
      return sum;
    }
    
    friend ostream& operator<<(ostream& os, const Account& a){
      os << BEGIN_ACCOUNT << " "
        << a.name << endl;

      return os;
    }

    friend istream& operator>>(istream& is, Account& a){
      is >> a.name;
      return is;
    }
};


#endif