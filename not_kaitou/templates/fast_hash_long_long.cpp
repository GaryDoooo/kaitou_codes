#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template<typename T> void fastscan(T &num)
{
    num = 0;
    bool neg = 0;
    int c =getchar_unlocked();
    if(c=='-')
    {
        neg =1;
        c = getchar_unlocked();
    }
    for(;c>='0' && c<='9';c=getchar_unlocked())
    {
        num = num*10+c-'0';
    }
    if(neg) num = -1*num;
}
template<typename T> void print(T n)
{
    if(n<0)
    {
        n = -n;
        putchar_unlocked('-');
    }
    char buffer[10];
    int i =10;
    do
    {
        buffer[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    do
    {
        putchar_unlocked(buffer[i]);
    }while(++i<10);
 
}
 
struct splitmix64_hash {
    size_t operator() (uint64_t x) const{
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};
 
template<class K,class V> using fast_hash_table = gp_hash_table<
        K,
        V,
        splitmix64_hash,
        equal_to<K>,
        direct_mask_range_hashing<>,
        linear_probe_fn<>,
        hash_standard_resize_policy<
            hash_exponential_size_policy<>,
            hash_load_check_resize_trigger<>,
            true
        >
>;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int N, X;
    fastscan(N); fastscan(X);
 
    fast_hash_table <long long, int> psum_occ;
    psum_occ.resize(N + 1);
    psum_occ[0] = 1;
 
    long long ans = 0;
    long long prefix_sum = 0;
    for(int i = 0, num; i < N; ++i) {
        fastscan(num);
        prefix_sum += num;
 
        auto it = psum_occ.find(prefix_sum - X);
        if(it != psum_occ.end()) {ans += it->second;}
 
        ++psum_occ[prefix_sum];
    }
 
    print(ans);
 
    return 0;
}
