/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/


#define MIN(a, b) ((a) > (b) ? (b) : (a))

int minPathSum(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || *grid == NULL) {
        return-1;
    }
    int row = gridSize;  //行
    int col = *gridColSize; //列数
    int **dp = (int **)malloc(sizeof(int *) * row);
    if (dp && *dp) {
        int i;
        for (i = 0; i < row; i++) {
            dp[i] = (int *)malloc(sizeof(int) * col);
        }
    }
    dp[0][0] = grid[0][0];
    int i, j;
    for (j = 1; j < col; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (i = 1; i < row; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for (i = 1; i < row; i++) {
        for (j = 1; j < col; j++) {
            dp[i][j] = MIN(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[i-1][j-1];
}
