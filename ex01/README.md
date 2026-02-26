# 🟢 Exercise 01: ft_boolean.h

## 📝 Objective
Create a header file (`ft_boolean.h`) containing specific macros and a custom data type so that a provided `main.c` file compiles and runs perfectly.

## 💡 The Logic
C does not have a native "boolean" (true/false) data type.
1. **Typedef:** We create our own boolean type using `typedef unsigned char t_bool;`. Using an `unsigned char` is highly memory efficient, taking up exactly 1 byte.
2. **Macros:** We use `#define` to assign semantic meaning to numbers (e.g., `#define TRUE 1` and `#define FALSE 0`). 
3. **Macro Functions:** We define `#define EVEN(x) (x % 2 == 0)`. The preprocessor will automatically swap the code out at compile time, seamlessly performing the math!

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_boolean.h`](ft_boolean.h)**

2. **Testing:**
   You must use the `-R CheckDefine` flag to verify macros in Norminette! Use the master **[`tester.c`](../tester.c)** file provided in the root `C-08` directory. You must pass the `-D EX01` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   norminette -R CheckDefine ft_boolean.h
   cc -Wall -Wextra -Werror -D EX01 ../tester.c -o test_ex01
   ./test_ex01 arg1 arg2
   ```
