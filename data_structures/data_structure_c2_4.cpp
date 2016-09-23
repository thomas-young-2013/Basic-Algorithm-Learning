#include <iostream>
#include <string>

using namespace std;

int main() {
    string m, n;
    while(cin >> m >> n) {
        int flag, value = 0;
        for (int i=0; i<m.length(); i++) {
            if(m[i]>value) {
                value = m[i];
                flag = i;
            }
        }
        cout << m.substr(0, flag+1) << n << m.substr(flag+1) << endl;
    }
    return 0;
}
