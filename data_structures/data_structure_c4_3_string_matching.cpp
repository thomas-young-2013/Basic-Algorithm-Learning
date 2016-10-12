#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int N = 100000;
char t1[N], t2[N];

bool deal(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    int tmp, last = -1;
    for (int i=0; i<len_a; i++) {
        tmp = last+1;
        bool flag = false;
        while(tmp < len_b) {
            if (b[tmp] == a[i]) {
                last = tmp;
                flag = true;
                break;
            }
            tmp++;
        }
        if (!flag) return false;
    }
    return true;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");

    // freopen("/home/thomas/Desktop/in.txt", "r", stdin );
    while(scanf("%s %s", t1, t2) != EOF) {
        if (deal(string(t1), string(t2))) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
