class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> potential_judges;
        unordered_map<int,unordered_set<int>> graph;
        for(int i = 1;i<=n;i++){
            potential_judges.insert(i);
        }
        
        for(auto trust_relation: trust){
            int parent = trust_relation[0];
            int child = trust_relation[1];
            
            potential_judges.erase(parent);
            graph[parent].insert(child);
        }
        
        if(potential_judges.size()!= 1){
            return -1;
        }
        
        int judge = * potential_judges.begin();
        
        for(auto x : graph){
            if(x.second.count(judge) != 1){
                return -1;
            }
        }
        
        return judge;
    }
};