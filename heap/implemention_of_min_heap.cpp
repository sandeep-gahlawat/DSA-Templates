#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return (2 * index) + 1;
    }

    int getRightChildIndex(int index) {
        return (2 * index) + 2;
    }

    void heapifyUp(int index) {
        if (index == 0)
            return;

        int parentIndex = getParentIndex(index);
        if (heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int smallestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallestIndex])
            smallestIndex = leftChildIndex;

        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex])
            smallestIndex = rightChildIndex;

        if (smallestIndex != index) {
            std::swap(heap[index], heap[smallestIndex]);
            heapifyDown(smallestIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    void removeMin() {
        if (heap.empty())
            return;

        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    int getMin() {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");

        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(1);

    while (!minHeap.isEmpty()) {
        std::cout << minHeap.getMin() << " ";
        minHeap.removeMin();
    }

    return 0;
}
