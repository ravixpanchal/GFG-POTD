class Solution {
public:
    vector<int> p;
    string ms;

    Solution() {} // default constructor

    // Build transformed string for Manacher's algorithm
    void buildManacherString(const string &s) {
        ms = "@";
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        ms += "#$";
    }

    // Runs Manacher's algorithm
    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;
            if (i < right)
                p[i] = min(right - i, p[mirror]);

            while (ms[i + p[i] + 1] == ms[i - p[i] - 1])
                ++p[i];

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
    }

    // Returns length of longest odd/even palindrome centered at original index cen
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // Checks if substring s[l..r] is a palindrome
    bool check(int l, int r) {
        return (r - l + 1) <= getLongest((r + l) / 2, (r - l + 1) % 2);
    }

    // Main function to find max sum of lengths of two disjoint palindromes
    int maxSum(string &s) {
        int n = s.size();
        vector<int> leftMark(n, 1), rightMark(n, 1);

        buildManacherString(s);
        runManacher();

        // Left mark
        for (int i = 0; i < n; i++) {
            int val = getLongest(i, 1);
            int li = i + val / 2;
            if (li < n)
                leftMark[li] = max(leftMark[li], val);
        }
        for (int i = n - 2; i >= 0; i--)
            leftMark[i] = max(leftMark[i], leftMark[i + 1] - 2);
        for (int i = 1; i < n; i++)
            leftMark[i] = max(leftMark[i], leftMark[i - 1]);

        // Right mark
        for (int i = n - 1; i >= 0; i--) {
            int val = getLongest(i, 1);
            int ri = i - val / 2;
            if (ri >= 0)
                rightMark[ri] = max(rightMark[ri], val);
        }
        for (int i = 1; i < n; i++)
            rightMark[i] = max(rightMark[i], rightMark[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--)
            rightMark[i] = max(rightMark[i], rightMark[i + 1]);

        // Combine
        int ans = 0;
        for (int i = 0; i + 1 < n; i++)
            ans = max(ans, leftMark[i] + rightMark[i + 1]);

        return ans;
    }
};


