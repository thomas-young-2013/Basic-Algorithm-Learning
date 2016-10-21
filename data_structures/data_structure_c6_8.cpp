#include <iostream>
#include <fstream>
#include <set>
#include <memory.h>
using namespace std;

const int N = 50005;
int father[N];

int getRoot(int t) {
    if (father[t]==0) return t;
    else return father[t] = getRoot(father[t]);
    // else return getRoot(father[t]);
}

void join(int a, int b) {
    int fatherA = getRoot(a);
    int fatherB = getRoot(b);
    if (fatherA!=fatherB) father[fatherA] = fatherB;
}

bool isConnected(int a, int b) {
    return getRoot(a) == getRoot(b);
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);

    int n, m, cnt=1;
    while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        memset(father, 0, N*sizeof(int));
        int t1, t2, count=0;
        while(m--) {
            scanf("%d %d", &t1, &t2);
            if (isConnected(t1, t2) == false) {
                join(t1, t2);
            }
        }
        set<int> sorts;
        for (int i=1; i<=n; i++) {
            int root = getRoot(i);
            if (root == 0) {
                count++;
            } else {
                if (sorts.find(root) == sorts.end()) {
                    sorts.insert(root);
                }
            }
        }
        count+=sorts.size();
        printf("Case %d: %d\n", cnt++, count);
    }
	return 0;
}
