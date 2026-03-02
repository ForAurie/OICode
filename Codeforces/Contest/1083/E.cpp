#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n=0): n(n), p(n), sz(n,1) { for(int i=0;i<n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<ll>> w(n-1, vector<ll>(m));
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++) cin>>w[i][j];
        }
        vector<vector<ll>> v(n, vector<ll>(m-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++) cin>>v[i][j];
        }
        vector<string> p(n-1);
        for(int i=0;i<n-1;i++) cin>>p[i];
        vector<string> q(n);
        for(int i=0;i<n;i++) cin>>q[i];

        int R = n-1;
        int C = m-1;
        int tot = R * C; // number of faces (单元格)
        // compute A for each face (i,j), i in [0..R-1], j in [0..C-1]
        vector<ll> A;
        A.resize(tot, 0);
        auto id = [&](int i,int j){ return i*C + j; };
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                ll val = 0;
                // w[i][j] - w[i][j+1] + v[i][j] - v[i+1][j]
                val = w[i][j] - w[i][j+1] + v[i][j] - v[i+1][j];
                A[id(i,j)] = val;
            }
        }

        DSU dsu(tot);
        vector<int> forced_single; // faces that are adjacent to a forbidden edge on border (only one adjacent face)
        // process vertical edges w: indices i in [0..n-2], j in [0..m-1], p[i][j]
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]=='0'){ // cannot be reconstructed -> constraint
                    int left_j = j-1;
                    int right_j = j;
                    bool hasLeft = (left_j >= 0 && left_j < C);
                    bool hasRight = (right_j >= 0 && right_j < C);
                    if(hasLeft && hasRight){
                        int u = id(i, left_j);
                        int v_id = id(i, right_j);
                        dsu.unite(u, v_id);
                    }else if(hasLeft){
                        forced_single.push_back(id(i, left_j));
                    }else if(hasRight){
                        forced_single.push_back(id(i, right_j));
                    }else{
                        // this vertical edge does not border any face (shouldn't happen because C>=1), ignore
                    }
                }
            }
        }
        // process horizontal edges v: indices i in [0..n-1], j in [0..m-2], q[i][j]
        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                if(q[i][j]=='0'){
                    int top_i = i-1;
                    int bot_i = i;
                    bool hasTop = (top_i >= 0 && top_i < R);
                    bool hasBot = (bot_i >= 0 && bot_i < R);
                    if(hasTop && hasBot){
                        int u = id(top_i, j);
                        int v_id = id(bot_i, j);
                        dsu.unite(u, v_id);
                    }else if(hasTop){
                        forced_single.push_back(id(top_i, j));
                    }else if(hasBot){
                        forced_single.push_back(id(bot_i, j));
                    }else{
                        // shouldn't happen
                    }
                }
            }
        }

        // accumulate sums per component
        vector<ll> comp_sum(tot, 0);
        for(int f=0; f<tot; ++f){
            int r = dsu.find(f);
            comp_sum[r] += A[f];
        }
        // mark forced components
        vector<char> forced(tot, 0);
        for(int idx : forced_single){
            int r = dsu.find(idx);
            forced[r] = 1;
        }
        // compute answer
        ll ans = 0;
        for(int i=0;i<tot;i++){
            if(dsu.find(i) == i){
                if(forced[i]) continue; // must be 0
                if(comp_sum[i] > 0) ans += comp_sum[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}