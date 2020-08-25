#include <string>
#include <vector>

using namespace std;

// 자물쇠와 키가 맞는지 확인하는 함수
bool isOpen(vector<vector<int>> ground, int keySize, int lockSize) {  
    for (int i = 0; i < lockSize; i++) {
        for (int j = 0; j < lockSize; j++) {
            if (ground[keySize - 1 + i][keySize - 1 + j] != 1) return false;
        }
    }
    return true;
}

// 열쇠 회전하는 함수
vector<vector<int>> rotateKey(vector<vector<int>> key) {
    vector<vector<int>> newKey(key.size(), vector<int>(key.size(), 0));

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            newKey[j][key.size() - 1 - i] = key[i][j];
        }
    }
    return newKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int groundSize = 2 * (key.size() - 1) + lock.size();    // 문제를 해결할 전체 공간의 한 변 길이
    vector<vector<int>> ground(groundSize, vector<int>(groundSize, 0)); // 문제를 해결할 전체 공간
    vector<vector<int>> newKey = key;

    // 전체 공간에 자물쇠 정보 저장
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            ground[key.size() - 1 + i][key.size() - 1 + j] = lock[i][j];
        }
    }
    
    // 열쇠 회전 반복
    for (int r = 0; r < 4; r++) {        
        // 열쇠 이동하며 확인
        for (int i = 0; i < key.size() + lock.size() - 1; i++) {
            for (int j = 0; j < key.size() + lock.size() - 1; j++) {
                // 열쇠 데이터 전체 공간에 저장
                vector<vector<int>> tmp = ground;
                for (int k = 0; k < key.size(); k++) {
                    for (int l = 0; l < key.size(); l++) {
                        tmp[i + k][j + l] += newKey[k][l];
                    }
                }
                if (isOpen(tmp, key.size(), lock.size())) return true;
            }
        }
        newKey = rotateKey(newKey);
    }
    return answer;
}