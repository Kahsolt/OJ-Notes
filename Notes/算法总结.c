/*KMP*/
int Next[1000];
string A,B;
void KMP()
{
    cin>>A>>B;
    int lena=A.length();//母串
    int lenb=B.length();//子串
    int j;
    Next[1]=j=0;
    for(int i=2;i<=lenb;i++)
    {
        while(j>0&&B[j+1]!=B[i])j=Next[j];
        if(B[j+1]==B[i])j++;
        Next[i]=j;
    }
    j=0;
    for(int i=1;i<=lena;i++)
    {
        while(j>0&&B[j+1]!=A[i])j=Next[j];
        if(B[j+1]==A[i])j++;
        if(j==lenb)
        {
            cout<<"??"<<i-lenb+1<<"?????"<<endl;
            j=Next[j];
        }
    }
}

/*下限二分搜索*/
int BinSearch(int x,int y)
{
    if(x==y&&f[x]!=k)return -1;
    
    int mid=(x+y)/2;
    if(k==f[mid])
    {
        while(mid>1&&f[mid-1]==k)mid--;
        return mid;
    }
    else if(k>f[mid]&&mid+1<=y)BinSearch(mid+1,y);
    else if(k<f[mid]&&x<=mid)BinSearch(x,mid);
    else return -1;
}
/*01背包*/
memset(f,0,sizeof(f));        
for(int i=1;i<=m;i++)
{
    cin>>V>>W;
    for(int j=n;j>=V;j--)
        f[j]=max(f[j],f[j-V]+W);
}
cout<<f[n]<<endl;
/*矩阵相乘*/
int matrixChain(int x[],int f[][],int s[][])    //s[]用于记录分点 
{
    memset(m,0,sizeof(m));
    for(int r=2;r<=n;r++)
    for(int i=1;i<=n-r+1;i++)
    {
        int j=i+r-1;
        m[i][j]=m[i-1][j]+p[i-1]*p[i]*p[j];
        s[i][j]=i;
        for(int k=i+1;k<j;k++)
        {
            int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            if(t<m[i][j])
            {
                m[i][j]=t;
                s[i][j]=k;
            }
        }
    }
}
/*最长公共子序列*/
int maxCmmnSubseq(int f[],DataType *x,DataType *y,int lenx,int leny)//返回最长公共子序列长度
{
    memset(f,0,sizeof(f));
    memset(b,0,sizeof(b));
    
    for(int i=1;i<=lenx;i++)
      for(int j=1;j<=leny;j++)
        if(x[i]==y[j])
        {
            f[i][j]=f[i-1][j-1]+1;
            b[i][j]=0;
        }
        else if(f[i-1][j]>=f[i][j-1])
        {
           f[i][j]=f[i-1][j];
           b[i][j]=1;
        }
        else
        {
           f[i][j]=f[i][j-1];
           b[i][j]=-1;
        }
    return f[lenx][leny];
}
void printLCS(int i,int j)
{
    if(i==0||j==0)return;
    if(b[i][j]==0)
    {
        printLCS(i-1,j-1);
        cout<<x[i-1]<<" "; 
    }
    else if(b[i][j]==1)
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}
/*高精度乘法*/
void Multiply()
{
    memset(c,0,sizeof(c));
    
    int k=0;
    for(int j=lenb;j>=1;j--)
    {
        k++;    //Shift
        for(int i=lena;i>=1;i--)
        {
            c[k+(lena-i)]+=(b[j]*a[i]%10);
            c[k+(lena-i)+1]+=(b[j]*a[i]/10);
            
            c[k+(lena-i)+1]+=(c[k+(lena-i)]/10);
            c[k+(lena-i)]=(c[k+(lena-i)]%10);
        }
    }
    
    lenc=2000;
    while(c[lenc]==0)lenc--;
}
/*快速排序*/
void QuickSort(DataType *seq,int left,int right)
{
    int x=left,y=right,mid=seq[(left+right)>>1];
    do
    {
        while(seq[x]<mid)x++;
        while(seq[y]>mid)y--;
        if(x<=y)
        {
            swap(seq[x],seq[y]);
            x++;y--;
        }
    }while(x<=y);
    if(left<y)QuickSort(seq,left,y);
    if(x<right)QuickSort(seq,x,right);
    return;
}
/*活动规划*/
int Greedy_Activity()
{
    int ans=1;
    trace[++trace[0]]=1;
    int p=1;    //指向答案子集中的最后一个活动 
    for(int i=2;i<=n;i++)
    if(act[i].start>=act[p].finish)    //取等，端点可重叠
    {
        trace[++trace[0]]=i;
        ans++;
        p=i;
    }
    return ans;
}
void Dijkstra(int f[],int s)    //s为起点
{
    int dis[maxSize+1];        //s到各个点距离
    bool visited[maxSize+1];    //访问记录
    for(int i=1;i<=n;i++)
    {
        if(f[s][i]<0)dis[i]=INT_MAX;
        else dis[i]=f[s][i];
        visited[i]=false;
    }
    dis[s]=0;
    while(true)
    {
        int id=-1;
        int mindis=INT_MAX;
        for(int i=1;i<=n;i++)
        if(!visited[i]&&dis[i]<mindis)
        {
            mindis=dis[i];
            id=i;
        }
        visited[id]=true;
        if(id==-1)break;    //最短的边也不可达，退出循环
        
        for(int j=1;j<=n;j++)    //更新了id，则以id相关的路都更新
            if(!visited[j]&&f[id][j]!=INT_MAX)
            {
                if(dis[id]+f[id][j]<dis[j])    //在通过新加入的u点路径找到离v0点更短的路径  
                dis[j]=dis[id]+f[id][j];
            }
   　　}
    }
}
/*Prim算法*/
void Prim(int f[],int start)
{
    int ans=0;
    int dis[101];
    for(int i=1;i<=n;i++)
        dis[i]=f[start][i];
    dis[start]=0;
    
    for(int i=2;i<=n;i++)
    {
        int mindis=INT_MAX;
        int id=-1;
        for(int j=1;j<=n;j++)
            if(dis[j]!=0&&dis[j]<mindis)
            {
                mindis=dis[j];
                id=j;
            }
        dis[id]=0;
        ans+=mindis;
        for(int k=1;k<=n;k++)
        if(dis[k]!=0&&f[id][k]<dis[k])
            dis[k]=f[id][k];
    }
    cout<<"Minimum is "<<ans<<endl;
}
/*二分快速取模 (a^b mod c)*/
int Montgomery(int a,int b,int c)
{
    int ans=1;
    a=a%c;
    while(b>0)
    {
        if(b&1)ans=(ans*a%c);
        b=b>>1;
        a=(a*a)%c;
    }
    return ans;
}
===========================================
01背包：
for i=1..N
   for v=V..c[i]
      f[v]=max{f[v],f[v-c[i]]+w[i]};
完全背包：
for i=1..N
    for v=c[i]...V
        f[v]=max{f[v],f[v-c[i]]+w[i]}
多重背包:
f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k<=n[i]}
满背包：
memset(f,-1,sizeof(f)); 
f[0] = 0; 
for(int i = 1; i<=N; i++) 
    for(int v=P; v>=c[i]; v--) 
        if(f[v-c[i]]!=-1 && f[v-c[i]]+p[i]>f[v]) 
=============================================
#include <queue>
empty() 如果队列为空返回真
pop()   删除对顶元素
push()  加入一个元素
size()  返回优先队列中拥有的元素个数
top()   返回优先队列对顶元素
priority_queue<int>q;

struct cmp{operator bool ()(int x, int y){return　x>y;}};
priority_queue<int, vector<int>, cmp>q;

struct node{int x, y;friend bool operator < (node a, node b){return a.x > b.x;}};
priority_queue<node>q;
=============================================
pair<int, double> p1;  //使用默认构造函数
pair<int, double> p2(1, 2.4);  //用给定值初始化
pair<int, double> p3(p2);  //拷贝构造函数
pair<int, double> p1;  //使用默认构造函数
p1.first = 1;
p1.second = 2.5;
pair<int, double> p1;
p1 = make_pair(1, 1.2);
=============================================
import java.util.LinkedList;
import java.util.Queue;

public class MinFlow {
    public static int V = 6;
    /**
     * @param rGraph 残留网络
     * @param s 源点
     * @param t 终点
     * @param path 路径
     * @return 是否可以在rGraph中找到一条从 s 到 t 的路径
     */
    public static boolean hasPath(int rGraph[][], int s, int t, int path[]) {
        boolean visited[] = new boolean[V];
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(s);
        visited[s] = true;
        //标准的BFS算法
        while(queue.size() > 0){
            int top = queue.poll();
            for(int i=0; i<V; i++){
                if(!visited[i] && rGraph[top][i] > 0){
                    queue.add(i);
                    visited[i] = true;
                    path[i] = top;
                }

            }
        }
        return visited[t] == true;
    }
    /**
     * @param graph 有向图的矩阵表示
     * @param s 源点
     * @param t 终点
     * @return 最大流量
     */
    private static int maxFlow(int[][] graph,int s, int t) {
        int rGraph[][] = new int[V][V];
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                rGraph[i][j] = graph[i][j];

        int maxFlow = 0;

        int path[] = new int[V];
        while(hasPath(rGraph, s, t, path)){
            int min_flow = Integer.MAX_VALUE;

            //更新路径中的每条边,找到最小的流量
            for(int v=t; v != s; v=path[v]){
                int u = path[v];
                min_flow = Math.min(min_flow, rGraph[u][v]);
            }

            //更新路径中的每条边
            for(int v=t; v != s; v=path[v]){
                int u = path[v];
                rGraph[u][v] -= min_flow;
                rGraph[v][u] += min_flow;
            }
            maxFlow += min_flow;
        }

        return maxFlow;
    }
    public static void main(String[] args) {
        //创建例子中的有向图
        int graph[][] = { { 0, 16, 13, 0, 0, 0 }, 
                { 0, 0, 10, 12, 0, 0 },
                { 0, 4, 0, 0, 14, 0 },
                { 0, 0, 9, 0, 0, 20 },
                { 0, 0, 0, 7, 0, 4 },
                { 0, 0, 0, 0, 0, 0 } };
        V = graph.length;
        int flow = maxFlow(graph, 0, 5);
        System.out.println("The maximum possible flow is :" + flow);
    }
}