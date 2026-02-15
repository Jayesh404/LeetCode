class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry == 0) {
                    result += '0';
                    carry = 1;
                } else {
                    result += '1';
                }
            } else if (a[i] == '0' && b[j] == '0') {
                if (carry == 0) result += '0';
                else {
                    result += '1';
                    carry = 0;
                }
            } else { // a[i] != b[j]
                if (carry == 0) {
                    result += '1';
                } else {
                    result += '0';
                    carry = 1;
                }
            }
            i--;
            j--;
        }

        while (i >= 0) {
            if (carry == 1) {
                if (a[i] == '1') result += '0';
                else {
                    result += '1';
                    carry = 0;
                }
            } else result += a[i];
            i--;
        }

        while (j >= 0) {
            if (carry == 1) {
                if (b[j] == '1') result += '0';
                else {
                    result += '1';
                    carry = 0;
                }
            } else result += b[j];
            j--;
        }

        if (carry) result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};
