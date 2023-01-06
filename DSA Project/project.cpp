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
            while (temp) {
                fout << "stack added " << temp->data << endl;
                temp = temp->next;
            }
            fout << "Minimum value: " << minimumValue << endl;
            fout << "Maximum value: " << maximumValue << endl;
            fout << "stack deleted : " << deleteValue << endl;
            print();
            write(fout);
            fout.close();
        }


        void print() {
            // Print the values of all nodes in the stack.
            Node* current = top;
            while (current) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        void write(std::ofstream& out) {
            // Write the values of all nodes in the stack to the output file.
            Node* current = top;
            while (current) {
                out << current->data << std::endl;
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
            string operation;
            stringstream seperate(line);
            int value = 0;

            seperate >> operation;
            if(operation == "list"){
                string subOperation;
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
                    list.deletedValueFunc(value);
                }
                else if(subOperation == "search"){
                    seperate >> value;
                    list.search(value);
                }
            }else if(operation == "sortedList"){
                string subOperation;
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
                
            }
        }

    file.close();
    list.writeToFile();
    stack.writeToFile();
    stack.print();
    
    return 0;
}