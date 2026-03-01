*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-c08.png" alt="C 08 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 C 08: Headers, Macros & Structures</h1>
  <p><i>Organizing code, defining custom types, and mastering arrays of structures.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**C 08** transitions from raw algorithmic problem-solving to software architecture and project organization.

In this module, you will learn how to create Header files (`.h`) to share function prototypes across multiple files, use Macros (`#define`) to replace code at compile time for better readability and optimization, and build your own custom data types using `struct` and `typedef`. Finally, you will dynamically allocate and manipulate an entire array of these custom structures.

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise. It focuses on the fundamental logic of C programming, emphasizing manual memory manipulation and edge-case management.*

### 🔹 Headers & Macros
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: ft.h`](ex00)** | **Header Files:** Creating a standard header file containing function prototypes. <br><br>**Logic:** We use "Include Guards" (`#ifndef FT_H`, `#define FT_H`, `#endif`) to prevent double-inclusion compilation errors. Inside, we declare the prototypes for basic functions like `ft_putchar` and `ft_strlen` so they can be referenced globally by any `.c` file that includes this header. |
| **[`ex01: ft_boolean.h`](ex01)** | **Booleans & Macros:** Building a custom boolean type and logic macros to make a provided `main.c` compile. <br><br>**Logic:** C natively lacks a boolean type. We use `typedef int t_bool;` and `#define TRUE 1` / `#define FALSE 0`. We also define macros like `#define EVEN(x) (x % 2 == 0)` to perform mathematical logic seamlessly during preprocessing. |
| **[`ex02: ft_abs.h`](ex02)** | **Macro Functions:** Creating a macro that dynamically calculates an absolute value. <br><br>**Logic:** The 42 Norm strictly forbids ternary operators. To bypass this, we use a mathematical boolean evaluation inside a `#define`: `#define ABS(Value) ((Value) * (((Value) > 0) - ((Value) < 0)))`. *Crucial Trap:* Every single instance of `Value` must be wrapped in strict parentheses to prevent mathematical precedence errors if a complex equation (like `ABS(5 - 10)`) is passed into the macro! |

### 🔢 Structures & Data Types
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex03: ft_point.h`](ex03)** | **Structures:** Defining a custom data type to hold multiple variables. <br><br>**Logic:** We create a `struct s_point` containing two integers (`x` and `y`). We use `typedef` so the user can declare it simply using `t_point point;` without needing the `struct` keyword every time. |

### 👑 Arrays of Structures (The Final Boss)
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex04: ft_strs_to_tab`](ex04)** | **Struct Allocation:** Converting an array of strings into an array of dynamically allocated structures. <br><br>**Logic:** We are given a `t_stock_str` struct which holds a string's size, its original pointer, and a duplicate copy. We `malloc` an array of these structs based on `ac + 1`. For each string in `av`, we populate the struct's variables, using `malloc` to duplicate the string for the `copy` field. The final struct in the array must have its `str` set to `NULL` (`0`) to act as a terminator. |
| **[`ex05: ft_show_tab`](ex05)** | **Displaying Struct Arrays:** Iterating through our newly built array of structures and printing their contents. <br><br>**Logic:** We iterate through the struct array until we hit the null-terminator (`par[i].str == 0`). For each valid struct, we print the `str`, use a custom `ft_putnbr` to print the `size`, and print the `copy`, separating everything with newlines. |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing
Because `ex00` through `ex03` are strictly `.h` (header) files, they cannot be compiled on their own. They must be included in a `.c` file that contains a `main` function. 

To test `ex04` and `ex05` (which are actual `.c` files), you must compile them together with a `main` function that generates the strings and passes them into the struct array.

1. **Clone the repository:**
   You can clone this module directly, or pull the entire 42 Piscine parent repository which includes this module as a submodule.

   **Option A: Clone this module directly**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/C-08.git C-08
   cd C-08
   ```

   **Option B: Clone the parent repository (with submodules)**
   ```bash
   git clone --recurse-submodules git@github.com:rfs-hybrid/42-Piscine.git 42-Piscine
   cd 42-Piscine/C-08
   ```
   *(Note: The `--recurse-submodules` flag ensures all nested module repositories are populated immediately.)*

2. **Testing Headers (ex00 - ex03):**
   Create a temporary `main.c` file, include your header (`#include "ex02/ft_abs.h"`), and compile it.
   ```bash
   cc -Wall -Wextra -Werror main.c -o test_header
   ./test_header
   ```

3. **Testing Struct Arrays (ex04 & ex05):**
   Use a custom **[`tester.c`](tester.c)** that includes **[`ft_stock_str.h`](ft_stock_str.h)** and compiles both `.c` files. **Note:** You must use the `-I .` flag so the compiler knows to look in the root directory for the header file!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX04 -D EX05 tester.c ex04/ft_strs_to_tab.c ex05/ft_show_tab.c -o test_structs
   ./test_structs argument1 argument2
   ```

4. **Test ALL Exercises at Once:**
   By passing the `-D TEST_ALL` master flag, you can activate the entire testing suite in one go! The command compiles the tester alongside the required source files and links the custom headers.
   ```bash
   cc -Wall -Wextra -Werror -I . -D TEST_ALL tester.c ex04/ft_strs_to_tab.c ex05/ft_show_tab.c -o test_all
   ./test_all argument1 argument2
   ```

### 🚨 The Norm & CheckDefine
Moulinette relies on a program called `norminette` to check if your files comply with the Norm. Every single `.c` and `.h` file must pass. 

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. 
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:13:57 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/06 22:24:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

**⚠️ Special Flag for Macros:**
When checking `.h` files that contain macros (specifically `ex01` and `ex02`), you MUST run Norminette with the `-R CheckDefine` flag. Moulinette will use this exact flag to grade you!
```bash
norminette -R CheckDefine ex01/ft_boolean.h
```

---

## 📚 Resources & References

* [C Header Files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm) - Understanding Include Guards.
* [C Preprocessors & Macros](https://www.geeksforgeeks.org/c-preprocessor-directives/) - How `#define` works.
* [C Structures (struct)](https://www.w3schools.com/c/c_structs.php) - Building custom data types.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions and headers were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation, enforcing the concept that learning is about developing the ability to find an answer, not just getting one directly.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
