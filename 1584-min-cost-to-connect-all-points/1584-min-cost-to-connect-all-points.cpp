struct Edge{
    int to;
    int length;
    Edge(int to , int length) : to(to) , length(length){}
    
    bool operator<(const Edge& rhs) const{
        return length > rhs.length;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total = 0;
        
        vector<bool> visited (points.size(),false);
        priority_queue<Edge> que;
        if(points.size() >= 2){
            que.push({0, 0});
        }
        
        int visitedCounter = 1;
        
        while(!que.empty() && visitedCounter <= points.size()){
            auto current = que.top();
            que.pop();
            
            if(visited[current.to]){
                continue;
            }
            visited[current.to] = true;
            
            total += current.length;
            visitedCounter++;
            
            for(int i  = 0;i< points.size(); i++){
                if(!visited[i]){
                    int len = abs(points[i][0] - points[current.to][0]);
                    len += abs(points[i] [1] - points [current.to][1]);
                    que.push({i, len});
                }
            }
        }
        
        return total;
    }
};