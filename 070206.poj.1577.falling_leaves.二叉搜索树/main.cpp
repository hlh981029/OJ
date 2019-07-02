#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node {
    char data;
    node *left, *right;
    node() {
        left = right = NULL;
    }
    ~node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void insert(node *root, char data) {
    node *next = root, *current, *temp = new node();
    temp->data = data;
    while (next) {
        current = next;
        if (data > current->data) {
            next = current->right;
        } else {
            next = current->left;
        }
    }
    if (data > current->data) {
        current->right = temp;
    } else {
        current->left = temp;
    }
}

void preorder(node *root) {
    cout << root->data;
    if (root->left)
        preorder(root->left);
    if (root->right)
        preorder(root->right);
}

int main() {
    vector<string> nodes;
    string temp;
    while (cin >> temp) {
        if (temp != "*" && temp != "$") {
            nodes.push_back(temp);
        } else {
            node *root = new node();
            root->data = nodes[nodes.size() - 1][0];
            for (int i = nodes.size() - 2; i >= 0; i--) {
                for (int j = 0; j < nodes[i].length(); j++) {
                    insert(root, nodes[i][j]);
                }
            }
            preorder(root);
            cout << endl;
            delete root;
            nodes.clear();
            if (temp == "$") {
                break;
            }
        }
    }
}
