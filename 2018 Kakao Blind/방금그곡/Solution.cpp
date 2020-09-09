#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int ansPlaytime = 0, flag = 0;

    while (m.find('#') != -1) {
        int flag = m.find('#');
        m[flag - 1] += 'a' - 'A';
        m.erase(m.begin() + flag);
    }

    for (auto musicInfo : musicinfos) {
        string start, end, title, music, playMelody;
        int playtime, musicLength;
        flag = 0;

        start = musicInfo.substr(0, 5);
        end = musicInfo.substr(6, 5);
        flag = musicInfo.find(',', 12);
        title = musicInfo.substr(12, flag - 12);
        playtime = (60 * (stoi(end.substr(0, 2)) - stoi(start.substr(0, 2))) + (stoi(end.substr(3, 2)) - stoi(start.substr(3, 2))));
        music = musicInfo.substr(flag + 1);
        while (music.find('#') != -1) {
            int flag = music.find('#');
            music[flag - 1] += 'a' - 'A';
            music.erase(music.begin() + flag);
        }
        musicLength = music.size();

        for (int i = 0; i < (playtime / musicLength); i++) {
            playMelody += music;
        }
        playMelody += music.substr(0, playtime % musicLength);

        if (playMelody.find(m) != -1 && playtime > ansPlaytime) {
            answer = title;
            ansPlaytime = playtime;
        }
    }

    return answer;
}