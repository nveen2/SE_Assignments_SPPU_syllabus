// To develop this problem statement use the concept of friend class, inline function for calculating the price for both types, default constructor for initial initialization, user defined function for calculating total_profit. 

#include<iostream>
using namespace std;

class Hotel {
friend class HotelRoom;
private:
    int bed, bath, price;
    bool choice;
    void setPrice(Hotel& h) {
        if (h.choice) h.price = 50*(h.bed) + 100*(h.bath) + 100;
        else h.price =  50*(h.bed) + 100*(h.bath);
    }
public:
    Hotel() {
        bed = bath = price = 0;
        choice = false;
    }
};

class HotelRoom {
    Hotel h;

    public:
    HotelRoom(){}
    HotelRoom(int bed, int bath, bool choice = false){
        h.bed = bed;
        h.bath = bath;
        h.choice = choice;
        h.setPrice(h);
    }
    inline int getPrice() const{
        return h.price;
    }

    void showData(){
        cout<< h.bed << " "<< h.bath<<" "<<h.choice<<" "<<h.price<<endl;
    }
};

int getProfit(HotelRoom* h, int n){
    int profit = 0;
    for (int i=0; i<n; i++){
        profit += h[i].getPrice();
    }
    return profit;
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter Number of Rooms Booked\n > ";
    cin>>n;
    HotelRoom h[n];
    for (int i = 0; i < n; i++){
        int choice;
        cout<<"Enter type of Room"<<endl;
        cout<<"1. Standard"<<endl;
        cout<<"2. Apartment\n> ";
        cin>>choice;
        int bed, bath;
        cout<<"Enter Number of Rooms & Bathrooms\n> ";
        cin>>bed>>bath;
        if (bed < 1 || bed >5 || bath < 1 || bath>5){
            cout<<"We don't have that much accomodation\n";
            i--;
        }
        switch(choice){
            case 1: h[i] = HotelRoom(bed, bath);
            break;
            case 2: h[i] = HotelRoom(bed, bath, true);
            break;
            default: cout<<"Enter a valid option"; i--; break;
        }
    }
    
    int profit = getProfit(h, n);
    
    cout<<"Total Profit Earned by Hotel: "<<profit;
    return 0;
}

