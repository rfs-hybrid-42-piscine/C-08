# 🟢 Exercise 03: ft_point.h

## 📝 Objective
Create a header file (`ft_point.h`) that defines a custom structure to hold 2D coordinates so a provided `main` function compiles correctly.

## 💡 The Logic
We use the `struct` keyword to group multiple variables (an `x` integer and a `y` integer) into a single block of memory. We wrap the structure in a `typedef` statement, aliasing it to `t_point`. This allows the user to declare the structure simply by typing `t_point point;` without needing to write out the `struct` keyword every time.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_point.h`](ft_point.h)**

2. **Testing:**
   You must use the `-R CheckDefine` flag to verify macros in Norminette! Use the master **[`tester.c`](../tester.c)** file provided in the root `C-08` directory. You must pass the `-D EX03` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   norminette ft_point.h
   cc -Wall -Wextra -Werror -D EX03 ../tester.c -o test_ex03
   ./test_ex03
   ```
