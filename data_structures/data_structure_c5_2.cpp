#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAXINT 0x7FFFFFFF
#define MAX 200

struct huffmanNode {
    int leftNode,rightNode,parent;
    int value;
} huffmanNodes[MAX * 2];

int traverseTree(int idx, int depth) {
    int sum = 0;
    int child = 0;
    if (huffmanNodes[idx - 1].leftNode) {
        sum += traverseTree(huffmanNodes[idx - 1].leftNode, depth + 1);
        child++;
    }
    if (huffmanNodes[idx - 1].rightNode) {
        sum += traverseTree(huffmanNodes[idx - 1].rightNode, depth + 1);
        child++;
    }
    if (!child) {
        sum = huffmanNodes[idx - 1].value * depth;
    }
    return sum;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int num;
        int result = 0, tt;
        scanf("%d",&tt);
        memset(huffmanNodes,0,sizeof(huffmanNodes));
        for (int i = 0; i < tt; i++) {
            scanf("%d",&num);
            huffmanNodes[i].value = num;
        }
        for (int i = tt; i < tt * 2 - 1; i++) {
            int min1 = MAXINT, min2 = MAXINT;
            int minIdx1 = -1, minIdx2 = -1;
            for (int j = 0; j < i; j++) {
                if (huffmanNodes[j].parent)
                    continue;
                if (huffmanNodes[j].value < min1) {
                    min2 = min1;
                    minIdx2 = minIdx1;
                    min1 = huffmanNodes[j].value;
                    minIdx1 = j;
                } else if (huffmanNodes[j].value < min2) {
                    min2 = huffmanNodes[j].value;
                    minIdx2 = j;
                }
            }
            huffmanNodes[minIdx1].parent = i;
            huffmanNodes[minIdx2].parent = i;
            huffmanNodes[i].value = min1 + min2;
            huffmanNodes[i].leftNode = minIdx1 + 1;
            huffmanNodes[i].rightNode = minIdx2 + 1;
        }
        for (int i = 0; i < tt * 2 - 1; i++) {
            if (!huffmanNodes[i].parent) {
                result = traverseTree(i + 1,0);
                break;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
