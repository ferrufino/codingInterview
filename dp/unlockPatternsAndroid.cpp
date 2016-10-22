class Solution {
    
    
public:
    int func(int jump[10][10], bool v[10], int cur, int toTouch){
        
        if(toTouch<=0)
            return toTouch==0?1:0;
        
        int ways = 0;
        v[cur] = true;
        
        for(int i=1; i<10; i++){
            if(!v[i] && (!jump[i][cur] || v[jump[i][cur]] ))
                ways += func(jump, v, i, toTouch-1);
        }
        
        v[cur] = false;
        
        return ways;
        
    }
    
    int numberOfPatterns(int m, int n) {
        int jump[10][10] = {0};
        
        jump[1][3] = jump[3][1] = 2;
        
        jump[7][9] = jump[9][7] = 8;
        
        jump[1][7] = jump[7][1] = 4;
        
        jump[3][9] = jump[9][3] = 6;
        
        jump[1][9] = jump[9][1] = jump[2][8] = jump[8][2] = jump[3][7] = jump[7][3] = 5;
        
        bool visit[10] = {false};
        int ways = 0;
        
        for(int i = m; i<=n; i++){
            
            ways+= 4 * func(jump, visit, 1, i-1);
            ways+= 4 * func(jump, visit, 2, i-1);
            ways+= func(jump, visit, 5, i-1);
            
        }
        
        return ways;
    }
    
    
    
};
