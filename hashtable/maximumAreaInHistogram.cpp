

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iterator>
#include <set>

int maximumAreaInHistogram(vector<int> graph){
    
    if(!graph.size()) return 0;
    
    int maxArea = 0, area = 0, top = 0;
    stack<int> st;
    int graphSize = graph.size();
    
    st.push(0);
    int i = 0;
    for (; i<graphSize; ) {
        
        
        if (st.empty() || graph[i] >= graph[st.top()]) {
            st.push(i++);
        }else{
            top = st.top(); st.pop();
            
            if (st.empty()) {
                area = graph[top]*i;
            }else{
                area = graph[top]*(i-st.top()-1);
            }
            
            if (maxArea<area) {
                maxArea = area;
            }
            
        }
    }
    
    while (!st.empty()) {
        top = st.top(); st.pop();
        
        if (st.empty()) {
            area = graph[top]*i;
        }else{
            area = graph[top]*(i-st.top()-1);
        }
        
        if (maxArea<area) {
            maxArea = area;
        }
        
    }
    
    
    return maxArea;
}

int main(){
    vector<int> input = {2,1,2,3,1};
    cout<<maximumAreaInHistogram(input)<<endl;
}
