#include<bits/stdc++.h>
using namespace std ;

class StudentResult
{
	int s1, s2, s3, total ;
	float avg ;
	string grade ;
	public: StudentResult()
			{
				s1 = s2 = s3 = total = 0 ;
				avg = 0.0f ;
				grade = "" ;
			}
			void Calculate()
			{
				total = s1 + s2 + s3 ;
				avg = total/3 ;
				if( avg >= 66.66f )
					grade = "First with Dist class" ;
				else if( avg >= 60.00f && avg < 66.66f )
					grade = "First class" ;
				else if( avg >=50.00f && avg < 60.00f )
					grade = "Second class" ;
				else if( avg >=40.00f && avg < 50.00f )
					grade = "Pass class" ;
				else
					grade = "Fail class" ;
			}
			friend class Student ;
};
class Student
{
	int rno ;
	string name, cls, dob, bloodGroup, address ;
	long long int mobileno ;
	static int studCnt ;
	StudentResult *sr ;
	public:
		Student()		//Default Constructor
		{
			rno = mobileno = 0 ;
			name = cls = bloodGroup = "" ;
			dob = "DD/MM/YY" ;
			sr = new StudentResult() ;
			studCnt = 0 ;
		}
		static int getStudentCount()
		{
			return studCnt ;
		}
		Student(Student *stud)	//Copy Constructor
		{
			this->rno = stud->rno ;
			this->name = stud->name ;
			this->cls = stud->cls ;
			this->dob = stud->dob ;
			this->bloodGroup = stud->bloodGroup ;
			this->address = stud->address ;
			this->mobileno = stud->mobileno ;
			this->sr->s1 = stud->sr->s1 ;
			this->sr->s2 = stud->sr->s2 ;
			this->sr->s3 = stud->sr->s3 ;
			this->sr->total = stud->sr->total ;
			this->sr->avg = stud->sr->avg ;
			this->sr->grade = stud->sr->grade ;
		}
		void getData()
		{
			cout <<"\n\t Enter Student Persoanal Details:" ;
			cout << "\n Roll Number:" ;
			cin >> rno;
			cout << "\n Name:" ;
			cin.get() ;
			getline(cin,name) ;
			cout << "\n Class:" ;
			fflush(stdin) ;
			cin >> cls ;
			cout << "\n Date of Birth (DD/MM/YY):" ;
			cin.get() ;
			cin >> dob ;
			cout << "\n Blood Group:" ;
			cin.get() ;
			cin >> bloodGroup ;
			cout << "\n Address:" ;
			cin.get() ;
			getline(cin,address) ;
			cout << "\n Mobile Number:" ;
			cin >> mobileno ;
			cout << "\n\t Enter Student Result Data:" ;
			cout << "\n Subject 1 Marks:" ;
			cin >> sr->s1 ;
			cout << "\n Subject 2 Marks:" ;
			cin >> sr->s2 ;
			cout << "\n Subject 3 Marks:" ;
			cin >> sr->s3 ;
			studCnt++ ;
		}
		void putData()
		{
			cout<<setw(5)<<rno<<left<<setw(20)<<left<<name<<setw(6)<<left<<cls<<setw(11)<<left<<dob<<setw(7)<<left<<bloodGroup<<setw(25)<<left<<address<<setw(11)<<left<<mobileno ;
			sr->Calculate();
			cout<<setw(4)<<sr->s1<<setw(4)<<sr->s2<<setw(4)<<sr->s3<<setw(6)<<sr->total<<setw(8)<<setprecision(5)<<sr->avg<<setw(20)<<sr->grade<<endl ;
		}
		inline int getRno()
		{
			return rno ;
		}
		~Student()
		{
			cout << "\n Exiting from the Class." ;
		}
		void shift(Student *stud)
		{
			rno = stud->rno ;
			name = stud->name ;
			cls = stud->cls ;
			dob = stud->dob ;
			bloodGroup = stud->bloodGroup ;
			address = stud->address ;
			mobileno = stud->mobileno ;
			sr->s1 = stud->sr->s1 ;
			sr->s2 = stud->sr->s2 ;
			sr->s3 = stud->sr->s3 ;
			sr->total = stud->sr->total ;
			sr->avg = stud->sr->avg ;
			sr->grade = stud->sr->grade ;
		}
		static void del()
		{
			studCnt-- ;
		}
} ;
int Student::studCnt ;
int main()
{
	{
		Student s1 ;
		s1.getData() ;
		cout << "\n -------------------------------------------------------------------------------\n" ;
		cout<<setw(5)<<left<<"R No"<<setw(20)<<left<<"Name"<<setw(6)<<left<<"Class"<<setw(11)<<left<<"Birth Date"<<setw(7)<<left<<"BGroup"<<setw(25)<<left<<"Address"<<setw(11)<<left<<"Mobile No"
			<<setw(4)<<left<<"S1"<<setw(4)<<left<<"S2"<<setw(4)<<left<<"S3"<<setw(6)<<left<<"Total"<<setw(8)<<left<<"Average"<<setw(20)<<left<<"Grade"<<endl;
		s1.putData() ;
		Student s2(s1) ;
		s2.putData() ;
		cout << "\n -------------------------------------------------------------------------------\n" ;
	}
	int cnt, i, choice, key, flag = 0 ;
	char ch ;
	cout << "\n\t Max Number of Student into Class:" ;
	cin >> cnt ;
	Student *st = new Student[cnt] ;
	do
	{
		cout << "Student Database Program" ;
		cout << "\n 1. Add New Student" ;
		cout << "\n 2. Show all Students";
		cout << "\n 3. Search Particular Student" ;
		cout << "\n 4. How many Students Data Entry was Done?" ;
		cout << "\n 5. Delete Student" ;
		cout << "\n Enter your Choice:" ;
		cin >> choice ;

		switch(choice)
		{
			case 1: st[Student::getStudentCount()].getData() ;
					break ;
			case 2: cout << "\n\t All Student Database Records" ;
					cout << "\n -------------------------------------------------------------------------------\n" ;
					cout << setw(5)<<left<<"R No"<<setw(20)<<left<<"Name"<<setw(6)<<left<<"Class"<<setw(11)<<left<<"Birth Date"<<setw(7)<<left<<"BGroup"<<setw(25)<<left<<"Address"<<setw(11)<<left<<"Mobile No"
						<<setw(4)<<left<<"S1"<<setw(4)<<left<<"S2"<<setw(4)<<left<<"S3"<<setw(6)<<left<<"Total"<<setw(8)<<left<<"Average"<<setw(20)<<left<<"Grade"<<endl;
					for( i = 0 ; i < Student::getStudentCount() ; i++ )
						st[i].putData() ;
					cout << "\n -------------------------------------------------------------------------------\n" ;
					break ;
			case 3:	cout << "Enter Roll Number to Search Record:" ;
					cin >> key ;
					for( i = 0, flag = 0 ; i < Student::getStudentCount() ; i++ )
					{
						if( key == st[i].getRno() )
						{
							cout << "\n\t All Student Database Records" ;
							cout << "\n -------------------------------------------------------------------------------\n" ;
							cout << setw(5)<<left<<"R No"<<setw(20)<<left<<"Name"<<setw(6)<<left<<"Class"<<setw(11)<<left<<"Birth Date"<<setw(7)<<left<<"BGroup"<<setw(25)<<left<<"Address"<<setw(11)<<left<<"Mobile No"
								<<setw(4)<<left<<"S1"<<setw(4)<<left<<"S2"<<setw(4)<<left<<"S3"<<setw(6)<<left<<"Total"<<setw(8)<<left<<"Average"<<setw(20)<<left<<"Grade"<<endl;
							st[i].putData() ;
							cout << "\n -------------------------------------------------------------------------------\n" ;
							flag = 1 ;
						}
					}
					if( flag == 0 )
						cout << "\n"<<key<<" Record not present." ;
					break ;
			case 4:	cout << "Data Entry was Done out of "<<Student::getStudentCount()<<" / "<<cnt<<endl ;
					break ;
			case 5:	cout << "Enter Roll Number to Deleting Record:" ;
					cin >> key ;
					for( i = 0, flag = 0 ; i < Student::getStudentCount() ; i++ )
					{
						if( key == st[i].getRno() )
						{
							flag = 1 ;
							break ;
						}
					}
					if( flag == 0 )
						cout << "\n"<<key<<" Record not present." ;
					else
					{
						for( ; i < Student::getStudentCount()-1 ; i++ )
							st[i].shift(&st[i + 1]) ;
						Student::del() ;
						cout << "\n Record Deleted Successfully." ;
					}
					break ;
			default:cout << "\n Enter choice Inbetween 1 to 5 only." ;
					break ;
		}
		cout << "\n Do you want to continue(Y/N):" ;
		cin.get() ;
		cin >> ch ;
	}while( ch == 'y' || ch == 'Y' ) ;

	delete []st ;  //dynamic memory de-allocation
	cout << "Exit from Main" ;

	return 0 ;
}