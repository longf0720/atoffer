ass Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        if(1 == n) return 0;
        else if(2 == n) return 1;
        else{
            int f1=0,f2=1,fi=0;
            for(int i = 3; i <= n; i++){
                fi = f1 + f2;
                f1 = f2;
                f2 = fi;
            }
            return fi;
        }
    }
};

