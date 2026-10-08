#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int rollNo;
    string name;
    string course;
    float marks;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// Add a student
void addStudent() {

    if (studentCount >= MAX_STUDENTS) {
        cout << "\nStudent record limit reached!\n";
        return;
    }

    cout << "\n--------------------------------------------\n";
    cout << "             ADD STUDENT RECORD\n";
    cout << "--------------------------------------------\n";

    cout << "Enter Roll Number: ";
    cin >> students[studentCount].rollNo;

    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, students[studentCount].name);

    cout << "Enter Course/Branch: ";
    getline(cin, students[studentCount].course);

    cout << "Enter Marks: ";
    cin >> students[studentCount].marks;

    studentCount++;

    cout << "\nStudent record added successfully!\n";
}

// Display all students
void displayStudents() {

    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n";
    cout << "================================================================\n";
    cout << "                    STUDENT RECORDS\n";
    cout << "================================================================\n";

    cout << left
         << setw(10) << "Roll No"
         << setw(25) << "Name"
         << setw(20) << "Course"
         << setw(10) << "Marks" << endl;

    cout << "----------------------------------------------------------------\n";

    for (int i = 0; i < studentCount; i++) {

        cout << left
             << setw(10) << students[i].rollNo
             << setw(25) << students[i].name
             << setw(20) << students[i].course
             << setw(10) << students[i].marks
             << endl;
    }

    cout << "================================================================\n";
}

// Search student
void searchStudent() {

    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    int rollNo;

    cout << "\nEnter Roll Number to search: ";
    cin >> rollNo;

    for (int i = 0; i < studentCount; i++) {

        if (students[i].rollNo == rollNo) {

            cout << "\n--------------------------------------------\n";
            cout << "             STUDENT FOUND\n";
            cout << "--------------------------------------------\n";

            cout << "Roll Number : " << students[i].rollNo << endl;
            cout << "Name        : " << students[i].name << endl;
            cout << "Course      : " << students[i].course << endl;
            cout << "Marks       : " << students[i].marks << endl;

            return;
        }
    }

    cout << "\nStudent with Roll Number "
         << rollNo << " not found.\n";
}

// Update student
void updateStudent() {

    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    int rollNo;

    cout << "\nEnter Roll Number to update: ";
    cin >> rollNo;

    for (int i = 0; i < studentCount; i++) {

        if (students[i].rollNo == rollNo) {

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, students[i].name);

            cout << "Enter New Course/Branch: ";
            getline(cin, students[i].course);

            cout << "Enter New Marks: ";
            cin >> students[i].marks;

            cout << "\nStudent record updated successfully!\n";

            return;
        }
    }

    cout << "\nStudent with Roll Number "
         << rollNo << " not found.\n";
}

// Delete student
void deleteStudent() {

    if (studentCount == 0) {
        cout << "\nNo student records available.\n";
        return;
    }

    int rollNo;

    cout << "\nEnter Roll Number to delete: ";
    cin >> rollNo;

    for (int i = 0; i < studentCount; i++) {

        if (students[i].rollNo == rollNo) {

            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }

            studentCount--;

            cout << "\nStudent record deleted successfully!\n";

            return;
        }
    }

    cout << "\nStudent with Roll Number "
         << rollNo << " not found.\n";
}

int main() {

    int choice;

    cout << "\n";
    cout << "============================================\n";
    cout << "       STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "============================================\n";
    cout << "           C++ Console Application\n";
    cout << "============================================\n";

    do {

        cout << "\n";
        cout << "--------------- MAIN MENU -----------------\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "--------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "\nThank you for using Student Record Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}