#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
private:
    // Required prime factors: [count_2, count_3, count_5, count_7]
    
    // Number of prime factors [2, 3, 5, 7] provided by digits 0..9
    const std::vector<std::vector<int>> digitFactors = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2 -> 2^1
        {0, 1, 0, 0}, // 3 -> 3^1
        {2, 0, 0, 0}, // 4 -> 2^2
        {0, 0, 1, 0}, // 5 -> 5^1
        {1, 1, 0, 0}, // 6 -> 2^1 * 3^1
        {0, 0, 0, 1}, // 7 -> 7^1
        {3, 0, 0, 0}, // 8 -> 2^3
        {0, 2, 0, 0}  // 9 -> 3^2
    };

    // Calculate minimum digits needed to satisfy remaining prime factors
    int getMinDigitsNeeded(std::vector<int> req) {
        // Greedily combine factors into 9, 8, 6, 4
        int count9 = req[1] / 2; req[1] %= 2;
        int count8 = req[0] / 3; req[0] %= 3;
        
        int count6 = 0;
        if (req[0] == 1 && req[1] == 1) {
            count6 = 1;
            req[0] = 0;
            req[1] = 0;
        }
        
        int count4 = req[0] / 2; req[0] %= 2;
        int count2 = req[0];
        int count3 = req[1];
        int count5 = req[2];
        int count7 = req[3];

        return count9 + count8 + count6 + count5 + count7 + count4 + count3 + count2;
    }

    // Construct the optimal trailing suffix string given remaining prime requirements
    std::string buildSuffix(std::vector<int> req, int targetLength) {
        std::string suffix = "";

        // Greedily collect digits from largest to smallest
        while (req[1] >= 2) { suffix += '9'; req[1] -= 2; }
        while (req[0] >= 3) { suffix += '8'; req[0] -= 3; }
        while (req[3] >= 1) { suffix += '7'; req[3] -= 1; }
        if (req[0] >= 1 && req[1] >= 1) { suffix += '6'; req[0] -= 1; req[1] -= 1; }
        while (req[2] >= 1) { suffix += '5'; req[2] -= 1; }
        while (req[0] >= 2) { suffix += '4'; req[0] -= 2; }
        while (req[1] >= 1) { suffix += '3'; req[1] -= 1; }
        while (req[0] >= 1) { suffix += '2'; req[0] -= 1; }

        // Pad remaining spaces with '1's
        while ((int)suffix.length() < targetLength) {
            suffix += '1';
        }

        // Sort ascending to get lexicographically smallest suffix
        std::sort(suffix.begin(), suffix.end());
        return suffix;
    }

public:
    std::string smallestNumber(std::string num, long long t) {
        // Step 1: Prime factorize t
        std::vector<int> req(4, 0); // [2, 3, 5, 7]
        long long temp_t = t;
        
        while (temp_t % 2 == 0) { req[0]++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req[1]++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req[2]++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req[3]++; temp_t /= 7; }

        // If t has prime factors > 7, it's impossible using single-digit products
        if (temp_t > 1) return "-1";

        int n = num.length();

        // Find first zero index (if present, we cannot keep prefix past it)
        int firstZero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        // Calculate prefix factors of num up to first zero
        std::vector<std::vector<int>> prefixReq(n + 1, std::vector<int>(4, 0));
        std::vector<int> currentReq = req;
        prefixReq[0] = currentReq;

        for (int i = 0; i < std::min(n, firstZero); i++) {
            int d = num[i] - '0';
            for (int k = 0; k < 4; k++) {
                currentReq[k] = std::max(0, currentReq[k] - digitFactors[d][k]);
            }
            prefixReq[i + 1] = currentReq;
        }

        // Step 2: Check if num itself (if zero-free) is already valid
        if (firstZero == n && getMinDigitsNeeded(prefixReq[n]) == 0) {
            return num;
        }

        // Step 3: Try modifying from right-to-left
        for (int i = std::min(n - 1, firstZero); i >= 0; i--) {
            int currentDigit = num[i] - '0';
            int spaceRemaining = n - 1 - i;

            for (int nextDigit = currentDigit + 1; nextDigit <= 9; nextDigit++) {
                std::vector<int> remReq = prefixReq[i];
                for (int k = 0; k < 4; k++) {
                    remReq[k] = std::max(0, remReq[k] - digitFactors[nextDigit][k]);
                }

                if (getMinDigitsNeeded(remReq) <= spaceRemaining) {
                    std::string res = num.substr(0, i);
                    res += std::to_string(nextDigit);
                    res += buildSuffix(remReq, spaceRemaining);
                    return res;
                }
            }
        }

        // Step 4: If no valid modification within original length, expand length by 1
        int newLength = std::max(n + 1, getMinDigitsNeeded(req));
        return buildSuffix(req, newLength);
    }
};