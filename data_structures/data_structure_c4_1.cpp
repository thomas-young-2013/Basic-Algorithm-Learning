#include<iostream>
#include<string>
#include<set>
#include<fstream>
using namespace std;

const int  N = 50;
string data[N];
set<char> mappings[N];

string deal(string tmp) {
    int len = tmp.length();
    string result = "";
    int i=0, count=0;
    while(i<len) {
        if (tmp[i] != '[') {
            result.append(1, tmp[i]);
            i++;
        } else {
            i++;
            while(i<len && tmp[i] != ']') {
                mappings[count].insert(tmp[i++]);
            }
            count++;
            result.append(1, '[');
            i++;
        }
    }
    return result;
}

bool match(string a, string b) {
    if (a.length() != b.length()) return false;
    int count=0;
    for (int i=0; i<b.length(); i++) {
        if (b[i] == '[') {
            if (mappings[count].find(a[i]) == mappings[count].end()) return false;
            count++;
        } else {
            if (a[i] != b[i]) return false;
        }
    }
    return true;
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
    string tempt,tempt_t;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> data[i];
    }
    cin >> tempt;
    tempt_t = deal(tempt);

    for (int i=0; i<n; i++) {
        if (match(tolower(data[i]), tempt_t)) cout << i+1 << " " << data[i] << endl;
    }
    return 0;
}
