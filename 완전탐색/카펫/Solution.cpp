#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int height = 3;
    int width = 0;

    while (true) {
        width = brown / 2 - (height - 2);
        if (yellow == (width - 2) * (height - 2)) {
            return { width, height };
        }
        height++;
    }

    return answer;
}