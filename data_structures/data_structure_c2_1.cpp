#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check(string t) {
    int n = t.length();
    if (n <= 1) return true;
    for (int i=1; i < n; i++) {
        if (t[0]!=t[i]) return false;
    }
    return true;
}

int main() {
    int n, count=1;
    // ifstream in;
    // in.open("/home/thomas/Downloads/in1.txt");

    while(cin >> n && n != 0) {
        if (count != 1) cout << endl;

        string str;
        cin >> str;
        cout << "Test case #" << count++ << endl;
        // check the special case.
        if (check(str)) {
            for (int i=2; i<=n; i++) {
                cout << i << " " << i << endl;
            }
        } else {
            for (int i=2; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    if (i%j != 0) continue;

                    int k=j;
                    string tmp = str.substr(0,j);
                    while(k < i) {
                        if (str.substr(k, j) != tmp) break;
                        k += j;
                    }
                    if (k >= i) {
                        cout << i << " " << i/j << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
