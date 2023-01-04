#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Linked List class
class LinkedList {
 public:
  LinkedList() : head_(NULL), tail_(NULL) {}

  // adds a new value to the beginning of the list
  void AddFirst(int value) {
    Node* new_node = new Node(value);
    if (IsEmpty()) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      new_node->next = head_;
      head_ = new_node;
    }
  }

  // removes the first value from the list and returns it
  int RemoveFirst() {
    if (IsEmpty()) {
      return -1;
    } else {
      int removed_value = head_->value;
      head_ = head_->next;
      if (IsEmpty()) {
        tail_ = NULL;
      }
      return removed_value;
    }
  }

  // returns a boolean indicating whether the list is empty
  bool IsEmpty() {
    return head_ == NULL;
  }

 private:
  // Node class for the linked list
  class Node {
   public:
    Node(int value) : value(value), next(NULL) {}
    int value;
    Node* next;
  };

  Node* head_;
  Node* tail_;
};

// Linked Stack class
class LinkedStack {
 public:
  LinkedStack() : list_() {}

  // adds a new value to the top of the stack
  void Push(int value) {
    list_.AddFirst(value);
  }

  // removes the top value from the stack and returns it
  int Pop() {
    return list_.RemoveFirst();
  }

  // returns the top value from the stack without removing it
  int Peek() {
    if (IsEmpty()) {
      return -1;
    } else {
      return list_.head_->value;
    }
  }

  // returns a boolean indicating whether the stack is empty
  bool IsEmpty() {
    return list_.IsEmpty();
  }

 private:
  LinkedList list_;
};

// main function
int main() {
  // create an empty stack
  LinkedStack stack;

  // read input file
  ifstream input_file("input.txt");
  string line;

  // process each line of the input file
  while (getline(input_file, line)) {
    // split the line into the operation and value
    size_t space_pos = line.find(' ');
    string operation = line.substr(0, space_pos);
    int value = stoi(line.substr(space_pos + 1));

    // perform the operation on the stack
    if (operation == "add") {
      stack.Push(value);
    } else if (operation == "delete") {
      stack.Pop();
    } else if (operation == "print") {
      // print the current state of the stack
      PrintStack(stack);
    }
  }

  return 0;
