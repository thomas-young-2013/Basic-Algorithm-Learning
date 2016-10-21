#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <iomanip>

using namespace std;

/*struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d, Node* l=NULL, Node* r=NULL) {
        data = d;
        left = l;
        right = r;
    }
};*/

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    char tmp[50];
    map<string, int> mappings;
    int count=0;
    while(gets(tmp)) {
        string str(tmp);
        mappings[str] += 1;
        ++count;
    }
    for (map<string ,int>::iterator i=mappings.begin(); i!=mappings.end(); i++) {
        cout << i->first << " ";
        cout << fixed << setprecision(4) << (float)i->second/count*100 << endl;
    }
	return 0;
}
