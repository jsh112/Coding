#include <iostream>
#include <vector>

class MinHeap {
   private:
    std::vector<unsigned int> heap;

    // 삽입 후 정렬하는 함수

    void heapup(int idx) {
        if (idx == 0)
            return;
        int pIdx = (idx - 1) / 2;

        // 부모보다 작은 경우 교환
        if (heap[idx] < heap[pIdx]) {
            std::swap(heap[idx], heap[pIdx]);
            heapup(pIdx);
        }
    }

    // 삭제 후 정렬하는 함수
    void heapdown(int idx) {
        int left_cIdx = 2 * idx + 1;
        int right_cIdx = 2 * idx + 2;
        int smallestIdx = idx;

        // 왼쪽 자식과 비교
        if (left_cIdx < heap.size() && heap[left_cIdx] < heap[smallestIdx])
            smallestIdx = left_cIdx;

        // 오른쪽 자식과 비교
        if (right_cIdx < heap.size() && heap[right_cIdx] < heap[smallestIdx])
            smallestIdx = right_cIdx;

        if (smallestIdx != idx) {
            std::swap(heap[idx], heap[smallestIdx]);
            heapdown(smallestIdx);
        }
    }

   public:
    void insert(int value) {
        heap.push_back(value);
        heapup(heap.size() - 1);
    }

    // 최솟값 제거 후 반환
    void extractMin() {
        if (heap.empty()) {
            std::cout << "0\n";
            return;
        }
        int minValue = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapdown(0);
        std::cout << minValue << '\n';
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    MinHeap heap;

    unsigned int x;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x == 0) {
            heap.extractMin();
        } else {
            heap.insert(x);
        }
    }

    return 0;
}