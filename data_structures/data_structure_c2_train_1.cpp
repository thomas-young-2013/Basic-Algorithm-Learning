#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n, m, last = 0;
    cin >> n >> m;
    vector<int> vec;
    for (int i=1; i<=n; i++) vec.push_back(i);
    while(true) {
        int len = vec.size();
        if (len <= 1) break;
        last = (last+m-1)%len;
        vec.erase(vec.begin()+last);
    }
    cout << vec[0] << endl;
    return 0;
}
