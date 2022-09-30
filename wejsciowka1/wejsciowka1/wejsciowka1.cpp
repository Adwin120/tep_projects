// wejsciowka1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;



class Student;
class Course
{
public:
    Course()
    {
        name = "";
        capacity = 32;
        studentTable = new Student * [capacity];
        int studentsEnrolled = 0;
    }
    Course(string courseName, int courseCapacity)
    {
        name = courseName;
        capacity = courseCapacity;
        studentTable = new Student * [capacity];
        int studentsEnrolled = 0;
    }
    ~Course() {
        delete[] studentTable;
    }
    bool addStudent(Student* stud)
    {
        if (studentsEnrolled < capacity) {
            studentTable[studentsEnrolled] = stud;
            studentsEnrolled++;
            return true;
        }
        return false;
    }
    void removeStudent(Student* stud)
    {
        int offset = 0;
        Student** newTable = new Student * [capacity];
        for (int i = 0; i + offset < studentsEnrolled; i++)
        {
            if (studentTable[i] == stud)
            {
                offset = 1;
            }
            newTable[i] = studentTable[i + offset];
        }

        delete[] studentTable;
        studentTable = newTable;
        studentsEnrolled--;
    }
    Student** studentTable;
    int studentsEnrolled;
private:
    string name;
    int capacity;
};

class Student
{
public:
    Student()
    {
        index = 0;
        courseTable = new Course * [maxCourses];
        amountOfCourses = 0;
    }
    Student(int studentIndex)
    {
        index = studentIndex;
        courseTable = new Course * [maxCourses];
        amountOfCourses = 0;
    }
    ~Student()
    {
        for (int i = 0; i < amountOfCourses; i++)
        {
            courseTable[i]->removeStudent(this);
        }
        delete[] courseTable;
    }

    void enroll(Course& course)
    {
        if (amountOfCourses < maxCourses)
        {
            courseTable[amountOfCourses] = &course;
            amountOfCourses++;
            course.addStudent(this);
        }
        else
        {
            cout << "za duzo kursow";
        }
    }
private:
    int index;
    Course** courseTable;
    int amountOfCourses;
    const int maxCourses = 32;
};




int main()
{
    Course* course = new Course("algorytmy", 10);
    Student* stud = new Student(12345);
    cout << course->studentsEnrolled<< endl;
    stud->enroll(*course);
    cout << course->studentsEnrolled << endl;
    delete stud;
    cout << course->studentsEnrolled << endl;

    delete course;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
