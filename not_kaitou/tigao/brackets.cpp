#include <bits/stdc++.h>
using namespace std;
int sign[255], b_lvl = 0, sign_index = 0, symbol_index = 0;
char symbol[255];
string traversal(int start, int end, int parent_sign, bool right) {
    string res, signs = "+-*/";
    if (start == end) {
        res = symbol[start];
    } else {
        auto min_pos  = min_element(sign + start, sign + end);
        int this_sign = *min_pos & 3;
        res           = traversal(start, min_pos - sign, this_sign, 0) +
              signs[this_sign] +
              traversal(min_pos - sign + 1, end, this_sign, 1);
        if (parent_sign >> 1 > this_sign >> 1 or
            (parent_sign == 3 and right and this_sign == 2) or
            (parent_sign == 1 and right and this_sign == 0))
            res = "(" + res + ")";
    }
    return res;
}
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') b_lvl++;
        if (c == ')') b_lvl--;
        if (c >= 'a' and c <= 'z') symbol[symbol_index++] = c;
        if (c == '+') sign[sign_index++] = b_lvl * 4;
        if (c == '-') sign[sign_index++] = b_lvl * 4 + 1;
        if (c == '*') sign[sign_index++] = b_lvl * 4 + 2;
        if (c == '/') sign[sign_index++] = b_lvl * 4 + 3;
    }
    cout << traversal(0, sign_index, 0, 0) << endl;
}

