#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        while (true) {
            if (val == current->value) {
                cout << "Value already exists in the tree." << endl;
                return;
            }
            if (val < current->value) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                else {
                    current = current->right;
                }
            }
        }
    }

    void breadthFirstTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->value << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }

    void reverseTraversal(Node* node) {
        if (node != nullptr) {
            reverseTraversal(node->right);
            cout << node->value << " ";
            reverseTraversal(node->left);
        }
    }
};

