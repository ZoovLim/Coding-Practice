#include <string>
#include <vector>

using namespace std;

bool isOkRow(int x, int y, vector<vector<bool>> row, vector<vector<bool>> col, int opt) {   // Check possibility action to row
    bool answer = false;

    if (opt == 0 && !row[x][y]) return true;    // Check deletion option
    if (col[x][y - 1] || col[x + 1][y - 1]) return true;    // By column
    else if (row[x - 1][y] && row[x + 1][y]) return true;   // By two rows

    return answer;
}

bool isOkCol(int x, int y, vector<vector<bool>> row, vector<vector<bool>> col, int opt) {   // Check possibility action to col
    bool answer = false;

    if (opt == 0 && !col[x][y]) return true;    // Check deletion option
    if (y == 0 || col[x][y - 1]) return true;   // By column
    else if (row[x - 1][y] || row[x][y]) return true;    // By row
    
    return answer;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<bool>> row(n + 2, vector<bool>(n + 1, false));
    vector<vector<bool>> col(n + 2, vector<bool>(n + 1, false));

    for (auto it : build_frame) {
        int x = it[0], y = it[1], kind = it[2], opt = it[3];
        x++;
        if (opt == 1) {   // Addition
            if (kind == 0) {   // Column
                if (isOkCol(x, y, row, col, opt)) col[x][y] = true;
            }
            else {  // Row
                if (isOkRow(x, y, row, col, opt)) row[x][y] = true;
            }
        }
        else {  // Deletion
            if (kind == 0) {   // Column
                col[x][y] = false;
                if(!isOkCol(x, y + 1, row, col, opt)) col[x][y] = true;
                else if (!isOkRow(x - 1, y + 1, row, col, opt) || !isOkRow(x, y + 1, row, col, opt)) col[x][y] = true;                      
            }
            else {  // Row
                row[x][y] = false;
                if (!isOkCol(x, y, row, col, opt) || !isOkCol(x + 1, y, row, col, opt)) row[x][y] = true;
                else if (!isOkRow(x - 1, y, row, col, opt) || !isOkRow(x + 1, y, row, col, opt)) row[x][y] = true;
            }
        }
    }

    for (int x = 1; x <= n + 1; x++) {
        for (int y = 0; y <= n; y++) {
            if (col[x][y]) answer.push_back({ x - 1, y, 0 });
            if (row[x][y]) answer.push_back({ x - 1, y, 1 });
        }
    }
    return answer;
}