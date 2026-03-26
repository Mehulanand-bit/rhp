#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<map>
#include<numeric>
using namespace std;
#define ll long long int

void display(vector<vector<int>>&mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

  

void solve(){
int R,C;
cin>>R>>C;
vector<vector<int>>mat(R,vector<int>(C));
vector<vector<int>>res(R,vector<int>(C));

for(int i=0;i<R;i++){
	for(int j=0;j<C;j++){
		cin>>mat[i][j];
	}
}

int max1=-1,max2=-1;

for(int j=0;j<C;j++){
	if(mat[0][j]>max1){
		max1=mat[0][j];
		max2=max1;
		}else{
			if(mat[0][j]>max2){
				max2=mat[0][j];
			}
		}
		
		res[0][j]=mat[0][j];
}

for(int i=1;i<R;i++){
	int maxr1=-1,maxr2=-1;
	for(int j=0;j<C;j++){
		
		if(mat[i-1][j]==max1){
			res[i][j]=mat[i][j]+max2;
		}else{
			res[i][j]=mat[i][j]+max1;
		}
		
		if(res[i][j]>maxr1){
		maxr1=res[i][j];
		maxr2=maxr1;
		}else{
			if(res[i][j]>maxr2){
				maxr2=res[i][j];
			}
		}
		
	}
	max1=maxr1;
	max2=maxr2;
}

cout<<max1<<endl;;

display(res);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--){
    	solve();
    }
    
}
