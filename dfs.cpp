#include <stdio.h>
#include <stdlib.h>
 
// Cấu trúc node trong danh sách kề
struct Node {
    int vertex;
    struct Node* next;
};
 
// Cấu trúc đồ thị
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;  // Mảng đánh dấu đỉnh đã được thăm
};
 
// Hàm tạo node mới
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 
// Hàm tạo đồ thị
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    // Tạo danh sách kề
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
 
    // Khởi tạo danh sách kề và mảng visited
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;  // Chưa đỉnh nào được thăm
    }
    return graph;
}
 
// Thêm cạnh vào đồ thị
void addEdge(struct Graph* graph, int src, int dest) {
    // Thêm đỉnh dest vào danh sách kề của đỉnh src
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // Thêm đỉnh src vào danh sách kề của đỉnh dest (đồ thị vô hướng)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
 
// Hàm DFS
void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;
 
    // Đánh dấu đỉnh hiện tại đã được thăm
    graph->visited[vertex] = 1;
    printf("Da tham dinh %d\n", vertex);
 
    // Duyệt tất cả các đỉnh kề với đỉnh hiện tại
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
 
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
 
int main() {
    int vertices, edges;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);
 
    struct Graph* graph = createGraph(vertices);
 
    printf("Nhap so canh cua do thi: ");
    scanf("%d", &edges);
 
    // Thêm các cạnh vào đồ thị
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Nhap canh thu %d (dinh u va dinh v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
 
    // Thực hiện DFS từ đỉnh 0 (hoặc bất kỳ đỉnh nào)
    printf("Duyet do thi theo chieu sau (DFS):\n");
    DFS(graph, 0);
 
    return 0;
}