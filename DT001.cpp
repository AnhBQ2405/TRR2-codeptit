#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int main(){
			int t, n; cin >> t >> n;
			int a[n + 1][n + 1], cnt[1001], ans; vector<int> ke[1001];
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					cin >> a[i][j];
					cnt[i] += a[i][j];
					if(a[i][j] && i < j){
						ke[i].pb(j);
						++ans;
					}
				}
			}
			if(t == 1){
				for(int i = 1; i <= n; i++) cout << cnt[i] << ' ';
			}
			else{
				cout << n << ' ' << ans << endl;
				for(int i = 1; i <= n; i++){
					for(int x : ke[i]){
						cout << i << ' ' << x << endl;
					}
				}
			}
		}
