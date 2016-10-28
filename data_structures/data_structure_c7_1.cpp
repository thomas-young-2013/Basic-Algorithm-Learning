#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> mappings;
map<int, string> mappings1;
const int N = 40;
const int INF = 10000000;
int graph[N][N], n;
int dist[N][N],path[N][N];

void floyd() {
    // init the path..
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (graph[i][j]!=INF) path[i][j]=i;
            else path[i][j]=-1;
            dist[i][j]=graph[i][j];
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k]+dist[k][j]<dist[i][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    // path[i][k]=i;
                    path[i][j]=path[k][j];
                }
            }
        }
    }
}

void outputRoute(string x, string y) {
    if (x == y) {
        cout << x << endl;
        return;
    }

    int from=mappings[x], to=mappings[y];
    int stacks[N], pointer=0;
    while(path[from][to]!=from) {
        stacks[pointer++]=path[from][to];
        to=path[from][to];
    }

    cout << x;
    int last=from;
    while(pointer>0) {
        int tmp = stacks[--pointer];
        // cout << tmp << "->";
        cout << "->(" << graph[last][tmp] << ")->" << mappings1[tmp];
        last = tmp;
    }
    cout << "->(" << graph[last][mappings[y]] << ")->" << y << endl;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Downloads/in.txt");
    string tmp, x, y;
    int m;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        mappings[tmp]=i;
        mappings1[i]=tmp;
    }
    // init the graph.
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) graph[i][j]=INF;
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        cin >> graph[mappings[x]][mappings[y]];
        graph[mappings[y]][mappings[x]]=graph[mappings[x]][mappings[y]];
    }
    floyd();
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        outputRoute(x, y);
    }
    return 0;
}
