#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct edge {
    int weight;
    int boy, girl;
    bool operator<(const edge& other) { return weight < other.weight; }
};
vector<edge> edges;
int inD[1005];  // boy 1-500, girl 501-1000
int pick[1005];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    if (k == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        edge e;
        scanf("%d %d", &e.boy, &e.girl);
        e.girl += 500;
        inD[e.boy]++;
        inD[e.girl]++;
        edges.push_back(e);
    }
    for (int i = 0; i < k; i++)
        edges[i].weight = min(inD[edges[i].boy], inD[edges[i].girl]);
    // cout << "weight" << endl;
    sort(edges.begin(), edges.end());
    cout << " " << endl;
    for (int j = 0; j < k; j++) {
        int b = edges[j].boy, g = edges[j].girl;
        if (pick[b] == 0 and pick[g] == 0) {
            pick[b] = g;
            pick[g] = b;
        }
        inD[g]--;
        inD[b]--;
        for (int i = 1; i <= k; i++)
            edges[i].weight = min(inD[edges[i].boy], inD[edges[i].girl]);
        sort(edges.begin(), edges.end());
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += (pick[i] > 0);
    printf("%d\n", res);
    for (int i = 1; i <= n; i++)
        if (pick[i]) printf("%d %d\n", i, pick[i] - 500);
}
