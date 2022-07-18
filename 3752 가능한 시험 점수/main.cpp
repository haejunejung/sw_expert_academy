#include <iostream>
#include <vector>

/* 자꾸 출력에서 #1 이 부분을 놓치고 #0부터 시작해서 틀리는데, 조금 더 유심히 볼 것. */

int main (void) {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,testcase;
    cin >> T;

    for (testcase = 1; testcase <= T; ++testcase) {
        int N;
        cin >> N;

        int *score = new int[N];
        for (int i = 0; i < N; ++i) {
            cin >> score[i];
        }

        bool flag[10001] = { }; /* 존재할 수 있는 배점 체크 */
        vector <int> v; /* 존재할 수 있는 배점 */

        v.push_back(0); /* 처음 들어가는 수들을 벡터 안에 넣기 위함 */

        for (int i = 0; i < N; ++i) {
            int len = v.size();
            int s = score[i];
            for (int j = 0; j < len; ++j) {
                if (!flag[s+ v[j]]) {
                    flag[s+v[j]] = true;
                    v.push_back(s+v[j]);
                }
            }
        }

        cout << "#" << testcase << " " << v.size() << '\n';

    }

    return 0;
}