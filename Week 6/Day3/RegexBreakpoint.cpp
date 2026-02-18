#include <iostream>
#include <string>

class UserAccount {
private:
    std::string username;
    std::string email;
    int age;
    bool verified;

public:
//To have break at each member fucntion (invloves defaut destructors too )
//We do rbreak ^UserAccount::
    UserAccount(const std::string& name, const std::string& mail, int a) 
        : username(name), email(mail), age(a), verified(false) {}

    void setUsername(const std::string& name) {
        username = name;
        std::cout << "Username set to: " << name << "\n";
    }

    void setEmail(const std::string& mail) {
        email = mail;
        std::cout << "Email set to: " << mail << "\n";
    }

    void setAge(int a) {
        age = a;
        std::cout << "Age set to: " << a << "\n";
    }

    void setVerified(bool v) {
        verified = v;
        std::cout << "Verified set to: " << (v ? "true" : "false") << "\n";
    }

    void getInfo() {
        std::cout << "User: " << username << ", " << email 
                  << ", Age: " << age << ", Verified: " << verified << "\n";
    }

    bool checkAge() {
        return age >= 18;
    }
};

class Logger {
public:
    static void logInfo(const std::string& msg) {
        std::cout << "[INFO] " << msg << "\n";
    }

    static void logWarning(const std::string& msg) {
        std::cout << "[WARN] " << msg << "\n";
    }

    static void logError(const std::string& msg) {
        std::cout << "[ERROR] " << msg << "\n";
    }

    static void logDebug(const std::string& msg) {
        std::cout << "[DEBUG] " << msg << "\n";
    }
};

int main() {
    UserAccount user("alice", "alice@example.com", 25);

    //To have breakpoint at every set fucntion
    //We used rbreak set
    user.setUsername("alice_updated");
    user.setEmail("new@example.com");
    user.setAge(26);
    user.setVerified(true);

    user.getInfo();
    user.checkAge();

    //Same here we use rbreak log
    Logger::logInfo("User updated");
    Logger::logWarning("Email changed");
    Logger::logError("Age verification failed");
    Logger::logDebug("All operations complete");

    return 0;
}