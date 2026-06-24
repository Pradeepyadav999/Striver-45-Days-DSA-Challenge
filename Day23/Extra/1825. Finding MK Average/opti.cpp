#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

class MKAverage {
public:
    int m, k;
    queue<int> q;

    multiset<int> low, mid, high;

    long long midSum = 0;

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void balance() {

        while(low.size() > k) {
            auto it = prev(low.end());

            mid.insert(*it);
            midSum += *it;

            low.erase(it);
        }

        while(low.size() < k && !mid.empty()) {
            auto it = mid.begin();

            low.insert(*it);
            midSum -= *it;

            mid.erase(it);
        }

        while(high.size() > k) {
            auto it = high.begin();

            mid.insert(*it);
            midSum += *it;

            high.erase(it);
        }

        while(high.size() < k && !mid.empty()) {
            auto it = prev(mid.end());

            high.insert(*it);
            midSum -= *it;

            mid.erase(it);
        }
    }

    void addElement(int num) {

        q.push(num);

        if(low.empty() || num <= *prev(low.end())) {
            low.insert(num);
        }
        else if(high.empty() || num >= *high.begin()) {
            high.insert(num);
        }
        else {
            mid.insert(num);
            midSum += num;
        }

        balance();

        if(q.size() > m) {

            int old = q.front();
            q.pop();

            auto it = low.find(old);

            if(it != low.end()) {
                low.erase(it);
            }
            else if((it = high.find(old)) != high.end()) {
                high.erase(it);
            }
            else {
                it = mid.find(old);

                midSum -= old;
                mid.erase(it);
            }

            balance();
        }
    }

    int calculateMKAverage() {

        if(q.size() < m)
            return -1;

        return midSum / (m - 2 * k);
    }
};


int main() {
    MKAverage* obj = new MKAverage(3, 1);
    obj->addElement(3);
    obj->addElement(1);
    obj->addElement(10);
    int param_2 = obj->calculateMKAverage();
    cout << "MK Average: " << param_2 << endl; // Output: 3
    return 0;
}