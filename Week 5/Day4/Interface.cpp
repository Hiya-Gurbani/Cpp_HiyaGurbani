class IBank {
    //Any other data member we can define as we have nothing explicitly
public:
    virtual void handleMenu() = 0;
    virtual bool login(Constants::UserRole role) = 0;
    virtual void logout() = 0;

    virtual ~IBank() = default;
};

int main() {
    // IBank bank; Cannot decalre this
}