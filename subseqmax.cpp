#include <stdio.h>
 
// Hàm tính tổng con lớn nhất sử dụng quy hoạch động

int maxSubArraySum(int arr[], int n) {

    int max_sum = arr[0];  // Tổng lớn nhất toàn cục

    int current_sum = arr[0];  // Tổng của dãy con hiện tại
 
    for (int i = 1; i < n; i++) {

        // Tính tổng của dãy con kết thúc tại arr[i]

        current_sum = (arr[i] > current_sum + arr[i]) ? arr[i] : current_sum + arr[i];
 
        // Cập nhật tổng lớn nhất toàn cục nếu cần

        if (current_sum > max_sum) {

            max_sum = current_sum;

        }

    }
 
    return max_sum;

}
 
int main() {

    int arr[] = {-2, 1, -3, 4, -1, 2, 8, 1, -5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
 
    int max_sum = maxSubArraySum(arr, n);

    printf("Tong con lon nhat cua day la: %d\n", max_sum);
 
    return 0;

}

 
#include <stdio.h>
 
// Hàm đệ quy tính tổng con lớn nhất kết thúc tại phần tử thứ i

int maxSubArrayRec(int arr[], int i, int *global_max) {

    // Cơ sở đệ quy: nếu là phần tử đầu tiên, trả về giá trị của nó

    if (i == 0) {

        printf("At index %d: current_sum = arr[0] = %d\n", i, arr[0]);

        return arr[0];

    }
 
    // Tính tổng con lớn nhất kết thúc tại chỉ số i bằng đệ quy

    int prev_sum = maxSubArrayRec(arr, i - 1, global_max);  // Gọi đệ quy

    int current_sum = prev_sum + arr[i];

    // Chọn giữa bắt đầu dãy con mới hoặc tiếp tục với dãy con trước đó

    int result = (arr[i] > current_sum) ? arr[i] : current_sum;
 
    // Cập nhật tổng lớn nhất toàn cục nếu cần

    if (result > *global_max) {

        *global_max = result;

    }
 
    // Hiển thị quá trình truy vết

    printf("At index %d: current_sum = %d, result = %d, global_max = %d\n", 

           i, current_sum, result, *global_max);
 
    // Trả về tổng con lớn nhất kết thúc tại chỉ số i

    return result;

}
 
// Hàm khởi động tính tổng con lớn nhất của toàn dãy bằng đệ quy

int maxSubArray(int arr[], int n) {

    // Biến lưu tổng con lớn nhất toàn cục

    int global_max = arr[0];
 
    // Bắt đầu đệ quy từ phần tử cuối cùng

    maxSubArrayRec(arr, n - 1, &global_max);
 
    return global_max;

}
 
int main() {

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
 
    int max_sum = maxSubArray(arr, n);

    printf("Tong con lon nhat cua day la: %d\n", max_sum);
 
    return 0;

}

 