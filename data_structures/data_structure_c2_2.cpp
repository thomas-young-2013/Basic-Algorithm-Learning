#include <iostream>

using namespace std;

int calculateSorts(int m, int n) {
    if (m == 0 || n == 1) return 1;
    if (m < n) return calculateSorts(m, n-1);
    else return calculateSorts(m, n-1) + calculateSorts(m-n, n);
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int m, n;
        cin >> m >> n;
        cout << calculateSorts(m, n) << endl;
    }
    return 0;
}
