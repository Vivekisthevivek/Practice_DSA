class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0, one = n;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zero++;
            }
        }
        
        one -= zero;

        int cntZero = 0, score = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                cntZero++;
            }
            else {
                one--;
            }

            score = max(cntZero + one, score);
        }

        return score;

    }
};