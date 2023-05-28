#include <iostream>
#include <queue>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {}

    int max_value() {
        if (maxque.empty()) {
            return -1;
        }
        return maxque.front();
    }

    void push_back(int value) {
        que.push(value);
        while (!maxque.empty() && maxque.back() < value) {
            maxque.pop_back();
        }
        maxque.push_back(value);
    }

    int pop_front() {
        if (que.empty()) {
            return -1;
        }
        int ans = que.front();
        if (ans == maxque.front()) {
            maxque.pop_front();
        }
        que.pop();
        return ans;
    }

private:
    queue<int> que;
    deque<int> maxque;
};

int main() {
    MaxQueue obj;
    obj.push_back(1);
    obj.push_back(2);
    int param1 = obj.max_value();
    int param2 = obj.pop_front();
    int param3 = obj.max_value();
    cout << param1 << endl; // Êä³ö2
    cout << param2 << endl; // Êä³ö1
    cout << param3 << endl; // Êä³ö2
    return 0;
}
