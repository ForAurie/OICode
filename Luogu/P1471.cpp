#include <cstdio>
#include <cstddef>
#include <cctype>
#include <type_traits>
#include <string>
template<size_t BUF_SIZE = (1 << 20) * 4>
class FastIO {
private:
    char outdat[BUF_SIZE], indat[BUF_SIZE];
    size_t n = 0, outidx = 0, inidx = 0;
    FILE* inFile;
    FILE* outFile;
public:
    FastIO(FILE* in = stdin, FILE* out = stdout) : inFile(in), outFile(out) {}
    inline void putchar(char c) {
        outdat[outidx++] = c;
        if (outidx == BUF_SIZE) {
            std::fwrite(outdat, 1, BUF_SIZE, outFile);
            outidx = 0;
        }
    }
    inline void flush() { if (outidx) std::fwrite(outdat, 1, outidx, outFile), outidx = 0; }
    inline char getchar() {
        if (inidx >= n) {
            n = std::fread(indat, 1, BUF_SIZE, inFile);
            inidx = 0;
            if (n == 0) return -1;
        }
        return indat[inidx++];
    }
    template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
    inline FastIO& operator<<(T x) {
        static char s[24];
        if (x < 0) putchar('-'), x = -x;
        int n = 0;
        do s[n++] = x % 10 | 0x30, x /= 10;
        while (x);
        while (n--) putchar(s[n]);
        return *this;
    }
    template<typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline FastIO& operator>>(T& x) {
        x = 0;
        char ch = getchar();
        bool flag = false;
        while (!std::isdigit(ch)) {
            if (ch == '-') flag = true;
            ch = getchar();
        }
        while (std::isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch & 15);
            ch = getchar();
        }
        if (flag) x = -x;
        return *this;
    }
    template<typename T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
    inline FastIO& operator>>(T& x) {
        x = 0;
        bool neg = false;
        char ch = getchar();
        while (!std::isdigit(ch) && ch != '.') {
            if (ch == '-') neg = true;
            ch = getchar();
        }
        while (std::isdigit(ch)) {
            x = x * 10 + (ch ^ 0x30);
            ch = getchar();
        }
        if (ch == '.') {
            ch = getchar();
            T div = static_cast<T>(1);
            while (isdigit(ch)) {
                div /= 10;
                x += (ch ^ 0x30) * div;
                ch = getchar();
            }
        }
        if (neg) x = -x;
        if (ch == 'E' || ch == 'e') {
            ch = getchar();
            neg = false;
            if (ch == '+') {
                ch = getchar();
            } else if (ch == '-') {
                neg = true;
                ch = getchar();
            }
            int exp = 0;
            while (isdigit(ch)) {
                exp = (exp << 3) + (exp << 1) + (ch ^ 0x30);
                ch = getchar();
            }
            T base = 10;
            if (neg) {
                while (exp) {
                    if (exp & 1) x /= base;
                    base *= base;
                    exp >>= 1;
                }
            } else {
                while (exp) {
                    if (exp & 1) x *= base;
                    base *= base;
                    exp >>= 1;
                }
            }
        }
        return *this;
    }
    inline FastIO& operator<<(char ch) { putchar(ch); return *this; }
    inline FastIO& operator>>(char& ch) {
        ch = getchar();
        while(!std::isgraph(ch)) ch = getchar();
        return *this;
    }
    inline FastIO& operator<<(const std::string& s) {
        for (const auto& i : s) putchar(i);
        return *this;
    }
    inline FastIO& operator>>(std::string& s) {
        char ch = getchar();
        while(!std::isgraph(ch)) ch = getchar();
        s.clear();
        do s.push_back(ch), ch = getchar();
        while (std::isgraph(ch));
        return *this;
    }
    ~FastIO() {
        flush();
    }
};
FastIO<(1 << 20) * 4> __IOER__;
#include <bits/stdc++.h>
#define cin __IOER__
#define cout __IOER__
#define getchar __IOER__.getchar
#define putchar __IOER__.putchar
#define fflush(stdout) __IOER__.flush()
#define endl '\n'
using namespace std;
const int N = 1e5+10;
typedef double Type;

struct node{
    Type v, vv, tag;
}tr[N << 4];
int m;

inline void build(const int &n){
    for(m=1;m<=n;m<<=1);
    for(int i = m+1;i<=m+n;++i) cin >> tr[i].v,tr[i].vv = tr[i].v*tr[i].v;
    for(int i = m-1;i;--i)tr[i].v=tr[i<<1].v+tr[i<<1|1].v,tr[i].vv = tr[i<<1].vv+tr[i<<1|1].vv;
}

inline void add(int l,int r,const Type &v){
    Type lres=0,rres=0;
    int lm=0,rm=0,now=1;
    for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1,now<<=1){
        lres+=lm*tr[l].tag;
        rres+=rm*tr[r].tag;

        tr[l].vv+=v*(v*lm+2*lres);
        tr[r].vv+=v*(v*rm+2*rres);
        
        tr[l].v+=v*lm;
        tr[r].v+=v*rm;
        
        if(~l&1)lres+=tr[l^1].v,tr[l^1].tag+=v,tr[l^1].vv+=v*(v*now+2*tr[l^1].v),tr[l^1].v+=v*now,lm+=now;
        if(r&1)rres+=tr[r^1].v,tr[r^1].tag+=v,tr[r^1].vv+=v*(v*now+2*tr[r^1].v),tr[r^1].v+=v*now,rm+=now;
    }
    lres+=lm*tr[l].tag;
    rres+=rm*tr[r].tag;
    tr[l].vv+=v*(v*lm+2*lres);
    tr[r].vv+=v*(v*rm+2*rres);

    tr[l].v+=v*lm;
    tr[r].v+=v*rm;
    lm+=rm;
    lres+=rres;
    l>>=1;
    for(;l;l>>=1){
        lres+=tr[l].tag*lm;
        tr[l].v+=v*lm;
        tr[l].vv+=v*(v*lm+2*lres);
        
    }
}


inline Type query(int l,int r){
    Type res = 0;
    int lm=0,rm=0,now=1;
    
    for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1,now<<=1){
        res+=tr[l].tag*lm+tr[r].tag*rm;
        if(~l&1)res+=tr[l^1].v,lm+=now;
        if(r&1)res+=tr[r^1].v,rm+=now;
    }
    res+=tr[l].tag*lm+tr[r].tag*rm;
    l>>=1;
    lm+=rm;
    for(;l;l>>=1){
        res+=tr[l].tag*lm;
    }
    return res;
}

inline Type queryt(int l,int r){
    Type lres=0,rres=0,res=0;
    int lm = 0,rm = 0,now = 1;
    for(l+=m-1,r+=m+1;l^r^1;l>>=1,r>>=1,now<<=1){
        res+=tr[l].tag*tr[l].tag*lm+tr[r].tag*tr[r].tag*rm+2*(tr[l].tag*lres+tr[r].tag*rres);
        lres+=tr[l].tag*lm;
        rres+=tr[r].tag*rm;
        if(~l&1)lres+=tr[l^1].v,res+=tr[l^1].vv,lm+=now;
        if(r&1)rres+=tr[r^1].v,res+=tr[r^1].vv,rm+=now;
    }
    res+=tr[l].tag*tr[l].tag*lm+tr[r].tag*tr[r].tag*rm+2*(tr[l].tag*lres+tr[r].tag*rres);
    l>>=1;
    lm+=rm;
    lres+=rres+tr[l].tag*lm+tr[r].tag*rm;
    for(;l;l>>=1){
        res+=tr[l].tag*(lm+2*lres);
        lres+=tr[l].tag*lm;
    }
    return res;
}
inline void printd(double ans){
    if(ans<0)ans=-ans,putchar('-');
    ans+=0.00005;
    cout << (int)ans;
    putchar('.');
    int res = (ans-(int)ans)*10000;
    if(res==0){
        cout << "0000\n";
        return;
    }else if(res<10){
        putchar('0');putchar('0');putchar('0');
    }else if(res<100){
        putchar('0');putchar('0');
    }else if(res<1000){
        putchar('0');
    }
    cout << res << endl;
}
int main(){
    int n, q;
    cin >> n >> q;
    build(n);
    int op, x, y;
    Type v;
    while(q--){
        cin >> op >> x >> y;
        switch(op){
            case 1:
                cin >> v;
                add(x, y, v);
            break;
            case 2:
                printd(query(x, y) / (y - x + 1));
            break;
            default:
                double eva = query(x, y);
                eva *= eva / (y - x + 1);
                printd((queryt(x, y) - eva) / (y - x + 1));
            break;
        }
    }
    return 0;
}