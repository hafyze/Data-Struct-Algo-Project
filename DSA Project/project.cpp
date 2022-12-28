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

int main(){
    vector<int> number;
    ifstream input_file("text_input.txt");

    //cout << "Size: " << SIZE << endl;

    int i;
    while (input_file >> i) {
        number.push_back(i);
    }
    for(i=0; i<number.size(); i++){
        cout << number[i] << endl;
    }
    input_file.close();

    return 0;
}