/* counting sort
 * average time complexity  O(n+k)
 * best time complexity     O(n+k)
 * worst time complexity    O(n+k)
 * space complexity         O(k)
 * sorting type             out-place
 * stability                yes
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void display(vector<int> vec) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << " ";
    }
    cout << endl;
}

void counting_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    int minv = vec[0], maxv = vec[0];
    unordered_map<int, int> bucket;
    for (int i = 0; i < len; ++i) {
        if (vec[i] < minv)
            minv = vec[i];
        if (vec[i] > maxv)
            maxv = vec[i];
        if (!bucket.count(vec[i]))
            bucket[vec[i]] = 0;
        ++bucket[vec[i]];
    }

    int isort = 0;
    for (int i = minv; i <= maxv; ++i) {
        while (bucket.count(i) && bucket[i] > 0) {
            vec[isort++] = i;
            --bucket[i];
        }
    }
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    counting_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
