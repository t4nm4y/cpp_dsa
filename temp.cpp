#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s; 
    int n=s.length();
    int zeros_before = s.find('1');
    int zeros_after = n - 1 - s.rfind('1');

    int ones_count = 0;
    for (int i = zeros_before; i <= n - zeros_after - 1; i++) {
        if (s[i] == '1') {
            ones_count++;
        }
    }
    cout << min(zeros_before + ones_count + zeros_after, n) << endl;
    return 0;
}

