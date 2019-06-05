class Solution {
public:
    bool isPalindrome(int x) {
  		if(x < 0) return false;
  		int temp = 0, tempX = x;
  		while(tempX) {
  			temp = temp * 10 + tempX % 10;
  			tempX = tempX / 10;
  		}      
  		return x == temp;
    }
};