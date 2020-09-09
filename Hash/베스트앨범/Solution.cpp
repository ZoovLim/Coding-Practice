#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<string, int> genrePlaysPair;
typedef pair<int, int> numPlaysPair;

bool genreCompare(genrePlaysPair p1, genrePlaysPair p2) {
    if (p1.second > p2.second) return true;
    return false;
}

bool songCompare(numPlaysPair p1, numPlaysPair p2) {
    if (p1.second > p2.second) return true;
    if (p1.second == p2.second) return p1.first < p2.first;
    else return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genrePlaysmap;
    unordered_map<string, vector<numPlaysPair>> genreSongsmap;

    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        genreSongsmap[genre].push_back(make_pair(i, plays[i]));
        genrePlaysmap[genre] += plays[i];
    }

    vector<genrePlaysPair> genrePlaysVector(genrePlaysmap.begin(), genrePlaysmap.end());
    sort(genrePlaysVector.begin(), genrePlaysVector.end(), genreCompare);

    for (auto pair : genrePlaysVector) {
        vector<numPlaysPair> tmp = genreSongsmap[pair.first];
        sort(tmp.begin(), tmp.end(), songCompare);
        for (int i = 0; i < min((int)tmp.size(), 2); i++) {
            answer.push_back(tmp[i].first);
        }
    }

    return answer;
}