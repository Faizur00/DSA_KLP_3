#include <iostream>
#include <stack>
using namespace std;

void shiftStacks(stack<int>& s1, stack<int>& s2) {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
}

int main() {
    int q;cin >> q;

    stack<int> stack_enqueue;  // s1
    stack<int> stack_dequeue;  // s2

    for (int i = 0; i < q; ++i) {
        int tipe;
        cin >> tipe;

        if (tipe == 1) {
            int x;
            cin >> x;
            stack_enqueue.push(x);
        } else if (tipe == 2) {
            shiftStacks(stack_enqueue, stack_dequeue);
            if (!stack_dequeue.empty()) {
                stack_dequeue.pop();
            }
        } else if (tipe == 3) {
            shiftStacks(stack_enqueue, stack_dequeue);
            if (!stack_dequeue.empty()) {
                cout << stack_dequeue.top() << endl;
            }
        }
    }

    return 0;
}