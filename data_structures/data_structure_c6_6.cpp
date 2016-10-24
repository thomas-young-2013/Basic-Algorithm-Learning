#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

struct Node {
    string name;
    int childrenNum;
    vector<Node*> children;
    vector<string> childrenName;
    Node(string name_t) {
        name = name_t;
        childrenNum=0;
    }
};

stack<Node*> stacks;
Node *root=NULL;
Node *lastNode;
bool isEnd; // end or not.
string searchStr;

void add(string str) {
    if (str == "{") {
        stacks.push(lastNode);
        return;
    }
    if (str == "}") {
        stacks.pop();
        return;
    }
    Node *top = stacks.top();
    Node *tmp = new Node(str);
    lastNode = tmp;
    top->children.push_back(tmp);
    top->childrenNum++;
    top->childrenName.push_back(str);
}

void searchTree(Node *node) {
    int len = node->childrenNum;
    if (len > 0) {
        int index = 0;
        bool flag=false;
        for (int i=0; i<len; i++) {
            if(node->childrenName[i] == searchStr) {
                index = i;
                flag = true;
                break;
            }
        }
        if (flag) {
            if (index==len-1) cout << "";
            else for (int i=index+1; i<len; i++) cout << node->childrenName[i];
            cout << endl;
            isEnd=true;
        } else {
            for (int i=0; i<len; i++) {
                if (!isEnd) searchTree(node->children[i]);
            }
        }
    }
}

void deallocate(Node *node) {
    if (node == NULL) return;
    if (node->childrenNum>0) {
        for (int i=0; i<node->childrenNum; i++) {
            deallocate(node->children[i]);
        }
    }
    delete node;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Downloads/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    int n;
    cin >> n;
    cin.get();
    while(n--) {
        char data[100];
        // init.
        while(!stacks.empty()) stacks.pop();
        deallocate(root);
        isEnd = false;

        lastNode=root=new Node("root");
        stacks.push(root);

        while(true) {
            cin.getline(data, 100, '\n');
            string str(data);
            if (str.length() == 0) break;
            add(str);

        }

        cin.getline(data, 100, '\n');
        searchStr = string(data);

        searchTree(root);
        if (!isEnd) cout << "No\n";

        cin.get();
        cin.get();
    }
    return 0;
}
