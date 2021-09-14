#include "minHeap.h"


void minHeap::insert(int value){                    // insert function

    heap.push_back(value);                            // adding value

    int pos = heap.size() - 1;

    siftUp(pos);

}

void minHeap::siftDown(int pos){
                 
    int lchild = (2 * pos) + 1;
    int rchild = (2 * pos) + 2;
    int smallest = pos;
        
            if ((lchild < heap.size()) && (heap[lchild] < heap[pos])){
                
                smallest = lchild;

            }

            if (rchild < heap.size() && heap[rchild] < heap[smallest]){
                
                smallest = rchild;

            }

            if (smallest != pos) {
            
                swap(heap[pos], heap[smallest]);
                siftDown(smallest);

            }
}




void minHeap::siftUp(int pos){
            
    int parent = (pos - 1) / 2;

    if (pos && heap[parent] > heap[pos]){
                
        swap(heap[pos], heap[parent]);

        siftUp(parent);
    
    }
        
}


minHeap::minHeap(vector<int> data){

    heap = data;
    int index = (heap.size() / 2) - 1;

        for (int i = index; i >= 0; i--) {
 
            siftDown(i);
 
        }

}



int minHeap::removeMin(){
            
    int root = heap[0];

    heap[0] = heap.back();
    
    heap.pop_back();

    siftDown(0);
        
return root;

}