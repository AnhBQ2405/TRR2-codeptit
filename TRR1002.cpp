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
			fstream in, out;
			in.open("DT.INP", ios :: in);
			out.open("DT.OUT", ios :: out);
			int t, n; in >> t >> n;
			int a[n + 1][n + 1]; vector<int> ke[1001];
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					in >> a[i][j];
					if(a[i][j]) ke[i].pb(j);
				}
			}
			if(t == 1){
				for(int i = 1; i <= n; i++) out << ke[i].size() << ' ';
			}
			else{
				out << n << endl;
				for(int i = 1; i <= n; i++){
					out << ke[i].size() << ' ';
					for(int x : ke[i]){
						out << x << ' ';
					}
					out << endl;
				}
			}
		}
