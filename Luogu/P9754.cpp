#include<bits/stdc++.h>
using namespace std;
const string ERR = "ERR"; const pair<string, int> PRE[] = { make_pair("byte", 1), make_pair("short", 2), make_pair("int", 4), make_pair("long", 8) };
size_t& Id(const string& s) { static unordered_map<string, size_t> mp; return mp[s]; }
inline size_t calc(size_t p, size_t al) { return p == 0 ? 0 : ((p - 1) / al + 1) * al; }
struct Class {
    string name;
    size_t al, sz, id;
    vector<pair<int, string>> son; vector<size_t> mv;
    Class(const string& name, size_t id, size_t sz) : name(name), al(sz), sz(sz), id(id) { Id(name) = id; }
    void insert(const Class& x, const string& name) {
        son.push_back(make_pair(x.id, name));
        al = max(al, x.al);
        mv.push_back(calc(sz, x.al));
        sz = mv.back() + x.size();
    }
    size_t size() const { return calc(sz, al); }
};
vector<Class> cs;
size_t find(const Class& u, stack<string>& s) {
    if (s.empty()) return 0;
    for (int i = 0; i < (int) u.son.size(); i++)
        if (u.son[i].second == s.top())
            return s.pop(), find(cs[u.son[i].first], s) + u.mv[i];
    return 0;
}
string query(const Class& u, size_t addr) {
    if (u.id < 4) {
        if (addr >= cs[u.id].size()) return ERR;
        else return "";
    }
    for (int i = 0; i < (int) u.son.size(); i++) {
        if (i + 1 == (int) u.son.size() || u.mv[i + 1] > addr) {
            if (addr >= u.mv[i] + cs[u.son[i].first].size()) return ERR;
            auto res = query(cs[u.son[i].first], addr - u.mv[i]);
            if (res == ERR) return ERR;
            else return u.son[i].second + '.' + res;
        }
    }
    return ERR;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (auto i : PRE) cs.push_back(Class(i.first, cs.size(), i.second));
    Class main(ERR, -1, 0);
    int n, op, k; size_t addr; string name, type;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 1) {
            cin >> name >> k;
            cs.push_back(Class(name, cs.size(), 0));
            while (k--)
                cin >> type >> name, cs.back().insert(cs[Id(type)], name);
            cout << cs.back().size() << ' ' << cs.back().al << '\n';
        } else if (op == 2) {
            cin >> type >> name;
            main.insert(cs[Id(type)], name);
            cout << main.mv.back() << '\n';
        } else if (op == 3) {
            cin >> name;
            stack<string> st, s; string tmp;
            for (auto i : name) {
                if (i == '.') st.push(tmp), tmp.clear();
                else tmp.push_back(i);
            }
            if (tmp.size()) st.push(tmp);
            while (st.size()) s.push(st.top()), st.pop();
            cout << find(main, s) << '\n';
        } else {
            cin >> addr;
            auto res = query(main, addr);
            if (res.size() && res.back() == '.') res.pop_back();
            if (res == ERR) cout << "ERR\n";
            else cout << res << '\n';
        }
    }
	return 0;
}