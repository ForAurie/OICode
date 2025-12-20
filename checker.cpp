#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        system("gen.exe>data.in");
        system("main.exe<data.in>data.out");
        system("chk.exe<data.in>data.ans");
        if (system("fc data.out data.ans")) {
            return 0;
        }
    }
}