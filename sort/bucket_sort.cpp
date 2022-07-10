/* bucket sort
 * average time complexity  O(n+k)
 * best time complexity     O(n+k)
 * worst time complexity    O(n²)
 * space complexity         O(n+k)
 * sorting type             out-place
 * stability                yes
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void display(vector<int> vec) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << " ";
    }
    cout << endl;
}

void bucket_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    int minv = vec[0];
    for (int i = 0; i < len; ++i)
        if (vec[i] < minv)
            minv = vec[i];

    const int bkt_cnt = 10;
    const int bkt_vol = 10;
    unordered_map<int, vector<int>> buckets;

    for (int ix = 0; ix < bkt_cnt; ++ix) {
        vector<int> temp;
        buckets[ix] = temp;
        int lower = minv + ix * bkt_vol;
        int upper = minv + (ix + 1) * bkt_vol;

        for (int jx = 0; jx < len; ++jx) {
            if (ix == 0) {
                if (vec[jx] < upper)
                    buckets[ix].push_back(vec[jx]);
            } else if (ix == bkt_cnt - 1) {
                    if (vec[jx] >= lower)
                        buckets[ix].push_back(vec[jx]);
            } else {
                if (vec[jx] >= lower && vec[jx] < upper)
                    buckets[ix].push_back(vec[jx]);
            }
        }

        sort(buckets[ix].begin(), buckets[ix].end());
    }

    int isort = 0;
    for (int ix = 0; ix < bkt_cnt; ++ix) {
        if (buckets[ix].empty())
            continue;
        for (int jx = 0; jx < buckets[ix].size(); ++jx)
            vec[isort++] = buckets[ix][jx];
    }

    buckets.clear();
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    bucket_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
