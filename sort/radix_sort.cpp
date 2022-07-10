/* radix sort
 * average time complexity  O(nk)
 * best time complexity     O(nk)
 * worst time complexity    O(nk)
 * space complexity         O(nk)
 * sorting type             out-place
 * stability                yes
 */

#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> vec) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << " ";
    }
    cout << endl;
}

// find max bit of all elements in list
int max_bit(vector<int> &vec) {
    int maxv = vec[0];
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i] > maxv)
            maxv = vec[i];

    int bit_cnt = 1;
    int ten = 10;
    while (maxv >= ten) {
        maxv /= ten;
        ++bit_cnt;
    }

    return bit_cnt;
}

void radix_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;

    int bit_cnt = max_bit(vec);
    int radix = 1;
    int key;
    vector<int> temp(vec.begin(), vec.end());

    for (int ix = 1; ix <= bit_cnt; ++ix) {
        vector<int> count(10, 0);

        for (int jx = 0; jx < len; ++jx) {
            key = (vec[jx] / radix) % 10;
            ++count[key];
        }

        for (int jx = 1; jx < 10; ++jx)
            count[jx] = count[jx - 1] + count[jx];

        for (int jx = len - 1; jx >= 0; --jx) {
            key = (vec[jx] / radix) % 10;
            temp[count[key] - 1] = vec[jx];
            --count[key];
        }

        for (int jx = 0; jx < len; ++jx)
            vec[jx] = temp[jx];

        radix *= 10;
    }

    temp.clear();
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    radix_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
