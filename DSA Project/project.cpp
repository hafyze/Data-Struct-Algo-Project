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

void sortLinkedList(int number[]){

}

int main(){
    int number[SIZE];
    ifstream input_file("text_input.txt");

    int i;
    while (input_file >> i) {
        cin >> number[i];
    }

    for(i=0; i<SIZE; i++){
        cout << number[i] << endl;

        if(number[i] == 0){
            break;
        }
    }

    input_file.close();         //Closes the file

    sortLinkedList(number);     //Call function to sort linked list

    return 0;
}