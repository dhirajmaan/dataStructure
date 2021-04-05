// #include <iostream>

class student
{
private:
    char *name;
    int age;

public:
    student(int age, char *name)
    {
        //shallow copy we shoud not do it
        // this->age = age;
        // this->name = name;
        this->age = age;
        this->name = new char[strlen(name) + 1]; //pointing the new array to class name
        strcpy(this->name, name);                //copying the character of name to newly created array
    }

    void print()
    {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }

    //copy constructor
    student(student &s)
    { //here we must pass by refrence to avoid infinite loop
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1]; //pointing the new array to class name
        strcpy(this->name, s.name);
    }
};
