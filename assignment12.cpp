#include <iostream>
#include <string>
#include <fstream> // Required for Experiment 10 (File Persistence)

using namespace std;

// ==========================================
// EXP 11: EXCEPTIONS (Custom Banking Error Class)
// ==========================================
class BankingError {
public:
    void show() {
        cout << "Transaction Alert: Invalid funds transaction blocked!" << endl;
    }
};

// ==========================================
// EXP 9: VIRTUAL & OVERRIDING (Base Account Interface)
// ==========================================
class Account {
protected:
    // EXP 2: ENCAPSULATION (Protected data protected inside boundaries)
    string name;
    double balance;

public:
    // EXP 3: INITIALIZATION (Constructor using fallback defaults)
    Account(string n = "Anonymous", double b = 0.0) : name(n), balance(b) {}

    // EXP 5: LIFECYCLE (Virtual Destructor for absolute cleanups)
    virtual ~Account() {
        cout << "[System]: Account metadata released safely for: " << name << endl;
    }

    // Common shared transaction tools
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: ₹" << amount << " successfully." << endl;
        }
    }

    // EXP 9: RUNTIME POLYMORPHISM (Virtual functions to behave differently downstream)
    virtual void withdraw(double amount) = 0; // Pure Virtual Function
    virtual void printStatement() {
        cout << "Holder Name: " << name << " | Balance Asset: ₹" << balance << endl;
    }

    // Accessor tools for persistence pipelines
    string getName() { return name; }
    double getBalance() { return balance; }
};

// ==========================================
// EXP 7: INHERITANCE (Savings Subclass)
// ==========================================
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // EXP 5 & 7: CONSTRUCTOR CHAINING (Linear base sequence routing)
    SavingsAccount() : Account("New Savings User", 0.0), interestRate(3.0) {}

    SavingsAccount(string n, double b, double r) : Account(n, b), interestRate(r) {}

    // EXP 5: LIFECYCLE (Subclass clean destruction sequence)
    ~SavingsAccount() {
        cout << "[System]: Savings records closed." << endl;
    }

    // EXP 9: OVERRIDING (Custom implementation for specialized withdraw rule)
    void withdraw(double amount) override {
        // EXP 11: EXCEPTIONS (Throw error block if withdrawal drops balance below zero)
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
        Account::printStatement(); // Calls general layout
        cout << "Configured Interest Rate yield: " << interestRate << "%" << endl;
    }

    // ==========================================
    // EXP 8: POLYMORPHISM (Operator Overloading)
    // ==========================================
    
    // Overloading '+' to combine totals of two savings vaults
    double operator+(SavingsAccount other) {
        return this->balance + other.balance;
    }

    // Overloading '==' to check if balances match
    bool operator==(SavingsAccount other) {
        return this->balance == other.balance;
    }
};

// ==========================================
// EXP 7: INHERITANCE (Checking Subclass)
// ==========================================
class CheckingAccount : public Account {
private:
    double fee;

public:
    CheckingAccount(string n, double b, double f) : Account(n, b), fee(f) {}

    ~CheckingAccount() {
        cout << "[System]: Checking records closed." << endl;
    }

    // EXP 9: OVERRIDING (Enforces transaction fees on withdrawals)
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

// ==========================================
// EXP 6: OVERLOADING (Compile-Time Function Overloading)
// ==========================================
class BankLogger {
public:
    // Version 1: Logs standard message strings
    void logAction(string message) {
        cout << "[Bank System Logger]: " << message << endl;
    }

    // Version 2: Logs raw tracking numeric status codes
    void logAction(int code) {
        cout << "[Bank Operational Status Notification]: Verified Trace Flag -> " << code << endl;
    }
};

// ==========================================
// MAIN CAPSTONE SYNTHESIS ENTRY POINT (EXP 12)
// ==========================================
int main() {
    // EXP 4: MODELING (Architecting the structural operations log tool)
    BankLogger logger;

    cout << "--- PHASE 1: Exception Bounds Security Tests ---\n" << endl;

    SavingsAccount customerA("Amit", 5000.0, 4.0);
    CheckingAccount customerB("Pooja", 3000.0, 50.0);

    // EXP 11: EXCEPTIONS (Try-Catch transaction validation)
    try {
        logger.logAction("Initiating transactional check for customer Amit...");
        customerA.withdraw(6500.0); // This transaction fails (Insufficient funds!)
    } 
    catch (BankingError e) {
        // EXP 11: EXCEPTIONS (Gracefully recovered boundary loop handling anomalies)
        e.show(); 
        cout << endl;
    }

    cout << "--- PHASE 2: Live Standard Financial Operations Loops ---\n" << endl;

    // EXP 6: OVERLOADING (Compiler selects right logger variant automatically)
    logger.logAction(200); 
    
    // Core Deposits & Withdrawals execution
    customerA.deposit(1500.0);
    customerA.applyInterest();
    customerA.printStatement(); // Triggers Dynamic overridden layout logic

    customerB.deposit(500.0);
    
    // EXP 11: EXCEPTIONS (Valid execution under exception tracking framework boundaries)
    try {
        customerB.withdraw(1000.0);
    } catch(BankingError e) {
        e.show();
    }
    customerB.printStatement();

    cout << "\n--- PHASE 3: Custom Financial Evaluation Operators ---\n" << endl;

    SavingsAccount customerC("Rohan", 6656.0, 4.0); // Crafted to equal updated customerA balance metric

    // EXP 8: POLYMORPHISM (Using customized simple arithmetic logic wrappers directly)
    double bankCombinedLiquidity = customerA + customerC;
    cout << "Total Combined Assets Value (Amit + Rohan): ₹" << bankCombinedLiquidity << endl;

    if (customerA == customerC) {
        cout << "Asset Matching Verdict: Structurally identical financial balance holdings." << endl;
    } else {
        cout << "Asset Matching Verdict: Varied ledger balances detected." << endl;
    }

    cout << "\n--- PHASE 4: Permanent Drive Ledger Data Backups ---\n" << endl;

    string storageFileName = "statement_vault.txt";

    // EXP 10: PERSISTENCE (Output Stream file writing disk arrays)
    ofstream ledgerWriter(storageFileName, ios::out | ios::trunc);
    if (ledgerWriter.is_open()) {
        ledgerWriter << customerA.getName() << "\n";
        ledgerWriter << customerA.getBalance() << "\n";
        ledgerWriter.close();
        cout << "[Storage Stream]: Successfully saved current ledger data logs to local file disk." << endl;
    }

    // EXP 10: PERSISTENCE (Input Stream file data recovery checks)
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
    // Main boundary scope ends here. Automated system cleanup destructors will fire inside the console window next.
    return 0;
}
