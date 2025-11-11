#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int cnt = 0, sign = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	sign = -1;
		c = getchar();
	}
	while(isdigit(c)){
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * sign;
}//quick read
const int N = 4e5 + 10;
const int inf = 2e18;
int a[N], bfmx1[N], bfmn1[N];//before max1, before min1
int b[N], afmx2[N], afmn2[N];//after max2, after min2
int minn[N], maxn[N], M[N], mn[N];
void solve(){
	int n = read();
	int size = 2 * n;
	bfmx1[0] = -inf;
	bfmn1[0] = inf;
	for(int i = 1; i <= n; i++){
		a[i] = read();
		bfmx1[i] = max(bfmx1[i - 1], a[i]);
		bfmn1[i] = min(bfmn1[i - 1], a[i]);
	}
	afmx2[n + 1] = -inf;
	afmn2[n + 1] = inf;
	for(int i = 1; i <= n; i++){
		b[i] = read();
	}
	for(int i = n; i >= 1; i--){
		afmx2[i] = max(afmx2[i + 1], b[i]);
		afmn2[i] = min(afmn2[i + 1], b[i]);
	}
	for(int i = 1; i <= n; i++){
		minn[i] = min(bfmn1[i], afmn2[i]);
		maxn[i] = max(bfmx1[i], afmx2[i]);
	}
	for(int i = 1; i <= size; i++){
		M[i] = inf;
	}
	for(int i = 1; i <= n; i++){
		int m = minn[i];
		M[m] = min(M[m], maxn[i]);
	}
	mn[size + 1] = inf;
	int k = inf;
	for(int i = size; i >= 1; i--){
		k = min(k, M[i]);
		mn[i] = k;
	}
	int fs = 0;
	for(int i = 1; i <= size; i++){
		if(mn[i] > size){
			fs += (size - i + 1);
		}else{
			int cnt = mn[i] - i;
			if(cnt > 0)	fs += cnt;
		}
	}
	int total = (size * (size + 1)) / 2;
	printf("%lld\n", total - fs);
}
signed main(){
	int T = read();
	while(T--){
		solve();
	}
	return 0;
}