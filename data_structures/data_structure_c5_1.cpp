#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10000;
int data[N];
int heap_num;

// adjust the minimal heap..
void push(int num) {
    // store
    int tmp = heap_num++;
    data[tmp] = num;
    // adjust.
    while(tmp > 0 && data[(tmp-1)/2] > data[tmp]) {
        swap(data[(tmp-1)/2], data[tmp]);
        tmp = (tmp-1)/2;
    }
}

// get the heap top and adjust.
int remove() {
    // remove the top.
    int heap_top = data[0];
    data[0] = data[--heap_num];
    // adjust the heap.
    int tmp = 0;
    while(true) {
        int left_child = 2*tmp + 1;
        int right_child = 2*tmp + 2;

        if (right_child < heap_num && data[right_child] < data[left_child] && data[right_child] < data[tmp]) {
            swap(data[right_child], data[tmp]);
            tmp = right_child;
        } else {
            if (left_child < heap_num && data[left_child] < data[tmp]) {
                swap(data[left_child], data[tmp]);
                tmp = left_child;
            } else {
                break;
            }
        }
    }
    return heap_top;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        heap_num = 0;
        while(m--) {
            int type, num;
            cin >> type;
            if (type == 1) {
                cin >> num;
                push(num);
            } else {
                cout << remove() << endl;
            }
        }
    }
    return 0;
}
