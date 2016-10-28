#include <iostream>
#include <memory.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200;
int n;
int father[N];

int getRoot(int t) {
    if(father[t]==-1) return t;
    return father[t] = getRoot(father[t]);
}

bool isConnected(int a, int b) {
    return getRoot(a)==getRoot(b);
}

void add(int a, int b) {
    int ra = getRoot(a);
    int rb = getRoot(b);
    if (ra != rb) {
        father[ra] = rb;
    }
}

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};

bool cmp(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Downloads/in.txt");
    char tmp, tmp1;
    int distance, num;
    cin >> n;
    memset(father, -1, N*sizeof(int));
    vector<Edge> edges;
    for (int i=0; i<n-1; i++) {
        cin >> tmp >> num;
        for (int j=0; j<num; j++) {
            cin >> tmp1 >> distance;
            edges.push_back(Edge(tmp-'A', tmp1-'A', distance));
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    int len = edges.size(), cnt=0, sum=0;
    for (int i=0; i<len; i++) {
        if (isConnected(edges[i].from, edges[i].to)==false) {
            add(edges[i].from, edges[i].to);
            sum+=edges[i].weight;
            cnt++;
            if (cnt == n-1) break;
        }
    }
    cout << sum << endl;
    return 0;
}
