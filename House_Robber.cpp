#include<bits/stdc++.h>
using namespace std;

int houseRobber(vector<int> cashMoney) {
    int n = cashMoney.size();
    int prev1 = cashMoney[0];
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int steal = cashMoney[i];
        if(i > 1) steal += prev2;
        int notSteal = 0 + prev1;
        int currSteal = max(steal, notSteal);
        prev2 = prev1;
        prev1 = currSteal;
    }
    return prev1;
}

int main() {
    vector<int> valueInHouse = {1, 3, 2, 1};
    int n = valueInHouse.size();
    vector<int> temp1, temp2;
    if(n == 1) return valueInHouse[0];
    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    int totalStealMoney = max(houseRobber(temp1), houseRobber(temp2));

    cout << totalStealMoney;

    return 0;
}