#include <iostream>
#include <fstream>

using namespace std;

int n, m, num;
int array[65536];
char operation;

int main() {
    //ifstream cin;
    //cin.open("/home/thomas/Desktop/in.txt");
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> array[i];
    for (int i=0; i<m; i++) {
        cin >> operation >> num;
        if (operation == 'C') {
            for (int j=0; j<n; j++) array[j]+=num;
        } else {
            int count = 0;
            for (int j=0; j<n; j++) {
                count += (array[j] >> num)&1;
            }
            cout << count << endl;
        }
    }
    return 0;
}
