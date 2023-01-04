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
    vector<int> g;
    vector<int> l;
    float avgG = 0;
    float avgL = 0;

    //set up input and calculate sums
    for(int i = 0; i < n; i++) {
        int num = 10;
        string id;
        cin >> id;
        cin >> num;

        if(id == "G") {
            g.push_back(num);
            avgG += num; 
        }else if (id == "L") {
            l.push_back(num);
            avgL += num;
        }
    }
       
    //calculate averages with sum
    avgG = avgG/g.size();
    avgL = avgL/l.size();

    //sort greater and lesser
    sort(g.begin(), g.end());
    sort(l.begin(), l.end(), greater<int>());

    int maxValue = 0;

if(g.size() == 0 || l.size() == 0) {
    maxValue =  g.size() + l.size();
}else{
    for(int i = 0; i < g.size(); i++) {
        for(int j = 0; j < l.size(); j++) {
            if(g.at(i) <= l.at(j)) {
                maxValue = max(maxValue, i+j+2);
            }
        }
    }
    
    
    
    maxValue = max(maxValue, (int) l.size());
    maxValue = max(maxValue, (int) g.size());
}
    
    cout << n-maxValue;
}

//O(N^2/2)
