class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image
        ini_color = image[sr][sc]

        image[sr][sc] = color

        rows, cols = len(image), len(image[0])

        q = deque()
        q.append((sr, sc))

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while q:
            x, y = q.popleft()
            for dx, dy in directions:
                xx, yy = x + dx, y + dy
                if 0 <= xx < rows and 0 <= yy < cols and image[xx][yy] == ini_color:
                    image[xx][yy] = color
                    q.append((xx, yy))


        return image