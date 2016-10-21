#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 10000;

string data[N];

bool isPre(const string &a, const string &b) {
    int lenA = a.length(), lenB = b.length();
    int i=0;
    while(i<lenA && i<lenB) {
        if (a[i]!=b[i]) return false;
        i++;
    }
    return true;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> data[i];
        }
        sort(data, data+n);
        bool flag = false;
        for (int i=1; i<n;i++) {
            if (isPre(data[i-1], data[i])) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
	return 0;
}
