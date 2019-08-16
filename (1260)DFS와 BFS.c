#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visit[1001] = {0};
int fuck[1001][1001] = {0, };
int N; //정점의 개수
int M; //간선의 개수
int V; //탐색 시작 번호
int start;
int end;
int i,j;
int mom;

typedef struct Stack{
    int data[1003000];
    int top;
}Stack;

void StackInit(Stack *s){
    s->top = -1;
}

void StackPush(Stack *s, int data){
    s->top += 1;
    s->data[s->top] = data;
}

int StackPop(Stack *s){
    return s->data[s->top--];
}

int StackEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    else return 0;
}



Stack s;

typedef struct Queue{
    int data[1003000];
    int head;
    int tail;
}Queue;

int QueueEmpty(Queue *q){
    if(q->head == q->tail)
        return 1;
    else return 0;
}

void EnQueue(Queue *q, int data){
    q->data[q->head++] = data;
    q->head = q->head;
}

int DeQueue(Queue *q){
    int data;
    if(QueueEmpty(q)){
        printf("Queue Empty\n");
        exit(-1);
    }
    data = q->data[q->tail++];
    q->tail = q->tail;
    return data;
}

Queue q;

int dfs(int V){
    //printf("before : %d\n\n", V);
    for(j=0;j<=N;j++)
    {
        if(fuck[mom][j] == 1) {
            if (visit[j] == 0)
            {
                StackPush(&s, mom);

                printf(" %d", j);
                visit[j] = 1;
                mom = j;
                //printf("After : %d\n", V);
                dfs(mom);
            }
        }
    }
    if(StackEmpty(&s)) {
        //printf("Stack Empty\n");
        return 0;
    }
    else{
        mom = StackPop(&s);
        //printf("After : %d\n", V);
        dfs(mom);
    }
    return 0;
}

void bfs(int V){
    for(j=0;j<=N;j++) {
        if (fuck[mom][j] == 1) {
            if (visit[j] == 0){
                EnQueue(&q, j);
            }
        }
    }

    if(QueueEmpty(&q)) return;
    else {
        mom = DeQueue(&q);
        if (visit[mom] == 0){
            visit[mom] = 1;
            printf(" %d", mom);
            bfs(mom);
        }
        else{  //visit[mom] == 1
            while(visit[mom] == 0){
                mom = DeQueue(&q);
            }
            //printf(" %d", mom);
            bfs(mom);
        }
    }
}


int main()
{
    StackInit(&s);
    q.head = 0;
    q.tail = 0;

    scanf("%d %d %d", &N, &M, &V);

    for(i=0;i<M;i++)
    {
        scanf("%d %d", &start, &end);
        if(start == 0 || end == 0) exit(-1);
        fuck[start][end] = 1;
        fuck[end][start] = 1;
    }



    //printf("**result**\n");
    //for(i=0;i<=N;i++){
    //    for(j=0;j<=N;j++){
    //        printf("%d ",fuck[i][j]);
    //    }
    //    printf("\n");
    // }
    //printf("\n\n");

    visit[V] = 1;
    mom = V;
    printf("%d", mom);

    dfs(V);
    printf("\n");


    //BFS 시작

    for(i=0;i<=N;i++)
        visit[i] = 0;

    visit[V] = 1;
    mom = V;
    printf("%d", mom);

    bfs(V);
}
