// COMSC-210 | Final 2 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


class LinkedList{
    public: 
        LinkedList() { head = nullptr; tail = nullptr; } 

        void push_back(string n, string d) {
            Node* newNode = new Node(n, d);
            if (!tail) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void print() {
        Node* current = head;
        if (!current) {
            cout << "    Line is empty." << endl;
            return;
        }
        while (current) {
            cout << "        " << current->name<< ", Ordered: " << current->drink << endl;
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
string randomDrink(const vector<string>& );

int main(){
    vector<string> names {"Alice","Bob","Charlie","Diana","Ethan","Fiona"};
    vector<string> drinks = {"Latte","Espresso","Mocha","Tea","Cappuccino","Americano"};

    LinkedList line; 

    return 0;
}

string randomName(const vector<string>& names) {
    return names.at(rand() % names.size());
}

string randomDrink(const vector<string>& drinks ){
    return drinks.at(rand() % drinks.size());
}