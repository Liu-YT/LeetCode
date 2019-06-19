
/*

blog: https://segmentfault.com/a/1190000015034975?utm_source=tag-newest

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int l = (a + b + 1) / 2;
        int r = (a + b + 2) / 2;
        int* lp = a > 0 ? &nums1[0] : NULL;
        int* rp = b > 0 ? &nums2[0] : NULL;
        return (getKth(lp, a, rp, b, l) + getKth(lp, a, rp, b, r)) * 1.0 / 2.0;
    }

    int getKth(int* lp, int a, int* rp, int b, int k) {
    	if(a == 0)	return rp[k-1];
    	if(b == 0)	return lp[k-1];
    	if(k == 1)	return min(lp[0], rp[0]);
    	int i = min(a, k / 2);
    	int j = min(b, k / 2);
    	if(lp[i-1] > rp[j-1]) 
    		return getKth(lp, a, rp+j, b-j, k-j);
    	else
    		return getKth(lp+i, a-i, rp, b, k-i);
    }
};