#include <iostream>
#include <stack>
using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack_enqueue;
    stack<int> stack_dequeue;

    void transferStack() {
        // Transfer only if stack_dequeue is empty
        if (stack_dequeue.empty()) {
            while (!stack_enqueue.empty()) {
                stack_dequeue.push(stack_enqueue.top());
                stack_enqueue.pop();
            }
        }
    }

public:
    void enqueue(int x) {
        stack_enqueue.push(x);
    }

    void dequeue() {
        transferStack();
        if (!stack_dequeue.empty()) {
            stack_dequeue.pop();
        }
    }

    void printFront() {
        transferStack();
        if (!stack_dequeue.empty()) {
            cout << stack_dequeue.top() << endl;
        }
    }
};

int main() {
    int q;
    cin >> q;

    QueueUsingTwoStacks queue;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (type == 2) {
            queue.dequeue();
        } else if (type == 3) {
            queue.printFront();
        }
    }

    return 0;
}
