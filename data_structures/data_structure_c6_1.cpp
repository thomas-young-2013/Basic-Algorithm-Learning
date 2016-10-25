#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int N = 30;
int n, result=1;
char pre[N];
char post[N];

int getCombinationNum(int num) {
    if (num==0) return 1;
    unsigned int tmp = 1;
    for (int i=0; i<num;i++) tmp *= (n-i);
    for (int i=1; i<=num; i++) tmp/=i;
    return tmp;
}

void computeBranch(int s1, int e1, int s2, int e2) {
    if (s1 == e1 && s2 == e2) return;
    int i = s1+1, j = s2, count = 0;
    while(j < e2) {
        int len = 0;
        while(post[j+len] != pre[i] && j+len<e2) len++;

        count++;
        computeBranch(i, i+len, j, j+len);

        i = i+1+len;
        j = j+len+1;
    }
    result *= getCombinationNum(count);
}

int main() {
    // freopen("/home/thomas/Downloads/in.txt", "r", stdin);

    while(true) {
        scanf("%d", &n);
        if (n == 0) break;

        result = 1;
        scanf("%s%s", pre, post);
        int len = strlen(pre);
        computeBranch(0, len-1, 0, len-1);
        cout << result << endl;
    }
    return 0;
}
