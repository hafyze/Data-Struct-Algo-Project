#include <iostream>

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

  void inorderHelper(Node* node) {
    if (!node) {
      return;
    }

    inorderHelper(node->left);
    cout << node->data << " ";
    inorderHelper(node->right);
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
    inorderHelper(root);
    cout << endl;
  }
};

int main() {
  BinarySearchTree bst;
  bst.add(30);
  bst.add(50);
  bst.add(20);
  bst.add(10);
  bst.deleteNode(30);

  bst.inorder();  // Output: 3 4 5 7 10

  return 0;
}
