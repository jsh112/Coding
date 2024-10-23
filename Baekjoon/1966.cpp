#include <iostream>
#include <utility>
using namespace std;

class CircularQueue
{
private:
    std::pair<int, int> *arr;
    int size, front, rear, currentSize;

public:
    CircularQueue(int sz) : size(sz), front(-1), rear(-1), currentSize(0)
    {
        arr = new std::pair<int, int>[size + 1];
    }
    ~CircularQueue() { delete[] arr; }

    bool isFull() { return (currentSize == size); }

    bool isEmpty() { return (currentSize == 0); }

    void enqueue(int priority, int index)
    {
        if (isFull())
            return;
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % (size + 1);
        arr[rear] = {priority, index};
        currentSize++;
    }
    std::pair<int, int> dequeue()
    {
        if (isEmpty())
            return {-1, -1};
        std::pair<int, int> tmp = arr[front];
        front = (front + 1) % (size + 1);
        currentSize--;
        return tmp;
    }
    bool hasHigherPriority(int currentPriority)
    {

        int i = front;
        for (int count = 0; count < currentSize; count++)
        {
            if (arr[i].first > currentPriority)
            {
                return true;
            }
            i = (i + 1) % (size + 1);
        }
        return false;
    }
    void print_queue(int widx)
    {
        int cnt = 0;
        while (!isEmpty())
        {
            int currentPriority = arr[front].first;
            if (hasHigherPriority(currentPriority))
            {
                std::pair<int, int> tmp = dequeue();
                enqueue(tmp.first, tmp.second);
            }
            else
            {
                cnt++;
                std::pair<int, int> d = dequeue();

                if (d.second == widx)
                    std::cout << cnt << '\n';
            }
        }
    }
};

int main()
{
    int num_test;
    std::cin >> num_test;
    // num_test가 0이면 종료
    while (num_test--)
    {
        int num_doc, want_idx;
        std::cin >> num_doc >> want_idx;
        CircularQueue q(num_doc);

        for (int i = 0; i < num_doc; i++)
        {
            int priority;
            std::cin >> priority;
            q.enqueue(priority, i);
        }
        q.print_queue(want_idx);
    }

    return 0;
}