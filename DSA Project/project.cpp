#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int SIZE = 100;

struct ListNode{
    int data;
    ListNode* next;
};

int main(){
    ifstream input_file("text_input.txt");
    string line;

    while (getline(input_file, line)) {
        cout << line << endl;
    }
    input_file.close();

    return 0;
}