from functools import cache

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        row = len(matrix)
        col = len(matrix[0])
        result = 0
        result_map = {}

        def check_bounds(x,y):
            nonlocal row,col
            if x >= 0 and y >= 0 and x < row and y < col:
                return True
            else:
                return False
        @cache
        def dfs(x,y):
            temp_result = 0
            direction = [(0,1),(1,0),(-1,0),(0,-1)]
            for i,j in direction:
                new_x = x+i
                new_y = y+j
                if check_bounds(new_x,new_y) and matrix[new_x][new_y] > matrix[x][y]:
                    temp_result = max(temp_result,dfs(new_x,new_y))
            return temp_result + 1


        for i in range(row):
            for j in range(col):
                visited = []
                result = max(result,dfs(i,j))

        return result