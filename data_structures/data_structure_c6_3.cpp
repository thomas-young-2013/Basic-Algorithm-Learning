#include <iostream>
#include <fstream>
#include <memory.h>
#include <iterator>
#include <map>

using namespace std;

const int N = 500;
struct Node {
    int layer;
    string name;
    int childrenNum;
    map<string, int> mappings;
    Node *children[N];
    Node(string name_t="", int layer_t=0) {
        name = name_t;
        layer = layer_t;
        childrenNum=0;
    }
};

Node *root;

void add(string str) {
    str.push_back('\\');
    int last=0, len=str.length(), i=0;
    Node* tmp = root;
    while(i<len) {
        if (str[i]=='\\') {
            string dirName = str.substr(last, i-last);
            Node *temp;
            if (tmp->mappings[dirName] == 0) {
                temp = new Node(dirName, tmp->layer+1);
                tmp->children[++tmp->childrenNum] = temp;
                tmp->mappings[dirName] = tmp->childrenNum;
            } else {
                temp = tmp->children[tmp->mappings[dirName]];
            }
            tmp = temp;
            last = i+1;
        }
        i++;
    }
}

void listDirs(Node *node) {
    if (node->childrenNum > 0) {
        for (map<string, int>::iterator i=node->mappings.begin(); i!=node->mappings.end(); i++) {
            int layer = node->layer;
            string result = "";
            for (int j=0; j<layer; j++) result.push_back(' ');
            result+=i->first;
            cout << result << endl;
            listDirs(node->children[i->second]);
        }
    }
}

int main() {
    // ifstream cin;
    // cin.open("C:\\Users\\Administrator\\Desktop\\in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    int n;
    string str;
    cin >> n;
    root = new Node("root", 0);
    while(n--) {
        cin >> str;
        add(str);
    }
    // list the constructure of this directory.
    listDirs(root);
    return 0;
}
