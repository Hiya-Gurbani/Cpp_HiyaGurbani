### Steps to run the program

1. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

2. **Compile the source files into position-independent code (`.o` files):**

```bash
g++ -I./inc -fPIC -c src/Application.cpp -o bin/Application.o
g++ -I./inc -fPIC -c src/InputHandler.cpp -o bin/InputHandler.o
g++ -I./inc -fPIC -c src/Matrix.cpp -o bin/Matrix.o
g++ -I./inc -fPIC -c src/MenuHandler.cpp -o bin/MenuHandler.o
g++ -I./inc -fPIC -c src/Validator.cpp -o bin/Validator.o
```

3. **Create the shared library:**

```bash
g++ -shared -o libmatrix.so bin/*.o
```

4. **Compile the main program and link it with the shared library:**

```bash
g++ -I./inc main/main.cpp -L. -lmatrix -Wl,-rpath=. -o main.out
```


5. **Run the program:**

```bash
./main.out
```