/* bubble sort
 * average time complexity  O(n²)
 * best time complexity     O(n)
 * worst time complexity    O(n²)
 * space complexity         O(1)
 * sorting type             in-place
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

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    for (int ix = 0; ix < len; ++ix)
        for (int jx = ix + 1; jx < len; ++jx)
            if (vec[ix] > vec[jx])
                swap(vec[ix], vec[jx]);
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    bubble_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
