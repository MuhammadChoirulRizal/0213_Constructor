#include <iostream>
using namespace std;

class Student
{
private:
    static int studentTotal;

public:
    string name;
    string status;
    int age;

    Student(string pName, int pAge)
    {
        name = pName;
        age = pAge;
        status = "new Student";
        ++studentTotal;
        cout << name << "created" << endl
             << "status" << status << endl;
        cout << endl;
    }
    ~Student()
    {
        cout << name << "destroyed" << endl;
        --studentTotal;
        cout << endl;
    }

    static int getstudentTotal()
    {
        return studentTotal;
    }
    static void setstudentTotal(int a)
    {
        studentTotal = a;
    }
};
int Student::studentTotal = 0;
int main()
{
    cout << "student total is" << Student ::getstudentTotal() << endl;
    Student st1("Anu", 40);
    Student st2("Agus", 30);
    Student::setstudentTotal(10);
    cout << "student total is" << Student ::getstudentTotal() << endl;
    {
        Student st3("al", 10);
        Student st4("bl", 20);
        cout << "student total is" << Student ::getstudentTotal() << endl;
    }
    cout << "student total is" << Student ::getstudentTotal() << endl;
    
}
