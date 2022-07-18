#include <iostream>
#include <algorithm>

/* 그리디로 풀었는데 10개 테스트 케이스 중 9개만 정답을 맞았다 ?? */

/* 
    그리디로 푸는 것은 맞는데, 홀수 짝수가 같은 복도를 사용한다 (29,30) 같은 복도를 사용한다는 것을 놓쳤다 
    그리고, 현재 방과 도달하는 방의 크기를 비교해서 넣어줘야 한다. 두 개가 어떻게 되었든, 사용하는 복도는 같기 때문에 작은 것부터 넣을 수 있도록 하였다
*/

bool allClear (bool checkClear[], int N) {
    for (int i = 0; i < N; ++i) {
        if (checkClear[i] == false) return false;
    }

    return true;
}

int main (void) {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, testcase;
    cin >> T;

    for (testcase=1; testcase<=T; ++testcase) {
        int N;
        cin >> N;
        std::pair<int,int> *studentInfo = new std::pair<int,int>[N];
        for (int i = 0; i < N; ++i) {
            int current, future;
            cin >> current >> future;

            if (current > future) {
                studentInfo[i].first = future;
                studentInfo[i].second = current;
            } else {
                studentInfo[i].first = current;
                studentInfo[i].second = future;
            }
        }

        sort (studentInfo, studentInfo+N, less<>());

        int count = 0;
        bool *checkClear = new bool[N];
        for (int i = 0; i < N; ++i) {

            if (allClear(checkClear, N)) break;

            if (!checkClear[i]) {
                int end;
                if (studentInfo[i].second % 2 == 0) end = studentInfo[i].second;
                else end = studentInfo[i].second+1;

                checkClear[i] = true;
                count++;
                for (int j = i+1; j < N; ++j) {
                    if (!checkClear[j]) {
                        if (studentInfo[j].first > end) {
                            checkClear[j] = true;

                            if (studentInfo[j].second % 2 == 0) end = studentInfo[j].second;
                            else end = studentInfo[j].second+1;
                        }
                    }
                }
            }
        }

        cout << "#" << testcase << " " << count << '\n';
    }

    return 0;
}