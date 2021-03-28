#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0 or n < 2) return false;
    for (int i = 3; i < sqrt(n) + 1; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// A utility for creating palindrome
int createPalindrome(int input, int b, bool isOdd) {
    int n = input;
    int palin = input;
    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;
    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0) {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

// Function to print decimal palindromic number
vector<int> generatePalindromes(int min, int max) { //n)
    int number;
    vector<int> res;
    // Run two times for odd and even length palindromes
    for (int j = 0; j < 2; j++) {
        // Creates palindrome numbers with first half as i.
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) <= max) {
            if (number >= min) res.push_back(number);
            i++;
        }
    }
    return res;
}

int main() {
    int min, max;
    cin >> min >> max;
    vector<int> candidates;
    candidates = generatePalindromes(min, max);
    sort(candidates.begin(), candidates.end());
    for (auto i : candidates) {
        if (is_prime(i)) cout << i << endl;
    }
    return 0;
}