#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
const int N = 100;
string data[N];
string d[N];
int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> data[i];

    queue<string> queues[9];
    queue<string> que[4];
    for (int i=0; i<n; i++) {
        queues[data[i][1]-'1'].push(data[i]);
    }
    for (int i=0; i<9; i++) {
        cout << "Queue" << i + 1 << ":";
        if (!queues[i].empty()) {
            string t;
            t = queues[i].front();
            que[t[0]-'A'].push(t);
            cout << t;
            queues[i].pop();
        }
        while(!queues[i].empty()) {
            string t;
            t = queues[i].front();
            que[t[0]-'A'].push(t);
            cout << " " << t;
            queues[i].pop();
        }
        cout << endl;
    }
    int count = 0;
    for (int i=0; i<4; i++) {
        cout << "Queue" << char('A' + i) << ":";
        if (!que[i].empty()) {
            d[count++] = que[i].front();
            cout << que[i].front();
            que[i].pop();
        }
        while(!que[i].empty()) {
            d[count++] = que[i].front();
            cout << " " << que[i].front();
            que[i].pop();
        }
        cout << endl;
    }
    cout << d[0];
    for (int i=1; i<n; i++) {
        cout << " " << d[i];
    }
    cout << endl;
    return 0;
}
