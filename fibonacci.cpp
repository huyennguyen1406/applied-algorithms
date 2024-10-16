#include <stdio.h>
 
// Tạo một mảng để lưu trữ giá trị Fibonacci đã tính
int memo[1000];
 
// Hàm Fibonacci sử dụng đệ quy có nhớ
int fibonacci(int n) {
    // Trường hợp cơ bản
    if (n == 0) return 0;
    if (n == 1) return 1;
 
    // Kiểm tra xem giá trị đã được tính chưa
    if (memo[n] != -1)
    {
        printf("memo[%d] solved\n", n);
        return memo[n];
    }
 
    // Tính giá trị Fibonacci và lưu lại trong memo
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}
 
int main() {
    int n;
    // Khởi tạo giá trị -1 cho mảng memo để đánh dấu chưa được tính
    for (int i = 0; i < 1000; i++) {
        memo[i] = -1;
    }
 
    // Nhập vào số n
    printf("Nhập giá trị n: ");
    scanf("%d", &n);
 
    // Gọi hàm Fibonacci và in kết quả
    printf("Fibonacci của %d là %d\n", n, fibonacci(n));
 
    return 0;
}