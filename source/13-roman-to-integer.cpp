class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int N = s.length();
        
        int temp = 0;
        for (int i=0; i<N; i++) {
            switch(s[i]) {
                case 'V':
                    res += 5;
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'M':
                    res += 1000;
                    break;
                case 'I':
                    if ((i+1<N)) {
                        switch(s[i+1]) {
                            case 'V':
                                res += 4;
                                i++;
                                break;
                            case 'X':
                                res += 9;
                                i++;
                                break;
                            default:
                                res += 1;
                                break;
                        }
                        break;
                    }
                    else {
                        res += 1;
                        break;
                    }
                case 'X':
                    if ((i+1<N)) {
                        switch(s[i+1]) {
                            case 'L':
                                res += 40;
                                i++;
                                break;
                            case 'C':
                                res += 90;
                                i++;
                                break;
                            default:
                                res += 10;
                                break;
                        }
                        break;
                    }
                    else {
                        res += 10;
                        break;
                    }
                case 'C':
                    if ((i+1<N)) {
                        switch(s[i+1]) {
                            case 'D':
                                res += 400;
                                i++;
                                break;
                            case 'M':
                                res += 900;
                                i++;
                                break;
                            default:
                                res += 100;
                                break;
                        }
                        break;
                    }
                    else {
                        res += 100;
                        break;
                    }
            }
        }
        return res;
    }
};

