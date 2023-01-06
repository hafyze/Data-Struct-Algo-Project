#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int value;
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

        LinkedList(){
            head = nullptr;
        }

        void add(int value) {
            // Add a new node with the value to the front of the list.
            head = new Node{value, head};             
        }

        int minFind() {
            minimumValue = head->value;

            Node* current = head;
            while(current){
                if(current->value < minimumValue){
                    minimumValue = current->value;
                }
                current = current->next;
            }
            return minimumValue;
        }


        int maxFind() {
            maximumValue = head->value;

            Node* current = head;
            while(current){
                if(current->value > maximumValue){
                    maximumValue = current->value;
                }
                current = current->next;
            }
            return maximumValue;
            }

        void readFromFile(){
            // Open input file.
            ifstream file("text_input.txt");

            // Read operation from  input file.
            string operation;

            int value;
            while (file >> operation) {
                
                if (operation == "listAdd") {
                    file >> value;
                    add(value);
                } 
                else if(operation == "min") {
                    minFind();

                }
                else if(operation == "max") {
                    maxFind();
                }
                else if(operation == "delete"){
                    file >> value;
                    deleteNum(value);
                }
                else if(operation == "search"){
                    file >> value;
                    search(value);
                }
            }
            file.close();
        }

        void writeToFile(){
            Node* current = head;
            // Open the output file.
            ofstream fout("text_output.txt");

            // Write the list to the output file.
            fout << "list created" << endl;
            while (current) {
                fout << "list added " << current->value << endl;
                current = current->next;
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

        void deleteNum(int value){
            // Special case for the head node.
            if (head->value == value) {
                Node* new_head = head->next;
                delete head;
                head = new_head;
                return;
            }

            Node* current = head;
            while(current->next && current->next->value != value){
                current = current->next;
            }

            if(current->next) {
                Node* temp = current->next;
                current->next = temp->next;
                deleteValue = temp->value;
                delete temp;
            }
        }

        bool found;
        void search(int target){
            found = false;
            Node* current = head;
            while(current) {
                if(current->value == target){
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

                fout << current->value << " ";
                current = current->next;
            }
        }
};

int main() {
    LinkedList list;

    list.readFromFile();

    list.writeToFile();
    

    return 0;
}