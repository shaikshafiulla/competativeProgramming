#include <bits/stdc++.h>
using namespace std;
 int minSteps(int n) {
    unordered_set<int> se;
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                se.insert(d);
                n /= d;
            }
            d++;
        }
        int sum = 0;
        for(int i:se)
            sum+=i;
        return sum;
    }
int main(){
    int n;
    cin>>n;
	cout << minSteps(n);
	return 0;
}
