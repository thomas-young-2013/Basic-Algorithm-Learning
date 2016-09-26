#include <iostream>
#include <fstream>

using namespace std;
const int N = 1000000;
int array[N];
int array_min[N];
int array_max[N];

int get_min(int a[], int lb, int ub) {
    int tmp = a[lb];
    for (int i=lb+1; i <= ub; i++) {
        if (tmp > a[i]) tmp = a[i];
    }
    return tmp;
}

int get_max(int a[], int lb, int ub) {
    int tmp = a[lb];
    for (int i=lb+1; i <= ub; i++) {
        if (tmp < a[i]) tmp = a[i];
    }
    return tmp;
}

int main() {
    ifstream cin;
    cin.open("/home/thomas/Desktop/in.txt");

    int m, n;
    cin >> m >> n;
    for (int i=0; i<m; i++) scanf("%d", &array[i]);

    // init
    int last_min=array[0], last_max=array[0];
    for(int i=0; i<n; i++) {
        if (array[i] < last_min) last_min = array[i];
        if (array[i] > last_max) last_max = array[i];
    }
    array_min[n-1] = last_min;
    array_max[n-1] = last_max;
    for (int i=n; i<m; i++) {
        if (array[i-n] == array_min[i-1]) {
            if (array[i] < array_min[i-1]) array_min[i] = array[i];
            else array_min[i] = get_min(array, i-n+1, i);
        } else {
            if (array[i] < array_min[i-1]) array_min[i] = array[i];
            else array_min[i] = array_min[i-1];
        }

        if (array[i-n] == array_max[i-1]) {
            if (array[i] > array_max[i-1]) array_max[i] = array[i];
            else array_max[i] = get_max(array, i-n+1, i);
        } else {
            if (array[i] > array_max[i-1]) array_max[i] = array[i];
            else array_max[i] = array_max[i-1];
        }
    }
    cout << array_min[n-1];
    for (int i=n; i<m; i++) cout << " " << array_min[i];
    cout << endl;

    cout << array_max[n-1];
    for (int i=n; i<m; i++) cout << " " << array_max[i];
    cout << endl;

    return 0;
}
