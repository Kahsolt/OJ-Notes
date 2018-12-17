#include<cstdio>
#include<cstdlib>
#define maxsize 1000000+10
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}tree;
void create(tree *&t,char str[])
{
    tree *st[maxsize],*p;
    int top=-1,k=0,j=0;
    char ch;
    t=NULL;
    ch=str[j];
    while(ch!='\n')
    {
        switch(ch)
        {
        case '(':
            top++;st[top]=p;k=1;break;
        case ')':
            top--;break;
        case ',':
            k--;break;
        default:
            p=(tree *)malloc(sizeof(tree));
            p->data=ch;p->lchild=p->rchild=NULL;
            if(t==NULL)
                t=p;
            else
            {
                switch(k)
                {
                case 1:
                    st[top]->lchild=p;break;
                case 2:
                    st[top]->rchild=p;break;
                }
            }
        }
        j++;
        ch=str[j];
    }
}
//判断二叉树是不是完全二叉树
//int ans[maxn],s=0;
//void create(tree *&t,char str[])
//{
//    tree *st[maxn],*p;
//    int top=-1,k=0,i=0,n=strlen(str);
//    t=NULL;
//    while(i<n)
//    {
//        if(str[i]=='(')
//        {
//           st[++top]=p;k=1;
//        }
//        else if(str[i]==')') --top;
//        else if(str[i]==',') k=2;
//        else
//        {
//            p=(tree *)malloc(sizeof(tree));
//            p->data=str[i];p->lchild=p->rchild=NULL;
//            if(t==NULL)
//            {
//                t=p;
//                t->num=1;
//                ans[s++]=t->num;
//            }
//            else
//            {
//                if(k==1)
//                {
//                    st[top]->lchild=p;
//                    st[top]->lchild->num=st[top]->num*2;
//                    ans[s++]=st[top]->num*2;
//                }
//                else
//                {
//                    st[top]->rchild=p;
//                    st[top]->rchild->num=st[top]->num*2+1;
//                    ans[s++]=st[top]->num*2+1;
//                }
//            }
//        }
//        i++;
//    }
//}
//bool solve()
//{
//    sort(ans,ans+s);
//   for(int i=0;i<s-1;i++)
//   {
//       if(ans[i+1]!=ans[i]+1)
//         return false;
//   }
//   return true;
//}

//二叉树节点是字符串
//typedef struct node
//{
//    char data[20];
//    int num;
//    struct node *lchild;
//    struct node *rchild;
//}tree;
//void create(tree *&t,char *str)
//{
//    tree *st[maxsize],*p;
//    int top=-1,k=0,j=0;
//    char ch;
//    t=NULL;
//    ch=str[j];
//    while(ch!='\0')
//    {
//        if(ch=='(')
//        {
//            top++;st[top]=p;k=1;
//        }
//        else if(ch==',') k=2;
//        else if(ch==')') top--;
//        else
//        {
//            p=(tree *)malloc(sizeof(tree));
//            int i=0;
//            while(ch!='('&&ch!=')'&&ch!=','&&ch!='\0')
//            {
//                p->data[i]=ch;
//                i++;j++;
//                ch=str[j];
//            }
//            p->data[i]='\0';
//            j--;
//            p->lchild=p->rchild=NULL;
//            if(t==NULL)  t=p;
//            else
//            {
//                if(k==1) st[top]->lchild=p;
//                else st[top]->rchild=p;
//            }
//        }
//        j++;
//        ch=str[j];
//    }
//}

//二叉树的数组转换为二叉树
//typedef struct node
//{
//    int data;
//    struct node *lchild;
//    struct node *rchild;
//}tree;
//void Create(tree *&t,int a[],int n)
//{
//    tree *st[maxsize],*p,*s;
//    int front=-1,rear=-1,j=1;
//    rear++;
//    st[rear]=t;
//    st[rear]->data=a[j++];
//    while(j<=n)
//    {
//        front++;
//        p=st[front];
//        if(a[j]!=-1)
//        {
//            s=(tree *)malloc(sizeof(tree));
//            s->data=a[j];
//            s->lchild=s->rchild=NULL;
//            rear++,j++;
//            st[rear]=s;
//            p->lchild=s;
//        }
//        else
//        {
//            j++;
//            p->lchild=NULL;
//        }
//        if(j>n)
//        {
//            p->rchild=NULL;
//            break;
//        }
//        if(a[j]!=-1)
//        {
//            s=(tree *)malloc(sizeof(tree));
//            s->data=a[j];
//            s->lchild=s->rchild=NULL;
//            rear++,j++;
//            st[rear]=s;
//            p->rchild=s;
//        }
//        else
//        {
//            j++;
//            p->rchild=NULL;
//        }
//    }
//}

tree *find(tree *t,char x)
{
    tree *p;
    if(t==NULL)
        return NULL;
    else if(t->data==x)
        return t;
    else
    {
        p=find(t->lchild,x);
        if(p!=NULL)
            return p;
        else
            return find(t->rchild,x);
    }
}
int height(tree *t)
{
    int lchild,rchild;
    if(b==NULL) return 0;
    else
    {
        lchild=height(b->lchild);
        rchild=height(b->rchild);
        return (lchild>rchild)?(lchild+1):(rchild+1);
    }
}
void print(tree *t)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            print(t->lchild);
            if(b->rchild!=NULL) printf(",");
            print(t->rchild);
            printf(")");
        }
    }
}
void order1(tree *t)
{
    if(b!=NULL)
    {
        printf("%c",b->data);
        order1(t->lchild);
        order1(t->rchild);
    }
}
void order2(tree *t)
{
    if(b!=NULL)
    {
        order2(b->lchild);
        printf("%c",b->data);
        order2(b->rchild);
    }
}
void order3(tree *t)
{
    if(b!=NULL)
    {
        order3(t->lchild);
        order3(t->rchild);
        printf("%c",b->data);
    }
}
void DispLeaf(tree *t)
{
    if(b!=NULL)
    {
        if(b->lchild==NULL&&b->rchild==NULL)
            printf("%c",b->data);
        DispLeaf(b->lchild);
        DispLeaf(b->rchild);
    }
}
int Level(tree *t,char x,int h)
{
    int l;
    if(b==NULL)
        return 0;
    else if(b->data==x)
        return h;
    else
    {
        l=Level(t->lchild,x,h+1);
        if(l!=0)
            return l;
        else
            return (Level(b->rchild,x,h+1));
    }
}
bool like(tree *t1,tree *t2)
{
    bool like1,like2;
    if(t1==NULL&&t2==NULL)
        return true;
    else if(t1==NULL||t2==NULL)
        return false;
    else
    {
        like1=like(t1->lchild,t2->lchild);
        like2=like(t2->rchild,t2->rchild);
        return (like1&&like2);
    }
}
bool ancestor(tree *t,char x)
{
    if(b==NULL)
        return false;
    else if(b->lchild!=NULL&&b->lchild->data==x||b->rchild!=NULL&&b->rchild->data==x)
    {
        printf("%c",b->data);
        return true;
    }
    else if(ancestor(b->lchild,x)||ancestor(b->rchild,x))
    {
        printf("%c",b->data);
        return true;
    }
    else
        return false;
}
void Pre(tree *t)
{
    tree *st[maxszie],*p;
    int top=-1;
    if(t!=NULL)
    {
        top++;
        st[top]=t;
        while(top>-1)
        {
            p=st[top];
            top--;
            printf("%c",p->data);
            if(p->rchild!=NULL)
            {
                top++;
                st[top]=p->rchild;
            }
            if(p->lchild!=NULL)
            {
                top++;
                st[top]=p->lchild;
            }
        }
        printf("\n");
    }
}
void InOrder(tree *t)
{
    tree *st[maxsize],*p;
    int top=-1;
    if(b!=NULL)
    {
        p=b;
        while(top>-1||p!=NULL)
        {
            while(p!=NULL)
            {
                top++;
                st[top]=p;
                p=p->lchild;
            }
            if(top>-1)
            {
                p=st[top];
                top--;
                printf("%c",p->data);
                p=p->rchild;
            }
        }
    }
}
void PostOrder1(tree *t)
{
    tree *st[maxsize],*p;
    int flag,top=-1;
    if(t!=NULL)
    {
        do
        {
            while(t!=NULL)
            {
                top++;
                st[top]=t;
                t=t->lchild;
            }
            p=NULL;
            flag=1;
            while(top!=-1&&flag)
            {
                t=st[top];
                if(t->rchild==p)
                {
                    printf("%c ",t->data);
                    top--;
                    p=t;
                }
                else
                {
                    t=t->rchild;
                    flag=0;
                }
            }
        }
        while(top!=-1);
        printf("\n");
    }
}
void LevelOrder(tree *b,int L)
{
    tree *p,*qu[maxn];
    int front=-1,rear=-1;
    qu[++rear]=b;
    while(front!=rear)
    {
        front++;
        p=qu[front];
        printf("%d ",p->data);
        if(p->lchild!=NULL)
        {
            rear++;
            qu[rear]=p->lchild;
        }
        if(p->rchild!=NULL)
        {
            rear++;
            qu[rear]=p->rchild;
        }
    }
    printf("\n");
}
int main()
{
    int a;
}
