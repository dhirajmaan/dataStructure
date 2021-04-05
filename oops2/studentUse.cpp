#include <iostream>
using namespace std;
#include <cstring>     //thid has the function strlen and strcpy
#include "student.cpp" //simply the code of student.cpp get copied here

int main()
{
    char name[] = "abc";
    student s1(10, name);
    char name1[] = "abcde";
    student s2(12, name1);

    s1.print();
    s2.print();

    student s3(s1);
    s3.print();
    return 0;
}