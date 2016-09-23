#include <iostream>
#include <fstream>

using namespace std;

const int N = 400;
int array[N];

void init() {
    for (int i=0; i<N; i++) array[i] = 0;
}

void bigIntegerMul(string a, string b) {
    init();
    if (a=="0" || b=="0") {
        cout << "0" << endl;
        return;
    }
    if (a=="1") {
        cout << b << endl;
        return;
    }
    if (b=="1") {
        cout << a << endl;
        return;
    }

    int len1 = a.length(), len2 = b.length();
    if (len1 < len2) {
        swap(a, b);
        swap(len1, len2);
    }

    for (int i = len2-1; i>=0; i--) {
        int bias = len2-i-1, n=0, extra=0;
        for (int j=len1-1; j>=0; j--) {
            int prod = (b[i]-'0')*(a[j]-'0') + extra + array[n+bias];
            extra = prod/10;
            array[n+bias] = prod%10;
            n++;
        }
        if (extra != 0) {
            array[bias+n] = extra;
        }
    }
    int flag = N-1;
    while(array[flag--] == 0);
    flag++;
    while(flag>=0) {
        cout << array[flag--];
    }
    cout << endl;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");

    string a, b;
    cin >> a >> b;
    bigIntegerMul(a, b);
    return 0;
}
