# ASCII Table Generator in C

This project demonstrates **low-level file I/O in C** using system calls like `open`, `read`, `write`, and `close`.
The program writes the ASCII codes for values **32–126** to a file, then reads them back, printing both the numeric values and their corresponding characters.

---

## 📂 Features

* Generates a file containing ASCII codes (32–126).
* Reads integers from the file and outputs:

  * The numeric ASCII code
  * The corresponding ASCII character
* Implements file operations using system calls instead of standard library functions.
* Includes error handling for file operations.

---

## 🛠️ Technologies Used

* **C Programming Language**
* **POSIX System Calls** (`open`, `write`, `read`, `close`)
* **Linux/Unix environment**

---

## 🚀 How to Compile and Run

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/ascii-table-generator.git
   cd ascii-table-generator
   ```

2. Compile the program:

   ```bash
   gcc lab13.c -o prog
   ```

3. Run the program with a filename as argument:

   ```bash
   ./prog DATA.txt
   ```

---

## 📊 Example Output

```
32  
33 !  
34 "  
35 #  
36 $  
...  
125 }  
126 ~  
```

---

## 📖 Learning Objectives

This project reinforces:

* Working with **low-level file I/O**.
* Converting between **numeric values and characters**.
* Parsing integers manually from text data.
* Error handling in C.

---

## 📝 Future Improvements

* Allow users to specify custom ASCII ranges via command-line arguments.
* Support multiple output formats (decimal, hex, char).
* Option to write results to both file and terminal.

---

## 👤 Author

* **David Salas C.**
  Computer Science Student | Passionate about Systems Programming & Software Development
