#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 500;
int d[N];

void interChange(int x, int y, int n) {
    int fatherX, fatherY, xLeftFlag = 1, yLeftFlag = 1;
    for (int i=0; i<n; i++) {
        if (d[2*i+1] == x) {
            fatherX = i;
            break;
        }
        if (d[2*i+2] == x) {
            fatherX = i;
            xLeftFlag = 2;
            break;
        }
    }
    for (int i=0; i<n; i++) {
        if (d[2*i+1] == y) {
            fatherY = i;
            break;
        }
        if (d[2*i+2] == y) {
            fatherY = i;
            yLeftFlag = 2;
            break;
        }
    }
    swap(d[2*fatherX+xLeftFlag], d[2*fatherY+yLeftFlag]);
}

int leftSibiling(int num) {
    int index = num;
    while(d[2*index+1] != -1) {
        index = d[2*index+1];
    }
    return index;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        for (int i=0; i<N; i++) d[i] = -1;

        int m, n, self, left, right, type, x, y, num;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> self >> left >> right;
            d[2*self+1] = left;
            d[2*self+2] = right;
        }
        // start operating.
        for (int i=0; i<m; i++) {
            cin >> type;
            if (type == 1) {
                cin >> x >> y;
                interChange(x, y, n);
            } else {
                cin >> num;
                cout << leftSibiling(num) << endl;
            }
        }
    }
    return 0;
}
