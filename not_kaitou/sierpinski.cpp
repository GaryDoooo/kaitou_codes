#include <iostream>
using namespace std;

void draw(char res[][], int lvl, int x, int y) {
    if (lvl == 1) {
        res[x][y] = '/';
        res[x + 1][y] = '\';
                        res[x][y+1]=' - ';
                        res[x+1][y+1]=' - ';//]
                    }else{
                        int offset=1<<(lvl-1);
                        draw(res, lvl-1, x,y);
                        draw(res, lvl-1, x-offset,y+offset);
                        draw(res, lvl-1, x+offset,y+offset);
                    }
                    }
                        int main(){
                        int n;
                        cout<<"Input the level of the triangle (1-5): ";
                        cin>>n;
                        if (n<1 or n>5){
                        cout<<"\nOut of range.\n";
                        return 0;
                    }
                        int dim=1<<n;
                        char res[dim][dim];
                        draw(res,n,dim/2,0);
                        for (int y=0;y<dim;y++){
                        for (int x=0;x<dim;x++)
                        if (res[x][y]==' / ' or res[x][y]=='\' or res[x][y]==' - ')
                        cout << res[x][y];
                        cout<<endl;
                    }
                        return 0;
                    }