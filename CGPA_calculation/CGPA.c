#include <stdio.h>
#include <conio.h>  // For getch() to pause and wait for user input
#include <string.h> // For string handling functions

// Function to calculate grade points based on marks (using university's grading system)
int marks_to_grade_point(int marks, int max_marks) {
    float percentage = ((float)marks / max_marks) * 100;  // Convert to percentage
    if (percentage >= 90 && percentage <= 100)
        return 10;
    else if (percentage >= 80 && percentage < 90)
        return 9;
    else if (percentage >= 70 && percentage < 80)
        return 8;
    else if (percentage >= 60 && percentage < 70)
        return 7;
    else if (percentage >= 50 && percentage < 60)
        return 6;
    else if (percentage >= 40 && percentage < 50)
        return 5;
    else if (percentage >= 36 && percentage < 40)
        return 4;
    else
        return 0;  // Fail
}

// Function to calculate SGPA
float calculate_sgpa(int grade_points[], int credits[], int num_subjects) {
    int total_credit_points = 0, total_credits = 0;
    for (int i = 0; i < num_subjects; i++) {
        total_credit_points += grade_points[i] * credits[i];
        total_credits += credits[i];
    }
    return (float)total_credit_points / total_credits;
}

// Function to calculate CGPA
float calculate_cgpa(float sgpas[], int semester_credits[], int num_semesters) {
    int total_credit_points = 0, total_credits = 0;
    for (int i = 0; i < num_semesters; i++) {
        total_credit_points += sgpas[i] * semester_credits[i];
        total_credits += semester_credits[i];
    }
    return (float)total_credit_points / total_credits;
}

// Function to convert CGPA to percentage
float cgpa_to_percentage(float cgpa) {
    return cgpa * 10;
}

int main() {
    int num_subjects;
    printf("Welcome to the Grade Calculation Tool!\n");

    // Ask for number of subjects and input details
    printf("How many subjects do you have? ");
    scanf("%d", &num_subjects);
    getchar();  // To clear the newline character left by scanf

    char subjects[num_subjects][20]; // Array to store subject names (maximum 20 characters per name)
    int internal_marks[num_subjects], semester_marks[num_subjects], other_marks[num_subjects];
    int credits[num_subjects];
    int grade_points[num_subjects];

    printf("\nPlease enter the marks for each subject (Internal, Semester, Other if applicable) and the credits.\n");

    for (int i = 0; i < num_subjects; i++) {
        printf("\nEnter the name for subject %d: ", i + 1);
        fgets(subjects[i], sizeof(subjects[i]), stdin); // Read subject name
        subjects[i][strcspn(subjects[i], "\n")] = 0; // Remove newline character from subject name

        printf("Enter internal marks for %s: ", subjects[i]);
        scanf("%d", &internal_marks[i]);
        printf("Enter semester marks for %s: ", subjects[i]);
        scanf("%d", &semester_marks[i]);
        printf("Enter other marks for %s (leave 0 if not applicable): ", subjects[i]);
        scanf("%d", &other_marks[i]);
        printf("Enter the credits for %s (2 or 4 credits): ", subjects[i]);
        scanf("%d", &credits[i]);

        // Total marks calculation based on credit value
        int total_marks = internal_marks[i] + semester_marks[i] + other_marks[i];
        int max_marks = (credits[i] == 2) ? 50 : 100;

        // Calculate the grade points for the subject
        grade_points[i] = marks_to_grade_point(total_marks, max_marks);

        printf("Total marks for %s is: %d/%d\n", subjects[i], total_marks, max_marks);

        getchar();  // Clear the input buffer for the next iteration
    }

    // Calculate SGPA
    float sgpa = calculate_sgpa(grade_points, credits, num_subjects);
    printf("\nYour SGPA for this semester is: %.2f\n", sgpa);

    // Ask if the user wants to see the SGPA as a percentage
    char percentage_choice;
    printf("\nWould you like to see your SGPA as a percentage? (y/n): ");
    scanf(" %c", &percentage_choice);

    if (percentage_choice == 'y' || percentage_choice == 'Y') {
        float percentage = cgpa_to_percentage(sgpa);
        printf("Your SGPA in percentage is: %.2f%%\n", percentage);
    } else {
        printf("Alright! No percentage calculation.\n");
    }

    printf("\nThank you for using the Grade Calculation Tool!\n");

    // Pausing the program to see the result before exit
    printf("Press any key to exit...\n");
    getch();

    return 0;
}
