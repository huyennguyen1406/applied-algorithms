#include <stdio.h>
#include <stdlib.h>
 
// Cấu trúc một node trong danh sách kề
struct Node {
    int vertex;
    struct Node* next;
};
 
// Cấu trúc đồ thị
struct Graph {
    int numVertices;
    struct Node** adjLists;
};
 
// Hàm tạo một node mới
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 
// Hàm tạo đồ thị với số đỉnh cho trước
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    // Khởi tạo danh sách kề cho mỗi đỉnh
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
 
// Hàm thêm cạnh vào đồ thị
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
 
// Hàm in danh sách kề của đồ thị
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("\n Danh sach ke cua dinh %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
 
int main() {
    int vertices, edges;
 
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);
 
    // Tạo đồ thị
    struct Graph* graph = createGraph(vertices);
 
    printf("Nhap so canh cua do thi: ");
    scanf("%d", &edges);
 
    // Nhập cạnh của đồ thị
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Nhap canh thu %d (dinh u va dinh v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
 
    // In đồ thị dưới dạng danh sách kề
    printGraph(graph);
 
    return 0;
}