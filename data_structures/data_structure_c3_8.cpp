#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Node {
    int pos;
    int step;
    Node(int p, int s) {
        pos = p;
        step = s;
    }
};
const int N = 100000;
bool isvisited[N];
bool isvalid(int t) {
    return (t >= 0) && (t <= 100000);
}
void init() {
    for (int i=0; i<N; i++) isvisited[i] = false;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int m, n;
    cin >> m >> n;
    init();
    if (n <= m) {
        cout << m-n << endl;
    } else {
        queue<Node> stk;
        stk.push(Node(m, 0));
        isvisited[m] = true;
        while(!stk.empty()) {
            int t = stk.front().pos;
            int s = stk.front().step;
            if (t == n) break;
            stk.pop();

            if (isvalid(t-1) && isvisited[t-1] == false) {
                stk.push(Node(t-1, s + 1));
                isvisited[t-1] = true;
            }
            if (isvalid(t+1) && isvisited[t+1] == false) {
                stk.push(Node(t+1, s + 1));
                isvisited[t+1] = true;
            }
            if (isvalid(t*2) && isvisited[t*2] == false) {
                stk.push(Node(t*2, s + 1));
                isvisited[t*2] = true;
            }
        }
        cout << stk.front().step << endl;
    }
    return 0;
}
