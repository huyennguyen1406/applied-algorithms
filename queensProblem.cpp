#include <stdio.h>
#include <math.h>

#define N 8 // Kích thước của bàn cờ (8x8)

int board[N]; // Mảng lưu vị trí của các con hậu, board[i] là vị trí của con hậu trên hàng i

// Hàm kiểm tra xem có thể đặt một con hậu tại vị trí (row, col) hay không
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Kiểm tra nếu có con hậu nào đã được đặt cùng cột hoặc cùng đường chéo
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0; // Không an toàn
        }
    }
    return 1; // An toàn
}

// Hàm giải bài toán con hậu bằng kỹ thuật Backtracking
void solveNQueens(int row) {
    if (row == N) { // Nếu đã đặt thành công tất cả N con hậu
        // In ra một lời giải
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j) {
                    printf("Q "); // Q đại diện cho con hậu
                } else {
                    printf(". "); // Dấu "." đại diện cho ô trống
                }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) { // Kiểm tra nếu có thể đặt hậu ở vị trí (row, col)
            board[row] = col; // Đặt con hậu vào vị trí đó
            solveNQueens(row + 1); // Tiếp tục đặt hậu cho hàng tiếp theo
        }
    }
}

int main() {
    solveNQueens(0); // Bắt đầu giải bài toán từ hàng đầu tiên
    return 0;
}