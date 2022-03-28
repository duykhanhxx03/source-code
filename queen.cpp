#include <iostream>
using namespace std;
bool check_ngang (int **arr, int x, int y, int n){
    for (int i=0; i<n; i++){
        if(arr[x][i]==1&&y!=i){
            return true;
        }
    }
    return 0;
}
bool check_doc (int **arr, int x, int y, int n){
    for (int i=0; i<n; i++){
        if(arr[i][y]==1&&x!=i){
            return true;
        }
    }
    return 0;
}
bool check_cheo_phai (int **arr, int x, int y, int n){
    int _x=x,_y=y;
    while(_x<0||_y>n-1){
        if(arr[_x][_y] == 1 && x != _x && y != _y) {
            return 1;
        }
        _x--;
        _y++;
    }
    _x=x;
    _y=y;
    while(_x>n-1||_y<0){
        if(arr[_x][_y] == 1 && x != _x && y != _y) {
            return 1;
        }
        _x++;
        _y--;
    }
    return 0;
}
bool check_cheo_trai (int **arr, int x, int y, int n){
    int _x=x,_y=y;
    while(_x<0||_y<0){
        if(arr[_x][_y] == 1 && x != _x && y != _y) {
            return 1;
        }
        _x--;
        _y--;
    }
    _x=x;
    _y=y;
    while(_x>n-1||_y>n-1){
        if(arr[_x][_y] == 1 && x != _x && y != _y) {
            return 1;
        }
        _x++;
        _y++;
    }
    return 0;
}
int main(){
    int n; cin>>n;
    int **arr=new int*[n];
    for (int i=0; i<n; i++){
        arr[i]=new int[n];
    }
    bool flags = true;
    for (int i=0; i<=n-1; i++){
        int a,b; cin>>a>>b;
        arr[a-1][b-1]=1;
        if (check_ngang(arr,a-1,b-1,n) == true) flags = false;
        if (check_doc(arr,a-1,b-1,n) == true) flags = false;
        if (check_cheo_phai(arr,a-1,b-1,n) == true) flags = false;
        if (check_cheo_trai(arr,a-1,b-1,n) == true) flags = false;
    }
    cout<<((flags==1)? "no":"yes");
    return 0;
}