#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 15
#define DEBUGNOT

/*
declare 左子树访问标记[]
declare 右子树访问标记[] 
let 根节点压站
while 栈不空 do
  let 取栈顶元素作当前子树t
  if t未访问左子树 then
    标记t已访问左子树
    while t的左子树存在 do
      let 当前子树t移动为原t的左子树
      t压栈
      标记t已访问左子树
    endwhile
  endif

  if 右子树访问标记[t] then
    打印节点t
    弹栈
  else 
    if 右子树存在 then
      右子树入栈
    endif
    标记t已访问右子树
  endif
endwhile
*/

int print(int *stack, int top, int *dealleft, int *dealright)
{
  int i;
  printf("\n=======\n");
  for(i=0;i<=top;i++)
    printf("%d ", stack[i]);
  printf("\n");
  for(i=1;i<=MAXN;i++)
    printf("%d ", dealleft[i]);
  printf("\n");
  for(i=1;i<=MAXN;i++)
    printf("%d ", dealright[i]);
  printf("\n=======\n");
}
int postorder(int *tree)
{
  int dealleft[MAXN];
  memset(dealleft, 0, sizeof(dealleft));
  int dealright[MAXN];
  memset(dealright, 0, sizeof(dealright));
  int stack[MAXN], top=-1, idx;
  stack[++top]=1;

  while(top!=-1)
  {
#ifdef DEBGU
    print(stack, top, dealleft, dealright);
    system("sleep 1");
#endif
    idx=stack[top];
    if(!dealleft[idx])
    {
     dealleft[idx]=1;
      while(idx*2<=MAXN && tree[idx*2]!=-1)   /* left sub-tree */
      {
        idx=idx*2;
        stack[++top]=idx;
        dealleft[idx]=1;
      }
    }
    if(dealright[idx])
    {
      printf("%d ", tree[idx]);		/* print as root */
      top--;
    }
    else
    {
      if(idx*2+1<=MAXN && tree[idx*2+1]!=-1)/* right sub-tree */
        stack[++top]=idx*2+1;
      dealright[idx]=1;
    }
  }
}

int main()
{
  int tree[]={-1,1,2,3,4,5,6,-1,-1,-1,7,-1,8,9,-1,-1};
  postorder(tree);

  return 0;
}
