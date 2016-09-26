#include <iostream>
#include <fstream>

using namespace std;
const int N = 200;
int stack[N];
int top;

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    cin >> n;
    while(n--) {
        int m;
        int flag = true;
        cin >> m;
        top = 0;
        while(m--) {
            string operation;
            cin >> operation;
            if (operation == "push") {
                int tmp;
                cin >> tmp;
                stack[top++] = tmp;
            } else {
                if (top > 0) top--;
                else flag = false;
            }
        }
        if (flag && top > 0) {
            cout << stack[0];
            for (int i=1; i<top; i++) cout << " " << stack[i];
            cout << endl;
        }
        if (!flag) cout << "error" << endl;
    }

    return 0;
}


/*
    wait all the input.
*/
