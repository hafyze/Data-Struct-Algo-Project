#include <iostream>
#include <fstream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
 private:
  Node* root;

  void addHelper(int data, Node*& node) {
    if (!node) {
      node = new Node(data);
      return;
    }

    if (data < node->data) {
      addHelper(data, node->left);
    } else {
      addHelper(data, node->right);
    }
  }

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
  BinarySearchTree bst;

  // Open input file
  ifstream input("input.txt");
  if (!input) {
    cerr << "Error opening input file" << endl;
    return 1;
  };

  // Read data
