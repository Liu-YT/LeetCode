class Solution {
public:
	void replaceSpace(char *str,int length) {
        int spaceNum = 0;
        
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') {
                ++spaceNum;
            }
        }

        int newLen = length + 2 * spaceNum;
        for(int i = length - 1, j =newLen - 1; i >= 0; i--) {
            if(str[i] != ' ') {
                str[j--] = str[i];
            }
            else {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
	}
};