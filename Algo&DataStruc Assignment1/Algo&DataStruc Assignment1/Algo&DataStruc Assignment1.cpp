#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }


    /// <summary>
    /// Append function for linked list
    /// Takes in a string value, in our case information about product
    /// if the current head is pointing to a nullpointer it makes a new node with the data we enter and make that head nullpointer
    /// </summary>
    /// <param name="value"></param>
    void append(string value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    /// <summary>
    /// Method to display the entire linked list
    /// Current stores the memordy address of the head
    /// While current is not null it continues the loop
    /// Print data stored
    /// make current's pointer switch from itself to the next and so on until it points to empty
    /// </summary>
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << "\n";
            current = current->next;
        }
    }
};

int main() {
    
    
    // Create a linked list object
    LinkedList myList;
    ifstream fileName("Info.txt"); // Sets file name
    string currLine; // Hold string of data for linked list,



    //Reads from file
    if (fileName.is_open()) {
        for (int i = 0; getline(fileName, currLine); i++) {
            currLine.erase(std::remove(currLine.begin(), currLine.end(), ','), currLine.end()); // removes commas
            //cout << currLine << "\n";
            myList.append(currLine);
        }

    }



    cout << "\nConsole\n";


    myList.display();



}
