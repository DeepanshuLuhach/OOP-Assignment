#include<iostream>
#include<string.h>
using namespace std;
class Student
{
    int id;
    char *name;
    public:
    Student()
    {

    }
    Student(char *s, int i)
    {
        int len=strlen(s);
        name=new char(len+1);
        strcpy(name,s);
        id=i;
    }
    void Display()
    {
        cout<<id<<"\t"<<name;
    }
};
int main()
{
    Student s("AIT",52);
    s.Display();
    return 0;

}
