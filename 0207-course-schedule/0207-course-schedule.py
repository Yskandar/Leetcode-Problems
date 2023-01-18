class Solution:
    
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        dico_courses = {}
        dico_visited = {}
        for pre_req in prerequisites:
            if dico_courses.get(pre_req[0]) is None:
                dico_courses[pre_req[0]] = []
            dico_courses[pre_req[0]] += [pre_req[1]]
        
        
        
        def dfs(course):
            
            if dico_visited.get(course) is not None:
                return False
            if dico_courses.get(course) is None:
                return True
            
            dico_visited[course] = True
            for req in dico_courses[course]:
                if not dfs(req):
                    return False
            dico_visited[course] = None
            dico_courses[course] = None
            return True
        
        for pre_req in prerequisites:
            if not dfs(pre_req[0]):
                return False
            
        
        return True
        
        
        