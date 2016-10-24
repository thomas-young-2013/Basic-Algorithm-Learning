#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

const int N = 2005;

int father[N], rela[N];

int getFather(int x) {
    if (father[x] == -1) return x;
    int tmp = father[x];
    father[x] = getFather(father[x]);
    rela[x] = (rela[x]+rela[tmp])%2;
    return father[x];
}

bool isConnected(int x, int y) {
    return getFather(x) == getFather(y);
}

void merge(int x, int y) {
    int fatherX = getFather(x);
    int fatherY = getFather(y);
    father[fatherX] = fatherY;
    rela[fatherX] = (1+rela[x]+rela[y])%2;
}

int main() {
    // freopen("/home/thomas/Downloads/in.txt", "r", stdin);
    // ofstream cout;
    // cout.open("/home/thomas/Downloads/out1.txt");*/
    int t=0, n, num, inter, x, y;
    scanf("%d", &n);
    while(t++ < n) {
        scanf("%d %d", &num, &inter);
        // init.
        memset(father, -1, sizeof(int)*N);
        memset(rela, 0, sizeof(int)*N);
        bool flag = false;
        while (inter--) {
            scanf("%d %d", &x, &y);
            if (flag) continue;

            if (isConnected(x, y)) {
                if (rela[x] == rela[y]) flag = true;
            } else {
                merge(x, y);
            }
        }
        printf("Scenario #%d:\n", t);
        if (flag) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        if (t!=n) printf("\n");
    }
    return 0;
}
