class Counter {
private:
    int count = 0;

public:
    void increment() { count++; }
    void reset() { count = 0; }
    int getCount() const { return count; }
};
