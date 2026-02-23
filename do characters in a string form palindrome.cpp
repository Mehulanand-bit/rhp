#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void solve(){
	string s;
	cin>>s;
	int flag=0;
	
	for (char ch:s){
	flag=flag^(1<<(ch-'a'));
	}
	if(flag==0 || (flag&(flag-1)==0)){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	
}
int main(){
	 ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;

}
