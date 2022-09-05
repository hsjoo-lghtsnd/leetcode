class Solution {
public:
    bool isValid(string s) {
        int N = s.length();
        vector<char> v;
        char temp;
        
        for (int i=0; i<N; i++) {
            switch(s[i]) {
                case '(':
                case '{':
                case '[':
                    v.push_back(s[i]);
                    break;
                default:
                    if (v.empty()) {
                        return false;
                    }
                    temp = v.back();
                    v.pop_back();
                    switch(s[i]) {
                        case ')':
                            if (temp != '(')
                                return false;
                            break;
                        case '}':
                            if (temp != '{')
                                return false;
                            break;
                        case ']':
                            if (temp != '[')
                                return false;
                            break;
                        default:
                            return false; // error
                    }
            }
        }
        return v.empty();
    }
};
