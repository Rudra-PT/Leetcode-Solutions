class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startCities;
        for (int i = 0; i < paths.size(); i++) {
            startCities.insert(paths[i][0]); 
        }
        for (int i = 0; i < paths.size(); i++) {
            string destination = paths[i][1];
            if (startCities.find(destination) == startCities.end()) {
                return destination;
            }
        }
        
        return "";
    }
};