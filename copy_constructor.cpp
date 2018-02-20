#include<iostream>
#include<string.h>
using namespace std;
class Student{
private:
    std::string stud_name;
    std::string stud_address;
    int stud_rollno;
    int *c;
public:
    Student()
    {
        std::cout<<"Calling default constructor"<<std::endl;
    }
    Student(std::string name,std::string address,int rollno,int n){
        std::cout<<"Calling parameterized constructor"<<std::endl;
        stud_name=name;
        stud_address=address;
        stud_rollno=rollno;
        c=new int[n];
        *c=n;

    }
   Student(const Student &obj)
    {
        std::cout<<"Calling copy constructor"<<std::endl;
        c=new int[1];
        c=obj.c;
        stud_name=obj.stud_name;
        stud_address=obj.stud_address;
        stud_rollno=obj.stud_rollno;
    }
   void operator=(const Student &obj)
   {
        std::cout<<"Calling overloaded = copy constructor"<<std::endl;
        c=obj.c;
        stud_name=obj.stud_name;
        stud_address=obj.stud_address;
        stud_rollno=obj.stud_rollno;

   }
    void displayStudent(){
        std::cout<<"Student :"<<*c<<"Char :"<<&c<<std::endl;
        std::cout<<"Student Name :"<<stud_name<<std::endl;
        std::cout<<"Student Address :"<<stud_address<<std::endl;
        std::cout<<"Student Roll No :"<<stud_rollno<<std::endl;
    }
};
int main()
{
    Student stud;
    stud.displayStudent();
    Student stud1("Mahesh","Aurangabad",10,1);
    stud1.displayStudent();
    Student stud2=stud1;  //Default Copy constructor called - Deep Copy Constructor Example
    stud2.displayStudent();
    Student stud3(stud1); //Default Copy constructor called - Deep Copy Constructor Example
    stud3.displayStudent();
    Student stud4;
    stud4=stud1; //Default Overloaded = Constuctor called - Shallow Copy Constructor Example
    stud4.displayStudent();
    return 0;
}
