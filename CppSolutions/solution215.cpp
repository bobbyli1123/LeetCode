// 2025-4-29
// 215. 数组中的第K个最大元素 <Medium> [数组][排序][堆]



#include "environment.h"

using namespace std;

class Solution {
    public:
    
        void heapify(vector<int> &nums, int n, int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
    
            if (left < n && nums[left] > nums[largest]) {
                largest = left;
            }
    
            if (right < n && nums[right] > nums[largest]) {
                largest = right;
            }
    
            if (largest != i) {
                swap(nums[largest], nums[i]);
                heapify(nums, n, largest);
            }
    
        }
    
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
    
            // 建堆 (从最后一个叶子结点开始)
            for (int i = n / 2 - 1; i >= 0; --i) {
                heapify(nums, n, i);
            }
    
            // 从堆顶取值 k 次（堆排序）
            for (int i = n - 1; i >= n - k; --i) {
                swap(nums[0], nums[i]); // 取值到数组末尾
                heapify(nums, i, 0); //重新堆化，堆大小减 1
            }
            
            return nums[n - k];
        }
    };