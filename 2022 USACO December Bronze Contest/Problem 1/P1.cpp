#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    //Cases input
    int n;
    cin >> n;

    //Variables
    vector<int> prices;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prices.push_back(x);
    }
    sort(prices.begin(), prices.end(), greater<int>());

    long long sum = 0;
    int set = prices.at(0);

    for(int i=0;i<n;i++) {
        int s = prices.at(i);
        long long cP = (long long) s * (long long) (i+1);
        
        if(cP > sum) {
            sum = (long long) s * (long long) (i+1);
            set = s;
        }else if(cP == sum && s < set) {
            set = s;
        }
    }
    
    cout << sum << " " << set << endl;
}
