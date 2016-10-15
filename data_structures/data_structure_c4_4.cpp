#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int N = 1000000;
int Next[N];

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

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string str;
    while(cin >> str && str != ".") {
        int n = str.length();
        get_next(str, Next);
        int i = n;
        if (i%(i-Next[i-1]) == 0 && Next[i-1] != 0) {
            cout << i/(i - Next[i-1]) << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}
