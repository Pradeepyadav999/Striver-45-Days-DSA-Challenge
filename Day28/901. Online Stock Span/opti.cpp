#include <iostream>
#include <vector>
using namespace std;

class StockSpanner {
public:
    vector<int>prices;
    vector<int>spans;
    StockSpanner() {
    }
    int next(int price) {
        int span = 1;
        int i = prices.size() - 1;
        while(i>=0 && prices[i]<=price){
            span+=spans[i];
            i-=spans[i]; //Jump back by span
        }
        prices.push_back(price);
        spans.push_back(span);

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