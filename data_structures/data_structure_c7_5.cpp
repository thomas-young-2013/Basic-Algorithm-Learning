#include <iostream>
#include <memory.h>
#include <fstream>
#include <vector>

using namespace std;

const int N = 1000;
int inDegree[N], resultSet[N], isAdded[N];
vector<int> graph[N];

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Downloads/in.txt");
    int n, m, x, y;
    memset(inDegree, 0, N*sizeof(int));
    memset(isAdded, 0, N*sizeof(int));
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        inDegree[y]++;
        graph[x].push_back(y);
    }
    int cnt=0;
    while(cnt < n) {
        for (int i=1; i<=n; i++) {
            if(isAdded[i]==0 && inDegree[i]==0) {
                resultSet[cnt]=i;
                isAdded[i] = 1;
                // remove this relative edges.
                int size = graph[i].size();
                for (int j=0; j<size; j++) inDegree[graph[i][j]]--;
                break;
            }
        }
        cnt++;
    }
    cout << "v" << resultSet[0];
    for (int i=1; i<n; i++) cout << " v" << resultSet[i];
    cout << endl;
    return 0;
}
