class BankAccount {
public:
    int balance;
    BankAccount(int initial) : balance(initial) {}

    void deposit(int amount)  { 
        balance += amount; 
    }

    //No check on withdrawal
    void withdraw(int amount) { 
        balance -= amount; 
    } 

    void applyFee(int fee) { 
        balance = balance - fee; 
    }
};

int main() {
    BankAccount acct(100);
    acct.deposit(50);     
    acct.withdraw(30);     
    acct.applyFee(10); 
    acct.withdraw(200);   //Here, balance would become negative
    acct.deposit(20);     
    return 0;
}