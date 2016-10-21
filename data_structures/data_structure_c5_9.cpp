#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y, lNum=0, rNum=0;
        cin >> x >> y;
        while(x > 1 || y > 1) {
            if (x > y) {
                if (y == 1) lNum += (x-y);
                else lNum += x/y;
                x = x%y;
            } else {
                if (x == 1) rNum += (y-x);
                else rNum += y/x;
                y = y%x;
            }
        }
        cout << "Scenario #" << i << ":\n";
        cout << lNum << " " << rNum << endl;
        if (i!=n) cout << endl;
    }
	return 0;
}
