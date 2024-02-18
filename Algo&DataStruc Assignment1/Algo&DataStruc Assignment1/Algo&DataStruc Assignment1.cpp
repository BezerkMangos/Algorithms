// Algo&DataStruc Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Node {
    //Information saved in each node
public:
    string line;
    int itemNum;
    string itemName;
    string itemName2;
    double itemPrice;
    string category;
    // Pointer to  node
    Node* next;
};

//Start of linked list class
class LinkedList {
private:
    Node* head; //Head of the list, first element
public:
    int index = 0;
    LinkedList() : head(nullptr) {}

 
    //Insertion Method
    // Adding nodes to linked list, data required, in this case itmNum, 
    void insert(int Num,string itemName,string itemName2 ,double price, string cate) {
        Node* newNode = new Node; // Creates a new node
        newNode->itemNum = Num; // Sets node's data to parameter data
        newNode->itemName = itemName;
        newNode->itemName2 = itemName2;
        newNode->itemPrice = price;
        newNode->category = cate;
       
        newNode->next = head; 
        head = newNode;// makes head point to new node and not null
    }

    void insert(string newLine) {
        Node* newNode = new Node;
        newNode->line = newLine;

        newNode->next = head;
    }

    

    //Dipslay Entire liked list by check to see if the pointer returns null, if it does there is no next, starts at tail works back to head
    void display() {
        Node* current = head; // Makes a node pointer to the head of the list
        index = 0;
        while (current != nullptr) {
            cout << index << ": ";
            cout << current->line;
            cout << current->itemNum; // Prints out the current data
            cout << current->itemName; 
            cout << current->itemName2; 
            cout << current->itemPrice; 
            cout << current->category; 
            current = current->next; // Moves current to the data of the next pointer,
            cout << "\n";
            index = index + 1;
        }
        
    }
    
    void DeleteNode() {

    }

};
//End of Linked list Class




int main()
{

    // Create a linked list object
    LinkedList myList;

    LinkedList itemNum;
    LinkedList itemName;
    LinkedList price;
    LinkedList category;

    int tempItemNum;
    string tempItemName;
    string tempItemName2;
    int tempPrice;
    string tempCategory;

	ifstream fileName("Info.txt"); // Sets file name
	string currLine; // Hold string of data for linked list,

    
    
    //Reads from file
    if (fileName.is_open()) {
        for (int i = 0; getline(fileName, currLine); i++) {
            currLine.erase(std::remove(currLine.begin(), currLine.end(), ','), currLine.end()); // removes commas
            cout << currLine << "\n";
            myList.insert(currLine);
        }

    }
    
 

    cout << "\nConsole\n";
    myList.display();
	
    
    




}

