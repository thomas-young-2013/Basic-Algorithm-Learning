#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 500;

char data[N];

struct Node {
	int layer;
	int index;
	Node(int i, int l) {
		index = i;
		layer = l;
	}
	Node() {}
};

Node stack[N];

int countDash(string str) {
	int result=0;
	while(str[result] == '-') result++;
	return result;
}

void pre_order(int num) {
	if (data[num] != '-' && data[num] != '*') {
		cout << data[num];
		pre_order(2*num+1);
		pre_order(2*num+2);
	}
}

void in_order(int num) {
	if (data[num] != '-' && data[num] != '*') {
		in_order(2*num+1);
		cout << data[num];
		in_order(2*num+2);
	}
}

void post_order(int num) {
	if (data[num] != '-' && data[num] != '*') {
		post_order(2*num+1);
		post_order(2*num+2);
		cout << data[num];
	}
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
		// init.
		int stackNum=0;
		for (int i=0; i<N; i++) data[i] = '-';
		string str;
		while(cin >> str && str != "0") {
			int layer = countDash(str);
			if (layer == 0) {
				stack[stackNum++] = Node(0, layer);
				data[0] = str[0];
			} else {
				int fatherNode;
                while(stack[stackNum-1].layer >= layer) {
                    stackNum--;
                }

				fatherNode = stack[stackNum-1].index;
				int index = 2*fatherNode+1;
				if (data[index] != '-') index += 1;
				data[index] = str[layer];
				stack[stackNum++] = Node(index, layer);
			}
		}
		// traverse the binary tree.

		pre_order(0);
		cout << endl;
		post_order(0);
		cout << endl;
		in_order(0);
		cout << endl;
		if (n!=0) cout << endl;
	}
	return 0;
}
