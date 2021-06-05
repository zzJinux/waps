var solution=minPathSum
func Min(a, b int) int { if a<b { return a }; return b }
func minPathSum(grid [][]int) int {
	M,N:=len(grid),len(grid[0])
	for j:=1;j<N;j++ {
		grid[0][j]+=grid[0][j-1]
	}
	for i:=1;i<M;i++ {
		grid[i][0]+=grid[i-1][0]
		for j:=1;j<N;j++ {
			grid[i][j]+=Min(grid[i][j-1],grid[i-1][j])
		}
	}
	return grid[M-1][N-1]
}
