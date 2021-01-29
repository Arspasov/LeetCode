struct Point{
    int x;
    int y;
    
    bool operator<(const Point& rhs) const {
        return  x * x + y * y > rhs.x * rhs.x + rhs.y * rhs.y;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        std::priority_queue<Point> que;
        for(auto point : points){
            que.push({point [0],point[1]});
        }
        vector<vector<int>> result;
        
        for(int _ = 0; _ < K; _++){
             vector<int> point;
            point.push_back(que.top().x);
            point.push_back(que.top().y);
            result.push_back(point);
            que.pop();
        }
        return result;
    }
};