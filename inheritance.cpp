
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