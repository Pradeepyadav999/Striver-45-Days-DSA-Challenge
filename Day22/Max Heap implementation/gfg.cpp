#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class maxHeap {
  private:
    vector<int>heap;
  public:

    void push(int x) {
        heap.push_back(x);
        
        int index=heap.size()-1;
        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]< heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void pop() {
        if(heap.empty()) return;
        
        heap[0] = heap.back();
        heap.pop_back();
        int index = 0;
        while(true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int largest = index;

            if(left < heap.size() &&
               heap[left] > heap[largest])
                largest = left;

            if(right < heap.size() &&
               heap[right] > heap[largest])
                largest = right;

            if(largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }
    int peek() {
        if(heap.empty())
            return -1;
        return heap[0];    }

    int size() {
        return heap.size();
    }
};

int main(){
    maxHeap h;
    h.push(5);
    h.push(6);
    h.push(3);
    h.push(2);
    h.push(1);

    cout << "Max element: " << h.peek() << endl; // Output: 6
    cout << "Size of heap: " << h.size() << endl; // Output: 5

    h.pop();
    cout << "Max element after pop: " << h.peek() << endl; // Output: 5
    cout << "Size of heap after pop: " << h.size() << endl; // Output: 4

    return 0;
}