#include<iostream>
using namespace std ;
#define size 10
int arr[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1} ;

void insert( int data ){
    int key = data % size ;
    if( arr[key] == -1 ){
        arr[key] = data ;
        cout << data << " added successfully.\n" ;
    }
    else{
        int temp = key ;
        while( true ){
            key++ ;
            if( arr[key] == -1 ){
                arr[key] = data ;
                cout << data << " added successfully.\n" ;
                break ;
            }
            if( key == size - 1 ){
                key = -1 ;
            }
            if( (temp != 0 && key == temp - 1) || ( key == 0 && key == size - 1 ) ){
                cout << "Array completed.\n" ;
                return ;
            }
        }
    }
}

bool search( int data ){
    int key = data % size ;
    if( arr[key] == data ){
        // cout << "Array found at position: " << key ;
        return true ;
    }
    else{
        int temp = key ;
        while( true ){
            key++ ;
            if( arr[key] == data ){
                // cout << "Array found at position: " << key ;
                return true ;
            }
            if( key == size - 1 ){
                key = -1 ;
            }
            if( key == temp - 1 ){
                // cout << "Element not found !!" ;
                return false ;
            }
        }
    }
}

void del( int data ){
    if( search(data) ){
        int key = data % size ;
        if( arr[key] == data ){
            arr[key] = -1 ;
            cout << data << " is successfully deleted.\n" ;
            return ;
        }
        else{
            int temp = key ;
            while( true ){
                key++ ;
                if( arr[key] == data ){
                    arr[key] = -1 ;
                    cout << data << " is successfully deleted.\n" ;
                    return ;
                }
                if( key == (size - 1) ){
                    key = -1 ;
                }
            }
        }
    }
    else{
        cout << data << " is not present!!!\n" ;
    }
}

int main(){
    int a = 1 ;
    while( a < 4 ){
        cout << "1. Insert an element.\n2. Search an element.\n3. Delete an element. " ;
        cin >> a ;
        cout << endl ;
        if( a == 1 ){
            cout << "Enter element to insert: " ;
            int data ; cin >> data ;
            insert(data) ;
            for(int i=0;i<size-1;i++){
                cout<<arr[i]<<endl;
            }
        }
        else if ( a == 2 ){
            cout << "Enter element to search: " ;
            int data ; cin >> data ;
            if( search(data) ){
                cout << data << " is present.\n";
            }
            else{
                cout << data << " not present !!!\n" ;
            }
            cout << endl ;
        }
        else if ( a == 3 ){
            cout << "Enter element to delete: " ;
            int data ; cin >> data ;
            del(data) ;
            for(int i=0;i<size-1;i++){
                cout<<arr[i]<<endl;
            }
            cout << endl ;
        }
        cout << endl ;
    }

    return 0 ;
}