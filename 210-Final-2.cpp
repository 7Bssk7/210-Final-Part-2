// COMSC-210 | Final 2 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Customer {
    string name;
    string drink;
    Customer(string n = "", string d = "") {
        name = n;
        drink = d;
    }
};


string randomName(const vector<string>& );
string randomDrink(const vector<string>& );

int main(){
    vector<string> names {"Alice","Bob","Charlie","Diana","Ethan","Fiona"};
    vector<string> drinks = {"Latte","Espresso","Mocha","Tea","Cappuccino","Americano"};

    //Test 

    Customer test( randomName(names), randomDrink(drinks));

    cout << test.name << " " << test.drink << endl;


    return 0;
}

string randomName(const vector<string>& names) {
    return names.at(rand() % names.size());
}

string randomDrink(const vector<string>& drinks ){
    return drinks.at(rand() % drinks.size());
}