#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    Node *left_child;
    Node *right_child;
    int data;
    Node(int d, Node* left=NULL, Node* right=NULL) {
        data = d;
        left_child = left;
        right_child = right;
    }
};

void preorder_traverse(Node *tmp) {
    if (tmp != NULL) {
        cout << " " << tmp->data;
        preorder_traverse(tmp->left_child);
        preorder_traverse(tmp->right_child);
    }
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int num;
    cin >> num;
    Node *root = new Node(num);
    while(cin >> num) {
        Node *tmp = root;
        while(tmp != NULL) {
            if (num < tmp->data) {
                if (tmp->left_child == NULL) {
                    tmp->left_child = new Node(num);
                    break;
                } else {
                    tmp = tmp->left_child;
                }
            }
            if (num > tmp->data) {
                if (tmp->right_child == NULL) {
                    tmp->right_child = new Node(num);
                    break;
                } else {
                    tmp = tmp->right_child;
                }
            }
            if (num == tmp->data) break;
        }
    }
    // pre-order traverse.
    cout << root->data;
    preorder_traverse(root->left_child);
    preorder_traverse(root->right_child);
    cout << endl;

    // ignore the memory free.
    return 0;
}
