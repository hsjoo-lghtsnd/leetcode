class Solution {
public:
    string addBinary(string a, string b) {
        if (a=="0") return b;
        if (b=="0") return a;

        string answer = "";

        bool a_is_longer = (a.length() > b.length());
        int N = a_is_longer ? a.length() : b.length();

        string zero_padding = "";
        int zero_length = a_is_longer ? N-b.length() : N-a.length();

        for (int i=0; i<zero_length; i++) {
            zero_padding = "0" + zero_padding;
        }

        if (a_is_longer) b = zero_padding + b;
        else a = zero_padding + a;
        

        bool carry = false;
        for (int i=0; i<N; i++) {
            if (carry) {
                if (a[a.length()-i-1] == '1') {
                    if (b[b.length()-i-1] == '1') {
                        answer = "1" + answer;
                    }
                    else {
                        answer = "0" + answer;
                    }
                    // carry = true;
                }
                else {
                    if (b[b.length()-i-1] == '1') {
                        answer = "0" + answer;
                        // carry = true;
                    }
                    else {
                        answer = "1" + answer;
                        carry = false;
                    }
                }
            }
            else if (a[a.length()-i-1] == '0') {
                if (b[b.length()-i-1] == '0') {
                    answer = "0" + answer;
                }
                else {
                    answer = "1" + answer;
                }
                // carry = false;
            }
            else {
                if (b[b.length()-i-1] == '0') {
                    answer = "1" + answer;
                    // carry = false;
                }
                else {
                    answer = "0" + answer;
                    carry = true;
                }
            }
        }

        if (carry) answer = "1" + answer;

        return answer;
    }
};
