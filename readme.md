# Bank App Simulator

## Steps to Run the Program

1. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

2. **Compile the source files into position-independent code (`.o` files):**

```bash
cd bin && g++ -I../inc -fPIC -c ../src/*.cpp && cd ..
```

3. **Create the shared library:**

```bash
g++ -shared -o libbank.so bin/*.o
```

4. **Compile the main program and link it with the shared library:**

```bash
g++ -I./inc main/main.cpp -L. -lbank -Wl,-rpath=. -o BankAppSimulator.out
```

5. **Run the program:**

```bash
./BankAppSimulator.out
```

---

## Steps to Run the Tests

### Compile all tests in single test file

```bash
cd Test && g++ -I../src -I../inc ../src/*.cpp src/*.cpp main/main.cpp -lgtest -lpthread -o BankTests.out

### Compile a single test file

```bash
cd Test && g++ -I../src -I../inc -I./inc ../src/*.cpp src/ValidatorTest.cpp main/main.cpp -lgtest -lgmock -lpthread -o BankTests.out
```

Replace `ValidatorTest.cpp` with any other test file to compile that file instead.

### Run the tests

```bash
./BankTests.out
```

---

### Filtering Tests

**Run a single test:**
```bash
./BankTests.out --gtest_filter=ValidatorNameTest.ExactMinLength_AllAlpha_ReturnsTrue
```

**Run all tests in a fixture or suite:**
```bash
./BankTests.out --gtest_filter=ValidatorNameTest.*
```

**Run all parameterized tests:**
```bash
./BankTests.out --gtest_filter=InvalidChars/*
```

**Run a specific parameterized fixture:**
```bash
./BankTests.out --gtest_filter=InvalidChars/ValidatorDigitsInvalidCharTest.*
```

**Run multiple suites:**
```bash
./BankTests.out --gtest_filter=ValidatorNameTest.*:ValidatorEmailTest.*
```

---

### Excluding Tests

**Skip a suite:**
```bash
./BankTests.out --gtest_filter=-ValidatorNameTest.*
```

**Skip a single test:**
```bash
./BankTests.out --gtest_filter=-ValidatorNameTest.ExactMinLength_AllAlpha_ReturnsTrue
```

**Skip multiple suites:**
```bash
./BankTests.out --gtest_filter=-ValidatorNameTest.*:-ValidatorEmailTest.*
```

---

### Disabling Tests

Prefix the test name with `DISABLED_` to disable it without deleting it:

```cpp
TEST(ValidatorNameTest, DISABLED_ExactMinLength_AllAlpha_ReturnsTrue) {
    ...
}
```

To explicitly run disabled tests:
```bash
./BankTests.out --gtest_filter=*DISABLED_*
```

---

### Other Useful Commands

**List all tests without running them:**
```bash
./BankTests.out --gtest_list_tests
```

**Repeat tests multiple times** (useful for catching flaky tests):
```bash
./BankTests.out --gtest_repeat=3 --gtest_filter=ValidatorNameTest.*
```
