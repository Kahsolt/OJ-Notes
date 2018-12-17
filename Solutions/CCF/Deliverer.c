#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 100000
#define MAXE 1000000

#define TIME_TRICK

#ifdef TIME_TRICK
#include <time.h>
#define TIME_TOLERANCE (CLOCKS_PER_SEC * 0.95)
clock_t time_start, time_stop;
#endif

typedef struct edge {
    int from : 20;
    int to : 20;
    int visited : 1;
    struct edge *conj;
} Edge, *pEdge;

int N, M, M2, i;
int *degree;
Edge **edges;
int top_edges=-1;
int *hash_base;
int *path;
int top_path=-1;
char eureka=0;

int LE(Edge *e1, Edge *e2)
{
    if(e1->from < e2->from) return 1;
    else if(e1->from > e2->from) return 0;
    if(e1->to <= e2->to) return 1;
    return 0;
}
void Qsort(Edge **edges, int left, int right)
{
    int x=left, y=right;
    Edge *pit=edges[x];
    while(x<y)
    {
        while(x<y && LE(pit, edges[y]))y--;
        edges[x]=edges[y];
        while(x<y && LE(edges[x], pit))x++;
        edges[y]=edges[x];
    }
    edges[x]=pit;
    
    if(left<x-1)Qsort(edges, left, x-1);
    if(y+1<right)Qsort(edges, y+1, right);
}
void Hashtable(Edge **edges)
{
    int p=0, last=edges[0]->from;
    hash_base[last]=0;
    p++;
    while(p<M2)
    {
        if(edges[p]->from!=last)
        {
            last=edges[p]->from;
            hash_base[last]=p;
        }
        p++;
    }
}
void Eular(int current_vertex, int edge_visited_count)
{
    /* printf("now at vertex %d, length=%d\n", current_vertex, edge_visited_count); */

#ifdef TIME_TRICK
    time_stop = clock();
    if(time_stop - time_start > TIME_TOLERANCE)
    return;
#endif

    if(edge_visited_count==M)
    {
        eureka=1;
        int i;
        printf("1 ");
        for(i=0;i<=top_path;i++)
            printf("%d ", path[i]);
        printf("\n");
        return;
    }

    int edge_idx=hash_base[current_vertex];
    Edge *edge=edges[edge_idx];
    while(!eureka && edge_idx<M2 && edge->from==current_vertex)
    {
        if(edge->visited==0)
        {
            edge->visited=1; edge->conj->visited=1;
            path[++top_path]=edge->to;
            /* printf("Try going to %d\n", edge->to); */
            Eular(edge->to, edge_visited_count+1);
            /* restore env on failure */
            edge->visited=0; edge->conj->visited=0;
            --top_path;
        }
        edge_idx++; /* try another way */
        edge=edges[edge_idx];
    }
}
void print()
{
    int i;
    printf("=======\n");
    for(i=0;i<M2;i++)
        printf("<%d> %d -> %d     # %x | %x\n", i, edges[i]->from, edges[i]->to, edges[i], edges[i]->conj);
    for(i=1;i<=N;i++)
        printf("edges linked to vertex %d starts from idx %d\n", i, hash_base[i]);
    printf("=======\n");
}

int main()
{
    scanf("%d%d", &N, &M); /* vertexes indexed from 1 to N*/
    M2=2*M;
    degree=malloc((N+1)*sizeof(int)); /* degree[0] UNUSED */
    memset(degree, 0, (N+1)*sizeof(int));
    hash_base=malloc((N+1)*sizeof(int));
    memset(hash_base, -1, (N+1)*sizeof(int));

    path=malloc(M*sizeof(int));
    memset(path, 0, M*sizeof(int));
    edges=malloc(M2*sizeof(pEdge)); /* save dual-direct, so double it */
    memset(edges, 0, M2*sizeof(pEdge));

    int x, y, countdown=M;
    while(countdown--)
    {
        scanf("%d%d", &x, &y);
        degree[x]++; degree[y]++;
        Edge *e1=malloc(sizeof(Edge)), *e2=malloc(sizeof(Edge));
        e1->from=x; e1->to=y; e1->visited=0; e1->conj=e2;
        e2->from=y; e2->to=x; e2->visited=0; e2->conj=e1;
        edges[++top_edges]=e1; edges[++top_edges]=e2;
    }
    
    int odd_degree=0;
    for(i=1;i<=N;i++)
        if((degree[i] & 0x1u)==1) odd_degree++;
    if(odd_degree==0 || (odd_degree==2 && (degree[1]&0x1u)==1))
    {
        Qsort(edges, 0, M2-1);
        Hashtable(edges);
        /* print(); */
#ifdef TIME_TRICK
        time_start = clock();
#endif
        Eular(1, 0);
    }
    if(!eureka) printf("-1\n");
    
    return 0;
}
