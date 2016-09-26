#include <iostream>
#include <stdio.h>
#include <deque>
#include <fstream>

using namespace std;
const int N = 1000000;
int array[N];
int array_max[N];
int array_min[N];

struct Node {
    int pos;
    int val;
    Node(int p, int v) {
        pos = p;
        val = v;
    }
};

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");

    int m, n;
    // cin >> m >> n;
    scanf("%d %d", &m, &n);
    // for (int i=0; i<m; i++) cin >> array[i];
    for (int i=0; i<m; i++) scanf("%d", &array[i]);
    deque<Node> que;
    deque<Node> que1;
    for (int i=0; i<m; i++) {
        // create max queue.
        if (que.empty()) {
            que.push_back(Node(i, array[i]));
        } else {
            while(array[i] >= que.back().val) {
                que.pop_back();
                if (que.empty()) break;
            }

            while(!que.empty() && i - que.front().pos >= n) que.pop_front();

            if (que.size() == n) que.pop_front();
            que.push_back(Node(i, array[i]));
        }

        // create min queue.
        if (que1.empty()) {
            que1.push_back(Node(i, array[i]));
        } else {
            while(array[i] <= que1.back().val) {
                que1.pop_back();
                if (que1.empty()) break;
            }

            while(!que1.empty() && i >= que1.front().pos + n) que1.pop_front();

            if (que1.size() == n) que1.pop_front();
            que1.push_back(Node(i, array[i]));
        }
        if (i >= n-1) {
            array_min[i] = que1.front().val;
            array_max[i] = que.front().val;
        }
    }

    cout << array_min[n-1];
    for (int i=n; i<m; i++) cout << " " << array_min[i];
    cout << endl;

    cout << array_max[n-1];
    for (int i=n; i<m; i++) cout << " " << array_max[i];
    cout << endl;

    return 0;
}
