### Steps to run the program

1. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

2. **Compile the source files into position-independent code (`.o` files):**

```bash
g++ -I./inc -fPIC -c src/DimensionHelpers.cpp -o bin/DimensionHelpers.o
g++ -I./inc -fPIC -c src/Input.cpp -o bin/Input.o
g++ -I./inc -fPIC -c src/MatrixOperations.cpp -o bin/MatrixOperations.o
g++ -I./inc -fPIC -c src/MatrixUtils.cpp -o bin/MatrixUtils.o
g++ -I./inc -fPIC -c src/MenuHandlers.cpp -o bin/MenuHandlers.o
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