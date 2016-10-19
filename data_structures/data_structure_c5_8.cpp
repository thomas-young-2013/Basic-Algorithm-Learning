#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
    Node(char d, Node* l=NULL, Node* r=NULL) {
        data = d;
        left = l;
        right = r;
    }
};

void build(Node *& root, string pre, int s1, int e1, string in, int s2, int e2) {
    if (s1 < e1 && s2 < e2) {

        // find the root.
        int rootIndex;
        for(int i=s2; i<e2; i++) {
            if (in[i] == pre[s1]) {
                rootIndex = i;
                break;
            }
        }

        root = new Node(in[rootIndex]);

        build(root->left, pre, s1+1, s1+rootIndex-s2+1, in, s2, rootIndex);

        build(root->right, pre, s1+rootIndex-s2+1, e1, in, rootIndex+1, e2);
    }
}

void postTraverse(Node *node) {
    if (node != NULL) {
        postTraverse(node->left);
        postTraverse(node->right);
        cout << node->data;
    }
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string pre, in;
    while(cin >> pre) {
        cin >> in;
        Node *root = NULL;
        build(root, pre, 0, pre.length(), in, 0, in.length());
        postTraverse(root);
        cout << endl;
    }
	return 0;
}
