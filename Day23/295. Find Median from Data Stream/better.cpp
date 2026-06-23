#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

class MedianFinder {
public:
    // Declare vector 
    vector<int>nums;
    MedianFinder() {
    }
    
    void addNum(int num) {
        auto it = lower_bound(nums.begin(),nums.end(),num);
        nums.insert(it,num);
    }
    
    double findMedian() {
        int n = nums.size();
        if(n%2 == 1){
            return nums[n/2];
        }else{
            return (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout<<obj->findMedian()<<endl;
    obj->addNum(3);
    cout<<obj->findMedian()<<endl;
    return 0;
 }