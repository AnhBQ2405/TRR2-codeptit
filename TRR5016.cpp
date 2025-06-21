#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
			int n, s, t, a[1001][1001], parent[1001][1001];
			void floyd(){
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						if(a[i][j] != 1e4 && a[i][j] != 0) parent[i][j] = j;
						else parent[i][j] = -1;
					}
				}
				for(int k = 1; k <= n; k++){
					for(int i = 1; i <= n; i++){
						for(int j = 1; j <= n; j++){
							if(a[i][j] > a[i][k] + a[k][j]){
								a[i][j] = a[i][k] + a[k][j];
								parent[i][j] = parent[i][k];
							}
						}
					}
				}
			}
			int main(){
			    freopen("DN.INP", "r", stdin);
			    freopen("DN.OUT", "w", stdout);
				cin >> n;
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++) cin >> a[i][j];
				}
				floyd();
				int res = 0;
				for(int i = 1; i <= n; i++){
					for(int j = i; j <= n; j++){
						if(a[i][j] != 0 && a[i][j] != 1e4 && res < a[i][j]){
							res = a[i][j];
							s = i; t = j;
						}
					}
				}
				cout << s << ' ' << t << ' ' << res << endl;
				vector<int> ans;
				ans.pb(s);
				while(s != t){
					s = parent[s][t];
					ans.pb(s);
				}
				for(int x : ans) cout << x << ' ';
			}
