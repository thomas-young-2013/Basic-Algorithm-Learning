#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

string int2str(int t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

string replace(string str) {
    string result;
    int len = str.length();
    for (int i=0; i<len; i++) {
        if (str[i] == ' ' || str[i] == '    ') continue;
        if (str[i] >= 'A' && str[i] <= 'z') {
            result += (int2str(str[i]));
        } else {
            result += str[i];
        }
    }
    return result;
}


stack<int> opd;
stack<char> opt;

void deal(char t) {
    if (opt.empty() || t == '(') opt.push(t);
    else {
        char tmp = opt.top();
        if (t == '+' || t == '-') {
            while(tmp != '(') {
                int res, num1, num2;
                num1 = opd.top();
                opd.pop();
                num2 = opd.top();
                opd.pop();

                if (tmp == '*') res = num1*num2;
                if (tmp == '/') res = num2/num1;
                if (tmp == '+') res = num1+num2;
                if (tmp == '-') res = num2-num1;
                opd.push(res);
                opt.pop();
                if (!opt.empty()) tmp = opt.top();
                else break;
            }
        }
        if (t == '*' || t == '/') {
            while (tmp == '*' || tmp == '/') {
                int res, num1, num2;
                num1 = opd.top();
                opd.pop();
                num2 = opd.top();
                opd.pop();

                if (tmp == '*') res = num1*num2;
                if (tmp == '/') res = num2/num1;
                opd.push(res);
                opt.pop();
                if (!opt.empty()) tmp = opt.top();
                else break;
            }
        }
        opt.push(t);
    }
}

void compute() {
    while(!opt.empty()) {
        char tmp = opt.top();
        opt.pop();
        if (tmp == '(') break;

        int res, num1, num2;
        num1 = opd.top();
        opd.pop();
        num2 = opd.top();
        opd.pop();
        if (tmp == '*') res = num1*num2;
        if (tmp == '/') res = num2/num1;
        if (tmp == '+') res = num1+num2;
        if (tmp == '-') res = num2-num1;
        opd.push(res);
    }
}

int cal(string str) {
    while(!opd.empty()) opd.pop();
    while(!opt.empty()) opt.pop();

    int len = str.length();
    int i=0;
    while(i<len) {
        int sum=0;
        bool flag = false;
        while (str[i] >= '0' && str[i] <= '9') {
            sum = 10*sum + str[i] - '0';
            i++;
            flag = true;
        }
        if (flag) opd.push(sum);
        if (i>=len) break;

        if (str[i] != ')') deal(str[i]);
        else compute();

        i++;
    }

    compute();
    return opd.top();
}
const int N = 100;
char array_a[N];
char array_b[N];

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    scanf("%d", &n);
    getchar();
    while(n--) {
        gets(array_a);
        gets(array_b);
        string a(array_a), b(array_b);
        // cout << a << " " << b << endl;
        if (cal(replace(a)) == cal(replace(b))) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
