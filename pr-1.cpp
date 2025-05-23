#include <iostream>

using namespace std;

class Cars
{
    private:
    string price;

    public:
    string name;
    string fuel;
    string model;

    void setData(string price,string name,string fuel,string model){
        this->price=price;
        this->name=name;
        this->fuel=fuel;
        this->model=model;
    }

     
    void getdata(){
        cout <<"Price:" << this->price << endl;
        cout <<"Name:" << this->name << endl;
        cout <<"Fuel:" << this->fuel << endl;
        cout <<"Model:" << this->model << endl;
    }

    static string company;

};

string Cars :: company ="Maruti";

int main()
{

    int number,i;
    string price;
    string name;
    string fuel;
    string model;

    cout <<"Enter how many models company have:";
    cin >> number;

    Cars c[number];

    for(i = 0;i < number;i++){

        cin.ignore();

        cout <<"Enter Price of Car: " << endl;
        getline(cin,price);

        cout <<"Enter Name of Car: " << endl;
        cin >> name;  

        cout <<"Enter Fuel of Car: " << endl;
        cin >> fuel;
    
        cout <<"Enter model of Car: " << endl;
        cin >> model;
   

        c[i].setData(price,name,fuel,model);
    }
    
    c[1].name="nexa";

    for(i = 0;i < number ; i++){
        cout <<"--------models----------" << endl;
        c[i].getdata(); 
        cout <<"Company:" <<Cars::company << endl;
        cout <<"--------models----------" << endl;
    }
    return 0;
}