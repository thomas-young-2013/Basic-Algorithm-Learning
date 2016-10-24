#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1000;
const int M = 26;
int rootNum=0, cnt=0;
string data[N];

struct Node {
    char data;
    Node *children[M];
    bool isEnd;
    int commonUsed;
    int childrenNum;
    Node(char d) {
        data = d;
        isEnd = false;
        childrenNum=commonUsed=0;
        for (int i=0; i<M; i++) children[i]=NULL;
    }
};

Node *root[M];

void buildTree() {
    for (int i=0; i<cnt; i++) {
        int len = data[i].length();
        Node *tmp;
        if (root[data[i][0]-'a']==NULL) {
            tmp = new Node(data[i][0]);
            root[data[i][0]-'a'] = tmp;
        } else {
            tmp = root[data[i][0]-'a'];
        }
        tmp->commonUsed++;

        for (int j=1; j<len; j++) {
            Node* temp=tmp->children[data[i][j]-'a'];
            if (temp==NULL) {
                tmp->childrenNum++;
                tmp->children[data[i][j]-'a'] = new Node(data[i][j]);
                temp = tmp->children[data[i][j]-'a'];
            }
            tmp = temp;
            tmp->commonUsed++;
            if (j==len-1) tmp->isEnd=true;
        }
    }
}

string getUniquePrefix(const string &str) {
    Node *temp = root[str[0]-'a'];
    int len=str.length(), index;
    if (temp->commonUsed == 1) return str.substr(0, 1);

    if (temp->childrenNum > 1) index = 0;
    for (int i=1; i<len; i++) {
        if (temp->children[str[i]-'a']->childrenNum>1) {
            index = i;
        }
        temp=temp->children[str[i]-'a'];
        if (temp->commonUsed > 1) index=i;
    }
    return str.substr(0, index+2);
}

int main() {
    /*ifstream cin;
    cin.open("/home/thomas/Downloads/in.txt");
    ofstream cout;
    cout.open("/home/thomas/Downloads/out1.txt");*/
    cnt=0;
    while(cin >> data[cnt]) { cnt++;}
    buildTree();
    for (int i=0; i<cnt; i++) {
        cout << data[i] << " " << getUniquePrefix(data[i]) << endl;
    }
    return 0;
}
