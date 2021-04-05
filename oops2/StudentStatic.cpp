class StudentStatic
{
private:
    static int totalStudent;

public:
    int roll;
    int age;
    StudentStatic()
    {
        totalStudent++;
    }
    //satic function
    static int getTotalStudent()
    {
        return totalStudent;
    }
};

int StudentStatic::totalStudent = 0; //initilization of the static member should be outside
                                     //of the class

#include <iostream>
using namespace std;

int main()
{
    StudentStatic s1, s2, s3, s4, s5;
    //static function should only be called by class name and adress resolution operator
    cout << StudentStatic::getTotalStudent() << endl;

    return 0;
}