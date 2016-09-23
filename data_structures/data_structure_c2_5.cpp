#include <iostream>
#include <fstream>
#include <map>
#include <iterator>

using namespace std;

int main() {
    int n;

    //ifstream cin;
    //cin.open("/home/thomas/Desktop/in.txt");

    cin >> n;
    while(n--) {
        map<int, int> array;

        int p, e;
        int count = 2;
        while(count--) {
            while(cin >> p >> e) {
                if (e < 0) break;
                array[e] += p;
            }
        }

        bool flag = false;
        for(map<int, int>::reverse_iterator i=array.rbegin(); i!=array.rend(); i++) {
            if (i->second != 0) {
                if (flag) cout << " ";
                else flag = true;
                //cout << "[ " << i->second << " " << i << " ]";
                printf("[ %d %d ]", i->second, i->first);
            }
        }
        cout << endl;
    }
    return 0;
}
