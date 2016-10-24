#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

string str;
int num = 0, formalHeight=0, binaryHeight=0;

struct Node {
    int layer;
    Node *left;
    Node *right;
    Node(int layer_t=0, Node *l=NULL, Node *r=NULL) {
        layer = layer_t;
        left = l;
        right = r;
    }
};

void build(const string &s) {
    stack<Node*> stacks;
    Node *root = new Node();
    stacks.push(root);
    // building tree.
    int len = s.length(), tmpHeight=0;
    for (int i=0; i<len; i++) {
        if (str[i]=='d') {
            ++tmpHeight;
            if (tmpHeight>formalHeight) formalHeight=tmpHeight;

            Node* top = stacks.top();
            Node* tmp;

            if (top->left == NULL) {
                tmp = new Node(top->layer+1);
                top->left = tmp;
            } else {
                tmp = top->left;
                // find the rightmost node.
                while(tmp->right!=NULL) {
                    tmp = tmp->right;
                }
                tmp->right = new Node(tmp->layer+1);
                tmp = tmp->right;
            }
            if (tmp->layer > binaryHeight) binaryHeight = tmp->layer;
            stacks.push(tmp);
        } else {
            --tmpHeight;
            stacks.pop();
        }
    }
    // ignore the deallocation of memory.
}

int main() {
    // ifstream cin;
    // cin.open("C:\\Users\\Administrator\\Desktop\\codes\\in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    // freopen("C:\\Users\\Administrator\\Desktop\\out1.txt", "w", stdout);
    int n = 1;
    while(cin >> str && str != "#") {
        // calculate the former tree's depth.
        int len = str.length();
        formalHeight = binaryHeight = 0;
        // build the binary tree.
        build(str);
        printf("Tree %d: %d => %d\n", n++, formalHeight, binaryHeight);
    }
    return 0;
}
