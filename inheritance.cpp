/*
This C++ code defines a program that models different types of staff members in an educational institution using inheritance and polymorphism. Here's a breakdown of the classes and their functionalities:

staff Class:

This class serves as a pure virtual base class, meaning it contains at least one pure virtual function (input_data() and display() in this case), making it an abstract class.
It contains common data members like code (staff code) and name (staff name).
It has a member function set_data() to set the name and code for a staff member.
teacher Class:

Inherits from the staff class.
Adds specific data members like subject and publication.
Implements the virtual functions input_data() and display(), allowing input and display of teacher-specific data.
officer Class:

Inherits from the staff class.
Adds a specific data member grade.
Implements the virtual functions input_data() and display(), allowing input and display of officer-specific data.
typist Class:

Inherits from the staff class.
Adds a specific data member speed.
Implements the virtual functions input_data() and display(), allowing input and display of typist-specific data.
casual Class:

Inherits from the typist class.
Adds specific data members daily and wages.
Implements the virtual functions input_data() and display(), allowing input and display of casual typist-specific data.
main() Function:

Instantiates objects of teacher and casual classes.
Calls input_data() and display() functions for both objects to input data and display it.
This program demonstrates inheritance where subclasses inherit attributes and behaviors from their base class (staff), and polymorphism is utilized through virtual functions input_data() and display(), allowing different behavior for each subclass when these functions are called
*/

#include <iostream>
using namespace std;

class staff  // pure virtual base  class 
{
protected:
    int code;
    char name[100];

public:
    void set_data()
    {
         cout << "enter name and code"<<endl;
        cin.getline(name, 100);
        cin >> code;
        cin.ignore(); 
    }
    virtual void input_data() = 0;
    virtual void display() = 0;
};

class teacher : public staff
{
protected:
    char subject[100];
    char publication[100];

public:
    void input_data()
    {
        set_data();   // called function from  base class 
        cout << "enter subject and publication"<<endl;
        cin.getline(subject,100);
        cin.getline(publication,100);
    }

    void display()
    {
        cout << endl << "code and name are " << code << endl
             << name << endl ;
        cout << "subjects and publication :" << subject << endl
             << publication << endl;
    }
};

class officer : public staff
{
protected:
    char grade[100];

public:
    void input_data()
    {
         set_data();
        cout << "Enter grade"<<endl;
        cin.getline(grade, 100);
        
    }

    void display()
    {
        cout << "code and name are " << code << endl
             << name << endl ;
        cout << "subjects and publication :" << grade << endl;
    }
};

class typist : public staff
{
protected:
    int speed ;

public:
    void input_data()
    {
         set_data();
        cout << "Enter speed of typist "<<endl;
        cin>>speed;
        
    }

    void display()
    {
        cout << "code and name are " << code << endl
             << name << endl ;
        cout << "subjects and publication :" << speed << endl;
    }
};

class casual : public typist
{
protected:
    float daily , wages  ;

public:
    void input_data()
    {
         set_data();
        cout << "Enter Daily and wages  of typist "<<endl;
        cin>>daily;
        cin>>wages;
        
    }

    void display()
    {
        cout << "code and name are " << code << endl
             << name << endl ;
        cout << "subjects and publication :" << daily << endl
                                            << wages<<endl;
    }
};

int main()
{
    teacher t1;
    t1.input_data();
    t1.display();

    casual c1;
    c1.input_data();

    c1.display();

    return 0;
}