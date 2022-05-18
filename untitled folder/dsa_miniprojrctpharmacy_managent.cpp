#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include<conio.h>
#include <iomanip>
#define max 10

using namespace std;
class medicineType	
{
public:

    void take_order();
    void delete_order(); 
    void modify(); 
	void order_list(); 
	void daily_summary(); 
	void exit();  
	medicineType();

};

 medicineType::medicineType ()
{

}		
struct node 
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Amoxicillin 500 mg","Vitamin D 50000 IU","AIbuprofen 800 mg","Cetirizine hydrochloride 10 mg","Amlodipine besylate 10 mg","Albuterol sulfate 108 mcg/act",
	"Albuterol sulfate 108 mcg/act","Cyclobenzaprine hydrochloride 10 mg","Hydrochlorothiazide 25 mg5","Cephalexin 500 mgn"};
	double Medicine[10] = {200.00,300.00,100.00,400.00,100.00,500.00,700.00,400.00,300.00,500.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()	
{
	system("cls");
    char r1=201,r2=200,r3=188,r4=187,r5=205,r6=186,r7=220,r8=202,r9=204,r10=203,r11=206,r12=185;
    cout<<"\n";
    for(int i=0;i<89;i++)
    cout<<r7;
    cout<<endl;
    
	cout<<"\n\n\n\n\t\t\t\tCreated By:"<<endl;
	cout<<"\t\t\tNaveen Jhajhriya(3233)"<<endl;
	cout<<"\t\t\tHimanshu Gaupale(3223)"<<endl;

	getch();
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\tPharmacy Management System\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<endl;
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();	
				break;
			}	
		
		
		case 2:
			{
				medicine.delete_order();	
				
				break;
			}	
			
		case 3:
			{
				medicine.modify();	
				
				break;
			}	

		case 4:
			{
				medicine.order_list();	

				break;
			}	
		case 5:
			{
				medicine.daily_summary();	
				
				break;
			}	
        case 6:
			{
				medicine.exit();	
				goto a;
				break;
			}	
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
	}while(menu!=6);
	a:
	cout<<"thank you"<<endl;
	
	return 0;
}


void medicineType::take_order()		
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

			
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amoxicillin 500 mg"<<"			        INR 200.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin D 50000 IU"<<"		            INR 300.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    AIbuprofen 800 mg"<<"		                INR 100.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Cetirizine hydrochloride 10 mg"<<"		INR 400.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Azithromycin 250 mg"<<"	 	            INR 100.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amlodipine besylate 10 mg"<<" 		    INR 500.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Albuterol sulfate 108 mcg/act"<<"		    INR 700.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Cyclobenzaprine hydrochloride 10 mg"<<"	INR 400.00"<<endl;
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Hydrochlorothiazide 25 mg5"<<"			INR 300.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Cephalexin 500 mgn"<<"		            INR 500.00"<<endl;
                cout<<" "<<endl;
    
	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->reciept_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" INR"<<endl;
        system("PAUSE");
                      
	}
	cout << "Order Taken Successfully"<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}


void medicineType::order_list()		
{
	int i, num, num2;	
	bool found;			
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<endl;
	cout <<"\t\tHere is the Order list\n"; 
	cout<<endl;


	if(temp == NULL) 
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	
        {
		cout <<"Reciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		cout << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout<<endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" INR"<<endl;
			cout<<endl;
		}
		int k=0;
		int sum = 0;
		while(k<i){
			sum += temp->amount[k];
			k++;
		}
		temp->total = sum;
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		do{
				cout<<"\n";
				if(num!=temp->total){
			    cout<<"\nPlease Enter The Full Bill Payment...";
				cout << "\nType the exact amount You need to pay: ";
				cin >> num;
				}

		}while(num!=temp->total);


		if (num == temp->total)
		{cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}else{
			
		}
		}


}
}	


void medicineType::delete_order()	
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
}	



void medicineType::modify()	
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" INR"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}		



void medicineType::daily_summary()		
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<endl;

		while(temp!=NULL)
		{
		
				cout <<"Reciept Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;
				
				cout<<"Order Date : "<<temp->date<<endl;
				
				cout<<endl;
			
				cout << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout <<endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" INR"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}

			int k=0;
			int sum = 0;
			while(k<i){
				sum += temp->amount[k];
				k++;
			}
			temp->total = sum;
			cout<<"Total Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";	
			temp=temp->next;
		}
	}
}		
void medicineType::exit() 
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	


