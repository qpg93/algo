/* shell sort
 * average time complexity  O(nlogn)
 * best time complexity     O(nlog²n)
 * worst time complexity    O(nlog²n)
 * space complexity         O(1)
 * sorting type             in-place
 * stability                no
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

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void shell_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    int intl = 1;
    while (intl < len / 3)
        intl = 3 * intl + 1;

    while (intl >= 1) {
        for (int ix = intl; ix < len; ++ix) {
            for (int jx = ix; jx >= intl && vec[jx] < vec[jx - intl]; jx -= intl)
                swap(vec[jx], vec[jx - intl]);
        }
        intl /= 3;
    }
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    shell_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
