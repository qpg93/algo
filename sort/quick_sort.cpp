/* quick sort: divide and conquer
 * average time complexity  O(nlogn)
 * best time complexity     O(nlogn)
 * worst time complexity    O(n²)
 * space complexity         O(logn)
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

void quick_sort_recursive(vector<int> &vec, int low, int high) {
    if (low >= high)
        return;

    int pivot = vec[high];      // use last element as pivot
    int left = low, right = high - 1;
    while (left < right) {      // find less & greater elem and swap them
        while (vec[left] < pivot && left < right)
            ++left;
        while (vec[right] > pivot && left < right)
            --right;
        swap(vec[left], vec[right]);
    }

    if (vec[left] >= pivot)
        swap(vec[left], vec[high]);
    else
        ++left;

    quick_sort_recursive(vec, low, left - 1);
    quick_sort_recursive(vec, left + 1, high);
}

void quick_sort(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    int low = 0, high = len - 1;
    quick_sort_recursive(vec, low, high);
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    quick_sort(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
