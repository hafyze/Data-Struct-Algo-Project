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
        int minimumValue;
        int maximumValue;
        int deleteValue;
        int foundTarget;
    public:
        Node* top;
        LinkedStack(){
            top = nullptr;
        }

        void push(int num){
            top = new Node{num, top};
        }

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

        void print(std::ofstream& out) {
            // Write the values of all nodes in the stack to the output file.
            Node* current = top;
            while (current) {
                out << current->data << " ";
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


        
        while (getline(file,line)) {
            
            stringstream seperate(line);
            string operation;
            string subOperation;
            seperate >> operation >> subOperation;

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
        }

    file.close();
    list.writeToFile();
    stack.writeToFile();
    
    return 0;
}