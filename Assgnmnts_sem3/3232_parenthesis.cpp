#include<iostream>
#include<string.h>
using namespace std;

char Ex[30];
int top;

void push(char a)
{      top++;   
       Ex[top]=a;                
}

void pop()
{        top--;                       
}


int main()
{  
   void push(char a);
   void pop();
   char ch[30]; 
   int i=0;
   top=-1;
   cout<<"\n Enter the expression";
   cin>>ch;
   while(i<strlen(ch))
   {   
     
      if((ch[i]=='{')||(ch[i]=='[')||(ch[i]=='('))
      {     push(ch[i]);                           
      }
         
      if(ch[i]=='}')
      {    if(Ex[top]=='{')
               pop();      
      }
      if(ch[i]==']')
      {    if(Ex[top]=='[')
               pop();
         
      }
      if(ch[i]==')')
      {    if(Ex[top]=='(')
               pop();
         
      }
  
      i++;
   }
      if(top==-1)
      {    
         cout<<"\n Expression is well parentherised";
         
      }
      else
      {  
            cout<<"\n Expression is not well parentherised";
      }
   
     
}   