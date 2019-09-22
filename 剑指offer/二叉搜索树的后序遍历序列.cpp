class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        
        if(size == 1) {
            return true;
        }

        if(size == 0) {
            return false;
        }

        int i;
        for(i = 0; i < size - 1; i++) {
            if(sequence[i] < sequence[size-1]) {
                continue;
            }
            else {
                break;
            }
        }

        for(i; i < size - 1; i++) {
            if(sequence[i] < sequence[size-1]) {
                return false;
            }
        }

        return true;
    }
};