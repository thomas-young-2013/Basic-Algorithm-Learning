#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
const int N = 80000;
int stack[N];
int top;

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    long long count = 0;
    // cin >> n;
    scanf("%d", &n);
    while(n--) {
        int tmp;
        // cin >> tmp;
        scanf("%d", &tmp);
        while(top > 0 && tmp >= stack[top-1]) top--;

        count += top;
        stack[top++] = tmp;
    }

    printf("%lld\n", count);
    return 0;
}

/* cause: long long
int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    long long count = 0;
    stack<int> con;
    cin >> n;
    // scanf("%d", &n);
    while(n--) {
        int tmp;
        cin >> tmp;
        // scanf("%d", &tmp);
        while(!con.empty() && tmp >= con.top()) {
            count += con.size() - 1;
            con.pop();
        }
        con.push(tmp);
    }

    while(!con.empty()) {
        count += con.size() - 1;
        con.pop();
    }
    cout << count << endl;
    return 0;
}
*/
