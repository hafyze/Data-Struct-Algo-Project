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

void sortLinkedList(const vector<int>& number, int size){
    // for(int i : number){
    //     cout << i << " ";
    // }
    // cout << endl;
    int min = 0, max;
    
    // for(int i=0; i<number.size(); i++){
    //     if(number[i] < number){

    //     }

    // }
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
    input_file.close();                     //Closes the file

    sortLinkedList(number, size);                  //Call function to sort linked list

    return 0;
}