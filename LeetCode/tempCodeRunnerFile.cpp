class Solution {
public:
    int smallestNumber(int n) {
        if(n==1 || n==0){
            return n;
        }
        int bits = sqrt(n)+1;
        return pow(2,bits) -1;
    }
};