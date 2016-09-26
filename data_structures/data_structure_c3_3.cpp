#include <iostream>
#include <fstream>

using namespace std;
const int N = 4000;

class queues {
    public:
        queues() {b = N-1; f = N;}
        void push_back(int t) {data[b--] = t;}
        void pop_back() {b++;}
        void pop_front() {f--;}
        bool empty() {return f == b+1;}
        int front() {return data[f-1];}
    private:
        int data[N];
        int f;
        int b;
};

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        queues queue;
        bool flag = true;
        while(m--) {
            int type, num;
            cin >> type >> num;
            if (type == 1) queue.push_back(num);
            else {
                if (queue.front() == num) {
                    queue.pop_front();
                } else {
                    flag = false;
                }
            }
        }
        if (flag) cout << "Queue" << endl;
        else cout << "Stack" << endl;
    }

    return 0;
}


/*
    wait all the input.
*/
