#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
long long c[1005];

long long rec(int i){
    if (c[i] >= 0) return c[i];
    if (s[i] == 'H'){
        long long t = 0;
        for (int j = i+1; j < s.length(); j++){
            if (s[j] == 'E'){
                t += rec(j);
            }
        }
        return c[i] = t;
    }
    if (s[i] == 'E'){
        long long t = 0;
        for (int j = i+1; j < s.length(); j++){
            if (s[j] == 'T'){
                t += rec(j);
            }
        }
        return c[i] = t;
    }
    if (s[i] == 'T'){
        long long t = 0;
        for (int j = i+1; j < s.length(); j++){
            if (s[j] == 'A'){
                t += rec(j);
            }
        }
        return c[i] = t;
    }
    if (s[i] == 'A'){
        long long t = 0;
        for (int j = i+1; j < s.length(); j++){
            if (s[j] == 'O'){
                t += 1;
            }
        }
        return c[i] = t;
    }
}

int main(){ // HETAO
    memset(c, 128, sizeof(c));
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'H'){
            ans += rec(i);
        }
    }
    cout << ans << endl;
    return 0;
}