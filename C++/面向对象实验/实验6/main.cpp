#include <iostream>
#include <fstream>
#include <cstring>

class Student {
public:
    char name[10];
    int ID;
    double gpa;

    void print() const {
        std::cout << name << " " << ID << " " << gpa << std::endl;
    }
};

void addStudent(const char* name, int ID, double gpa) {
    std::fstream file("students.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        file.open("students.dat", std::ios::out | std::ios::binary);
    }

    Student student;
    while (file.read((char*)&student, sizeof(Student))) {
        if (student.ID == ID) {
            std::cout << "Already entered" << std::endl;
            return;
        }
    }

    strcpy(student.name, name);
    student.ID = ID;
    student.gpa = gpa;

    file.clear();
    file.seekp(0, std::ios::end);
    file.write((char*)&student, sizeof(Student));
    file.close();
}

void searchByName(const char* name) {
    std::ifstream file("students.dat", std::ios::in | std::ios::binary);
    if (!file) {
        std::cout << "Not Found" << std::endl;
        return;
    }

    Student student;
    bool found = false;
    while (file.read((char*)&student, sizeof(Student))) {
        if (strcmp(student.name, name) == 0) {
            student.print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Not Found" << std::endl;
    }
    file.close();
}

void searchByID(int ID) {
    std::ifstream file("students.dat", std::ios::in | std::ios::binary);
    if (!file) {
        std::cout << "Not Found" << std::endl;
        return;
    }

    Student student;
    bool found = false;
    while (file.read((char*)&student, sizeof(Student))) {
        if (student.ID == ID) {
            student.print();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Not Found" << std::endl;
    }
    file.close();
}

void modifyGPA(int ID, double newGPA) {
    std::fstream file("students.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cout << "Not Found" << std::endl;
        return;
    }

    Student student;
    bool found = false;
    while (file.read((char*)&student, sizeof(Student))) {
        if (student.ID == ID) {
            student.gpa = newGPA;
            file.seekp(-sizeof(Student), std::ios::cur);
            file.write((char*)&student, sizeof(Student));
            std::cout << "Done" << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Not Found" << std::endl;
    }
    file.close();
}

int main() {
    // 示例命令
    addStudent("Tom", 1234567, 78.5);
    searchByName("Tom");
    searchByID(1234567);
    modifyGPA(1234567, 85.0);
    return 0;
}