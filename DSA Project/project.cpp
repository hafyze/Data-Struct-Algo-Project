#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 100;

struct ListNode{
    int data;
    ListNode* next;

};

class LinkedList{
    private:
        ListNode* head;

    public:
    LinkedList(){
        head = nullptr;
    }

    ~LinkedList(){
        makeEmpty();
    }

    void insertFront(T& element) {
        ListNode* newNode = new ListNode;
        newNode->data = element;
        newNode->next = head;
        head = newNode;
    }

    void insertback(T& element) {
        ListNode* newNode = new ListNode;
        newNode->data = element;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
            return;
        }

        ListNode<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteFront(){
        if(head == nullptr){
            return;
        }

        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }

    bool search(T& target) {
        bool found = false;
        ListNode<T>* ptr = head;

        while(ptr != nullptr && !found){
            if(ptr->date == target) {
                found = true;
            }
            else {
                ptr = ptr->next;
            }
            return found;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void makeEmpty(){
        while(head != nullptr){
            ListNode<T>* ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    friend ostream& operator<< (ostream& os, LinkedList<T>& list) {
        ListNode<T>* ptr = list.head;

        while(ptr != nullptr){
            os << ptr->data << " ";
            ptr = ptr->next;
        }
        return os;
    }
};

//  Function to sort  list  //
void sortList(vector<int>& number, int size){            

    // Loop entire array
    for(int i = 0; i < size - 1; i++){                           
        int min = i;

        // Loops the to find minimum element
        for(int j = i+1; j < size; j++){                        
            if(number[j] < number[min]) {
                min = j;
            }
        }

        if(min != i){
            swap(number[i], number[min]);
        }
    }
}                                                               

//  DISPLAY SORTED LIST FUNCTION  //
void displaySortedList(vector<int>& number, int size){    

    cout << "\nSorted Linked list: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Number " << i+1 
             << ": " << number[i] << " " << endl;
    }                                                           
}

// FUNCTION TO DISPLAY CURRENT Vector
void displayAssignVariable(vector<int>& number, int size){
    for(int i=0; i<size; i++){                                  
        cout << number[i] << endl;
    }
}

 //  MAIN FUNCTION   //
int main(){                                                    

    vector<int> number;
    // Open and reads the file
    ifstream input_file("text_input.txt");                      

    int i;
    // Adds value until no value is available to read
    while (input_file >> i) {                       

        // Value "i" added at vector end with push_back function
        number.push_back(i);                                    
    }

    // Storing the size of array tu variable
    int size = number.size();                                   
    displayAssignVariable(number, size);

    // Closes the file
    input_file.close();                                         

    // Call function to sort list
    sortList(number, size);                    
    // Call function to display sorted list           
    displaySortedList(number, size);                     
    
    LinkedList listObj;

    for(int i=0; i<size; i++){
        listObj.insertFront(number[i]);
    }

    return 0;
} 