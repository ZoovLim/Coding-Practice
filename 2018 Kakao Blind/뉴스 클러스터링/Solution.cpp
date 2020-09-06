#include <string>
#include <unordered_set>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_multiset<string> A;
    unordered_multiset<string> B;
    unordered_multiset<string> interSet;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) A.insert(str1.substr(i, 2));          
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) B.insert(str2.substr(i, 2));
    }

    auto it = A.begin();  
    while (it != A.end()) {
        if (B.find(*it) != B.end()) {
            interSet.insert(*it);
            B.erase(B.find(*it));
            it = A.erase(it);               
        }
        else it++;
    }
        
    it = B.begin();
    while (it != B.end()) {
        if (A.find(*it) != A.end()) {
            interSet.insert(*it);
            it = B.erase(it);
            A.erase(A.find(*it));
        }
        else it++;
    }
  
    if (!interSet.size() && !A.size() && !B.size()) return 65536; 
    answer = 65536 * ((double) interSet.size() / (interSet.size() + A.size() + B.size()));

    return answer;
}