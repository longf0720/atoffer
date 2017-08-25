int lock_ = 0;
class Solution {
private:
    static Solution *instance;
private:
    static void Lock(){
        while(lock_){}
        lock_ = 1;
    }
    static void UnLock(){
        if(lock_) lock_=0;
    }
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        if(instance == NULL)
        {
            Solution::Lock();
            if(instance == NULL)
            {
              instance = new Solution(); 
            } 
            Solution::UnLock();
        }
        return instance;
    }
};

Solution* Solution::instance=NULL;
