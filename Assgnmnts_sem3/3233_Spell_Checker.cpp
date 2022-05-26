#include <iostream>
using namespace std;
#include <fstream>


class SplChk_Node {
public:
    SplChk_Node *next;
    SplChk_Node(){
    };
    string SplChk_Word;
    int SplChk_Key;

    SplChk_Node(int key, string word){
        SplChk_Word = word;
        SplChk_Key = key;
        next = NULL;
    }
};

int SplChk_HashFunc(string SplChk_Word)
{   int w_sum=0;
    int w_Length = SplChk_Word.length();
    for (int i = 0; i < w_Length; i++)
        w_sum += SplChk_Word[i];
    int HashValue = w_sum % 20;
    return HashValue;
}

class SplChk_HashTable
{
    public:
    SplChk_Node USR_Array[20];
    SplChk_HashTable(){
    for (int i = 0; i < 20; i++){
            USR_Array[i].SplChk_Key = i, USR_Array[i].SplChk_Word = "NONE";
            USR_Array[i].next = NULL;
        }}
    void SplChk_InsertWord(string SplChk_Word);
    void SplChk_FindWord(string SplChk_Word);
    void SplCHk_DisplayHT();
};

void SplChk_HashTable::SplChk_InsertWord(string SplChk_Word)
{
    int HashValue = SplChk_HashFunc(SplChk_Word);
    SplChk_Node *p;
    p = new SplChk_Node(HashValue, SplChk_Word);
    if (USR_Array[HashValue].next == NULL)
    {
        USR_Array[HashValue].next = p; }
    else{
        SplChk_Node *temp;
        temp = USR_Array[HashValue].next;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p; }
}

void SplChk_HashTable::SplChk_FindWord(string SplChk_Word)
{
    int HashValue = SplChk_HashFunc(SplChk_Word);
    SplChk_Node *temp;
    temp = USR_Array[HashValue].next;
    int count = 0, flag = 0;
    while (temp != NULL)
    {
        if (temp->SplChk_Word == SplChk_Word)
        {
            flag = 1;
            count++;
            cout << " This is the CORRECT Spelling for word :- "<<SplChk_Word<<"\n Total Comparisons Made for checking :- " << count << endl;
            break;
        } else {
            count++;
        }
        temp = temp->next;
    }
        if(flag==0){cout << "Spelling is INCORRECT !!! " << endl; }}

void SplChk_HashTable::SplCHk_DisplayHT()
{
    SplChk_Node *temp;
    cout << "==================================================================================================================================================" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout<<" Key Value ";
        cout <<"["<< USR_Array[i].SplChk_Key << "] :- ";
        temp = USR_Array[i].next;
        while (temp != NULL)
        {
            cout << temp->SplChk_Word << " [=] ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    fstream file;
    string SplChk_Word, SplChk_File;
    SplChk_File = "test.txt";
    file.open(SplChk_File);
    string word;
    SplChk_HashTable h;
    while (file >> SplChk_Word)
    {
        h.SplChk_InsertWord(SplChk_Word);
    }
    int USR_Choice;
    do
    {
        cout<<"\n \n***** SPELL CHECKER using HASHING *****"<<endl;
        cout<<"\n 1. Display Hash Table \n 2. Check Spelling of a Word \n 3. Exit \n  \n Enter Your Choice:- ";
        cin >> USR_Choice;
        switch (USR_Choice)
        {
        case 1:
            h.SplCHk_DisplayHT();
            break;
        case 2:
            cout << " Spell the Word you want to search :-  ";
            cin >> word;
            h.SplChk_FindWord(word);
            break;

        case 3:
            cout << " Exit the Program " << endl;
            break;

        default:
            cout << " INVALID CHOICE !!! " << endl;
            break;
        }
    } while (USR_Choice != 0);

    return 0;
}
