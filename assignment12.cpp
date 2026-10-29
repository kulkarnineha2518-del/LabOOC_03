#include <iostream>
#include <string>
#include <fstream> 

using namespace std;
class BankingError {
public:
    void show() {
        cout << "Transaction Alert: Invalid funds transaction blocked!" << endl;
    }
};

class Account {
protected:
    // ENCAPSULATION 
    string name;
    double balance;

public:
  
    Account(string n = "Anonymous", double b = 0.0) : name(n), balance(b) {}

    
    virtual ~Account() {
        cout << "[System]: Account metadata released safely for: " << name << endl;
    }

  
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: ₹" << amount << " successfully." << endl;
        }
    }

    //  RUNTIME POLYMORPHISM 
    virtual void withdraw(double amount) = 0; 
    virtual void printStatement() {
        cout << "Holder Name: " << name << " | Balance Asset: ₹" << balance << endl;
    }


    string getName() { return name; }
    double getBalance() { return balance; }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    //  CONSTRUCTOR 
    SavingsAccount() : Account("New Savings User", 0.0), interestRate(3.0) {}

    SavingsAccount(string n, double b, double r) : Account(n, b), interestRate(r) {}

   
    ~SavingsAccount() {
        cout << "[System]: Savings records closed." << endl;
    }

    //  OVERRIDING
    void withdraw(double amount) override {
        //  EXCEPTIONS 
        if (amount <= 0 || amount > balance) {
            throw BankingError();
        }
        balance -= amount;
        cout << "Withdrawn from Savings: ₹" << amount << endl;
    }

    void applyInterest() {
        double addedInterest = balance * (interestRate / 100);
        balance += addedInterest;
        cout << "Interest Applied: +₹" << addedInterest << " at " << interestRate << "%" << endl;
    }

    void printStatement() override {
        cout << "\n=== Savings Statement ===" << endl;
        Account::printStatement(); 
        cout << "Configured Interest Rate yield: " << interestRate << "%" << endl;
    }

  
    // POLYMORPHISM (Operator Overloading)
   
    
    
    double operator+(SavingsAccount other) {
        return this->balance + other.balance;
    }

    bool operator==(SavingsAccount other) {
        return this->balance == other.balance;
    }
};

//  INHERITANCE (Checking Subclass)

class CheckingAccount : public Account {
private:
    double fee;

public:
    CheckingAccount(string n, double b, double f) : Account(n, b), fee(f) {}

    ~CheckingAccount() {
        cout << "[System]: Checking records closed." << endl;
    }

    //OVERRIDING 
    void withdraw(double amount) override {
        double totalDebit = amount + fee;
        if (amount <= 0 || totalDebit > balance) {
            throw BankingError();
        }
        balance -= totalDebit;
        cout << "Withdrawn from Checking: ₹" << amount << " (Fee: ₹" << fee << ")" << endl;
    }

    void printStatement() override {
        cout << "\n=== Checking Statement ===" << endl;
        Account::printStatement();
        cout << "Operational Service Fee per Withdrawal: ₹" << fee << endl;
    }
};

// 
//  OVERLOADING 

class BankLogger {
public:
   
    void logAction(string message) {
        cout << "[Bank System Logger]: " << message << endl;
    }

 
    void logAction(int code) {
        cout << "[Bank Operational Status Notification]: Verified Trace Flag -> " << code << endl;
    }
};


int main() {
  
    BankLogger logger;

    cout << "--- PHASE 1: Exception Bounds Security Tests ---\n" << endl;

    SavingsAccount customerA("Amit", 5000.0, 4.0);
    CheckingAccount customerB("Pooja", 3000.0, 50.0);

    try {
        logger.logAction("Initiating transactional check for customer Amit...");
        customerA.withdraw(6500.0); 
    } 
    catch (BankingError e) {
       
        e.show(); 
        cout << endl;
    }

    cout << "--- PHASE 2: Live Standard Financial Operations Loops ---\n" << endl;


    logger.logAction(200); 
    
  
    customerA.deposit(1500.0);
    customerA.applyInterest();
    customerA.printStatement(); 

    customerB.deposit(500.0);
   
    try {
        customerB.withdraw(1000.0);
    } catch(BankingError e) {
        e.show();
    }
    customerB.printStatement();

    cout << "\n--- PHASE 3: Custom Financial Evaluation Operators ---\n" << endl;

    SavingsAccount customerC("Rohan", 6656.0, 4.0); 

    //POLYMORPHISM 
    double bankCombinedLiquidity = customerA + customerC;
    cout << "Total Combined Assets Value (Amit + Rohan): ₹" << bankCombinedLiquidity << endl;

    if (customerA == customerC) {
        cout << "Asset Matching Verdict: Structurally identical financial balance holdings." << endl;
    } else {
        cout << "Asset Matching Verdict: Varied ledger balances detected." << endl;
    }

    cout << "\n--- PHASE 4: Permanent Drive Ledger Data Backups ---\n" << endl;

    string storageFileName = "statement_vault.txt";


    ofstream ledgerWriter(storageFileName, ios::out | ios::trunc);
    if (ledgerWriter.is_open()) {
        ledgerWriter << customerA.getName() << "\n";
        ledgerWriter << customerA.getBalance() << "\n";
        ledgerWriter.close();
        cout << "[Storage Stream]: Successfully saved current ledger data logs to local file disk." << endl;
    }

    ifstream ledgerReader(storageFileName, ios::in);
    if (ledgerReader.is_open()) {
        string recoveredHolder, recoveredBalance;
        getline(ledgerReader, recoveredHolder);
        getline(ledgerReader, recoveredBalance);
        ledgerReader.close();

        cout << "[Storage Stream]: Retrieved Verification Backup Record -> Name: " 
             << recoveredHolder << " | Verified Asset Balance: ₹" << recoveredBalance << endl;
    }

    cout << "\n--- PHASE 5: System Logouts & Resource Cleanup Lifecycle ---\n" << endl;
   
    return 0;
}
