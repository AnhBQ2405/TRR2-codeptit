#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define ii pair<int, int>
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int a[1001][1001], b[1001][1001], V, E, U, visited[1001], cnt[1001], in[1001], out[1001]; vector<int> ke[1001], EC; vector<ii> canh;
		int main(){
			freopen("DT.INP", "r", stdin);
			freopen("DT.OUT", "w", stdout);
			memset(a, 0, sizeof(a));
			int t; cin >> t >> V;
			memset(in, 0, sizeof(in));
			memset(out, 0, sizeof(out));
			for(int i = 1; i <= V; i++){
				int sz; cin >> sz;
				while(sz--){
					int j; cin >> j;
					canh.pb({i, j});
					in[j]++; out[i]++;
				}
			}
			if(t == 1){
				for(int i = 1; i <= V; i++) cout << in[i] << ' ' << out[i] << endl;
			}
			else{
				cout << V << ' ' << canh.size() << endl;
				for(auto x : canh){
					cout << x.first << ' ' << x.second << endl;
				}
			}
		}
