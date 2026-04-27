class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False] * n

        def dfs(city):
            for nei in range(n):
                if isConnected[city][nei] == 1 and not visited[nei]:
                    visited[nei] = True
                    dfs(nei)

        num_province = 0
        for i in range(n):
            if not visited[i]:
                num_province += 1
                dfs(i)

        return num_province
