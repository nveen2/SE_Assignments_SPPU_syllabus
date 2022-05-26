/*   
Develop a program in C++ to create database of Restaurant information system containing  the  
following  information:  bill_date,  table_no,  number_of_guest, item_list, 
iem_quantity_list, bill_amount+50 Service Charge. Calculate 
the total sale gain by the Restaurant owner at the end of the day.
Make use of Default constructor, Static member functions, Friend class, this pointer, inline code. Assume restaurant item list and their prices. 
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Restaurant{
    friend class Order;
    static string date;
    int num_gst, table_no, itm_ct, service;
    float bill_amt, cost;
    vector<int> itm_quant, itm;
    static int profit;
 
    void bill(Restaurant& r) { 
        r.bill_amt = 0;
        for(int i=0;i<r.itm_ct;i++) { 
            if(r.itm[i]==1) r.bill_amt += 100*r.itm_quant[i] ;
            if(r.itm[i]==2) r.bill_amt += 50*r.itm_quant[i] ;          
            if(r.itm[i]==3) r.bill_amt += 50*r.itm_quant[i] ;
            if(r.itm[i]==4) r.bill_amt += 80*r.itm_quant[i] ;
        }
        r.bill_amt += r.service;
    }

    static void updateProfit(Restaurant& r){
        Restaurant::profit += r.bill_amt;
    }

    public: 
    Restaurant(){
        this->num_gst = this->table_no = this->itm_ct = 0;
        this->bill_amt = this->cost = 0;
        this->itm_quant = this->itm = vector<int>{};
        this->service = 50;
    }

};

int Restaurant::profit = 0;
string Restaurant::date = "dd/mm/yy";

class Order{
    Restaurant r;
    
    public:
    static void getDate(){
        cout<<"Enter Bill Date (dd/mm/yy): ";
        cin>>Restaurant::date;
    }
    
    void getData() {
        cout<<"Enter table no: ";
        cin>> r.table_no;
        cout<<"Enter Number of Guest: "; 
        cin>>r.num_gst;
        cout<<"MENU\n";
        cout<<"1. Pizza\n";
        cout<<"2. Burger\n";
        cout<<"3. Pepsi\n";
        cout<<"4. Potato Flakes\n";
        cout<<"Enter Item Count: ";
        cin>>r.itm_ct;
        r.itm_quant.resize(r.itm_ct);
        r.itm.resize(r.itm_ct);
        for(int i=0;i<r.itm_ct;i++) {
            cout<<"Item index & Quantity: "; 
            cin>>r.itm[i]; 
            cin>>r.itm_quant[i];            
        } 
        r.bill(r);
        r.updateProfit(r);
    }

    inline void showBill() const{
        cout<<"Table num: "<<r.table_no<<" Bill: "<<r.bill_amt<<endl;
    }

    inline static int getProfit() {
        return Restaurant::profit;  
    }    
};

int main() { 
    Order::getDate();
    int n;
    cout<<"Enter Number of Transaction Happened in a day\n> ";
    cin>>n;
    Order order[n];
    for(int i=0;i<n;i++) {
        cout<<"Order "<<i+1<<endl;
        order[i].getData();
    } 
    for (int i=0;i<n;i++) order[i].showBill();
    
    int profit = Order::getProfit();
    cout<<"Total Profit Earned by Hotel: "<<profit;
    return 0;
}