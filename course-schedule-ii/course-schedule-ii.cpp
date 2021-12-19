class Solution {
public:

    vector<char> visited;
    vector<int> result;
    vector<vector<int>> graph;
    vector<int> findOrder (int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 'u');
        
       graph.resize(numCourses);
        for(auto edge: prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }
        
        for(int i = 0;i<numCourses;i++){
             if(dfs(i)== false){
                 return vector<int>();
             }
        }
        
        return result;
    }
    
     //c = closed;
    // o = open;
    // u = unvisited;
    bool dfs(int current){
        if(visited[current] == 'c'){
            return true;
        }
        if(visited[current] == 'o'){
            return false;
        }
        
        visited[current] = 'o';
        
        for(auto neigh : graph[current]){
            if(dfs(neigh) == false){
                return false;
            }
        }
        
        result.push_back(current);
        visited [ current] = 'c';
        return true;
    }
};