#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string dict[10000];
string data[10000];

bool is_similar(string str, string tmp) {
    int len_str = str.length();
    int len_tmp = tmp.length();
    if (abs(len_str - len_tmp) >= 2) return false;

    // replace one word. if same length.
    if (len_str == len_tmp) {
        int diff = 0;
        for (int i=0; i<len_str; i++) {
            if (str[i] != tmp[i]) diff++;
        }
        return (diff == 1);
    }

    // swap if necessary.
    if (len_str > len_tmp) {
        swap(str, tmp);
        swap(len_str, len_tmp);
    }

    // delete one word.
    bool flag = false;
    for (int i=0; i<len_tmp; i++) {
        string temp = tmp;
        temp.erase(i, 1);
        if (str == temp) {
            flag = true;
            break;
        }
    }
    if (flag) return true;
    else return false;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string str;
    int count = 0;
    while(cin >> str && str != "#") {
        dict[count++] = str;
    }

    while(cin >> str && str != "#") {
        bool flag = false;
        int cnt = 0;
        for (int i=0; i<count; i++) {
            // if it is in the dict.
            if (dict[i] == str) {
                flag = true;
                break;
            }

            // not in.
            if (is_similar(str, dict[i])) {
                data[cnt++] = dict[i];
            }
        }
        if (flag) cout << str << " is correct" << endl;
        else {
            cout << str << ":";
            for (int i=0; i<cnt; i++) cout << " " << data[i];
            cout << endl;
        }
    }
    return 0;
}
