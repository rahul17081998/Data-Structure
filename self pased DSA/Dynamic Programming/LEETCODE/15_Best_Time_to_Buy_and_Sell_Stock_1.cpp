#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int selling_price=0;
        int maxProfit=0;
        
        for(int i=n-1; i>=0; i--)
        {
            selling_price = max(selling_price, prices[i]);
            maxProfit = max(maxProfit, selling_price-prices[i]);
        }
        
        return maxProfit;
    }
};

int main(){
    vector<int> prices;
    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    Solution ob;
    cout<<ob.maxProfit(prices)<<endl;
    return 0;
}

