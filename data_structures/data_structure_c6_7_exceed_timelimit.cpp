#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

string str;
int num = 0, formalHeight=0, binaryHeight=0;
const int N = 100;

struct Node {
    Node *children[N];
    int childrenNum, layer;
    Node(int l=0) {layer = l; childrenNum=0;}
    void addChild(Node *node) {
        /*if (childrenNum !=0 && childrenNum%N == 0) {
            // Node *newChildren[childrenNum+N];
            // Node **newChildren = (Node*)new Node*[childrenNum+N];
            for (int i=0; i<childrenNum; i++) {
                newChildren[i] = children[i];
            }
            Node ** tmp = children;
            children = newChildren;
            delete[] tmp;
        }
        children[childrenNum++] = node;*/
        children[childrenNum++] = node;
    }
};

struct BNode {
    int layer;
    BNode *left;
    BNode *right;
    BNode(int layer_t=0, BNode *l=NULL, BNode *r=NULL) {
        layer = layer_t;
        left = l;
        right = r;
    }
};

inline void buildBinaryTree(Node* &node, BNode * &bnode) {
    if (node->childrenNum > 0) {
        bnode->left = new BNode(bnode->layer+1);
        int temp = node->childrenNum, i=0;
        buildBinaryTree(node->children[i], bnode->left);
        BNode *tmp = bnode->left;
        i++;
        while(i<temp) {
            tmp->right = new BNode(tmp->layer+1);
            buildBinaryTree(node->children[i++], tmp->right);
            tmp = tmp->right;
        }
        if (tmp->layer > binaryHeight) binaryHeight = tmp->layer;
    }
}

void build(string s) {
    stack<Node*> stacks;
    Node *root = new Node();
    stacks.push(root);
    // building tree.
    int len = s.length();
    for (int i=0; i<len; i++) {
        if (str[i]=='d') {
            Node *top=stacks.top();
            Node *tmp=new Node(top->layer+1);
            if (tmp->layer > formalHeight) formalHeight = tmp->layer;
            // top->children[top->childrenNum++] = tmp;
            top->addChild(tmp);
            stacks.push(tmp);
        } else {
            stacks.pop();
        }
    }
    // building binary tree.
    BNode *broot = new BNode(0);
    buildBinaryTree(root, broot);
    // ignore the deallocation of memory.
}

int main() {
    ifstream cin;
    cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int n = 1;
    while(cin >> str && str != "#") {
        // calculate the former tree's depth.
        int len = str.length();
        formalHeight = binaryHeight = 0;

        // build the binary tree.
        Node *root = new Node();
        build(str);
        printf("Tree %d: %d => %d\n", n++, formalHeight, binaryHeight);
    }
    return 0;
}
