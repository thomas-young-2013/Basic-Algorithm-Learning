#include <iostream>
#include <memory.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

const float INF = 100000000;
const int N = 105;
int n, m;
int x[N], y[N];
float graph[N][N];
bool isVisited[N];

float computeDistance(int a, int b) {
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main() {
    ifstream cin;
    cin.open("/home/thomas/Downloads/in.txt");

    while(cin >> n >> m) {
        // init the graph.
        float distance[N];
        int from, to;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) graph[i][j] = INF;
        }
        // foreach node, the cordinates.
        for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
        for (int i=0; i<m; i++) {
            cin >> from >> to;
            graph[from][to] = computeDistance(from, to);
        }
        // algorithm.
        memset(isVisited, false, N*sizeof(int));
        for (int i=1; i<=n; i++) {
            distance[i] = graph[1][i];
        }
        isVisited[1] = true;
        for (int j=0; j<n-1; j++) {
            int nearestCounty=0;
            float nearestDistance=INF;
            for (int i=1; i<=n; i++) {
                if (isVisited[i]==false && distance[i] < nearestDistance) {
                    nearestCounty = i;
                    nearestDistance = distance[i];
                }
            }
            isVisited[nearestCounty] = true;
            if (nearestCounty==0) break;
            // update the distance..
            for (int i=1; i<=n; i++) {
                if (isVisited[i]==false && graph[nearestCounty][i]!=INF && distance[nearestCounty]+graph[nearestCounty][i] < distance[i]) {
                    distance[i] = distance[nearestCounty]+graph[nearestCounty][i];
                }
            }
        }
        bool flag = true;
        float result = 0.0;
        for (int i=2; i<=n; i++) {
            if (distance[i]!=INF) result += distance[i];
            else flag = false;
        }
        if (flag) cout << fixed << setprecision(2) << result << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
