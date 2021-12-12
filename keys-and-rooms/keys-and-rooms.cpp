class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> unlocked(rooms.size(),false);
        vector<bool> visited(rooms.size(),false);
        unlocked [0] = true;
        
        queue<int> next_rooms;
        next_rooms.push(0);
        while(!next_rooms.empty()){
            int current_room = next_rooms.front();
            next_rooms.pop();
            if(visited[current_room]){
                continue;
            }
            
            visited[current_room] = true;
            for(auto key : rooms[current_room]){
                unlocked[key] = true;
                next_rooms.push(key);
            }
        }
        
        for(auto room : unlocked){
            if(room == false){
                return false;
            }
        }
        
        return true;
    }
};