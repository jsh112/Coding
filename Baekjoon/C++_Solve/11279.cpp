#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void push_heap(vector<unsigned int>& heap, unsigned int value) {
    heap.push_back(value);
    int idx = heap.size() - 1;

    // Heapify-up
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] < heap[idx]) {
            swap(heap[parent], heap[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

void pop_heap(vector<unsigned int>& heap) {
    if (heap.empty()) return;

    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();


    int idx = 0;
    int size = heap.size();
    while (true) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int largest = idx;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest == idx) break;
        
        swap(heap[idx], heap[largest]);
        idx = largest;
    }
}

void MaxHeap(int n) {
    unsigned int num;
    vector<unsigned int> heap;

    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num == 0) {
            
            if (heap.empty()) {
                cout << "0" << '\n';
            } else {
                cout << heap[0] << '\n';
                pop_heap(heap); 
            }
        } else {
            
            push_heap(heap, num);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    MaxHeap(n);
    return 0;
}
