#include <bits/stdc++.h>
#include <sys/time.h>
#include <ext/pb_ds/assoc_container.hpp>
#define N 200000
#define S 19
#define HS (1 << S)
using namespace std;
using namespace __gnu_pbds;

struct timeval tv;
unsigned long long t1, t2;

void ammojamo_hash() {
    int ht[HS];
    memset(ht, 0, HS * sizeof(int));
    for (int i = 1; i <= N; i++) {
        unsigned int h = ((i * 0x9e3779b1) >> (33 - S)) << 1;
        while (1) {
            if (ht[h] == 0) {
                ht[h] = i;
                break;
            } else {
                h = (h + 2) % HS;
            }
        }
    }
}

void map_table() {
    map<int, int> m;
    for (int i = 1; i <= N; i++) m[i] = i;
}

void unordered_map_table() {
    unordered_map<int, int> m;
    for (int i = 1; i <= N; i++) m[i] = i;
}

struct splitmix64_hash {
    size_t operator()(uint64_t x) const {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};

template <class K, class V>
using fast_hash_table = gp_hash_table<
    K, V, splitmix64_hash, equal_to<K>, direct_mask_range_hashing<>,
    linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
                                hash_load_check_resize_trigger<>, true>>;
void fast_hash() {
    fast_hash_table<int, int> m;
    for (int i = 1; i <= N; i++) m[i] = i;
}

int main() {
    puts("Make a table of 2e5 integers.");
    //
    // Ammojamo Hash table
    //
    gettimeofday(&tv, NULL);
    t1 = (unsigned long long)tv.tv_usec +
         (unsigned long long)tv.tv_sec * 1000000;
    for (int i = 1; i <= 100; i++) ammojamo_hash();
    gettimeofday(&tv, NULL);
    printf("HT use microseconds: %llu\n",
           ((unsigned long long)tv.tv_usec +
            (unsigned long long)tv.tv_sec * 1000000 - t1) /
               100);
    //
    // ordered map table
    //
    gettimeofday(&tv, NULL);
    t1 = (unsigned long long)tv.tv_usec +
         (unsigned long long)tv.tv_sec * 1000000;
    for (int i = 1; i <= 100; i++) map_table();
    gettimeofday(&tv, NULL);
    printf("map use microseconds: %llu\n",
           ((unsigned long long)tv.tv_usec +
            (unsigned long long)tv.tv_sec * 1000000 - t1) /
               100);
    //
    // UNordered map table
    //
    gettimeofday(&tv, NULL);
    t1 = (unsigned long long)tv.tv_usec +
         (unsigned long long)tv.tv_sec * 1000000;
    for (int i = 1; i <= 100; i++) unordered_map_table();
    gettimeofday(&tv, NULL);
    printf("unordered_map use microseconds: %llu\n",
           ((unsigned long long)tv.tv_usec +
            (unsigned long long)tv.tv_sec * 1000000 - t1) /
               100);
    //
    // Fast Hash table
    //
    gettimeofday(&tv, NULL);
    t1 = (unsigned long long)tv.tv_usec +
         (unsigned long long)tv.tv_sec * 1000000;
    for (int i = 1; i <= 100; i++) fast_hash();
    gettimeofday(&tv, NULL);
    printf("Fast Hash use microseconds: %llu\n",
           ((unsigned long long)tv.tv_usec +
            (unsigned long long)tv.tv_sec * 1000000 - t1) /
               100);
}
