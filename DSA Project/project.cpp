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

//  Function to sort link list  //
void sortLinkedList(vector<int>& number, int size){            

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
void displaySortedLinkedList(vector<int>& number, int size){    

    cout << "\nSorted Linked list: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Number " << i+1 
             << ": " << number[i] << " " << endl;
    }                                                           
}

// FUNCTION TO DISPLAY CURRENT Vector
void displayVariableAssign(vector<int>& number, int size){
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
    displayVariableAssign(number, size);

    // Closes the file
    input_file.close();                                         

    // Call function to sort linked list
    sortLinkedList(number, size);                    
    // Call function to display sorted linked list           
    displaySortedLinkedList(number, size);                     
    
    

    return 0;
}                                                               //               END                  //