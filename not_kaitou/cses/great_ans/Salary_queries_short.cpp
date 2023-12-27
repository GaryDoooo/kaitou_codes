   CSES
   doooom — Dark mode Log out

CSES Problem Set

Salary Queries

     * Task
     * Submit
     * Results
     * Statistics
     * Hacking

   Back to hacking
          time          victim   lang  max time
   2023-05-16 20:00:38 duong2803 C++20 0.20 s
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 4e5;

int bit[mxN * 2 + 5] = {};

void upd(int i, int u){
        for(; i < mxN * 2 + 5; i += i & -i) bit[i] += u;
}

int qry(int i){
        int res = 0;
        for(; i > 0; i -= i & -i) res += bit[i];
        return res;
}

void compress(vector<int> &a){
        int n = a.size();
        vector<pair<int,int>> b(n);
        for(int i = 0; i < n; ++i){
                b[i] = {a[i], i};
        }
        sort(b.begin(), b.end());
        int nxt = 1;
        for(int i = 0; i < n; ++i){
                if(i > 0 && b[i].first != b[i - 1].first) ++nxt;
                a[b[i].second] = nxt;
        }
}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        vector<int> a;
        vector<char> b;
        vector<int> idx;
        for(int i = 0; i < n; ++i){
                int x; cin >> x;
                a.push_back(x);
        }
        for(int i = 0; i < m; ++i){
                char c;
                int x, y;
                cin >> c >> x >> y;
                b.push_back(c);
                if(c == '?'){
                        a.push_back(x);
                        a.push_back(y);
                }else{
                        a.push_back(y);
                        idx.push_back(x);
                }
        }

        compress(a);

        for(int i = 0; i < n; ++i)
                upd(a[i], 1);

        int q = 0;
        int q2 = 0;
        for(int i = n; i < a.size();){
                if(b[q] == '?'){
                        cout << qry(a[i + 1]) - qry(a[i] - 1) << '\n';
                        i += 2;
                }else{
                        upd(a[idx[q2] - 1], -1);
                        upd(a[i], 1);
                        a[idx[q2] - 1] = a[i];
                        i++;
                        q2++;
                }
                q++;
        }

        return 0;
}

   Input as text:

   ________________________________________
   ________________________________________
   ________________________________________
   ________________________________________

   Input as file:                     

   Hack

Range Queries

   ... Forest QueriesHotel QueriesList RemovalsSalary QueriesPrefix Sum QueriesPizzeria QueriesSubarray Sum
   QueriesDistinct Values Queries...
     _______________________________________________________________________________________________________________

Your submissions

   2023-07-16 21:57:19 2023-07-16 21:40:14 2023-07-16 21:13:59 2023-07-16 21:12:35 2023-07-16 21:08:48 2023-07-16
   20:48:56 2023-07-16 20:38:10 2023-07-16 08:49:08 2023-07-16 08:41:25 2023-07-16 08:40:55 2023-07-16 08:33:23
   2023-07-16 08:32:32 2023-07-16 08:18:40
