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

        LinkedList() : head(nullptr){}

        void add(int value) {

            // Add a new node with the value to the front of the list.
            head = new Node{value, head};
        }

        // void print() {
        //     // Print the values of all nodes in the list.
        //     Node* current = head;
        //     while(current) {
        //         cout << "list added "<< current->value << endl;
        //         current = current->next;
        //     }
        //     cout << "Minimum value " << minimumValue << endl;
        //     cout << endl;
        // }

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


        void writeToFile(){
            // Open the output file.
            ofstream fout("text_output.txt");

            // Write the list to the output file.
            fout << "list created" << endl;
            while (head) {

                fout << "list added " << head->value << endl;
                head = head->next;
            }

            fout << "Minimum value: " << minimumValue << endl;
            fout << "Maximum value: " << maximumValue << endl;
            fout << "List deleted : " << deleteValue << endl;
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

        int search(int target){
            Node* current = head;
            while(current) {
                if(current->value == target){
                    cout << "Target found: " << target;
                }
            }
        }
};

int main() {
    LinkedList list;

    // Open input file.
    ifstream file("text_input.txt");

    // Read operation from  input file.
    string operation;

    int value;
    while (file >> operation) {
        
        if (operation == "add") {
        file >> value;
        list.add(value);
        } 
        else if(operation == "min") {
            list.minFind();

        }
        else if(operation == "max") {
            list.maxFind();
        }
        else if(operation == "delete"){
            file >> value;
            list.deleteNum(value);
        }
        else if(operation == "search"){
            file >> value;
            list.search(value);
        }
    }

    //list.print();
    list.writeToFile();
    file.close();

    return 0;
}