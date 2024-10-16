# Function to calculate grade points based on marks (using university's grading system)
def marks_to_grade_point(marks, max_marks):
    percentage = (marks / max_marks) * 100  # Convert to percentage
    if 90 <= percentage <= 100:
        return 10
    elif 80 <= percentage < 90:
        return 9
    elif 70 <= percentage < 80:
        return 8
    elif 60 <= percentage < 70:
        return 7
    elif 50 <= percentage < 60:
        return 6
    elif 40 <= percentage < 50:
        return 5
    elif 36 <= percentage < 40:
        return 4
    else:
        return 0  # Fail

# Function to calculate SGPA
def calculate_sgpa(grade_points, credits):
    total_credit_points = sum([g * c for g, c in zip(grade_points, credits)])
    total_credits = sum(credits)
    sgpa = total_credit_points / total_credits
    return sgpa

# Function to calculate CGPA
def calculate_cgpa(sgpas, semester_credits):
    total_credit_points = sum([sgpa * credit for sgpa, credit in zip(sgpas, semester_credits)])
    total_credits = sum(semester_credits)
    cgpa = total_credit_points / total_credits
    return cgpa

# Function to convert CGPA to percentage
def cgpa_to_percentage(cgpa):
    return cgpa * 10

# Main program
def main():
    print("Welcome to the Grade Calculation Tool!")

    # Ask for number of subjects and input details
    num_subjects = int(input("How many subjects do you have? "))
    subjects = []
    internal_marks = []
    semester_marks = []
    other_marks = []
    credits = []

    print("\nPlease enter the marks for each subject (Internal, Semester, Other if applicable) and the credits.")
    for i in range(num_subjects):
        subject = input(f"\nEnter the code for subject {i+1}: ")
        internal = int(input(f"Enter internal marks for {subject}: "))
        semester = int(input(f"Enter semester marks for {subject}: "))
        other = input(f"Enter other marks for {subject} (leave blank if not applicable): ")
        other = int(other) if other else 0

        # Ask for the credit value of the subject
        credit = int(input(f"Enter the credits for {subject} (2 or 4 credits): "))
        credits.append(credit)

        # Total marks calculation based on credit value
        if credit == 2:
            max_marks = 50
        elif credit == 4:
            max_marks = 100
        else:
            print("Invalid credit value. Please enter either 2 or 4 credits.")
            return

        total_marks = internal + semester + other
        subjects.append(subject)
        internal_marks.append(internal)
        semester_marks.append(semester)
        other_marks.append(other)

        # Display total marks for confirmation
        print(f"Total marks for {subject} is: {total_marks}/{max_marks}")

    # Calculate grade points based on total marks and max_marks
    grade_points = [marks_to_grade_point(internal + semester + other, 50 if credit == 2 else 100)
                    for internal, semester, other, credit in zip(internal_marks, semester_marks, other_marks, credits)]

    # Calculate SGPA
    sgpa = calculate_sgpa(grade_points, credits)
    print(f"\nYour SGPA for this semester is: {sgpa:.2f}")

    # Ask if the user wants to see the SGPA as a percentage
    percentage_choice = input("\nWould you like to see your SGPA as a percentage? (yes/no): ").lower()
    
    if percentage_choice == 'yes':
        percentage = cgpa_to_percentage(sgpa)
        print(f"Your SGPA in percentage is: {percentage:.2f}%")
    else:
        print("Alright! No percentage calculation.")

    print("\nThank you for using the Grade Calculation Tool!")

if __name__ == "__main__":
    main()
