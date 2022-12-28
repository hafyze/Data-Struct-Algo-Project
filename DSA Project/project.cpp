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

void sortLinkedList(vector<int>& number, int size){               //  Function to sort link list  //

    for(int i = 0; i < size - 1; i++){                           // Loop entire array
        int min = i;

        for(int j = i+1; j < size; j++){                         // Loops the to find minimum element
            if(number[j] < number[min]) {
                min = j;
            }
        }

        if(min != i){
            swap(number[i], number[min]);
        }
    }
}                                                               //         END           //


void displaySortedLinkedList(vector<int>& number, int size){    //  DISPLAY SORTED LIST FUNCTION  //

    for(int i = 0; i < size; i++){
        cout << "Number " << i+1 
             << ": " << number[i] << " ";
    }                                                           //               END              //
}


int main(){                                                     //  MAIN SECTION   //

    vector<int> number;
    ifstream input_file("text_input.txt");                      // Open and reads the file

    int i;
    while (input_file >> i) {                  
        number.push_back(i);                                    // Using vector function to declare variable in respective index
    }

    int size = number.size();                                   // Storing the size of array tu variable
    for(i=0; i<number.size(); i++){                             // Loop to display declared variable received by the file
        cout << number[i] << endl;

        if(number[i] == 0){
            break;
        }
    }
    input_file.close();                                         // Closes the file

    sortLinkedList(number, size);                               // Call function to sort linked list
    displaySortedLinkedList(number, size);                      // Call function to display sorted linked list
    
    
    return 0;
}                                                               //               END                  //