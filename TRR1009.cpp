#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 	
		int V, E, a[1001][1001];	vector<ii> canh;
			int main(){
//				freopen("DT.INP", "r", stdin);
//				freopen("DT.OUT", "w", stdout);
				int t; cin >> t >> V; memset(a, 0, sizeof(a));
				int cnt[V + 1]; memset(cnt, 0, sizeof(cnt));
				for(int i = 1; i <= V; i++){
						int sz; cin >> sz;
						while(sz--){
							int x; cin >> x;
							    if(i < x){
							    	cnt[i]++; cnt[x]++;
								canh.pb({i, x});
							}
						}
					}
				if(t == 1){
					for(int i = 1; i <= V; i++) cout << cnt[i] << ' ';	
				}
				else{
					cout << V << ' ' << canh.size() << endl;
					for(int i = 0; i < canh.size(); i++){
						a[canh[i].first][i + 1] = 1;
						a[canh[i].second][i + 1] = 1;
					}
					for(int i = 1; i <= V; i++){
						for(int j = 1; j <= canh.size(); j++) cout << a[i][j] << ' ';
						cout << endl;
					}
				}
			}
