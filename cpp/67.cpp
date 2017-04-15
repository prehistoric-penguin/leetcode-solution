// https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        int asz = a.size();
        int bsz = b.size();
        if (!asz && !bsz) return "";

        int cry = 0;
        int k = 0;
        std::string ans(std::max(asz, bsz), '0');
        for (int i = asz - 1, j = bsz - 1; i >= 0 || j >= 0; --i, --j) {
            cry += (i >= 0 ? a[i]-'0' : 0) + (j >= 0 ? b[j]-'0' : 0);

            ans[k++] = cry % 2 + '0';
            cry /= 2;
        }
        if (!cry) {
            // remove leading zeros
            ans.erase(ans.begin() + k, ans.end());
        } else {
            // add additional carry
            ans += '1';
        }
        return std::string(ans.rbegin(), ans.rend());
    }
};

