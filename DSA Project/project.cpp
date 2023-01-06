#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList{
    private:
        int minimumValue;
        int maximumValue;
        int deleteValue;
        int foundTarget;
    public:
        Node* head;

        void deletedValueFunc(int data){
            deleteValue = deleteNum(data);
        }

        LinkedList(){
            head = nullptr;
        }

        void add(int data) {
            // Add a new node with the value to the front of the list.
            head = new Node{data, head};
        }

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

        int deleteNum(int value){
            // Special case for the head node.
            if (head->data == value) {
                Node* new_head = head->next;
                int deleted_value = head->data;
                delete head;
                head = new_head;
                return deleted_value;
            }

                // Find the node before the one we want to delete.
            Node* temp = head;
            while (temp->next && temp->next->data != value) {
                temp = temp->next;
            }

            // Idelete if node found
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

        void print(){
            Node* current = head;
            
            ofstream fout("text_output.txt", ios::app);
            while (current != nullptr) {

                fout << current->data << " ";
                current = current->next;
            }
        }
};

class LinkedStack{
    private:
        Node* top;
        int minimumValue;
        int maximumValue;
        int deleteValue;
        int foundTarget;
    public:
        LinkedStack(){
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
                return -1;
            }
        }

        int minFind() {
            minimumValue = top->data;

            Node* current = top;
            while(current){
                if(current->data < minimumValue){
                    minimumValue = current->data;
                }
                current = current->next;
            }
            return minimumValue;
        }


        int maxFind() {
            maximumValue = top->data;

            Node* current = top;
            while(current){
                if(current->data > maximumValue){
                    maximumValue = current->data;
                }
                current = current->next;
            }
            return maximumValue;
            }

        void writeToFile(){
            Node* temp = top;
            // Open the output file.
            ofstream fout("text_output.txt", ios::app);

            // Write the list to the output file.
            fout << "\nstack created" << endl;
            while (temp != nullptr) {
                cout << temp->data << " ";
                fout << "stack added " << temp->data << endl;
                temp = temp->next;
            }
            fout << "Minimum value: " << minimumValue << endl;
            fout << "Maximum value: " << maximumValue << endl;
            fout << "stack deleted : " << deleteValue << endl;
            print();
            fout.close();
        }


        void print(){
            Node* current = top;
            
            ofstream fout("text_output.txt", ios::app);
            while (current != nullptr) {

                fout << current->data << " ";
                current = current->next;
            }
        }
};

int main() {
    LinkedList list;
    LinkedStack stack;
    // Open input file.
        ifstream file("text_input.txt");

        // Read operation from  input file.
        string line;


        int value = 0;
        while (getline(file,line)) {
            string operation;
            string subOperation;

            stringstream seperate(line);

            seperate >> operation;
            if(operation == "list"){
                seperate >> subOperation;
                if (subOperation == "add") {
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
                    seperate >> value;
                    cout << value;
                    list.deletedValueFunc(value);
                }
                else if(subOperation == "search"){
                    seperate >> value;
                    list.search(value);
                }
            }
            seperate >> operation;
            if(operation == "sortedList"){
                seperate >> subOperation;
                if (subOperation == "add") {
                    seperate >> value;
                    stack.push(value);
                } 
                else if(subOperation == "min") {
                    stack.minFind();
                    }
                else if(subOperation == "max") {
                    stack.maxFind();
                }
                else if(subOperation == "delete"){
                    seperate >> value;
                    cout << value;
                    stack.pop();
                }
            }
        }

    file.close();
    list.writeToFile();
    stack.writeToFile();
    
    return 0;
}