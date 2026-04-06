#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    vector<vector<int>> p(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p[i][j]=a[i][j];
            if(i>0) p[i][j]+=p[i-1][j];
            if(j>0) p[i][j]+=p[i][j-1];
            if(i>0 && j>0) p[i][j]-=p[i-1][j-1];
        }
    }

    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    int sum=p[r2][c2];
    if(r1>0) sum-=p[r1-1][c2];
    if(c1>0) sum-=p[r2][c1-1];
    if(r1>0 && c1>0) sum+=p[r1-1][c1-1];

    cout<<sum;
}
