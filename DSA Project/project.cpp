#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node* left;
    Node* right;
};

//LINKED LIST CLASS
class LinkedList{
    private:
        int minimumValue;
        int maximumValue;
        int deleteValue;
        int foundTarget;
    public:
        Node* head;

        //CONSTRUCTOR
        LinkedList(){
            head = nullptr;
        }

        //FUNCTION TO STORE DELETED NUM IN A VAR
        void deletedValueFunc(int data){
            deleteValue = deleteNum(data);
        }

        //ADDS THE DATA TO THE FRONT OF LIST
        void add(int data) {
            head = new Node{data, head};
        }

        //FINDS THE MIN NUMBER IN THE LINKED LIST
        int minFind() {
            minimumValue = head->data;

            Node* current = head;
            while(current){
                if(current->data < minimumValue){
                    minimumValue = current->data;
                }
                current = current->next;
            }
            return minimumValue;
        }

        //FINDS THE MAX NUMBER IN THE LINKED LIST
        int maxFind() {
            maximumValue = head->data;

            Node* current = head;
            while(current){
                if(current->data > maximumValue){
                    maximumValue = current->data;
                }
                current = current->next;
            }
            return maximumValue;
            }

        //WRITES THE PROCESS TO OUTPUT.TXT FILE
        void writeToFile(){
            Node* temp = head;
            // Open the output file.
            ofstream fout("text_output.txt");

            // Write the list to the output file.
            fout << "list created" << endl;
            while (temp != nullptr) {
                cout << temp->data << " ";
                fout << "list added " << temp->data << endl;
                temp = temp->next;
            }
            fout << "Minimum value: " << minimumValue << endl;
            fout << "Maximum value: " << maximumValue << endl;
            fout << "List deleted : " << deleteValue << endl;

            if(!found){
                fout << "Not found" << endl;
            }else
            
            fout << "Search found : " << foundTarget << endl;
            print();
            fout.close();
        }

        //DELETE THE TARGET NUMBER
        int deleteNum(int value){

            if (head->data == value) {
                Node* new_head = head->next;
                int deleted_value = head->data;
                delete head;
                head = new_head;
                return deleted_value;
            }

            Node* temp = head;
            while (temp->next && temp->next->data != value) {
                temp = temp->next;
            }

            // DELETE IF NODE IS FOUND
            if (temp->next) {
                Node* temp = temp->next;
                int deleted_value = temp->data;
                temp->next = temp->next;
                delete temp;
                return deleted_value;
            }else {
                return 1;
            }
        }

        //SEARCH THE NUMBER THAT WANT TO BE SEARCH
        bool found;
        void search(int target){
            found = false;
            Node* current = head;
            while(current) {
                if(current->data == target){
                    //cout << "Target found: " << target;
                    foundTarget = target;
                    found = true;
                }
                current = current->next;
            }
        }

        //PRINTS THE CURRENT LINKED LIST AFTER PREVIOUS PROCESS
        void print(){
            Node* current = head;
            
            ofstream fout("text_output.txt", ios::app);
            while (current != nullptr) {

                fout << current->data << " ";
                current = current->next;
            }
        }
};

// LINKED STACK CLASS
class LinkedStack{
    private:
        int minimumValue;
        int maximumValue;
        int deleteValue;
        int foundTarget;
    public:
        Node* top;
        LinkedStack(){
            top = nullptr;
        }
        
        //PUSH THE NUMBER TO THE TOP OF STACK
        void push(int num){
            top = new Node{num, top};
        }

        //POPS THE TOP OF STACK
        int pop(){
            if(top == nullptr){
                return 0;
            }

            int target = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return target;
        }

        //DELETES OR POP THE TARGETED NUMBER FROM FILE INPUT
        void deleteNumber(int target){
            Node* current = top;
            Node* previous = nullptr;
            while (current != nullptr) {
                if (current->data == target) {
                    if (previous == nullptr) {
                        top = current->next;
                        deleteValue = target;
                    } else {
                        previous->next = current->next;
                        
                    }
                    delete current;
                    break;
                }
                previous = current;
                current = current->next;
                }
         }

        //APPENDS THE PROCESS TO OUTPUT.TXT FILE
        void writeToFile(){
            Node* temp = top;
            // Open the output file.
            ofstream fout("text_output.txt", ios::app);

            // Write the list to the output file.
            fout << "\nstack created" << endl;
            while (temp) {
                fout << "stack added " << temp->data << endl;
                temp = temp->next;
            }
            fout << "stack deleted : " << deleteValue << endl;
            print(fout);
            fout.close();
        }

        void print(ofstream& out) {
            // Write the values of all nodes in the stack to the output file.
            Node* current = top;
            while (current) {
                out << current->data << " ";
                current = current->next;
            }
        }

};

class BinarySearchTree {
 private:
  Node* root;


  Node* findMinNode(Node* node) {
    while (node->left) {
      node = node->left;
    }
    return node;
  }

  void deleteHelper(int data, Node*& node) {
    if (!node) {
      return;
    }

    if (data < node->data) {
      deleteHelper(data, node->left);
    } else if (data > node->data) {
      deleteHelper(data, node->right);
    } else {
      // Case 1: No children
      if (!node->left && !node->right) {
        delete node;
        node = nullptr;
      }
      // Case 2: One child
      else if (!node->left) {
        Node* temp = node;
        node = node->right;
        delete temp;
      } else if (!node->right) {
        Node* temp = node;
        node = node->left;
        delete temp;
      }
      // Case 3: Two children
      else {
        Node* temp = findMinNode(node->right);
        node->data = temp->data;
        deleteHelper(temp->data, node->right);
      }
    }
  }

  void inorderHelper(Node* node, ofstream& output) {
    if (!node) {
      return;
    }

    inorderHelper(node->left, output);
    output << node->data << " ";
    inorderHelper(node->right, output);
  }

 public:
  BinarySearchTree() : root(nullptr) {}

  void add(int data) {
    addHelper(data, root);
  }

  void deleteNode(int data) {
    deleteHelper(data, root);
  }

  void inorder() {
    // Open output file
    ofstream output("output.txt");
    if (!output) {
      cerr << "Error opening output file" << endl;
      return;
    }

    // Perform in-order traversal of the binary search tree and write data to output file
    inorderHelper(root, output);

    // Close output file
    output.close();
  }
};

int main() {
    LinkedList list;
    LinkedStack stack;
    BinarySearchTree bst;
    // OPEN INPUT FILE
        ifstream file("text_input.txt");

        string line;


        // READ AND STORE INPUT TO LINE
        while (getline(file,line)) {
            
            // STRING STREAM SEPERATES THE LINE, WORD BY WORD
            stringstream seperate(line);
            string operation;
            string subOperation;
            //THE FIRST WORD IS SAVED IN OPERATION AS THE 1ST PROCESS
            //THE SECOND WORD IS SAVED IN SUBOPERATION AS 2ND PROCESS
            seperate >> operation >> subOperation;
            
            //PROCESS STARTS
            if(operation == "list"){
                
                if (subOperation == "add") {
                    int value;
                    seperate >> value;
                    list.add(value);
                } 
                else if(subOperation == "min") {
                    list.minFind();
                    }
                else if(subOperation == "max") {
                    list.maxFind();
                }
                else if(subOperation == "delete"){
                    int value;
                    seperate >> value;
                    list.deletedValueFunc(value);
                }
                else if(subOperation == "search"){
                    int value;
                    seperate >> value;
                    list.search(value);
                }
            }
            
            if(operation == "stack"){
                if (subOperation == "add") {
                    int value;
                    seperate >> value;
                    stack.push(value);
                }else if(subOperation == "delete"){
                    int value;
                    seperate >> value;
                    stack.deleteNumber(value);
                }
            }

            if(operation == "bst"){
                if(subOperation == "add"){
                    int value;
                    seperate >> value;
                    
                }else if(subOperation == "delete"){
                    int value;
                    seperate >> value;
                }else if(subOperation == "inorder"){

                }
            }
        }

    file.close();
    list.writeToFile();
    stack.writeToFile();
    
    return 0;
}