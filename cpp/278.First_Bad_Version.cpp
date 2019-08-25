// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// time limit
class Solution {
public:
    int firstBadVersion(int n) {
        for(int i = 1; i <= n; i++) {
            if(isBadVersion(i)) return i;
        }
        return n;
    }
};

// solution 1
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        if(isBadVersion(left))  return left;
        while(left < right) {
            // mid = (left + right) / 2;
            mid = left + (right - left) / 2;
            if(!isBadVersion(mid))  left = mid+1;
            else  right = mid;
        }
        return left;
    }
};

