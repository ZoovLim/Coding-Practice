#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int currentWeight = 0;

    queue<int> progressQ;   // positions of trucks on bridge Q
    queue<int> weightQ;     // weights of trucks on bridge Q

    // Push first truck
    answer++;
    currentWeight += *truck_weights.begin();
    weightQ.push(*truck_weights.begin());
    truck_weights.erase(truck_weights.begin());
    progressQ.push(1);

    while (!(progressQ.empty() && truck_weights.empty())) {
        answer++;        

        // Push one step all trucks
        int currentTrucks = weightQ.size();

        for (int i = 0; i < currentTrucks; i++) {
            if (progressQ.front() == bridge_length) {
                progressQ.pop();
                currentWeight -= weightQ.front();
                weightQ.pop();
            }
            else {
                progressQ.push(progressQ.front() + 1);                
                progressQ.pop();
            }
        }
        
        // If possible, push new truck
        if (!truck_weights.empty()) {
            if (progressQ.empty()) {
                progressQ.push(1);
                weightQ.push(*truck_weights.begin());
                currentWeight += weightQ.back();
                truck_weights.erase(truck_weights.begin());
            }
            else if (progressQ.back() > 1 && (currentWeight + *truck_weights.begin() <= weight)) {
                progressQ.push(1);
                weightQ.push(*truck_weights.begin());
                currentWeight += weightQ.back();
                truck_weights.erase(truck_weights.begin());
            }
        }        
    }

    return answer;
}