#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;
map<string, int> mappings;
char d[200];

void init() {
    mappings["zero"] = 0;mappings["one"] = 1;mappings["two"] = 2;
    mappings["three"] = 3;mappings["four"] = 4;mappings["five"] = 5;
    mappings["six"] = 6;mappings["seven"] = 7;mappings["eight"] = 8;
    mappings["nine"] = 9;mappings["ten"] = 10;

    mappings["eleven"] = 11;mappings["twelve"] = 12;mappings["thirteen"] = 13;
    mappings["fourteen"] = 14;mappings["fifteen"] = 15;mappings["sixteen"] = 16;
    mappings["seventeen"] = 17;mappings["eighteen"] = 18;mappings["nineteen"] = 19;
    mappings["twenty"] = 20;

    mappings["thirty"] = 30;mappings["forty"] = 40;mappings["fifty"] = 50;
    mappings["sixty"] = 60;mappings["seventy"] = 70;mappings["eighty"] = 80;
    mappings["ninety"] = 90;mappings["hundred"] = 100;mappings["thousand"] = 1000;
    mappings["million"] = 1000000;
}

bool is_scale(string t) {
    return (t == "hundred" || t == "thousand" || t == "million");
}

int main() {
    init();
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);

    while(gets(d)) {
        string str(d);
        if (str == "") break;
        size_t len = str.length();
        size_t pos, start=0;
        int value = 0, temp_value=0, last_scale = 1000000, last_digit=0;
        bool flag = false, negative = false;
        while(start < len) {
            pos = str.find(" ", start);
            if (pos != string::npos) {
                string tmp = str.substr(start, pos - start);
                start  = pos + 1;

                if (tmp == "negative") {
                    negative = true;
                    continue;
                }

                if (is_scale(tmp)) {
                    if (mappings[tmp] >= last_scale) {
                        // add the segment.
                        value += (temp_value+last_digit)*mappings[tmp];
                        temp_value = 0;
                    } else {
                        // calculate the current segment.
                        temp_value += last_digit*mappings[tmp];
                    }
                    last_scale = mappings[tmp];
                    last_digit = 0;
                } else {
                    last_digit += mappings[tmp];
                }
            } else {
                value += mappings[str.substr(start)];
                break;
            }
        }
        value = value + last_digit + temp_value;
        if (negative) value *= -1;
        cout << value << endl;
    }

    return 0;
}
