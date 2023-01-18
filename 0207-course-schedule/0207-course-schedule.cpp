class Solution {
public:
    bool dfs(int& course, unordered_map<int, bool>& dico_visited, unordered_map<int, vector<int>>& dico_courses) {

        if (dico_visited.find(course) != dico_visited.end()) { return false; }
        if (dico_courses.find(course) == dico_courses.end()) { return true; }


        dico_visited[course] = true;
        for (int req : dico_courses[course]) {

            if (not dfs(req, dico_visited, dico_courses)) {
                return false;
             };

        }
        dico_visited.erase(course);
        dico_courses.erase(course);
        return true;
    };
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, bool> dico_visited;
        unordered_map<int, vector<int>> dico_courses;
        
        for (vector<int> req : prerequisites) {

            if (dico_courses.find(req[0]) == dico_courses.end()) {
                dico_courses[req[0]] = vector<int>{};
            }
            dico_courses[req[0]].push_back(req[1]);
        }
        
        
        
        for (vector<int> req: prerequisites) {
            if (not dfs(req[0], dico_visited, dico_courses)) {
                return false;
            }
        }

        return true;
    }
};