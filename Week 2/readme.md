# Week2 - Dynamic Linking

This branch demonstrates **Implicit** and **Explicit Dynamic Linking** in C++.  

The project has the following folder structure:

```
Week2/
├── Implicit Dynamic Linking/
│   ├── inc/
│   ├── src/
│   └── Main/
        └── main.cpp
├── Explicit Dynamic Linking/
│   ├── inc/
│   ├── src/
│   └── Main/
        └── main.cpp
```

---

## 1. Implicit Dynamic Linking

In this approach, we compile our source files into a **shared library** (`.so`) and then link it while compiling the main program.

### Steps

1. **Navigate to the folder:**

```bash
cd "Implicit Dynamic Linking"
```

2. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

3. **Compile the source files into position-independent code (`.o` files):**

```bash
g++ -I./inc -fPIC -c src/Addition.cpp -o bin/Addition.o
g++ -I./inc -fPIC -c src/Subtraction.cpp -o bin/Subtraction.o
g++ -I./inc -fPIC -c src/Multiplication.cpp -o bin/Multiplication.o
g++ -I./inc -fPIC -c src/Division.cpp -o bin/Division.o
```

4. **Create the shared library:**

```bash
g++ -shared -o liboperations.so bin/Addition.o bin/Subtraction.o bin/Multiplication.o bin/Division.o
```

5. **Compile the main program and link it with the shared library:**

```bash
g++ -I./inc Main/main.cpp -L. -loperations -Wl,-rpath=. -o main.out
```


6. **Run the program:**

```bash
./main.out
```

---

## 2. Explicit Dynamic Linking

In this approach, we use the **`dlopen`**, **`dlsym`**, **`dlclose`** and **`dlerror`** functions to access the shared library at runtime.

### Steps

1. **Navigate to the folder:**

```bash
cd ..
cd "Explicit Dynamic Linking"
```


2. **Create a `bin` directory to store object files:**

```bash
mkdir bin
```

3. **Compile the source files into position-independent code (`.o` files):**

```bash
g++ -I./inc -fPIC -c src/Addition.cpp -o bin/Addition.o
g++ -I./inc -fPIC -c src/Subtraction.cpp -o bin/Subtraction.o
g++ -I./inc -fPIC -c src/Multiplication.cpp -o bin/Multiplication.o
g++ -I./inc -fPIC -c src/Division.cpp -o bin/Division.o
```

4. **Create the shared library:**

```bash
g++ -shared -o liboperations.so bin/Addition.o bin/Subtraction.o bin/Multiplication.o bin/Division.o
```

5. **Compile the main program with the `-ldl` flag:**

```bash
g++ -I./inc Main/main.cpp -ldl -o main.out
```

6. **Run the program:**

```bash
./main.out
```

---
