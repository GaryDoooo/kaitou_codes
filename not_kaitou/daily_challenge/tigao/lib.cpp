bool *gen_prime_map(int up_limit) {
    bool *prime;
    prime = (bool *) malloc((up_limit + 1) * sizeof(bool));
    memset(prime, 1, (1 + up_limit) * sizeof(bool));
    for (int i = 3; i <= sqrt(up_limit); i += 2 ) {
        if (prime[i])
            for (int j = i * i; j <= up_limit; j += 2 * i) prime[j] = 0;
    }
    prime[0] = prime[1] = 0;
    for (int i = 4; i <= up_limit; i += 2) prime[i] = 0;
    return prime;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
inline int read() {
    int x = 0;//, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) { ch = getchar();}
    while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;// * f;
}

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    char ch = nc(); int x = 0; // int flag = 1;
    while (!(ch >= '0' && ch <= '9')) ch = nc();
    while (ch >= '0' && ch <= '9')x = (x << 1) + (x << 3) + (ch ^ 48), ch = nc();
    return x;
}
