#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<map>
#include<numeric>
using namespace std;
#define ll long long int

  

void solve(){

string s;
cin>>s;
vector<int>lt(26,0);
vector<int>rt(26,0);

for(chat ch:s){
	rt[ch-'a']++;
}
ll count=0;
for(char ch:s){
	rt[ch-'a']--;
	for(char edge='a';edge<='z';edge++){
		count+=(lt[edge-'a']*rt[edge-'a']);
	}
	lt[ch-'a']++;
}

cout<<count;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    
}
