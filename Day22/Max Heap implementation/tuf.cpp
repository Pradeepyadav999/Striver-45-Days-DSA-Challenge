#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    vector<int>heap;
    public:
        void initializeHeap(){
            heap.clear();
        }
        void insert(int key){
            heap.push_back(key);
        
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

        void changeKey(int index, int new_val){
             int old = heap[index];
            heap[index] = new_val;
            if(new_val > old){
                while(index > 0){
                    int parent = (index - 1) / 2;
                    if(heap[parent] < heap[index]){
                        swap(heap[parent], heap[index]);
                        index = parent;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                while(true){
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
        }

        void extractMax(){
            if(heap.empty()) return;
            heap[0] = heap.back();
            heap.pop_back();
            int index = 0;
            while(true){
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

        bool isEmpty(){
            return heap.empty();
        }

        int getMax(){
            if(heap.empty()){
                return -1;
            }
            return heap[0];   
        }

        int heapSize(){
            return heap.size();
        }
};

int main(){
    Solution s;
    s.initializeHeap();
    s.insert(10);
    s.insert(20);
    s.insert(5);
    cout << "Max: " << s.getMax() << endl; // Output: Max: 20
    s.changeKey(1, 25); // Change value at index 1 to 25
    cout << "Max after changeKey: " << s.getMax() << endl; // Output: Max after changeKey: 25
    s.extractMax();
    cout << "Max after extractMax: " << s.getMax() << endl; // Output: Max after extractMax: 10
    return 0;
}