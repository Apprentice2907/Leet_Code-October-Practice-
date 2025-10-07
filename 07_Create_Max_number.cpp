// You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

// Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

// Return an array of the k digits representing the answer.

// Example 1:

// Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// Output: [9,8,6,5,3]
// Example 2:

// Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
// Output: [6,7,6,0,4]
// Example 3:

// Input: nums1 = [3,9], nums2 = [8,9], k = 3
// Output: [9,8,9]








// Using stack approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int toRemove = nums.size() - k;
        for (int num : nums) {
            while (!stack.empty() && toRemove > 0 && stack.back() < num) {
                stack.pop_back();
                toRemove--;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> merged;
        while (!nums1.empty() || !nums2.empty()) {
            if (nums1 > nums2) {
                merged.push_back(nums1.front());
                nums1.erase(nums1.begin());
            } else {
                merged.push_back(nums2.front());
                nums2.erase(nums2.begin());
            }
        }
        return merged;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> part1 = maxSubsequence(nums1, i);
            vector<int> part2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(part1, part2);
            best = max(best, candidate);
        }
        return best;
    }
};











// Optimal solution leetcode

class Solution {
public:
    #define MIN(a,b) (a<b?a:b)
    #define MAX(a,b) (a>b?a:b)
    // create max number of length t from single non-empty vector
    void getMax(int* num, int& len, int* result, int& t, int& sortedLen)
    {
    	int n, top = 0;
    	result[0] = num[0];
    	const int need2drop = len - t;
    	for (int i = 1; i < len; ++i){
    		n = num[i];
    		while (top >= 0 && result[top] < n && (i - top) <= need2drop) --top; // i - top means already dropped i - top numbers
    		if (i - top > need2drop){
    			sortedLen = MAX(1,top);
    			while (++top < t) result[top] = num[i++];
    			return;
    		}
    		if (++top < t) result[top] = n;
    		else top = t - 1;
    	}
    }
    // create max number of different length from single vector
    void dp(int *num, int len, int&sortedLen, int& minL, int& maxL, int *res, int &k){
    	int  j, *head, *prevhead = res;
    	const int soi = sizeof(int);
    	getMax(num, len, res, maxL,sortedLen);
    	for (int l = maxL; l > MAX(minL,1); --l){
    		head = prevhead + k;
    		memcpy(head, prevhead, l*soi);
    		for (j = sortedLen; j < l; ++j){
    			if (head[j] > head[j - 1]){
    				sortedLen = MAX(1, j - 1);
    				memcpy(head + j - 1, prevhead + j, soi*(l - j));
    				break;
    			}
    		}
    		if (j == l) sortedLen = l;
    		prevhead = head;
    	}
    }
    // merge max number created from single vector
    void merge(int* num1,int len1,int* num2,int len2,int* result,int& resSize){
    	int i = 0, j = 0, k = 0;
    	while (i < resSize){
    		if (j < len1 && k < len2){
    			if (num1[j] > num2[k])
    				result[i++] = num1[j++];
    			else if (num1[j] < num2[k])
    				result[i++] = num2[k++];
    			else{
    				int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
    				int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
    				flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
    				int * num = flag > 0 ? num1 : num2;
    				int & cnt = flag > 0 ? j : k;
    				int len = flag > 0 ? len1 : len2;
    				while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
    			}
    		}
    		else if (j < len1) result[i++] = num1[j++];
    		else result[i++] = num2[k++];
    	}
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
    	int soi = sizeof(int), len1 = nums1.size(), len2 = nums2.size(), step = k*soi;
    	int minL1 = MAX(0, k - len2), maxL1 = MIN(k, len1), minL2 = k - maxL1, maxL2 = k - minL1, range = maxL1 - minL1 + 1;
    	int * res = new int[range * k * 2 + 2 * k], *dp1 = res + k, *dp2 = res + range*k+k, *tmp=res+range*2*k+k;
    	memset(res, 0, step);
    	int sortedLen1 = 1, sortedLen2 = 1;
    	if (len1 == 0 && len2 > 0) getMax(&nums2[0], len2, res, k, sortedLen2);
    	else if (len1 > 0 && len2 == 0) getMax(&nums1[0], len1, res, k, sortedLen2);
    	else if (len1 > 0 && len2 > 0){
    		dp(&nums1[0], len1, sortedLen1, minL1, maxL1, dp1,k);
    		dp(&nums2[0], len2, sortedLen2, minL2, maxL2, dp2,k);
    		if (sortedLen1 + sortedLen2 > k){
    			merge(dp1 + k*(maxL1 - sortedLen1), sortedLen1, dp2 + k*(maxL2 - sortedLen2), sortedLen2, tmp, k);
    			vector<int> resv(tmp, tmp + k);
    			delete[] res;
    			return resv;
    		}
    		for (int i = minL1; i <= maxL1; ++i){
    			merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp,k);
    			if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
    		}
    	}
    	vector<int> resv(res, res + k);
    	delete[] res;
    	return resv;
    }
};