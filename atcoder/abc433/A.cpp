#include<bits/stdc++.h>
using namespace std;   
#define int long long
constexpr int N = 1e6+10;

int n;
string s;
vector<pair<int, int> > umy;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; ){
        
    // cout << i << endl;
        int cnt = 0;
        for(int j = i; j <= n; j++){
            if(s[i] != s[j]){
                umy.push_back({s[i], cnt});
                i = j;
                goto nxt;
            }
            cnt++;
            if(j == n){
                break;
            }
        }
        if(s[i] == s[n]){
            umy.push_back({s[i], cnt});
            i = n+1;
        }
        nxt:;
    }
    int ans = 0;
    for(int i = 1; i < (int)umy.size(); i++){
        if(umy[i].first == umy[i-1].first+1){
            ans += min(umy[i].second, umy[i-1].second);
        }
    }
    cout << ans;

    return 0;
}