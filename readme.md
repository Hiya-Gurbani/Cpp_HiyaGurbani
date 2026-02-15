### Steps to run the program

1. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

2. **Compile the source files into position-independent code (`.o` files):**

```bash
g++ -I./inc -fPIC -c src/Account.cpp -o bin/Account.o
g++ -I./inc -fPIC -c src/AdminController.cpp -o bin/AdminController.o
g++ -I./inc -fPIC -c src/Bank.cpp -o bin/Bank.o
g++ -I./inc -fPIC -c src/Customer.cpp -o bin/Customer.o
g++ -I./inc -fPIC -c src/CustomerController.cpp -o bin/CustomerController.o
g++ -I./inc -fPIC -c src/Display.cpp -o bin/Display.o
g++ -I./inc -fPIC -c src/InputHandler.cpp -o bin/InputHandler.o
g++ -I./inc -fPIC -c src/Transaction.cpp -o bin/Transaction.o
g++ -I./inc -fPIC -c src/Validator.cpp -o bin/Validator.o
```

3. **Create the shared library:**

```bash
g++ -shared -o libbank.so bin/*.o
```

4. **Compile the main program and link it with the shared library:**

```bash
g++ -I./inc main/main.cpp -L. -lbank -Wl,-rpath=. -o main.out
```


5. **Run the program:**

```bash
./main.out
```
