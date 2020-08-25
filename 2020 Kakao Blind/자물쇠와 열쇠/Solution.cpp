#include <string>
#include <vector>

using namespace std;

// �ڹ���� Ű�� �´��� Ȯ���ϴ� �Լ�
bool isOpen(vector<vector<int>> ground, int keySize, int lockSize) {  
    for (int i = 0; i < lockSize; i++) {
        for (int j = 0; j < lockSize; j++) {
            if (ground[keySize - 1 + i][keySize - 1 + j] != 1) return false;
        }
    }
    return true;
}

// ���� ȸ���ϴ� �Լ�
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
    int groundSize = 2 * (key.size() - 1) + lock.size();    // ������ �ذ��� ��ü ������ �� �� ����
    vector<vector<int>> ground(groundSize, vector<int>(groundSize, 0)); // ������ �ذ��� ��ü ����
    vector<vector<int>> newKey = key;

    // ��ü ������ �ڹ��� ���� ����
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            ground[key.size() - 1 + i][key.size() - 1 + j] = lock[i][j];
        }
    }
    
    // ���� ȸ�� �ݺ�
    for (int r = 0; r < 4; r++) {        
        // ���� �̵��ϸ� Ȯ��
        for (int i = 0; i < key.size() + lock.size() - 1; i++) {
            for (int j = 0; j < key.size() + lock.size() - 1; j++) {
                // ���� ������ ��ü ������ ����
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