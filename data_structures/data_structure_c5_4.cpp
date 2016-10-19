#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d, Node* l=NULL, Node* r=NULL) {
        data = d;
        left = l;
        right = r;
    }
};

const int N = 10000;
int in[N], post[N], nodeNum;

void build(Node *& root, int in[], int s1, int e1, int post[], int s2, int e2) {
    if (s1 < e1 && s2 < e2) {

        // find the root.
        int rootIndex;
        for(int i=s1; i<e1; i++) {
            if (in[i] == post[e2-1]) {
                rootIndex = i;
                break;
            }
        }

        root = new Node(in[rootIndex]);

        build(root->left, in, s1, rootIndex, post, s2, s2+rootIndex-s1);

        build(root->right, in, rootIndex+1, e1, post, s2+rootIndex-s1, e2-1);
    }
}

void preTraverse(Node *node) {
    if (node != NULL) {
        cout << " " << node->data;
        preTraverse(node->left);
        preTraverse(node->right);
    }
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    char tmp[N];
    gets(tmp);
    string inStr(tmp);
    gets(tmp);
    string postStr(tmp);

    int sum=0,cnt=0;
    // parse in string.
    int inLen = inStr.length();
    for (int i=0; i<inLen; i++) {
        if (inStr[i] != ' ') {
            sum = 10*sum + inStr[i]-'0';
        } else {
            in[cnt++] = sum;
            sum = 0;
        }
    }
    in[cnt++] = sum;
    nodeNum=cnt;
    sum=0,cnt=0;
    // parse post string..
    int postLen = postStr.length();
    for (int i=0; i<postLen; i++) {
        if (postStr[i] != ' ') {
            sum = 10*sum + postStr[i]-'0';
        } else {
            post[cnt++] = sum;
            sum=0;
        }
    }
    post[cnt++] = sum;
    Node *root = NULL;
    build(root, in, 0, nodeNum, post, 0, nodeNum);
    cout << root->data;
    preTraverse(root->left);
    preTraverse(root->right);
    cout << endl;
	return 0;
}
