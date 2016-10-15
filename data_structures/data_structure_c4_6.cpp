#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--) {
        int d[30];
        for(int i=0; i<30; i++) d[i] = 0;
        string str;
        cin >> str;

        size_t len = str.length();
        int max_index = 0;
        for (int i=0; i<len; i++) {
            int tmp = str[i]-'a';
            d[tmp] += 1;
            if (d[tmp] > d[max_index] || d[tmp] == d[max_index] && tmp < max_index) max_index = tmp;
        }
        cout << char('a' + max_index) << " " << d[max_index] << endl;
    }
    return 0;
}
