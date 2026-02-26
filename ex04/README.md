# 🟢 Exercise 04: ft_strs_to_tab

## 📝 Objective
Create a function that takes an array of strings, measures them, duplicates them, and packages them into a dynamically allocated array of custom structures.

## 💡 The Logic
1. **Structure Allocation:** We are provided a target struct (`t_stock_str`) holding an integer and two string pointers. We use `malloc` to allocate an array of these structures based on the size of `ac + 1`.
2. **Mapping:** We iterate through the provided string array (`av`). For each string, we use static helper functions to measure its length (`ft_strlen`) and duplicate it on the Heap twice (`ft_strdup`), mapping the values directly into the current struct's properties (`arr[i].size`, `arr[i].str`, `arr[i].copy`).
3. **Termination:** The array of structures must end with a null-terminator, so we explicitly set the final element's string pointer to `0`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_strs_to_tab.c`](ft_strs_to_tab.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-08` directory. You must pass the `-D EX04` flag to the compiler to selectively activate the test for this specific exercise! Since this requires **[`ft_stock_str.h`](../ft_stock_str.h)**, you must compile with the `-I .` flag so the compiler knows to check the current directory for the header!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX04 ../tester.c ft_strs_to_tab.c -o test_ex04
   ./test_ex04
   ```
