#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

/* using kmp algorithm.
 **/
void get_next(const string T, int next[]) {
    int len = T.length();
    int i, k;
    next[0] = 0;
    for (i = 1; i < len; ++i) {
        k = next[i-1];
        while (T[i] != T[k] && k != 0) k = next[k-1];
        if (T[i] == T[k]) next[i] = k+1;
        else next[i] = 0;
    }
}


const int N = 1000000;
char str[N];
int Next[N];

int main() {
    while(true) {
        scanf("%s", str);
        string tmp(str);
        if (tmp == ".") break;

        get_next(tmp, Next);
        int n = tmp.length();
        int m = Next[n-1];
        if (n%(n-m) == 0) cout << n/(n-m) << endl;
        else cout << 1 << endl;
    }
    return 0;
}
