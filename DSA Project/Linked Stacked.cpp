#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Node {

  int data;
  Node *next;
};

class Stack{
  private:
    Node* top;

  public:
    Stack(){
      top = nullptr;
    }

    bool empty(){
      if(top == nullptr){
        return true;
      }else {
        return false;
      }
    }

    void push(int num){
      Node* temp;
      temp = new Node;
      temp->data = num;

      if(top == nullptr){
        top = temp;
        temp->next = nullptr;
      }
      else {
        temp->next = top;
        top = temp;
      }
    }

    int pop(){
      int num;
       Node* temp;

       if(!empty()){
        num = top->data;
        temp = top;
        top = top->next;
        delete temp;
        return num;
       } 
       else{
        cout << "Stack is EMPTY!";
        return;
       }
    }
};

int main(){
<<<<<<< Updated upstream
  Stack stk;

  vector<int> number;
    // Open and reads the file
    ifstream input_file("text_input.txt");                      

    int i;
    // Adds value until no value is available to read
    while (input_file >> i) {                       

        // Value "i" added at vector end with push_back function
        number.push_back(i);                                    
    }

    for(int i=0; i < 4; i++){
      stk.push(number[i]);
    }

    
=======
  
>>>>>>> Stashed changes
}