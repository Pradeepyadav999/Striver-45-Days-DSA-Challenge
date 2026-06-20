class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash;
        for(int bill : bills) {
            if(bill == 5) {
                cash.push_back(5);
            }
            else if(bill == 10) {
                auto it = find(cash.begin(), cash.end(), 5);
                if(it == cash.end())
                    return false;
                cash.erase(it);
                cash.push_back(10);
            }
            else { 
                int change = 15;
                for(int i = cash.size() - 1; i >= 0 && change > 0; i--) {
                    if(cash[i] <= change) {
                        change -= cash[i];
                        cash.erase(cash.begin() + i);
                    }
                }
                if(change != 0)
                    return false;
                cash.push_back(20);
            }
        }
        return true;
    }
};