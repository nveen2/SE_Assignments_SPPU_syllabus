#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char arr[100];
    char ret[100];
    cout<<"Enter your name and age";
    cin.getline(arr,100);
//in this case the file is overwritten every time the file is opened
//if we dont want the file to be overwritten then we must open the file in append form

//file write operation
    //ofstream myfile("xyz.txt"); //thi sis nnormal mode
ofstream myfile("xyz.txt", ios::app); //this is append mode
//ios::ate -it always takes us to the end of file
//ios::out- output operation i.e. when we want to write something to the file  this is by default added
//there is also one more thing that is fstream it can perform both input and outpu opertaion so we have 
//to specify which operation it need to perform i.e(ios::out or ios::in))
//if we want to use the file with fstream and want to use the file in append mode
// then we can use (ios::out | ios::app )
    myfile<<arr;
    myfile.close();
    cout<<"File write operation performed successfully.";

//file read operation
cout<<"\nReading from file operation started"<<endl;
ifstream obj("xyz.txt");
obj.getline(ret,100);
cout<<"\nArray contents"<<"   "<<ret<<endl;
cout<<"file read operation successful"<<endl;
obj.close();
}