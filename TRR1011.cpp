#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define ii pair<int, int>
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int a[1001][1001], V, E, U, visited[1001], cnt[1001]; vector<int> ke[1001], EC; set<int> dske[1001]; 
		struct canh{
			int x, y, w;
		};
		vector<canh> v;
		int main(){
			freopen("DT.INP", "r", stdin);
			freopen("DT.OUT", "w", stdout);
			int t; cin >> t >> V >> E;
			memset(cnt, 0, sizeof(cnt));
			memset(a, -1, sizeof(a));
			for(int i = 1; i <= E; i++){
				int x, y, w; cin >> x >> y >> w;
				cnt[x]++; cnt[y]++;
				a[x][y] = w; a[y][x] = w;
			}
			if(t == 1){
				for(int i = 1; i <= V; i++) cout << cnt[i] << ' ';
			}
			else{
				cout << V << endl;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						if(i == j) cout << 0 << ' ';
						else if(a[i][j] == -1) cout << 10000 << ' ';
						else cout << a[i][j] << ' ';
					}
					cout << endl;
				}
			}
		}
