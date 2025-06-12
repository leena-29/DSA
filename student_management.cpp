
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks;

public:
    Student() {
        rollNumber = 0;
        name = "";
        marks = 0.0f;
    }

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: " << marks << "\n";
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

void addStudent() {
    ofstream file("students.dat", ios::binary | ios::app);
    Student s;
    s.input();
    file.write(reinterpret_cast<char*>(&s), sizeof(s));
    file.close();
    cout << "Student added successfully.\n";
}

void displayAll() {
    ifstream file("students.dat", ios::binary);
    Student s;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.display();
        cout << "------------------------\n";
    }
    file.close();
}

void searchStudent(int roll) {
    ifstream file("students.dat", ios::binary);
    Student s;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNumber() == roll) {
            s.display();
            found = true;
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Student with Roll Number " << roll << " not found.\n";
}

void deleteStudent(int roll) {
    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    Student s;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNumber() != roll) {
            temp.write(reinterpret_cast<char*>(&s), sizeof(s));
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice, roll;
    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                searchStudent(roll);
                break;
            case 4:
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                deleteStudent(roll);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
