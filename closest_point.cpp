#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
using namespace std;

bool distcomp(pair<double, double> a, pair<double, double> b){
    double dista = sqrt(pow(a.first, 2.0) + pow(a.second, 2.0));
    double distb = sqrt(pow(b.first, 2.0) + pow(b.second, 2.0));
    return dista < distb;
    
}

int main(){
    freopen("points.in", "r", stdin);
    vector<pair<double, double> > v;
    double a;
    double b;
    while (cin >> a >> b) v.push_back({a, b});
    sort(v.begin(), v.end(), distcomp);
    for (auto p : v) cout << p.first << " " << p.second << endl;
}
