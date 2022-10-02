#include <iostream>
using namespace std;
  
void rec(int n, char from, char to, char r){ 
    if (n == 0){
        return; 
    } 
    rec(n - 1, from, r, to); 
    cout << from << " To " << to << endl; 
    rec(n - 1, r, to, from); 
} 

int main(){ 
    int n;
    cin >> n;
    rec(n, 'A', 'C', 'B'); 
    return 0; 
} 