#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Process {
    int id;
    int priority;
};

class Scheduler {
private:
    priority_queue<pair<int, int>> queue; // priority, process id

public:
    void addProcess(int id, int priority) {
        queue.push({priority, id});
    }

    void run() {
        while (!queue.empty()) {
            auto current = queue.top();
            queue.pop();
            cout << "Running process ID: " << current.second
                 << " | Priority: " << current.first << endl;
        }
    }
};

int main() {
    Scheduler scheduler;

    scheduler.addProcess(1, 2);
    scheduler.addProcess(2, 5);
    scheduler.addProcess(3, 3);

    scheduler.run();
    return 0;
}
