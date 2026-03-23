### Steps to run the program

1. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

2. **Compile the source files into position-independent code (`.o` files):**

```bash
g++ -I./inc -fPIC -c src/DimensionHelper.cpp -o bin/DimensionHelper.o
g++ -I./inc -fPIC -c src/Input.cpp -o bin/Input.o
g++ -I./inc -fPIC -c src/MatrixOperation.cpp -o bin/MatrixOperation.o
g++ -I./inc -fPIC -c src/MatrixUtil.cpp -o bin/MatrixUtil.o
g++ -I./inc -fPIC -c src/MenuHandler.cpp -o bin/MenuHandler.o
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