class Solution {
public:
    int totalNumbers(vector<int>& digits) {
          set<int> nums;
        int n = digits.size();

        for(int i = 0; i< n; i++){
            for(int  j = i+1; j< n; j++){
                for(int k = j+1;k<n;k++){
                    int num1 = digits[i]*100 + digits[j]*10 + digits[k];
                    int num2 = digits[i]*100 + digits[k]*10 + digits[j];
                    int num3 = digits[j]*100 + digits[i]*10 + digits[k];
                    int num4 = digits[j]*100 + digits[k]*10 + digits[i];
                    int num5 = digits[k]*100 + digits[i]*10 + digits[j];
                    int num6 = digits[k]*100 + digits[j]*10 + digits[i];

                    if (digits[i] != 0) {
                        if(digits[k]%2 == 0) nums.insert(num1);
                        if(digits[j]%2==0) nums.insert(num2);
                    }

                    if (digits[j] != 0) {
                        if(digits[k]%2 == 0) nums.insert(num3);
                        if(digits[i]%2 == 0) nums.insert(num4);
                    }

                    if (digits[k] != 0) {
                        if(digits[j]%2 == 0) nums.insert(num5);
                        if(digits[i]%2 == 0) nums.insert(num6);
                    }
                }
            }
        }

        return nums.size();
    }
};