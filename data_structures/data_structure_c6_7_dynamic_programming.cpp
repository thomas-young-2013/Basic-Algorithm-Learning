#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 40005;

int father[N], depth[N], child[N];

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    char str[N];
    int n=1;
    while(true) {
        scanf("%s", str);
        int len = strlen(str);
        // exceptional case.
        if (len==0) {
            printf("Tree %d: 0 => 0\n", n++);
            continue;
        }
        // stop condition.
        if (str[0] == '#') break;
        // init.
        int tmpDepth=0, formalDepth=0, binaryDepth=0;
        memset(father, 0, sizeof(int)*N);
        memset(depth, 0, sizeof(int)*N);
        memset(child, 0, sizeof(int)*N);

        for (int i=1; i<=len; i++) {
            if (str[i-1] == 'd') {
                ++tmpDepth;
                if (tmpDepth>formalDepth) formalDepth=tmpDepth;

                father[i] = i-1;
                depth[i] = depth[i-1] + child[i-1]+1;
                ++child[i-1];
                if (binaryDepth<depth[i]) binaryDepth=depth[i];
            } else {
                --tmpDepth;
                depth[i]=depth[father[i-1]];
                child[i] = child[father[i-1]];
                father[i] = father[father[i-1]];
            }
        }
        printf("Tree %d: %d => %d\n", n++, formalDepth, binaryDepth);
    }
    return 0;
}
