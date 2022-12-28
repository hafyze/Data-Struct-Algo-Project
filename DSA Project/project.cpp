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
    string line;

    cout << "Size: " << SIZE << endl;

    int i;
    while (input_file >> i) {
        number.push_back(i);
    }
    input_file.close();

    return 0;
}