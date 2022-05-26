#include<iostream>
using namespace std;
#include<fstream>

class Node{
public:
    Node *next;
    string Word;
    int Key;
    Node(){}
    Node(int key,string word){
        Word=word;
        Key=key;
        next=NULL;
    }
};


int HashFunc(string word){
    int s=0;
    for(int i=0;i<word.length();i++){
        s+=word[i];
    }
    int k=s%23;
    return k;
}


class hashTable{
public:
    Node arr[23];
    hashTable(){
        for(int i=0;i<23;i++){
            arr[i].Key=i;
            arr[i].Word="NONE";
            arr[i].next=NULL;
        }
    }
    void InsertWord(string word){
        int hval=HashFunc(word);
        Node *p;
        p=new Node(hval,word);
        if(arr[hval].next==NULL){
                arr[hval].next=p;
        }
        else{
            Node *temp;
            temp=arr[hval].next;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=p;
        }
    }
    void FindWord(string word){
        int hval=HashFunc(word);
        Node *temp;
        temp=arr[hval].next;
        int cnt=0,flag=0;
        while(temp!=NULL){
            if(temp->Word==word){
                flag=1;
                cnt++;
                cout<<"The spelling is Correct"<<endl<<"The number of comparisons is "<<cnt<<endl;
                break;
            }
            else {
                cnt++;
            }
            temp=temp->next;
        }
        if (flag==0){cout<<"The spelling is Incorrect"<<endl;}
    }
    void DisplayDict(){
        Node *temp;
        cout<<"************************************************"<<endl;
        for(int i=0;i<23;i++){
            cout<<"key "<<arr[i].Key<<":-";
            temp=arr[i].next;
            while(temp!=NULL)
            {
                cout<<temp->Word<<"    ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};


int main(){
    fstream file;
    string dict_file,word;
    dict_file="dictionary.txt";
    file.open(dict_file);
    hashTable h;
    while(file>>word){h.InsertWord(word);}
    int ch;
    char t;
    do{
        cout<<"\n1.Display the Dictionary \n2.Check spelling \n\nEnter your choice:- ";
        cin>>ch;
        switch(ch){
            case 1:{h.DisplayDict();break;}
            case 2:{
                cout<<"Enter the word:-";
                cin>>word;
                h.FindWord(word);
                break;
            }
            default:
                cout<<"INVALID CHOICE !!!!"<<endl;
                break;
        }

        cout<<"\nDo you want to continue (Y/N)? ";
        cin>>t;
    }while(t=='y' || t=='Y');
    return 0;
}

