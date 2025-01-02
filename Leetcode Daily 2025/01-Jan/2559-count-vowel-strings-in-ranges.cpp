class Solution {
public:
    int isVowel(char ch){
        string str = "aeiou";
        return (str.find(ch) != string::npos);
    }   
    vector<int> vowelStrings(vector<string>& A, vector<vector<int>>& Q) {
        int n = A.size();
        vector<int> Pre(n,0);
        for(int i=0;i<n;i++){
            string temp = A[i];
            if(isVowel(temp[0]) && isVowel(temp[temp.size()-1])){
                Pre[i]++;
            }
            // cout << Pre[]
        }
        for(int i=1;i<n;i++){
            Pre[i] += Pre[i-1];
        }
        vector<int> ans;
        for(auto it : Q){
            int l = it[0];
            int r = it[1];
            if(l==0){ 
                ans.push_back(Pre[r]);
            }else{
                ans.push_back(Pre[r] - Pre[l-1]);
            }
        }
        return ans;


    }
};

// TLE 93/94
/*
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n1 = words.size();
        int n2 = queries.size();

        vector<int> v1(n1, 0);
        vector<int> v2(n2, 0);

        string vowel = "aeiou";
        int cnt = -1;
        for (auto str: words) {
            int n = str.size();
            cnt++;
            if (vowel.find(str[0]) != string::npos) {
                if (vowel.find(str[n-1]) != string::npos) {
                    v1[cnt] = 1;
                }
            }
        }

        int ans = 0;
        cnt = 0;
        for (auto it: queries) {
            for(int i = it[0]; i <= it[1]; i++) {
                v2[cnt] += v1[i];
            }
            cnt++;
        }

        return v2;
    }
};
*/