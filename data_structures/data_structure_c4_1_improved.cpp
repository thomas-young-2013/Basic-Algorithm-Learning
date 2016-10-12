#include<iostream>
#include<string>
#include<set>
#include<fstream>
using namespace std;

const int  N = 50;
string data[N];

bool match(string a, string t) {
    int cnt1=0, cnt2=0;
    while(cnt1 < a.length() && cnt2 < t.length()) {
        if (t[cnt2] == '[') {
            bool flag = false;
            while(t[++cnt2] != ']') {
                if (t[cnt2] == a[cnt1]) flag = true;
            }
            if (!flag) return false;
        } else {
            if (a[cnt1] != t[cnt2]) return false;
        }
        cnt1++;
        cnt2++;
    }
    if (cnt1 == a.length() && cnt2 == t.length()) return true;
    return false;
}

string tolower(string t) {
    for (int i=0; i<t.length(); i++) {
        if (t[i] >= 'A' && t[i] <= 'Z') t[i] = t[i]-('A' - 'a');
    }
    return t;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin );
    string tempt;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> data[i];
    }
    cin >> tempt;
    for (int i=0; i<n; i++) {
        if (match(tolower(data[i]), tempt)) cout << i+1 << " " << data[i] << endl;
    }
    return 0;
}
