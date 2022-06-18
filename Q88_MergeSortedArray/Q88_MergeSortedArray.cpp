#include <iostream>
#include <vector>

using namespace std;

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int sizeM = m;

    for (int i = 0; i < n; i++) {
        if (m == 0) {
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            sizeM++;
            break;
        }

        if (nums2[i] <= nums1[0]) {
            nums1.insert(nums1.begin(), nums2[i]);
            sizeM++;
            continue;
        }

        for (int j = 0; j < nums1.size(); j++) {
            if (nums1[j] < nums2[i] && nums2[i] <= nums1[j + 1]) {
                nums1.insert(nums1.begin() + j + 1, nums2[i]);
                sizeM++;
                break;
            }

            if (j == sizeM - 1 && nums1[j] < nums2[i]) {
                nums1.insert(nums1.begin() + sizeM, nums2[i]);
                sizeM++;
                break;
            }
        }
    }

    nums1.erase(nums1.begin() + m + n, nums1.begin() + nums1.size());

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << endl;
    }
}

int main()
{
    vector<int> num1 = { 0 };
    vector<int> num2 = { 1 };

    merge(num1, 0, num2, 1);

    return 0;
}
