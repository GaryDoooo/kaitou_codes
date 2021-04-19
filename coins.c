#include <stdio.h>

int main() {
    int min_sum = 100000;
    int min_coins[3];
    for (int i = 2; i < 99; i++)
        for (int j = i + 1; j < 100; j++) {
            int coins[3] = {1, i, j};
            int min[100];
            min[0]  = 0;
            int sum = 0;
            for (int k = 1; k < 100; k++) {
                int min_combination = 1000;
                for (int c = 0; c < 3; c++) {
                    if (k - coins[c] >= 0)
                        if (min_combination > 1 + min[k - coins[c]])
                            min_combination = 1 + min[k - coins[c]];
                }
                min[k] = min_combination;
                sum += min[k];
            }
            if (sum < min_sum) {
                min_sum = sum;
                for (int k = 0; k < 3; k++) min_coins[k] = coins[k];
            }
        }
    printf("Minimum Combination: %d %d %d\n", min_coins[0], min_coins[1],
           min_coins[2]);
}

