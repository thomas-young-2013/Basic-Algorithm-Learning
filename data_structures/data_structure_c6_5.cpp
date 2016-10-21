#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <set>

using namespace std;
const int N =100000;
int type[N], num=0;
int xCon[N], yCon[N];
int eat[N], n;
set<int> species[3];

bool contrast(int x, int y) {
    for (int i=0; i<n; i++) {

    }
}

bool inference(int d, int x, int y) {
    if (d == 2) {
        if (eat[x] == 0) {
            if (contrast(x, y)) return true;
            eat[x] = y;
            return true;
        } else {
            return isSameSpeice(eat[x], y);
        }
    } else {
        if (x == y) return true;
        return isSameSpeice(x, y);
    }
}


int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int k, d, x, y, falseAssertion=0;
    memset(eat, 0, N*sizeof(int));
    cin >> n >> k;
    while(k--) {
        cin >> d >> x >> y;
        // case one and case two.
        if (x > n || y > n || (d == 2 && x == y)) {
            falseAssertion++;
            continue;
        }
        if (inference(d, x, y) == true) {
            type[num] = d;
            xCon[num] = x;
            yCon[num] = y;
            num++;
        } else {
            falseAssertion++;
        }
    }
    cout << falseAssertion << endl;
	return 0;
}
