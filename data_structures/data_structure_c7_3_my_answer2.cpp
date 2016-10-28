#include <iostream>
#include <memory.h>
#include <fstream>
#include <vector>

using namespace std;

const int N = 10;
int inDegree[N], graph[N][N], que[2*N];

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Downloads/in.txt");

    string tmp;
    while(cin >> tmp && tmp.length() > 0 && tmp[0]!='E') {
        vector<int> graphs[N];
        for (int i=0; i < 4; i++) {
            for (int j=0; j<4; j++) {
                cin >> graph[i][j];
            }
        }
        cin >> tmp;
        // init.
        memset(inDegree, 0, N*sizeof(int));
        // build the graph (ordered pairs).
        for (int i=1; i<=9; i++) {
            int leftUpX = (i-1)/3;
            int leftUpY = (i-1)%3;
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    int temp=graph[leftUpX+j][leftUpY+k];
                    if (temp != i) {
                        graphs[i].push_back(temp);
                        // increment in degrees.
                        inDegree[temp]++;
                    }
                }
            }
        }
        int front=0, rear=0, cur;
        for (int i=1; i<=9; i++) if (inDegree[i]==0) que[rear++]=i;
        while(front < rear) {
            cur = que[front++];
            int len = graphs[cur].size();
            for (int i=0; i<len; i++) {
                int temp = graphs[cur][i];
                if (--inDegree[temp] == 0) que[rear++]=temp;
            }
        }
        if (front < 9) cout << "THESE WINDOWS ARE BROKEN\n";
        else cout << "THESE WINDOWS ARE CLEAN\n";
    }
    return 0;
}
