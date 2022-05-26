#include<iostream>
#include<stdio.h>

using namespace std;

class personal_data
{
    protected:
        char name[20];
        int age;
        char gender;
    
    public:
        void p_getdata()
        {
            cout<<"Enter Name:";
            gets(name);
            cout<<"enter age:";
            cin>>age;
            cout<<"Enter gender(M/F):";
            cin>>gender;
        }


};

class professional_data
{
    protected:
        int employ_no;
        char post[15];
        char department[20];

    public:
        void prof_getdata()
        {
            cout<<"Enter employee number:";
            cin>>employ_no;
            cout<<"Enter the post in organisation:";
            gets(post);
            cout<<"enter name of departement:";
            gets(department);

        }

};

class academic_data
{
    protected:
        char field[30];
        char grade;
        float percentage;

    public:
        void acad_getdata()
        {
            cout<<"Enter field in engineering:";
            gets(field);
            cout<<"enter overall garde obtained: ";
            cin>>grade;
            cout<<"Enter percentage:";
            cin>>percentage;

        }
};

class employee_bio: public personal_data,public professional_data,public academic_data
{
    public:
        void show_data();
};

void employee_bio::show_data()
{
    cout<<"Employee Details:";
    cout<<endl;

    cout<<"Personal Data : ";
    cout<<endl;
    cout<<"Name:";
    puts(name);
    cout<<"age:"<<age<<endl;
    cout<<"Gender:"<<gender<<endl;
    cout<<endl;

    cout<<"Professional Data : "<<endl;
    cout<<"Employee Number: "<<employ_no<<endl;
    cout<<"Post :";
    puts(post);
    cout<<"Departement: ";
    puts(department);
    cout<<endl;

    cout<<"Academic Data :"<<endl;
    cout<<"Field in Engineering:";
    puts(field);
    cout<<"Overall grade obtained:"<<grade<<endl;
    cout<<"Total percentage:"<<percentage<<endl;

}

int main()
{
    employee_bio E1;
    E1.p_getdata();
    E1.prof_getdata();
    E1.acad_getdata();
    E1.show_data();

    return 0;
}

