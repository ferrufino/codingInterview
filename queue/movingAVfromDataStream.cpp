class MovingAverage {
private:
    queue<int> q;
    double acum = 0;
    int limit = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        limit = size;
    }
    
    double next(int val) {
        
        if(q.size() < limit){
            
            acum+=val;
            q.push(val);
            
            return acum/(1.0*q.size());
        }else{
            
            acum-=q.front();
            acum+=val;
            q.pop();
            q.push(val);
            
            return acum/(1.0*q.size());
            
        }
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
