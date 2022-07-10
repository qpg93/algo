/* merge sort: divide and conquer
 * average time complexity  O(nlogn)
 * best time complexity     O(nlogn)
 * worst time complexity    O(nlogn)
 * space complexity         O(n)
 * sorting type             out-place
 * stability                yes
 */

#include <iostream>
#include <vector>
#include <climits>
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

// iterative method

void merge_sort(vector<int> &vec) {
    int len = vec.size();
    vector<int> vecb(len);

    for (int seg = 1; seg < len; seg += seg) {  // segment
        for (int start = 0; start < len; start += seg + seg) {
            int low = start;
            int mid = min(start + seg, len);
            int high = min(start + seg + seg, len);

            int key = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;

            while (start1 < end1 && start2 < end2)
                vecb[key++] = (vec[start1] < vec[start2]) ? vec[start1++] : vec[start2++];

            while (start1 < end1)
                vecb[key++] = vec[start1++];

            while (start2 < end2)
                vecb[key++] = vec[start2++];
        }

        vector<int> temp = vec;
        vec = vecb;
        vecb = temp;
    }

    vecb.clear();
}

// recursive method

void merge(vector<int> &vec, int left, int mid, int right) {
    /* prerequistes:
     *  vec[left...mid] is sorted       => copy to vecleft
     *  vec[mid+1...right] is sorted    => copy to vecright
     */
    vector<int> vecleft(vec.begin() + left, vec.begin() + mid + 1);
    vector<int> vecright(vec.begin() + mid + 1, vec.begin() + right + 1);

    int ileft = 0, iright = 0;
    vecleft.push_back(INT_MAX);
    vecright.push_back(INT_MAX);

    // pick min of vecleft[ileft] and vecright[iright] and put into vec[i]
    for (int i = left; i <= right; ++i)
        vec[i] = (vecleft[ileft] < vecright[iright]) ? vecleft[ileft++] : vecright[iright++];

    vecleft.clear();
    vecright.clear();
}

void mergesort(vector<int> &vec, int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergesort(vec, low, mid);
    mergesort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

void merge_sort_recursive(vector<int> &vec) {
    int len = vec.size();
    if (len <= 1) return;
    int low = 0, high = len - 1;    // index
    mergesort(vec, low, high);
}

int main() {
    int ia[24] = {8, 34, 3, 13, 1, 21, 5, 2,
                  16, 5, 88, 99, 12, 1, 0, 4,
                  25, 11, 41, 71, 81, 3, 7, 6};
    vector<int> vec(ia, ia+24);

    cout << "vector before sort" << endl;
    display(vec);

    // merge_sort(vec);
    merge_sort_recursive(vec);

    cout << "vector after sort" << endl;
    display(vec);
    return 0;
}
