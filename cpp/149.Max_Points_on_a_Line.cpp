// https://www.cnblogs.com/grandyang/p/4579693.html
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <= 2)  return points.size();
        int res = 0, duplicate;
        for(int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> m;
            duplicate = 1;
            for(int j = i+1; j < points.size(); j++) {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int d = gcd(dx, dy);
                m[{dx / d, dy / d}]++;  
            }
            res = max(res, duplicate);
            for(auto it : m) {
                res = max(res, it.second + duplicate);
            }
        }
        return res;
    }

    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};