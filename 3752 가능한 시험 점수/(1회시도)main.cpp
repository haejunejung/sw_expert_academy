#include<iostream>

/*
    1회 시도 - 시간 초과 에러 (dfs)
*/

void dfs (int score[], bool checkScore[], bool flag[], int start, int end, int sum, int &count) {
    if (!flag[sum]) {
        flag[sum] = true;
        count++;
    }
    
    for (int i = start; i < end; ++i) {
        if (!checkScore[i]) {
            checkScore[i] = true;
            dfs (score, checkScore, flag, i+1, end, sum+score[i], count);
            checkScore[i] = false;
        }
    }
}


int main (void) {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase = 0; testcase < T; ++testcase) {
        int N;
        cin >> N;

        int *score = new int[N];
        for (int i = 0; i < N; ++i) {
            cin >> score[i];
        }

        int count = 1;
        bool *checkScore = new bool[N];
        bool flag[10001] = { };
        flag[0] = true;

        for (int i = 0; i < N; ++i) {
            if (!flag[score[i]]) {
                flag[score[i]] = true;
                count++;
            }
            checkScore[i] = true;
            dfs(score, checkScore, flag, i+1, N, score[i], count);
            checkScore[i] = false;
        }

        cout << "#" << testcase << " " << count << '\n';
    }
    return 0;
}