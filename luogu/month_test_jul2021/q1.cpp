#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int l, t;
    int lp, tp, bp;
    int la, ta;
    cin >> l >> t >> lp >> tp >> bp;
// 	bool bmwi=false;
// 	if (lp + tp > bp*2)
// 		bmwi = true;
// 	bool nl, nt;
// 	int la, ta
// 	int total;
// 	while (nl or nt){
// 		if (nl and nt){
// 			if (bmwi){
// 				total += bp*2;
// 				la += 1;
// 				ta += 1;
// 			}
// 		}
// 	}
    int minn = 1000000;
    for (int b = 0; b <= min(l, t) * 2; b++) {
        int bfp = bp * b;
        int fp = bfp + (l - (b / 2)) * lp + (t - (b / 2)) * tp;
        if (fp < minn) minn = fp;
    }
    cout << minn;
    return 0;
}