#include<iostream>
#include<string>
#include<fstream>

using namespace std;

bool check(string str, size_t n) {
    int len = str.length();
    bool front_flag = false, back_flag = false;
    int i = n-1;
    while(i >= 0) {
        if (str[i] == '"') front_flag = true;
        i--;
    }
    i = n + 2;
    while(i < len) {
        if (str[i] == '"') back_flag = true;
        i++;
    }
    return front_flag && back_flag;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string sentence;
    bool flag = false;
    char d[200];
    while(gets(d)) {
        string sentence(d);
        int start = 0;
        while(start < sentence.length()) {
            if (flag == false) {
                size_t pos = sentence.find("/*", start);
                // find the special case..
                if (pos != string::npos && check(sentence, pos)) {
                    size_t pos_t = sentence.find("/*", pos+2);
                    if (pos_t == string::npos) pos = string::npos;
                    else pos = pos_t;
                }

                if (pos != string::npos) {
                    size_t end_pos = sentence.find("*/", pos+2);
                    cout << sentence.substr(start, pos - start);
                    if (end_pos != string::npos) {
                        // delete the comments and print the sentense.
                        start = end_pos+2;
                        flag = false;
                    } else {
                        flag = true;
                        break;
                    }
                } else {
                    cout << sentence.substr(start);
                    break;
                }
            } else {
                size_t end_pos = sentence.find("*/", start);
                if (end_pos != string::npos) {
                    flag = false;
                    start = end_pos+2;
                } else {
                    break;
                }
            }
        }
        if (!flag) cout << endl;
    }
    return 0;
}
