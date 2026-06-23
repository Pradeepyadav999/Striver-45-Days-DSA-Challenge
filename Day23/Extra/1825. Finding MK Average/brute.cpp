#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MKAverage {
public:
    int m,k;
    vector<int>stream;
    MKAverage(int m, int k) {
        this->m=m;
        this->k=k;
    }
    
    void addElement(int num) {
        stream.push_back(num);
    }
    
    int calculateMKAverage() {
        if(stream.size()<m){
            return -1;
        }
        vector<int>temp;
        // Take last m elements
        for(int i=stream.size() - m; i < stream.size(); i++){
            temp.push_back(stream[i]);
        }
        sort(temp.begin(),temp.end());
        long long sum = 0;
        for(int i=k;i<m-k;i++){
            sum += temp[i];
        }
        return sum / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

int main() {
    MKAverage* obj = new MKAverage(3, 1);
    obj->addElement(3);
    obj->addElement(1);
    obj->addElement(10);
    int param_2 = obj->calculateMKAverage();
    cout << "MK Average: " << param_2 << endl; // Output: 3
    return 0;
}