#include <iostream>
#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int>prices;
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        int span = 1;
        int n = prices.size() - 1;
        for(int i= n-1;i>=0;i--){
            if(prices[i] <= price)
                span++;
            else
                break;
        }
        return span;
    }
};

int main(){
    StockSpanner* obj = new StockSpanner();
    cout<<obj->next(100)<<endl;
    cout<<obj->next(80)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(70)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(75)<<endl;
    cout<<obj->next(85)<<endl;
}