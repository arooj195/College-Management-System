#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Person class definition
class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string addres) {
        name = n;
        age = a;
    address = addres;
    }

//    virtual
	 void display() const {
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address << endl;
    }
};

// Student class definition
class Student : public Person {
private:
    string studentID;
    vector<string> courses;

public:
    Student(string name, int age, string address, string studentI)
        : Person(name, age, address) {
        studentID = studentI;
    }

    void enrollCourse(const string& course) {
        courses.push_back(course);
    }

    void display() const {
        Person::display();
        cout << "Student ID: " << studentID << "\nCourses Enrolled: ";
        for (int i = 0; i < courses.size(); i++) {
            cout << courses[i] << " ";
        }
        cout << endl;
    }
};

// Teacher class definition
class Teacher : public Person {
private:
    string employeeID;
    vector<string> coursesTaught;

public:
    Teacher(string name, int age, string address, string employeeI)
        : Person(name, age, address) {
        employeeID = employeeI;
    }

    void assignCourse(const string& course) {
        coursesTaught.push_back(course);
    }

    void display() const {
        Person::display();
        cout << "Employee ID: " << employeeID << "\nCourses Taught: ";
        for (int i = 0; i < coursesTaught.size(); i++) {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
};

// Course class definition
class Course {
private:
    string courseID;
    string courseName;

public:
    Course(string courseI, string courseNam) {
        courseID = courseI;
        courseName = courseNam;
    }

    void display() const {
        cout << "Course ID: " << courseID << "\nCourse Name: " << courseName << endl;
    }
};

// Department class definition
class Department {
private:
    string departmentName;
    vector<Teacher> teachers;
    vector<Course> courses;
    vector<Student> students; // Added vector to store students

public:
    Department(string departmentNam) {
        departmentName = departmentNam;
    }

    void addTeacher(const Teacher& teacher) {
        teachers.push_back(teacher);
    }

    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void addStudent(const Student& student) { // Method to add students
        students.push_back(student);
    }

    void display() const {
        cout << "Department Name: " << departmentName << endl;
        cout << "Teachers: " << endl;
        for (int i = 0; i < teachers.size(); i++) {
            teachers[i].display();
            cout << endl;
        }
        cout << "Courses: " << endl;
        for (int i = 0; i < courses.size(); i++) {
            courses[i].display();
            cout << endl;
        }
    }

    void displayStudents() const { 
        cout << "Students: " << endl;
        for (int i = 0; i < students.size(); i++) {
            students[i].display();
            cout << endl;
        }
    }
};

Student createStudent() {
    string name, address, studentID;
    int age;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Student ID: ";
    getline(cin, studentID);
    return Student(name, age, address, studentID);
}

Teacher createTeacher() {
    string name, address, employeeID;
    int age;
    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Employee ID: ";
    getline(cin, employeeID);
    return Teacher(name, age, address, employeeID);
}

Course createCourse() {
    string courseID, courseName;
    cout << "Enter Course ID: ";
    cin.ignore();
    getline(cin, courseID);
    cout << "Enter Course Name: ";
    getline(cin, courseName);
    return Course(courseID, courseName);
}

// Main function to demonstrate the functionality
int main() {
    Department csDepartment("Computer Science");

    
    Student student1("Hafsa", 20, "123 Main St", "S1001");
    student1.enrollCourse("Math101");
    student1.enrollCourse("CS102");

    Student student2("Aimen", 22, "456 Oak St", "S1002");
    student2.enrollCourse("Eng201");

    Teacher teacher1("Amina", 45, "789 Pine St", "T2001");
    teacher1.assignCourse("Math101");

    Teacher teacher2("Iqra", 50, "101 Maple St", "T2002");
    teacher2.assignCourse("CS102");

    Course course1("Math101", "Calculus I");
    Course course2("CS102", "Introduction to Programming");

    csDepartment.addTeacher(teacher1);
    csDepartment.addTeacher(teacher2);
    csDepartment.addCourse(course1);
    csDepartment.addCourse(course2);

    csDepartment.addStudent(student1); // Add initial students to the department
    csDepartment.addStudent(student2);

    int choice;
    do {
        cout << "\n--- College Management System ---\n";
        cout << "Enter 1 to Add Student\n";
        cout << "Enter 2 to Add Teacher\n";
        cout << "Enter 3 to Add Course\n";
        cout << "Enter 4 to Display Students\n";
        cout << "Enter 5 to Display Department\n";
        cout << "Enter 6 Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent = createStudent();
                csDepartment.addStudent(newStudent); // Add new student to the department
                break;
            }
            case 2: {
                Teacher newTeacher = createTeacher();
                csDepartment.addTeacher(newTeacher);
                break;
            }
            case 3: {
                Course newCourse = createCourse();
                csDepartment.addCourse(newCourse);
                break;
            }
            case 4: {
                csDepartment.displayStudents(); // Display all students from the department
                break;
            }
            case 5: {	
                cout << "Department Information:\n";
                csDepartment.display();
                break;
            }
            case 6: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 6);

    return 0;
}

