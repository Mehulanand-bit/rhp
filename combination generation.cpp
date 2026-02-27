#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void solve(){
	string s;
	cin>>s;
	int N=s.length();
	for(int ctr=1;ctr<(1<<N);ctr++){
		for(int sh=0;sh<N;sh++){
			if((ctr&(1&&sh))!=0){
				cout<<s[sh];
			}
		}
		cout<<endl;
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
