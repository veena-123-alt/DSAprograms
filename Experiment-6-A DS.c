#include <stdio.h>
#include <conio.h>

#define size 20
#define T 1
#define F 0

struct edge {
    int terminal;
    struct edge *next;
};

struct vertex {
    int visit;
    int vertex_no;
    char info;
    int path_length;
    struct edge *Edge_ptr;
};

void Table(int , int matrix [size][size], struct vertex vert[size]);
struct edge *insert_vertex(int , struct edge *);
void DFS (int, int *dist, struct vertex vert [size]);
void input(int,  int a [size][size]);
void output(int, int a[size][size]);

struct edge *insert_vertex(int vertex_no, struct edge *first) {
    struct edge *new1, *current;
    new1 = (struct edge *)malloc(sizeof(struct edge));
    new1 -> next = NULL;
    if (!first) {
        return (new1);
    }
    for (current = first; current -> next; current = current -> next);
    current -> next = new1;
    return (first);
}

void Table(int vertex_no, int matrix[size][size], struct vertex vert[size]) {
    int i, j;
    for (i = 0; i < vertex_num; i++) {
        vert[i].visit = F;
        vert[i].vertex_no = i+1;
        vert[i].info = 'A' + i;
        vert[i].path_length = 0;
        vert[i].Edge_ptr = NULL;
    }
    for (i = 0; i < vertex_no; i++) {
        for (j = 0; j < vertex_no; j++) {
            if (matrix[i][j] > 0){
                vert [i].Edge_ptr = insert_vertex(j, vert [i].Edge_ptr);
            }
        }
    }
}

void DFS (int index, int *dist, struct vertex vert[size]){
    struct edge *link;
    vert [index].visit = T;
    vert [index].path_length = *dist;
    *dist += 1;
    for (link = vert[index].Edge_ptr; link = link -> next) {
        if (vert [link -> terminal].visit == F) {
            DFS(link->terminal, dist, vert);
        }
    }
}

void input(int number, int a [size][size]) {
    int i, j;
    printf("\n input the adjacency matrix \n");
    for (i = 0; i < number; i++) {
        for (j = 0; j < number; j++) {
            scanf("%d", &a[i][j]);
        }
        printf("\n");
    }
}

void output(int number, int a[size][size]){
    int i, j;
    printf("\n Adjacent matrix \n");
    for (i = 0; i < number; i++)
    {
        for (j = 0; j < number; j++)
        {
            printf("    %d", a[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int i;
    int number, index, dist;
    int a [size][size];
    struct vertex vert [size];
    struct edge *list;
    clrscr();
    printf("\n input the number of vertices in the graph: ");
    scanf("%d", &number);
    input(number, a);
    output(number, a);
    Table(number, a, vert);
    printf("\n input the starting vertex 0 - &d: ", number-1);
    scanf("%d", &index);
    dist = 0;
    DFS(index, &dist, vert);
    printf("\n Path length of the vert %d", vert[index].info);
    printf("\n Vertex lenggth vertex connectivity \n");
    for (i = 0; i < number; i++) {
        printf("\n %c %d ", vert[i].info, vert[i].path_length);
    }
    for(list = vert[i].Edge_ptr; list; list = list -> next){ 
        print(" ");
        putchar(list -> terminal + "A");
    }
    getch();
}
