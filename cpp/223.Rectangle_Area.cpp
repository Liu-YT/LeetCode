class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        unordered_map<int, unordered_set<int>> m;
        
        int area1 = abs(C-A) * abs(D-B);
        int area2 = abs(G-E) * abs(H-F);
        int comArea = 0;

        int left = max(A, E);
        int right = min(C, G);
        int up = min(D, H);
        int down = max(B, F);

        if(left < right && down < up) {
            comArea = (right - left) * (up - down);
        }

        return area1 - comArea + area2;
    }
};