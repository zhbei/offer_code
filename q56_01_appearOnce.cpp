    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int ans = 0;
        for(int a : data){
            ans ^= a;
        }
        int ans1 = 0, ans2 = 0;
        for(int a : data){
            if(ans & a){
                ans1 ^= a;
            }else{
                ans2 ^= a;
            }
        }
        *num1 = ans1;
        *num2 = ans2;
    }