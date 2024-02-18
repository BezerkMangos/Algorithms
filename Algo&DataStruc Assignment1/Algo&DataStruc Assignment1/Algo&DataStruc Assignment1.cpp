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
    /// 
    /// Doubles as a display and update just call it again and it will run through the list
    /// </summary>
    void display() { 
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << "\n";
            current = current->next;
        }
    }


};


#pragma region Bubble Sort

// Sorts array by bubble sort method, takes two elements
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /*
    Time Complexity 
    Best case for Bubble sort is if the elements are in order then it would be just O(n)
    This would come if all elements are in order then the sort wouldnt have a need to swap anything and go over it again.

    Worst case would be if elements were in reverse order, this would lead to a time complexity of O(n^2)
    This is because the sort would have to swap every single adjacent element multiple times making it O(n^2)
    
    */
}

// Displays Array by running through the length of it.
void display(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


#pragma endregion




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

    myList.display();


    //Showing sorting function I couldnt get working with the text but know how to use.
    int arrary[] = { 10,20,1,24,2512,312,4,12,23,51,25,56,5,12,312,33,125,3,14,123,12,31 };
    int size = sizeof(arrary) / sizeof(arrary[0]); // Gets size of array

    display(arrary,size); // Prints unsorted array
    sort(arrary,size); // Sorts the array
    display(arrary,size); // Prints sorted array
    



}
