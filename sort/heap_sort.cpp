/* heap sort
 * average time complexity  O(nlogn)
 * best time complexity     O(nlogn)
 * worst time complexity    O(nlogn)
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

void max_heapify(vector<int> &vec, int left, int right) {
    int father = left, son = father * 2 + 1;
    while (son <= right) {
        if (son + 1 <= right && vec[son] < vec[son + 1])
            ++son;

        if (vec[father] > vec[son])
            return;
        else {
            swap(vec[father], vec[son]);
            father = son;
            son = father * 2 + 1;
        }
    }
}

void heap_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    for (int i = len / 2 - 1; i >= 0; --i)
        max_heapify(vec, i, len - 1);

    for (int i = len - 1; i > 0; --i) {
        swap(vec[0], vec[i]);
        max_heapify(vec, 0, i - 1);
    }
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    heap_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
