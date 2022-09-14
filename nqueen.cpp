#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    int row,col;
    //check for column
    for(row=0; row<x; row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    //check for left upper diagonal
    row = x, col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1) return false;
        row--;
        col--;
    }
    //check for right upper diagram
    row = x, col = y;

    while(row>=0 && col<n){
        if(arr[row][col]==1) return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n){
    if(x>=n){
        return true;
    }
    for(int col=0; col<n; col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n,i,j;
    cin>>n;
    int** arr = new int*[n];
    for(i=0; i<n; i++){
        arr[i] = new int[n];
        for(j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    if(nQueen(arr, 0, n)){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Not Possible"<<endl;
    }
    return 0;
}
