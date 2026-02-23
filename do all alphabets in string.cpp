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
        flag=flag|(1<<ch-'a');
	}
	cout<<((flag == (1<<(26-1)))?"yes":"no");

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
