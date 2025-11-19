#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
int n, m;
int get(int x){
	int sum = 1,h = 1,ans = 0;
	for (int i = 1; i <= x; i++){
		if (sum + h*(x - i + 1)/i < n){
			h = h*(x - i + 1)/i;
			sum += h;
			ans += h*i;
		}else{
		    ans+=(n - sum)*i;
			break;
		}
	}
	return ans;
}
bool check1(int x){
	if (x >= 60) return true;
	int xx = 1;
	for (int i = 1; i <= x; i++){
		xx*=2;
		if (x >= n) return true;
		if (xx >= 1e18) return true;
	}
	return (xx >= n);
}
bool check(int x){
	if (check1(x) == 0) return false;
	return get(x) <= x*m;
}
 
void solve() {
    // int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    int l = 1, r = n, mid;
    if ((1 << l) < n) l++;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

signed main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}