#include <iostream>
#include <fstream>
#include <string>

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
int Next[N];

int main() {
    int n, count=1;
    // ifstream cin;
    // cin.open("/home/thomas/Downloads/in.txt");

    while(cin >> n && n != 0) {
        if (count != 1) cout << endl;

        string str;
        cin >> str;
        cout << "Test case #" << count++ << endl;

        get_next(str, Next);
        for (int i=2; i <= n; i++) {
            if (i%(i-Next[i-1]) == 0 && Next[i-1] != 0) {
                cout << i << " " << i/(i - Next[i-1]) << endl;
            }
        }

    }
    return 0;
}
