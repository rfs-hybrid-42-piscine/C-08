# 🟢 Exercise 05: ft_show_tab

## 📝 Objective
Create a function that parses the array of structures generated in the previous exercise and prints their contents to the terminal.

## 💡 The Logic
1. **Iteration:** We iterate through the array of `t_stock_str` structures using a `while` loop. The loop dynamically stops when it hits the null-terminator we injected in `ex04` (`while (par[++i].str)`).
2. **Formatting:** For every valid struct, we extract its properties and print them. We use a standard `write` loop for the string pointers (`str` and `copy`). We use a custom, recursive `ft_putnbr` helper function to safely print the integer (`size`). 
3. **Strict Output:** Every single printed element must be strictly followed by a newline `\n`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_show_tab.c`](ft_show_tab.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-08` directory. You must pass the `-D EX05` flag to the compiler to selectively activate the test for this specific exercise! Since this requires **[`ft_stock_str.h`](../ft_stock_str.h)**, you must compile with the `-I .` flag so the compiler knows to check the current directory for the header! You must compile this alongside `ex04` so the struct array can be generated before it is displayed!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX04 -D EX05 ../tester.c ../ex04/ft_strs_to_tab.c ft_show_tab.c -o test_ex05
   ./test_ex05 arg1 arg2
   ```
