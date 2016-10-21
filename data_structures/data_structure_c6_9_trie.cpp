#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

struct Node {
    struct Node *next[10];
    int isCover, isEnd;
};

int ok;

void clean(Node *p) {
    memset(p->next, 0, sizeof(p->next));
    p->isCover = p->isEnd = 0;
}

void insert(char *str, Node *root) {
    Node *p = root;
    int id;
    while(*str){
        id = *str - '0';
        if(p->next[id] == NULL){
            p->next[id] = (Node *)malloc(sizeof(Node));
            clean(p->next[id]);
        }
        p = p->next[id];
        if(p->isEnd) ok = 0;
        ++p->isCover;
        ++str;
    }
    if(p->isCover > 1) ok = 0;
    p->isEnd = 1;
}

void DELETE(Node *p) {
    for (int i = 0; i < 10; ++i)
        if(p->next[i]) DELETE(p->next[i]);
    free(p);
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int t, n;
    char str[12];
    scanf("%d", &t);
    while(t--) {
        Node *root = (Node *)malloc(sizeof(Node));
        scanf("%d", &n);
        clean(root); ok = 1;
        while(n--){
            scanf("%s", str);
            if(ok) insert(str, root);
        }
        printf(ok ? "YES\n" : "NO\n");
        DELETE(root);
    }
	return 0;
}
