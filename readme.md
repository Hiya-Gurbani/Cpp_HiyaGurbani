### Steps to run the program

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
