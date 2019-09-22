// 暴力破解
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);

        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A.size(); j++) {
                if(i == j) {
                    continue;
                }

                B[i] *= A[j];
            }
        }

        return B;
    }
};

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);

        for(int i = 1; i < A.size(); i++) {
            B[i] = A[i-1] * B[i-1];
        }

        int cur = 1;
        for(int i = A.size()-1; i >= 0; i--) {
            B[i] = B[i] * cur;
            cur = cur * A[i];
        }

        return B;
    }
};