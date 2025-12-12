// COMSC-210 | Final 2 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

const int LINE_SIZE = 3, SIMULATION = 10;

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
bool chance(int p);

int main(){
    srand(time(0));
    vector<string> names {"Alice","Bob","Charlie","Diana","Ethan","Fiona","Ben","Nick","Bryan","Finn","Arkhip"};
    vector<string> drinks = {"Latte","Espresso","Mocha","Tea","Cappuccino","Americano"};

    LinkedList line; 

    //randomName(names)
    //randomDrink(drinks)

    for(int i = 0; i < LINE_SIZE; ++i ){
        line.push_back(randomName(names),randomDrink(drinks));
    }

    cout << " Coffe Booth Line simulation:" << endl;
    cout << " Initial Line: " << endl;
    line.print();

    for (int round = 1; round <= 10; ++round) {
        cout << "Round " << round << ":" << endl;
        if (!line.empty()) {
            line.pop_front();
        } else {
            cout << "    Line is empty, no one served." << endl;
        }

        if(chance(50)){
            line.push_back(randomName(names), randomDrink(drinks));
        }

    }

    cout << " Line after simulation: " << endl;
    if(line.empty()){
        cout << "    Line is empty." << endl;
    }
    else{
        line.print();
    }


    return 0;
}

string randomName(const vector<string>& names) {
    return names.at(rand() % names.size());
}

string randomDrink(const vector<string>& drinks ){
    return drinks.at(rand() % drinks.size());
}

bool chance(int p){
    int random = rand()% 100 + 1;
    return(random<=p);
}