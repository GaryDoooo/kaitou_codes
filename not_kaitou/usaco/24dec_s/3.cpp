#include <bits/stdc++.h>
using namespace std;

// make a 1D array for N+2 by N+2 grid
// 0...W-1 is first row, W...2W-1 is the 2nd row....
int W, N, Q;
int a[2123456];  // before which step the cell
                 // was available, sort the step number in a[i], while i is the
                 // position in the 1D array
                 //
int o[2123456];  // the cell occupied or not, 0 is not occupied by a conveyor,
                 // a value >0 is the cell position the the conveyor connecting
                 // to
                 //
int res[212345]; // How many cells becoming unusable at the step. res[i] is the
                 // cell counts at step i
                 //
int step_p[212345]; // p=x+y*W,
                    // record each step, step_p which cell being occupied,
                    // Since we are doing the problem reversely, from the last
                    // step back to the first, we need layout the final stage,
                    // and tracing backwards.

void visit(const int input_p, const int step) {
    if (a[input_p])
        return;   // if a[i] has a value >0, it should be visited already in
                  // previous calculation
                  //
    stack<int> s; // using stack for dfs, cz using function will overflow since
                  // too many layers... BFS also works here. Just a way to go
                  // through all the cells.
                  //
    int d[4] = {1, -1, W, -W};
    s.push(input_p);
    a[input_p] = step;
    while (s.size()) {
        int p = s.top();
        s.pop();
        for (int i = 0; i < 4; i++) {
            int new_p = p + d[i];
            if (new_p < 0 or new_p >= W * W)
                continue; // Since the grid is W+2 by W+2, there is a rim around
                          // to be set to permenant usable and connects all the
                          // usable cells on the edges.
                          //
            if (a[new_p])
                continue;
            if (o[new_p] > 0 and o[new_p] != p)
                continue; // if the new_p cell is not occupied, or it occupied
                          // but pointing to this origin cell. we will push it
                          // into the DFS.
                          //
            s.push(new_p);
            a[new_p] = step;
        }
    }
}

int is_open(int p) {
    int d[4] = {1, -1, W, -W};
    for (int i = 0; i < 4; i++) {
        int new_p = p + d[i];
        if (a[new_p]) // if a cell adjacent to a cell with a[i]>0
                      // the a[i]>0 neighbor should be usable at this step,
                      // since it was processed in previous calc. while previous
                      // calc means steps after the current step, since calc
                      // goes reversely.
                      //
            return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &Q);
    W = N + 2;
    map<char, int> c2d;
    c2d['L'] = -1;
    c2d['R'] = 1;
    c2d['U'] = -W;
    c2d['D'] = W;
    for (int i = 0; i < Q; i++) {
        int x, y;
        char d;
        scanf("%d %d %c", &y, &x, &d);
        step_p[i] = x + y * W;
        o[step_p[i]] =
            step_p[i] + c2d[d]; // >0 is occupied, value is the cell pointing to
    }
    visit(0, Q + 1) ; // the function is to set all the connected cells' a[i] value
                      // to Q+1 step, which means the cell will be available forever.
                      //
    for (int i = Q - 1; i >= 0; i--) {
        o[step_p[i]] = 0;
        if (is_open(step_p[i]))
            visit(step_p[i], i + 1); // set all connected cells' a[i] value
                                     // from step #i the cell becomes unusable
    }
    for (int i = 0; i < W * W; i++)
        res[a[i]]++; // res[i] is the total number of cells becoming unavailable
                     // at step i
    int sum = 0;
    for (int i = 1; i <= Q; i++) {
        sum += res[i]; // total unusable cells at this step
        printf("%d\n", sum);
    }
}
