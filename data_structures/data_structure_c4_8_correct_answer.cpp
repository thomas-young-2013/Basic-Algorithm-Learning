#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 26;

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string cipher, plain;
    cin >> cipher >> plain;
    int cnt_ci[N] = {0};
    int cnt_pl[N] = {0};
    int len_ci = cipher.length();
    if (len_ci != plain.length()) {
        cout << "N0" << endl;
        return 0;
    }

    for (int i=0; i<len_ci; i++) {
        cnt_ci[cipher[i] - 'A']++;
        cnt_pl[plain[i] - 'A']++;
    }

    sort(cnt_ci, cnt_ci+N);
    sort(cnt_pl, cnt_pl+N);
    bool flag = false;
    for(int i=0; i<N; i++) {
        if(cnt_ci[i]!=cnt_pl[i]) {
            flag = true;
            break;
        }
    }

    if (!flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
