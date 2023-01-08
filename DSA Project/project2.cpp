// *********************************************************  
// Program: YOUR_FILENAME.cpp  
// Course: DCP5301 DSA      
// Tutorial section: TL4L
// Trimester: 2210
// Member_1: 1211201780 | Harith Iskandar Bin Mat Radzuan  | 1211201780@studen.mmu.edu.my  | 019-3986273
// Member_2: 1211201542 | Mohamad Zulhafiz Bin Mohd Jaafar | 1211201542@student.mmu.edu.my | 013-4336103
// Member_3: 1211203380 | Muhammad AFiq Bin Muhammad Nizam | 1211203380@student.mmu.edu.my | 012-6249316
// Member_4: 1211200183 | Muhammad Yazid Bin Shariful Azhar| 1211200183@student.mmu.edu.my | 019-4716930     
// *********************************************************
// Task Distribution
// Member_1:  
// Member_2:  Make the code for linked list and retrieving the input from the file and display it to the output of another file 
// Member_3:  Make the code for Linked Stack
// Member_4:  Make the code for Binary Search Tree
// *********************************************************

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//struct declared for all data structure
struct Node {
    int data;
    Node* next;
    Node* left;
    Node* right;

};

//LINKED LIST CLASS
class LinkedList{
    private:
        //DECLARED TO PRINT TO THE OUTPUT
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
                // WHEN CURRENT DATA IS LOWER THAN MINIMUM,
                // IT ASSIGNS TO MINIMUM VARIABLE
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

            //WRITES UPON THE INPUT FILE OPERATION
            fout << "list created" << endl;
            //LOOP TO ACCESS ALL THE LIST ADDED
            while (temp != nullptr) {
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

        //  DISPLAY SORTED LIST FUNCTION  //Harith
        void displaySortedList(int number, int size){
            cout<<"Sorted Linked List" << endl;

            for (int i=0; i<size; i++){
                cout<<" "<< number;
            }
            cout << "\n";
        }

        // FUNCTION TO DISPLAY CURRENT Vector
        void displayAssignVariable(int number, int size){
            for(int i=0; i<size; i++){
                cout << number << endl;
            }
        }

        //SEARCH THE NUMBER THAT WANT TO BE SEARCH
        bool found;
        void search(int target){
            found = false;
            Node* current = head;
            while(current) {
                if(current->data == target){
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
        
        //WRITES THE VALUE BY APPENDING TO THE OUTPUT FILE
        void print(ofstream& out) {
            Node* current = top;
            while (current) {
                out << current->data << " ";
                current = current->next;
            }
        }

};

//BINARY SEARCH TREE START
class BinarySearchTree {
    private:
        Node* root;
        int deletedValue;
    public:
        //CONSTRUCTOR TO INITALISE ROOT
        BinarySearchTree(){root=nullptr;}

        //FUNCTION THAT INSERTS THE NUM AT NODES BY TURN
        void insert(Node*& root, int num) {
            if (root == nullptr) {
                root = new Node{num, nullptr, nullptr};
                return;
            }
            if (num < root->data) {
                insert(root->left, num);
            } 
            else{
                insert(root->right, num);
            }
        }

        //DELETES THE TARGETED NUM/NODE
        int deleteNum(Node*& root, int num) {
            int deleteValue;
            if(root == nullptr){
                return -1;
            }

            if(num < root->data){
                return deleteNum(root->left, num);
            }
            else if(num > root->data){
                return deleteNum(root->right, num);
            }
            else if(root->left == nullptr){
                deleteValue = root->data;
                Node* temp = root;
                root = root->right;
                deleteValue = temp->data;
                delete temp;
                return deleteValue;
            }
            else if(root->right == nullptr){
                deleteValue = root->data;
                Node* temp = root;
                root = root->left;
                deleteValue = temp->data;
                delete temp;
                return deleteValue;
            }
            else{
                Node* minNode = root->right;

                while(minNode->left != nullptr){
                    minNode = minNode->left;
                    root->data = minNode->data;
                    return deleteNum(root->right, minNode->data);
                }
            }
            return deleteValue;
        }

        //TRAVERSE THE BINARY TREE INORDER WAY
        void inorder(Node* root) {
            if(root == nullptr){
                return;
            }
                inorder(root->left);
                //cout << root->data << " ";
                inorder(root->right);
        }

        //APPENDS THE OUTPUT TO THE FILE
        void writeToFile(int delNum){
            Node* temp;
            temp = root;
            // Write the list to the output file.
            ofstream fout("text_output.txt", ios::app);
            fout << "\nbst constructed" << endl;
            while(temp != nullptr){
                inorder(temp->left);
                fout << temp->data << " ";
                inorder(temp->right);
            }
            fout << "bst deleted " << delNum;
            fout.close();
        }
};

// SORTED LINKED LIST STARTS
class SortedLinkedList{
    private:
        Node* head;
        int deletedValue;
    public:
        SortedLinkedList(){
            head = nullptr;
        }

        //SET THE DELETED VALUE 
        void deletedValueFunc(int num){
            deletedValue = deleteNum(num);
        }

        //INSERTS THE NUMBER RETRIEVE FROM INPUT FILE
        void insert(int num){
            Node* ptr = new Node;
            ptr->data = num;
            ptr->next = nullptr;

            if(head == nullptr || head->data >= ptr->data) {
                ptr->next = head;
                head = ptr;
                return;
            }

            Node* temp = head;
             while (temp->next != nullptr && temp->next->data < ptr->data) {
                temp = temp->next;
            }

            ptr->next = temp->next;
            temp->next = ptr;
        }

        //DELETES NUMBER FROM INPUT FILE
        int deleteNum(int num) {
            Node* current = head;
            Node* previous = nullptr;
            int deleteVal;

            while (current != nullptr && current->data != num) {
                previous = current;
                current = current->next;
            }

            if (current == nullptr) {
                return -1;
            }

            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            deleteVal = current->data;
            delete current;
            return deleteVal;
        }

        //PRINTS THE CURRENT SORTED LINKED LIST
        void print(){
            Node* temp = head;
            
            ofstream fout("text_output.txt", ios::app);
            while(temp != nullptr) {
                fout << temp->data << " ";
                temp = temp->next;
            }
            fout << endl;
            fout.close();
        }

        //APPENDS THE OUTPUT TO FILE
        void writeToFile(){
            Node* temp;
            temp = head;

            ofstream fout("text_output.txt", ios::app);

            fout << "\nSorted list created" << endl;
            while (temp != nullptr) {
                fout << "list added " << temp->data << endl;
                temp = temp->next;
            }
            fout << "list deleted " << deletedValue << endl;
            print();
        }
};

int main() {
    LinkedList list;
    LinkedStack stack;
    BinarySearchTree bst;
    SortedLinkedList sll;

    Node* root;
    root = nullptr;

        // OPEN INPUT FILE
        ifstream file("text_input.txt");
        ofstream fout("output_text.txt", ios::app);
        string line;
        int deletedValue;


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
                //CONDITION IS RUN BASED ON SUBOPERATION STRING
                if (subOperation == "add") {
                    int value;
                    //INITIALISED THE VALUE OF SEPERATE 
                    seperate >> value;
                    //LIST OBJECT CALLS ADD FUNCTION TO INSERT VALUE RECEIVED
                    list.add(value);
                } 
                else if(subOperation == "min") {
                    //FINDS MINIMUM VALUE OF THE LIST
                    list.minFind();
                    }
                else if(subOperation == "max") {
                    //FINDS MAXIMUM VALUE OF THE LIST
                    list.maxFind();
                }
                else if(subOperation == "delete"){
                    //DELETES THE TARGET VALUE
                    int value;
                    seperate >> value;
                    list.deletedValueFunc(value);
                }
                else if(subOperation == "search"){
                    //SEARCH THE TARGET VALUE
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
                    bst.insert(root, value);
                }else if(subOperation == "delete"){
                    int value;
                    seperate >> value;
                    deletedValue = bst.deleteNum(root, value);
                }
                else if(subOperation == "inorder"){
                    bst.inorder(root);
                }
            }

            if(operation == "sortedList"){
                if(subOperation == "add"){
                    int value;
                    seperate >> value;
                    sll.insert(value);
                }
                else if(subOperation == "print"){
                    sll.print();
                }
                else if(subOperation == "delete"){
                    int value;
                    seperate >> value;
                    sll.deletedValueFunc(value);
                }
            }
        }
    //CLOSES THE INPUT FILE
    file.close();
    //CALLS TO WRITE THE OUTPUT TO THE FILE
    list.writeToFile();
    stack.writeToFile();
    bst.writeToFile(deletedValue);
    sll.writeToFile();

    return 0;
}