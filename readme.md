# Multi-Format File Parser

A C++ application that parses JSON, CSV and XML files using OOP principles 
and third-party libraries.

---

## Dependencies

| Library        | Format | Type          |
|----------------|--------|---------------|
| nlohmann/json  | JSON   | Header-only   |
| rapidcsv       | CSV    | Header-only   |
| pugixml        | XML    | Shared library|

---

## Setup

Install pugixml via terminal:
```bash
sudo apt install libpugixml-dev
```

Download the following headers and place them in `inc/` before building:

- **nlohmann/json.hpp** — https://github.com/nlohmann/json 
  Place at `inc/nlohmann/`

- **rapidcsv.h** — https://github.com/d99kris/rapidcsv  
  Place at `inc/rapidcsv.h`

---

## Build and Run

**Step 1 — Create a `bin` directory to store object files:**
```bash
mkdir bin
```

**Step 2 — Compile to object files**
```bash
cd bin && g++ -I../inc -c ../src/*.cpp && cd ..
```

**Step 3 — Create static library**
```bash
ar rcs libparser.a bin/*.o
```

**Step 4 — Build executable**
```bash
g++ -I./inc main/main.cpp -L. -lparser -lpugixml -o parser.out
```

**Step 5 — Run**
```bash
./parser.out
```

---

## Supported Formats

- `.json` — array of objects
- `.csv`  — comma separated with headers
- `.xml`  — attribute or child element based

---

## Sample Usage
```
========================================
       Welcome to File Parser App
========================================

This app can parse the following formats:

  [1]  JSON  (.json)
  [2]  CSV   (.csv)
  [3]  XML   (.xml)

----------------------------------------

Enter the full file path: sample.csv

========================================
  File   : sample.csv
  Format : CSV
  Records: 1
========================================

--- Record 1 ---
  name            : Alice
  age             : 30
  city            : Delhi
  profession      : Engineer
```