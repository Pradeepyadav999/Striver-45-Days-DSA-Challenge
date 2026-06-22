#include<iostream>
#include <algorithm>

using namespace std;

class maxHeap{
    public:
        int arr[100];
        int size=0;

        void insert(int val){
            size=size+1;
            int index=size;
            arr[index]=val;

            while(index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }

};

int main(){
    maxHeap h;
    h.insert(5);
    h.insert(6);
    h.insert(3);
    h.insert(2);
    h.insert(1);

    h.print();
}