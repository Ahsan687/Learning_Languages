Here's a sample **README** file for your CGPA Calculation tool to use on GitHub:
---

# CGPA Calculation Tool

This CGPA Calculation Tool is a simple command-line application written in **C** that helps you calculate your **SGPA (Semester Grade Point Average)** and **CGPA (Cumulative Grade Point Average)** based on university grading systems. It uses a 10-point grading scale to convert marks into grade points and computes the SGPA and CGPA based on the total credits and grades earned.

## Features

- Converts marks to grade points based on a university’s standard 10-point scale.
- Calculates SGPA for a semester based on the credits and grades of each course.
- Optionally converts SGPA to percentage.
- Simple command-line interface with interactive prompts.
- Supports both 2-credit and 4-credit courses.

## Grading System

The tool uses the following grading system to convert marks to grade points:

| Marks Range     | Grade Point |
|-----------------|-------------|
| 90 to 100       | 10          |
| 80 to <90       | 9           |
| 70 to <80       | 8           |
| 60 to <70       | 7           |
| 50 to <60       | 6           |
| 40 to <50       | 5           |
| 36 to <40       | 4           |
| Less than 36    | 0 (Fail)    |

## How It Works

1. The program prompts you to enter the number of subjects.
2. For each subject, you are asked to enter:
    - Internal marks
    - Semester marks
    - Other marks (optional)
    - The number of credits for the subject (2 or 4 credits).
3. The total marks for each subject are used to calculate the grade point based on the grading system.
4. The program calculates the **SGPA** by taking the weighted average of the grade points (based on the number of credits for each subject).
5. You can optionally convert the SGPA to a percentage.
6. The program pauses after displaying the results so you can review the output.

## Usage

To compile and run the program:

### Compilation:

```bash
gcc cgpa_calculator.c -o cgpa_calculator
```

### Running:

```bash
./cgpa_calculator
```
#### OR 
## Simply Download the cgpa_calculator.exe
## change directory to the download folder 
```bash
cd path\to\your\file
```
## then run the code
```bash
cgpa_calculator
```
Once you run the program, you will be prompted to input your data as follows:

1. Enter the number of subjects you have.
2. For each subject:
   - Enter the subject name.
   - Enter internal marks.
   - Enter semester marks.
   - Optionally, enter other marks.
   - Specify whether the subject is worth 2 or 4 credits.
3. After inputting data for all subjects, the program will calculate and display your **SGPA**.
4. You can choose whether to see the SGPA as a percentage by responding with 'y' or 'n'.

### Example Output:

```bash
Welcome to the Grade Calculation Tool!
How many subjects do you have? 6

Please enter the marks for each subject (Internal, Semester, Other if applicable) and the credits.

Enter the name for subject 1: Physics
Enter internal marks for Physics: 14
Enter semester marks for Physics: 78
Enter other marks for Physics (leave 0 if not applicable): 0
Enter the credits for Physics (2 or 4 credits): 4
Total marks for Physics is: 92/100

...

Your SGPA for this semester is: 7.91

Would you like to see your SGPA as a percentage? (y/n): y
Your SGPA in percentage is: 79.10%

Thank you for using the Grade Calculation Tool!
Press any key to exit...
```

## Requirements

- **C Compiler**: GCC, MinGW, or any other standard C compiler.
- Works on Windows, Linux, or any platform that supports C programming.

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute this tool.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit a pull request with improvements or bug fixes. All contributions are welcome!

---
