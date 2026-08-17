# 👑 N-Queens Problem Solver

This project provides a clean, modern C++ solution to the classic **N-Queens Problem** using the **Backtracking** algorithm.

## 📖 About the Problem

The N-Queens problem is the challenge of placing `N` chess queens on an `N × N` chessboard so that no two queens threaten each other. According to chess rules, this means that no two queens can share the same:
- Row
- Column
- Diagonal

## 🚀 Algorithm: Backtracking

The solution utilizes a recursive backtracking approach to efficiently explore valid board configurations:
1. **Row-by-Row Placement:** The algorithm tries to place exactly one queen in each row, starting from the top.
2. **Safety Check (`isSafe`):** Before placing a queen, it verifies that no previously placed queen can attack the current square (checking the column and upper diagonals).
3. **Recursive Search:** If safe, it temporarily places the queen and recursively moves to the next row.
4. **Backtracking:** If a dead end is reached (meaning no valid column exists in the current row), it retracts the previous placement and explores the next possible column.

## 🛠️ Prerequisites

To compile and run this program, you need a C++ compiler that supports C++11 or higher, such as:
- [GCC (g++)](https://gcc.gnu.org/)
- [Clang](https://clang.llvm.org/)
- [MSVC (Visual Studio)](https://visualstudio.microsoft.com/)

## ⚙️ Compilation & Execution

1. Save the C++ code into a file named `nqueens.cpp`.
2. Open your terminal or command prompt and navigate to the folder containing the file.
3. Compile the source code using the following command:
   ```bash
   g++ -std=c++11 -o nqueens nqueens.cpp
   ```
4. Run the generated executable:
   - On Linux/macOS:
     ```bash
     ./nqueens
     ```
   - On Windows:
     ```cmd
     nqueens.exe
     ```

## 💻 Example Usage

```text
--- N-Queens Problem Solver ---
Enter the number of Queens (N): 8

One possible solution for 8 Queens is:

Q . . . . . . . 
. . . . Q . . . 
. . . . . . . Q 
. . . . . Q . . 
. . Q . . . . . 
. . . . . . Q . 
. Q . . . . . . 
. . . Q . . . . 
```

## 🧠 Educational Value

This code is written without legacy C-style headers (`<stdio.h>`, `<conio.h>`) to demonstrate modern C++ practices using the Standard Template Library (STL) like `std::vector`.

---
*Created as an algorithmic exercise in C++.*
