// COMSC-210 | Final 2 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <deque>
#include <stack>
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
        cout << "  Current line:" << endl;
        while (current) {
            cout << "    "<< current->name<< ", Ordered: " << current->drink << endl;
            current = current->next;
        }
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
    vector<string> names {"Alice","Bob","Charlie","Diana","Ethan","Fiona","Ben","Nick","Bryan","Finn","Arkhip","John","Emily","Michael","Sasha","David","Jessica","Daniel","Laura","James","Emma",
    "Matthew","Hannah","Andrew","Rachel","Chris","Joseph","Ashley"};
    vector<string> drinks = {"Latte","Espresso","Mocha","Tea","Cappuccino","Americano"};
    vector<string> muffins = {"Blueberry Muffin","Chocolate Muffin","Banana Muffin","Bran Muffin"};
    vector<string> friend_br = {"Red Bracelet","Blue Bracelet","Leather Bracelet","Green Bracelet","Yellow Bracelet"};
    vector<string> stickers = {"Anime Stickers","CS Stickers","Cartoon Stickers","Nature Stickers","Car Stickers"};

    LinkedList coffee_line; 
    deque<Customer> muff_line;
    vector<Customer> bracelet_line;
    stack<Customer> sticker_line; // I chose a stack data structure to use LIFO (Last-In, First-Out) in this project


    //randomName(names)
    //randomDrink(drinks)

    for(int i = 0; i < LINE_SIZE; ++i ){
        coffee_line.push_back(randomName(names),randomGood(drinks));
        Customer c_m (randomName(names), randomGood(muffins));
        muff_line.push_back(c_m);
        Customer c_b (randomName(names), randomGood(friend_br));
        bracelet_line.push_back(c_b);
        Customer c_s (randomName(names), randomGood(stickers));
        sticker_line.push(c_s);
    }

    cout << " Lines simulation:" << endl;
    cout << "\n Initial Coffee Line: " << endl;
    coffee_line.print();
    cout << "\nInitial Muffin Line:" << endl;
    for (auto& c : muff_line) {
        cout << "    " << c.name << ", Ordered: " << c.good << endl;
    }
    cout << "\nInitial Bracelet Line:" << endl;
    for (auto& c : bracelet_line) {
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
        } 
        else {
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
            cout << "  Current line:" << endl;
            for (auto& c : muff_line) {
                cout << "    " << c.name << ", Ordered: " << c.good << endl;
            }
        }


        cout << "\nBracelet Booth:" << endl;
        if (!bracelet_line.empty()) {
            cout << "    Serving " << bracelet_line.front().name << ", Ordered: " << bracelet_line.front().good << endl;
            bracelet_line.erase(bracelet_line.begin());
        } 
        else {
            cout << "    Line is empty, no one served." << endl;
        }
        if(chance(50)){
            Customer nC (randomName(names), randomGood(friend_br));
            bracelet_line.push_back(nC);
        }
        if (bracelet_line.empty()) {
            cout << "    Line is empty." << endl;
        } 
        else {
            cout << "  Current line:" << endl;
            for (auto& c : bracelet_line) {
                cout << "    " << c.name << ", Ordered: " << c.good << endl;
            }
        }

        cout << "\nStickers Booth:" << endl;
        if (!sticker_line.empty()) {
            cout << "    Serving " << sticker_line.top().name << ", Ordered: " << sticker_line.top().good << endl;
            sticker_line.pop();
        } 
        else {
            cout << "    Line is empty, no one served." << endl;
        }
        if(chance(50)){
            Customer nC (randomName(names), randomGood(stickers));
            sticker_line.push(nC);
        }
        if (sticker_line.empty()) {
            cout << "    Line is empty." << endl;
        } 
        else {
            cout << "  Current line:" << endl;
            stack<Customer> temp = sticker_line;
            while(!temp.empty()){
                cout << "    " << temp.top().name << ", Ordered: " << temp.top().good << endl;
                temp.pop();
            }
        }
        

    }

    cout << "\nLines after simulation: " << endl;

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
        cout << "  Current line:" << endl;
        for (auto& c : muff_line) {
            cout << "    " << c.name << ", Ordered: " << c.good << endl;
        }
    }

    cout << "\nBracelet Booth:" << endl;
    if (bracelet_line.empty()) {
            cout << "    Line is empty." << endl;
        } 
    else {
        cout << "  Current line:" << endl;
        for (auto& c : bracelet_line) {
            cout << "    " << c.name << ", Ordered: " << c.good << endl;
        }
    }

    cout << "\nStickers Booth:" << endl;
    if (sticker_line.empty()) {
        cout << "    Line is empty." << endl;
    } 
    else{
        cout << "  Current line:" << endl;
        stack<Customer> temp = sticker_line;
            while(!temp.empty()){
                cout << "    " << temp.top().name << ", Ordered: " << temp.top().good << endl;
                temp.pop();
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