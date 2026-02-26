# 🟢 Exercise 00: ft.h

## 📝 Objective
Create a standard C header file (`ft.h`) that contains the prototypes of several fundamental functions.

## 💡 The Logic
Header files are used to share function declarations across multiple `.c` files so the compiler knows how to link them.
1. **Include Guards:** To prevent the compiler from crashing due to double-inclusion (if the file is accidentally included twice), we wrap the entire file in preprocessor directives: `#ifndef FT_H`, `#define FT_H`, and `#endif`.
2. **Prototypes:** Inside the guards, we list the function prototypes exactly as they would appear in a `.c` file, but ending with a semicolon (`;`). 

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft.h`](ft.h)**

2. **Testing:**
   Create a dummy `main.c` that includes your header (`#include "ft.h"`) and compile it to ensure there are no syntax errors.
   ```bash
   cc -Wall -Wextra -Werror main.c -o test_ex00
   ```
