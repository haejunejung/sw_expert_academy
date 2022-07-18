#include <iostream>
#include <cstring>
#include <set>

/* vector를 사용했을 때, 시간초과가 나와서 set을 사용하였다 */

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char board[4][4];
set <string> v;

void checkCases (int row, int col, string s) {
    s += board[row][col];

    if (s.length() == 7) {
        v.insert(s);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = row + dy[i];
        int nx = col + dx[i];
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        checkCases(ny, nx, s);
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase) {
        
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                cin >> board[row][col];
            }
        }

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                string s = "";
                checkCases (row, col, s);
            }
        }

        cout << "#" << testcase << " " << v.size() << '\n';

        v.clear();
    }
    return 0;

}