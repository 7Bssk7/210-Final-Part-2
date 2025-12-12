// COMSC-210 | Final 2 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <deque>
using namespace std;

const int LINE_SIZE = 3, SIMULATION = 10;

struct Customer{
    string name;
    string good;
    Customer(string n, string g){
        name = n;
        good = g;
    }
};

class LinkedList{
    public: 
        LinkedList() { head = nullptr; tail = nullptr; } 

        void push_back(string n, string d) {
            Node* newNode = new Node(n, d);
            cout << "    New customer joins: " << n << ", Ordered: " << d << endl;
            if (!tail) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_front(){
            if(!head){
                cout << "    Line is empty, no one served." << endl;
                return;
            }
            Node* temp = head;
            cout << "    Serving " << temp->name << ", Ordered: " << temp->drink << endl;
            if (head->next) {
                head = head->next;
            }  
            else{
                head = tail = nullptr;
            }

            delete temp;
            
        } 

        bool empty(){
            return head == nullptr;
        }

        void print() {
        Node* current = head;
        if (!current) {
            cout <<"    Line is empty, no one served." << endl;
            return;
        }
        while (current) {
            cout << "    Current line:" << endl;
            cout << "    "<< current->name<< ", Ordered: " << current->drink << endl;
            current = current->next;
        }
        cout << endl;
    }

    private: 
    struct Node {
        string name;
        string drink;
        Node *next;
        Node(string n, string d, Node* nxt = nullptr){
            name = n;
            drink = d;
            next = nxt;
        }
    };

    Node* head;
    Node* tail;    
};


string randomName(const vector<string>& );
string randomGood(const vector<string>& );
bool chance(int p);

int main(){
    srand(time(0));
    vector<string> names {"Alice","Bob","Charlie","Diana","Ethan","Fiona","Ben","Nick","Bryan","Finn","Arkhip"};
    vector<string> drinks = {"Latte","Espresso","Mocha","Tea","Cappuccino","Americano"};
    vector<string> muffins = {"Blueberry Muffin","Chocolate Muffin","Banana Muffin","Bran Muffin"};
    vector<string> friend_br = {"Red Bracelet","Blue Bracelet","Leather Bracelet","Green Bracelet","Yellow Bracelet"};

    LinkedList coffee_line; 
    deque<Customer> muff_line;
    vector<Customer> bracelet_line;

    //randomName(names)
    //randomDrink(drinks)

    for(int i = 0; i < LINE_SIZE; ++i ){
        coffee_line.push_back(randomName(names),randomGood(drinks));
        Customer c (randomName(names), randomGood(muffins));
        muff_line.push_back(c);
    }

    cout << " Line simulation:" << endl;
    cout << " Initial Coffee Line: " << endl;
    coffee_line.print();
    cout << "Initial Muffin Line:" << endl;
    for (auto& c : muff_line) {
        cout << "    " << c.name << ", Ordered: " << c.good << endl;
    }

    for (int round = 1; round <= 10; ++round) {

        cout << "\nRound " << round << ":" << endl;


        cout << "\nCoffee Booth:" << endl;
        if (!coffee_line.empty()) {
            coffee_line.pop_front();
        }
        if(chance(50)){
            coffee_line.push_back(randomName(names), randomGood(drinks));
        }
        coffee_line.print();



        cout << "\nMuffin Booth:" << endl;
        if (!muff_line.empty()) {
            cout << "    Serving " << muff_line.front().name << ", Ordered: " << muff_line.front().good << endl;
            muff_line.pop_front();
        } else {
            cout << "    Line is empty, no one served." << endl;
        }
        if(chance(50)){
            Customer nC (randomName(names), randomGood(muffins));
            muff_line.push_back(nC);
        }
        if (muff_line.empty()) {
            cout << "    Line is empty." << endl;
        } 
        else {
            for (auto& c : muff_line) {
                cout << "    Current line:" << endl;
                cout << "    " << c.name << ", Ordered: " << c.good << endl;
            }
        }
        cout << endl;

        

    }

    cout << "Lines after simulation: " << endl;

    cout << "\nCoffee Booth:" << endl;
    if(coffee_line.empty()){
        cout << "    Line is empty." << endl;
    }
    else{
        coffee_line.print();
    }

    cout << "\nMuffin Booth:" << endl;
    if (muff_line.empty()) {
            cout << "    Line is empty." << endl;
        } 
    else {
        for (auto& c : muff_line) {
            cout << "    Current line:" << endl;
            cout << "    " << c.name << ", Ordered: " << c.good << endl;
        }
    }

    return 0;
}

string randomName(const vector<string>& names) {
    return names.at(rand() % names.size());
}

string randomGood(const vector<string>& good ){
    return good.at(rand() % good.size());
}

bool chance(int p){
    int random = rand()% 100 + 1;
    return(random<=p);
}