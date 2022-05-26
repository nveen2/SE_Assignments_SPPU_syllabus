#include <iostream>
using namespace std;
int arr[10][2];

void Insertion(int roll){
    int index = roll%10;
    if(arr[index][0] == -1){
        arr[index][0] = roll;
    }
    else{
        if((arr[index][0]%10) == index){
            while(arr[index][0] != -1){
                index++;
                if(index > 9){
                    index-=10;
                }
            }
            arr[index][0] = roll;
            int i = index-1;
            if(i < 0){
                i = 10-i;
            }
            for(; arr[i][0] != -1; i--){
                if(i < 0){
                    i = 11-i;
                }
                if(roll%10 == (arr[i][0]%10)){
                    arr[i][1] = index;
                    break;
                }
            }
        }
        else{
            int temp = arr[index][0];
            int tempP = arr[index][1];
            int position = index;
            arr[index][0] = roll;
            arr[index][1] = -1;
            position++;
            while(arr[position][0] != -1){
                position++;
                if(position > 9){
                    position-=10;
                }
            }
            arr[position][0] = temp;
            arr[position][1] = tempP;
            int i = position-1;
            if(i < 0){
                i = 10-i;
            }
            for(; arr[i][0] != -1; i--){
                if(i < 0){
                    i = 11-i;
                }
                if(temp%10 == (arr[i][0]%10)){
                    if(arr[i][1] != -1){
                        arr[i][1] = position;
                        break;
                    }
                }

            }
        }
    }
}

void Searching(int roll){
    int index = roll%10;
    bool flag = 0;
    if(arr[index][0] == roll){
        flag = 1;
    }
    else{
        while(true){
            index = arr[index][1];
            if(arr[index][0] == roll){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        cout<<"Roll Number at Index : "<<index<<endl;
    }
    else{
        cout<<"Roll Number Not Found"<<endl;
    }
}

int main()
{
    for(int i = 0; i < 10; i++){
        arr[i][0] = arr[i][1] = -1;
    }
    int choice;
    char ch;
    int roll;
    do{
        cout<<"1. Insert Student"
            <<"\n2. Search Student"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        for(int i = 0; i < 10; i++){
            cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        }
        switch(choice){
            case 1:cout<<"Enter Roll Number : ";
                cin>>roll;
                Insertion(roll);
                for(int i = 0; i < 10; i++){
                    cout<<i<<" "<<arr[i][0]<<" "<<arr[i][1]<<endl;
                }
                break;
            case 2:cout<<"Enter Roll Number : ";
                cin>>roll;
                Searching(roll);
                break;
        }

    }while(ch<3);

    return 0;
}
