#include <iostream>
#include <memory.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 200;
int n, m;
int x[N], y[N];
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
    float distance;
};

float computeDistance(int a, int b) {
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

bool cmp(Edge e1, Edge e2) {
    return e1.distance < e2.distance;
}

int main() {
    ifstream cin;
    cin.open("/home/thomas/Downloads/in.txt");

    while(cin >> n >> m) {
        memset(father, -1, N*sizeof(int));
        vector<Edge> edges;
        // foreach node, the cordinates.
        for (int i=0; i<n; i++) cin >> x[i] >> y[i];
        for (int i=0; i<m; i++) {
            Edge edge = Edge();
            cin >> edge.from >> edge.to;
            edge.distance=computeDistance(edge.from, edge.to);
            edges.push_back(edge);
        }
        sort(edges.begin(), edges.end(), cmp);
        int cnt=0;
        float result=0;
        for (int i=0; i<m; i++) {
            if (isConnected(edges[i].from, edges[i].to)==false) {
                add(edges[i].from, edges[i].to);
                result+=edges[i].distance;
                cnt++;
            }
        }
        if (cnt == n-1) cout << fixed << setprecision(2) << result << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
