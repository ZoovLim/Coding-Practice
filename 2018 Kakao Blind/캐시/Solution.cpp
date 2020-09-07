#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int count = 0, index = 0;
    deque<string> cache;
    
    if (cacheSize == 0) return cities.size() * 5;

    while (count != cacheSize && index < cities.size()) {
        transform(cities[index].begin(), cities[index].end(), cities[index].begin(), ::tolower);
        auto it = find(cache.begin(), cache.end(), cities[index]);
        if (it == cache.end()) {
            count++;
            answer += 5;
        }
        else {
            cache.erase(it);
            answer++;
        }
        cache.push_back(cities[index++]);
    }   

    for (; index < cities.size(); index++) {   
        transform(cities[index].begin(), cities[index].end(), cities[index].begin(), ::tolower);
        auto it = find(cache.begin(), cache.end(), cities[index]);
        if (it == cache.end()) {
            cache.pop_front();
            answer += 5;
        }
        else {
            cache.erase(it);
            answer++;
        }
        cache.push_back(cities[index]);
    }
    return answer;
}