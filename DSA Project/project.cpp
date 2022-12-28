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

void sortLinkedList(vector<int>& number, int size){     //Function to sort link list

    for(int i = 0; i < size - 1; i++){          //Loop entire array
        int min = i;

        for(int j = i+1; j < size; j++){        //Loops the to find minimum element
            if(number[j] < number[min]) {
                min = j;
            }
        }

        if(min != i){
            swap(number[i], number[min]);
        }
    }
}

void displaySortedLinkedList(vector<int>& number, int size){
    
    for(int i = 0; i < size; i++){
        cout << "Number " << i+1 
             << ": " << number[i] << " ";
    }
}

int main(){
    vector<int> number;
    ifstream input_file("text_input.txt");


    int i;
    while (input_file >> i) {
        number.push_back(i);
    }

    int size = number.size();

    for(i=0; i<number.size(); i++){
        cout << number[i] << endl;

        if(number[i] == 0){
            break;
        }
    }
    input_file.close();                         //Closes the file

    sortLinkedList(number, size);               //Call function to sort linked list
    displaySortedLinkedList(number, size);      //Call function to display sorted linked list
    

    return 0;
}