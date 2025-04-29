#include<iostream>
using namespace std;
class Person{
	protected:
		int age;
		string name;
	public:
		Person(string n,int a=0):name(n),age(a){
		}
		virtual void Display(){
			cout<<"Name:"<<name<<","<<"Age:"<<age<<endl;
		}
};
class Student:protected Person{
	protected:
		int roll_no;
		string branch;
		double marks;
	public:
		Student(string name,int age,int roll_no,string branch,double marks):Person(name,age){
			this->roll_no=roll_no;
			this->branch=branch;
			this->marks=marks;
		}
		float CalCgpa(){
			return marks/10;
		}
		void display(){
			cout<<"Student Details:"<<endl;
			Person::Display();
			cout<<"Roll No:"<<roll_no<<endl;
			cout<<"Branch:"<<branch<<endl;
			cout<<"Marks:"<<marks<<endl;
			cout<<"CGPA:"<<CalCgpa()<<endl;
		}
};
class Faculty:protected Person{
	protected:
		int fac_id,salary;
		string dept;
	public:
		Faculty(string name,int age,int fac_id,string dept,int salary):Person(name,age){
		this->fac_id=fac_id;
		this->dept=dept;
		this->salary=salary;
		}
		void display(){
			cout<<"Faculty Details:"<<endl;
			Person::Display();
			cout<<"Faculty ID:"<<fac_id<<endl;
			cout<<"Dept:"<<dept<<endl;
			cout<<"Salary:"<<salary<<endl;
		}
};
class TeachingAssistant:public Student,public Faculty{
	
	public:
		TeachingAssistant(string name,int age,int roll_no,string branch,double marks,int fac_id,string dept,int salary):Student(name, age, roll_no, branch, 0), Faculty(name, age, fac_id, dept, salary) {
		}
    void display(){ 
        cout << "Teaching Assistant Details:"<<endl;
        Student::Display();
        Faculty::Display();
    }
};
int main(){
	Student S1("Raj Malhotra",20,2023101,"CSE (AI-ML)",89);
	S1.display();
	cout<<"\n";
	Faculty F1("Dr. A. Sharma",45,1001,"Computer Science",120000);
	F1.display();
	TeachingAssistant T1("Priya Desai",25,1923105,"CSE(AI-ML)",0,2005,"Artificial Intelligence",35000);
	T1.display();
}
