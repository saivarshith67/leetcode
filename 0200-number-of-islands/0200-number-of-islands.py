class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0

        LAND = "1"
        WATER = "0"

        rows = len(grid)
        cols = len(grid[0])

        def dfs(i, j):
            if i < 0 or i >= rows or j < 0 or j >= cols or grid[i][j] == WATER:
                return

            # here current point is LAND so change it to WATER to mark as visited and navigate
            grid[i][j] = WATER

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        num_islands = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == LAND:
                    num_islands += 1
                    dfs(i, j)

        return num_islands

        