#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<map>
#include<numeric>
using namespace std;
#define ll long long int

int find(vector<int>&seg,int node,int nl,int nr,int l, int r){
	if(nl>=l && nr<=r){
		return seg[node];
	}
	if(nr<l || nl>r){
		return 0;
	}
	
	return find(seg,2*node,nl,(nl+nr)/2,l,r)+ find(seg,(2*node)+1,((nr+nl)/2)+1,nr,l,r);
	
}


void solve(){
   int N;
   cin>>N;
   int tpow=0;
   while((1<<tpow)<N)tpow++;
   int newN=(1<<tpow);
   
   vector<int>segment_tree((newN+newN),0);
   for(int i=newN;i<(newN+N);i++){
   	cin>>segment_tree[i];
   }
   
   for(int i=newN-1;i>0;i--){
   	segment_tree[i]=segment_tree[2*i]+segment_tree[(2*i)+1];
   }
   
   for(int i=1;i<(newN+N);i++){
   	cout<<segment_tree[i]<<" ";
   }
   cout<<endl;
   N=newN;
   int q;
   cin>>q;
   
   while(q-->0){
   	int x,y;
   	cin>>x>>y;
   	cout<<find(segment_tree,1,1,N,x,y)<<endl;
   	
   }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
   
    while(t--){
    	solve();
    }
    
}
