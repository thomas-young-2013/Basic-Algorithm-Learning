#include <cstdio>
#include <iostream>

using namespace std;

const int N = 50005;
int father[N];
int relation[N];

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        father[i]= i;
        relation[i] = 0;
    }
}

int find(int x)
{
    if(x != father[x])
    {
        int temp = father[x];
        father[x] = find(temp);
        relation[x] = (relation[x] + relation[temp]) % 3;
    }
    return father[x];
}

int main()
{
    // freopen("/home/thomas/Downloads/in.txt", "r", stdin);

    int n, m, x, y, d, fx, fy, cnt;

    scanf("%d %d", &n, &m);

    cnt = 0;
    init(n);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &d, &x, &y);
        if(x > n || y > n)
        {
            ++cnt;
            continue;
        }
        if(d == 2 && x == y)
        {
            ++cnt;
            continue;
        }
        fx = find(x);
        fy = find(y);
        if(fx == fy)
        {
            if(d == 1 && relation[x] != relation[y])
                ++cnt;
            if(d == 2 && relation[x] != (relation[y] + 2)%3)
                ++cnt;
        }
        else
        {
            father[fy] = fx;
            relation[fy] = (relation[x] + (d-1) + (3-relation[y])) % 3;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
