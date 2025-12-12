// COMSC-210 | Final 2 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


string randomName(const vector<string>& );

int main(){
    vector<string> names {"Alice","Bob","Charlie","Diana","Ethan","Fiona"};



    return 0;
}

string randomName(const vector<string>& names) {
    return names.at(rand() % names.size());
}