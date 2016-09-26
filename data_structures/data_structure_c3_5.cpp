#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

stack<int> opd;
stack<char> opt;

// deal with * / + -..
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

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        // init the stack.
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
        cout << opd.top() << endl;
    }

    return 0;
}
