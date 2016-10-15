#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int N = 200;
string placement(string str, int t) {
    size_t len = str.length();
    for (int i=0; i<len; i++) {
        int index = str[i] - 'A' + t;
        index %= 26;
        str[i] = char('A' + index);
    }
    return str;
}

bool compare(string a, string b) {
    size_t len_a = a.length(), len_b = b.length();
    bool flags[N];
    for (int i=0; i<N; i++) flags[i] = false;
    for (int i=0; i<len_a; i++) {
        bool f = false;
        for (int j=0; j<len_b; j++) {
            if (a[i] == b[j] && flags[j] == false) {
                flags[j] = true;
                f = true;
                break;
            }
        }
        if (!f) return false;
    }
    return true;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string cipher, plain;
    cin >> cipher >> plain;

    bool flag = false;
    for (int i=0; i<=25; i++) {
        string tmp = placement(plain, i);
        if (compare(tmp, cipher)) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
