// Develop a program in C++ to create a database of student information system containing the following information: Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. etc

// Construct the database with suitable member functions. 

// Make use of constructor, default constructor, Copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling

#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class StudentResult {
	int s1,s2,s3,s4,net;
	float avg;
	string grade;

	public: 
    StudentResult() {
		s1 = s2 = s3 = s4 = net = 0;
		avg = 0.0f;
		grade = "";
	}
	void Calculate() {
		net = s1+s2+s3+s4;
		avg = net/4;

		if(avg >= 75.00f) grade="Distinction";
		else if(avg >= 60.00f && avg < 75.00f) grade="Second";
		else if(avg >= 50.00f && avg < 60.00f) grade="Third";
		else if(avg >= 40.00f && avg < 50.00f) grade="Pass";
		else grade="Fail";
	}
	friend class Student;
};

class Student {
	int rno;
	string name,cls,dob,bloodGroup;
	long long int mobileno;
	static int studCnt;
	StudentResult* sr;

	public:
	// Default Constructor (Initialising the values)
	Student() {
		rno = mobileno = 0;
		name = cls = bloodGroup = "";
		dob = "dd/mm/yy";
		sr = new StudentResult();
		studCnt = 0;
	}
	// Copy constructor
	Student(Student* stud){
		this->rno=stud->rno;
		this->name=stud->name;
		this->cls=stud->cls;
		this->dob=stud->dob;
		this->bloodGroup=stud->bloodGroup;
		this->mobileno=stud->mobileno;
		this->sr->s1=stud->sr->s1;
		this->sr->s2=stud->sr->s2;
		this->sr->s3=stud->sr->s3;
		this->sr->s4=stud->sr->s4;
		this->sr->net=stud->sr->net;
		this->sr->avg=stud->sr->avg;
		this->sr->grade=stud->sr->grade;
	}
	void getData(){
		cout<<"\nEnter Student Persoanal Details\n";
		cout<<"  Name\n  > ";
		cin.get();
		getline(cin,name);
		cout<<"  Roll Number\n  > ";
		cin>>rno;
		cout<<"  Class\n  > ";
		fflush(stdin);
		cin>>cls;
		cout<<"  Date of Birth (DD/MM/YY)\n  > ";
		cin.get();
		cin>>dob;
		cout<<"  Blood Group\n  > ";
		cin.get();
		cin>>bloodGroup;
		cout<<"  Mobile Number\n  > (+91)";
		cin>>mobileno;
		cout<<"Enter Student Result Data\n";
		cout<<"  Subject 1 Marks\n  > ";
		cin>>sr->s1;
		cout<<"  Subject 2 Marks\n  > ";
		cin>>sr->s2;
		cout<<"  Subject 3 Marks\n  > ";
		cin>>sr->s3;
		cout<<"  Subject 4 Marks\n  > ";
		cin>>sr->s4;	
		studCnt++;
		cout<<"Student Added Succesfully";
	}
    void putData() {
		// Calculating Student result
		sr->Calculate();

		cout<<setw(5)<<rno<<left<<setw(20)<<left<<name<<setw(6)<<left<<cls<<setw(11)<<left<<dob<<setw(7)<<left<<bloodGroup<<setw(25)<<left<<mobileno<<setw(4)<<sr->s1<<setw(4)<<sr->s2<<setw(4)<<sr->s3<<setw(4)<<sr->s4<<setw(6)<<sr->net<<setw(8)<<setprecision(5)<<sr->avg<<setw(20)<<sr->grade<<endl;
	}
	void shift(Student *stud){
		rno=stud->rno;
		name=stud->name;
		cls=stud->cls;
		dob=stud->dob;
		bloodGroup=stud->bloodGroup;
		mobileno=stud->mobileno;
		sr->s1=stud->sr->s1;
		sr->s2=stud->sr->s2;
		sr->s3=stud->sr->s3;
		sr->net=stud->sr->net;
		sr->avg=stud->sr->avg;
		sr->grade=stud->sr->grade;
	}
	inline static void del() {
		studCnt--;
	}
	inline static int getStudentCount() {
		return studCnt;
	}
	inline int getRno(){
		return rno;
	}
	~Student(){
		delete sr;
	}
};

int Student::studCnt;

int main() {
	int cnt,i,inp,key;
	bool flag;
	char choice;
	cout<<"\nMax Number of Student into Class\n> ";
	cin>>cnt;
	Student* st = new Student[cnt];
	do{
		cout<<"\nStudent Database Program\n";
		cout<<"\n 1. Add Student Data";
		cout<<"\n 2. Show all Students";
		cout<<"\n 3. Search Particular Student";
		cout<<"\n 4. No of Student Entries";
		cout<<"\n 5. Delete Student";
		cout<<"\n\nEnter your Choice\n> ";

		cin>>inp;

		switch(inp){
			case 1: st[Student::getStudentCount()].getData();
					break;
			case 2: cout<<"\nAll Student Database Records\n";

					cout<<setw(5)<<left<<"R-No"<<setw(20)<<left<<"Name"<<setw(6)<<left<<"Class"<<setw(11)<<left<<"Birth Date"<<setw(7)<<left<<"BGroup"<<setw(25)<<left<<"Mobile No"
						<<setw(4)<<left<<"S1"<<setw(4)<<left<<"S2"<<setw(4)<<left<<"S3"<<setw(4)<<left<<"S4"<<setw(6)<<left<<"net"<<setw(8)<<left<<"Average"<<setw(20)<<left<<"Grade"<<endl;

					for(i=0;i<Student::getStudentCount();i++)
						st[i].putData();
					break;
			case 3:	cout<<"Enter Roll Number to Search Record\n> ";
					cin>>key;
					for(i=0,flag=false;i<Student::getStudentCount();i++)
					{
						if(key==st[i].getRno())
						{
							cout<<"\nAll Student Database Records\n";
							cout<<setw(5)<<left<<"R-No"<<setw(20)<<left<<"Name"<<setw(6)<<left<<"Class"<<setw(11)<<left<<"Birth Date"<<setw(7)<<left<<"BGroup"<<setw(25)<<left<<"Mobile No"<<setw(4)<<left<<"S1"<<setw(4)<<left<<"S2"<<setw(4)<<left<<"S3"<<setw(4)<<left<<"S4"<<setw(6)<<left<<"net"<<setw(8)<<left<<"Average"<<setw(20)<<left<<"Grade"<<endl;

							st[i].putData();
							flag=true;
						}
					}
					if(!flag)
						cout<<"\n"<<key<<" Record not present.";
					break;
			case 4:	cout<<Student::getStudentCount()<<" student's data has been entered out of "<<cnt<<endl;
					break;
			case 5:	cout<<"Enter Roll Number to Deleting Record:";
				    cin>>key;
				    for(i=0,flag=false;i<Student::getStudentCount();i++){
						if(key==st[i].getRno()){
							flag=true;
							break;
						}
			        }
			        if(flag){
						for(;i<Student::getStudentCount()-1;i++)
				        	st[i].shift(&st[i+1]);
				        Student::del();
				        cout<<"\n Record Deleted Successfully.";
					}
				    else cout<<"\n"<<key<<" Record not present.";
			        break;
			default: cout<<"\nWrong Choice ;p";
		}
		cout<<"\nDo you want to continue(Y/N)\n> ";
		cin.get();
		cin>>choice;
	}while(tolower(choice)=='y');

	delete []st;

	cout<<"\nMemory cleared successfully from heap\nProgram ended successfully\n";
	return 0;
}