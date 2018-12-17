// 00 利用一个二叉树的广义表表示方法，用二叉链表的方式建立一棵二叉树（字符版）测试状态：OJ
// 01 利用一个二叉树的广义表表示方法，用二叉链表的方式建立一棵二叉树（数字版）测试状态：OJ
// 02 给出一个二叉树的先序遍历和中序遍历建立二叉树 测试状态：OJ
// 03 给出一个二叉树的中序遍历和后序遍历建立二叉树 测试状态：本地
// 04 已知具有n个结点的非空完全二叉树采用顺序存储结构，由此用二叉链表方式建立一棵二叉树 测试状态：本地
// 05 先序遍历递归算法 测试状态：本地
// 06 中序遍历递归算法 测试状态：OJ
// 07 后序遍历递归算法 测试状态：OJ
// 08 层次遍历算法 测试状态：本地
// 09 统计二叉树中叶子节点的个数（先序遍历）测试状态：OJ
// 10 求二叉树的深度（后序遍历） 测试状态：OJ修改版
// 11 判断一棵二叉树是否是完全二叉树（层次遍历） 测试状态：OJ
// 12 先序遍历非递归算法;
// 13  中序遍历非递归算法；
// 14  后序非递归

// ********************源代码********************
typedef struct BiTNode // 二叉链表结点类型定义
{
	char data; // 数据域存放字符
	struct BiTNode *lchild; // 左孩子
	struct BiTNode *rchild; // 右孩子
}BiTNode, *BiTree;

typedef struct BiTNode // 二叉链表结点类型定义
{
	int data; // 数据域存放数字
	struct BiTNode *lchild; // 左孩子
	struct BiTNode *rchild; // 右孩子
}BiTNode, *BiTree;

// 00 利用一个二叉树的广义表表示方法，用二叉链表的方式建立一棵二叉树（字符版）
BiTree CreateBiTree( char *p ) // p广义表字符数组的头指针// 
{
	BiTree pointer; // 声明一个二叉链表结点指针
	BiTree root = NULL; // 声明一个根节点指针
	enum Sign{ LEFT, RIGHT }; // 声明了一个Sign类型变量用于标识左右孩子
	enum Sign flag; // 用于记录左右孩子标志
	BiTree stack[100]; // 建树过程中要用到栈，在此将栈的大小设为100，需要修改时，只需要修改此处即可
	int top = 0; // 栈顶指针

	for( ; *p != '\0'; p++ )
	{
		if( ( *p >= 'A' && *p <= 'Z' ) || ( *p >= 'a' && *p <= 'z' ) )
		{
			pointer = ( BiTree )malloc( sizeof( BiTNode ) );
			pointer->data = *p; // 初始化数据域
			pointer->lchild = NULL; // 初始化左指针
			pointer->rchild = NULL; // 初始化右指针
			if( !root )
			{
				root = pointer;
			}
			else
			{
				if( flag == LEFT )
				{
					stack[top - 1]->lchild = pointer;
				}
				else
				{
					stack[top - 1]->rchild = pointer;
				}
			}
		}
		else
		{
			switch( *p )
			{
				case '(':
					flag = LEFT;
					stack[top] = pointer;
					top++;
					break;

				case ')':
					top--;
					break;

				case ',':
					flag = RIGHT;
					break;

				default:
					puts( "ERROR 00" ); //加入了这句用来查找错误
					break;
			}
		}
	}
	return root; // 返回根节点的地址
}
// 01 利用一个二叉树的广义表表示方法，用二叉链表的方式建立一棵二叉树（数字版）
BiTree CreateBiTree( char *p ) // p广义表字符数组的头指针
{
	BiTree pointer; // 声明一个二叉链表结点指针
	BiTree root = NULL; // 声明一个根节点指针
	enum Sign{ LEFT, RIGHT }; // 声明了一个Sign类型变量用于标识左右孩子
	enum Sign flag; // 用于记录左右孩子标志
	BiTree stack[100]; // 建树过程中要用到栈，在此将栈的大小设为100，需要修改时，只需要修改此处即可
	int top = 0; // 栈顶指针
	int number; // 用于计算每一个读入的数字

	for( ; *p != '\0'; p++ )
	{
		if( *p >= '0' && *p <= '9' )
		{
			number = *p - 48;
			p++;
			while( *p >= '0' && *p <= '9' )
			{
				number = number * 10 + *p - 48;
				p++;
			}
			p--;
			pointer = ( BiTree )malloc( sizeof( BiTNode ) );
			pointer->data = number; // 初始化数据域
			pointer->lchild = NULL; // 初始化左指针
			pointer->rchild = NULL; // 初始化右指针
			if( !root )
			{
				root = pointer;
			}
			else
			{
				if( flag == LEFT )
				{
					stack[top - 1]->lchild = pointer;
				}
				else
				{
					stack[top - 1]->rchild = pointer;
				}
			}
		}
		else
		{
			switch( *p )
			{
				case '(':
					flag = LEFT;
					stack[top] = pointer;
					top++;
					break;

				case ')':
					top--;
					break;

				case ',':
					flag = RIGHT;
					break;

				default:
					puts( "ERROR 00" ); //加入了这句用来查找错误
					break;
			}
		}
	}
	return root; // 返回根节点的地址
}
// 02 给出一个二叉树的先序遍历和中序遍历建立二叉树
BiTree CrtPostBT( char pre[], char in[], int ps, int is, int n )
// 已知pre[ps……ps+n-1]为二叉树的先序序列
//     in[is……is+n-1]为二叉树的中序序列
{
	int k;
	BiTree T;

	if( n == 0 )
	{
		T = NULL;
	}
	else
	{
		T = ( BiTree )malloc( sizeof( BiTNode ) );
		for( k = is; k <= is + n - 1; k++ )
		{
			if( in[k] == pre[ps] )
			{
				break;
			}
		}
		T->data = in[k];
		if( k == is )
			T->lchild = NULL;
		else
			T->lchild = CrtPostBT( pre, in, ps + 1, is, k - is );

		if( k == is + n - 1 )
			T->rchild = NULL;
		else
			T->rchild = CrtPostBT( pre, in, ps + 1 + ( k - is ), k + 1, n - 1 - ( k - is ) );
	}
	return T; // 返回根节点地址
}
// 03 给出一个二叉树的中序遍历和后序遍历建立二叉树
BiTree CrtPostBT( char in[], char post[], int is, int ps, int n )
// 已知in[is……is+n-1]为二叉树的中序序列
//     post[ps……ps+n-1]为二叉树的后序序列
{
	int k;
	BiTree T;

	if( n == 0 )
	{
		T = NULL;
	}
	else
	{
		T = ( BiTree )malloc( sizeof( BiTNode ) );
		for( k = is + n - 1; k >= is; k-- )
		{
			if( in[k] == post[ps + n - 1] )
			{
				break;
			}
		}
		T->data = in[k];
		if( k == is )
			T->lchild = NULL;
		else
			T->lchild = CrtPostBT( in, post, is, ps, k - is );

		if( k == is + n - 1 )
			T->rchild = NULL;
		else
			T->rchild = CrtPostBT( in, post, k + 1, k, n - 1 - k );
	}
	return T; // 返回根节点地址
}
// 04 已知具有n个结点的非空完全二叉树采用顺序存储结构，由此用二叉链表方式建立一棵二叉树 测试状态：未
BiTree CreatBiTree( ElemType BT[], int n ) // BT 二叉树的顺序存储结构的数组，ElemType用来指定数据的类型
{
	BiTree T, ptr[100]; // 此处将数组的大小设为100，如需修改大小，只需修改此处即可
	int i, j;

	ptr[1] = ( BiTree )malloc( sizeof( BiTNode ) ); // 没有利用数组的第一位，即ptr[0]
	ptr[1]->data = BT[1];
	ptr[1]->lchild = NULL;
	ptr[1]->rchild = NULL;
	T = ptr[1];
	for( i = 2; i < n; i++ )
	{
		ptr[i] = ( BiTree )malloc( sizeof( BiTNode ) );
		ptr[i]->data = BT[i];
		ptr[i]->lchild = NULL;
		ptr[i]->rchild = NULL;
		j = i / 2;
		if( i - 2 * j == 0 )
		{
			ptr[j]->lchild = ptr[i];
		}
		else
		{
			ptr[j]->rchild = ptr[i];
		}
	}
	return T;
}
// 05 先序遍历递归算法
void Preorder( BiTree T, void(*visit)() ) // T二叉树的根节点，visit访问函数的地址
{
	if( T )
	{
		visit(); // 访问函数
		Preorder( T->lchild, visit );
		Preorder( T->rchild, visit );
	}
}
// 06 中序遍历递归算法
void Inorder( BiTree T, void(*visit)() ) // T二叉树的根节点，visit访问函数的地址
{
	if( T )
	{
		Inorder( T->lchild, visit );
		visit(); // 访问函数
		Inorder( T->rchild, visit );
	}
}
// 07 后序遍历递归算法
void Postorder( BiTree T, void(*visit)() ) // T二叉树的根节点，visit访问函数的地址
{
	if( T )
	{
		Postorder( T->lchild, visit );
		Postorder( T->rchild, visit );
		visit(); // 访问函数
	}
}
// 08 层次遍历  from:book
void LevelOrder(BiTNode *b)
{
     BiTNode *p;
     BiTNode *qu[MaxSize];
     int front,rear;
     front=rear=-1;
     rear++;
     qu[rear]=b;
     while(front!=rear)
     {
                       front=(front+1)%MaxSize;
                       p=qu[front];
                       printf("%c",p->data);
                       if(p->lchild!=NULL)
                       {
                                          rear=(rear+1)%MaxSize;
                                          qu[rear]=p->lchild;
                       }
                       if(p->rchild!=NULL)
                       {
                                          rear=(rear+1)%MaxSize;
                                          qu[rear]=p->rchild;
                       }
     }
     printf("\n");
}


// 08 not 层次遍历算法
void Layerorder( BiTree T, void(*visit)() ) // T二叉树的根节点，visit访问函数的地址
{
	int size = 100; // 遍历过程中要用到队列，在此将队列的大小设为100，需要修改时，只需要修改此处即可
	BiTree Quene[size]; // 遍历过程中未使用循环队列
	int front = 0; // 队首指针
	int rear = 0; // 队尾指针
	BiTree p;

	if( T )
	{
		Queen[rear++] = T;
		while( front < rear )
		{
			p = Queen[front++];
			visit(); // 访问函数
			if( p->lchild )
				Queen[rear++] = p->lchild;
			if( p->rchild )
				Queen[rear++] = p->rchild;
		}
	}
}
// 09 统计二叉树中叶子节点的个数（先序遍历）
void CountLeaf( BiTree T, int *count ) // T二叉树的根节点，count记录叶子节点个数的地址
{
	if( T )
	{
		if( ( !T->lchild )&&( !T->rchild ) )
			(*count)++;
		CountLeaf( T->lchild, count );
		CountLeaf( T->rchild, count );
	}
}
// 10 求二叉树的深度（后序遍历）
int Depth( BiTree T ) // T二叉树的根节点
{
	int depthval; // 二叉树的深度
	int depthLeft; // 左二叉树的深度
	int depthRight; // 右二叉树的深度

	if( !T )
		depthval = 0;
	else
	{
		depthLeft = Depth( T->lchild );
		depthRight = Depth( T->rchild );
		depthval = 1 + ( depthLeft > depthRight ? depthLeft : depthRight );
	}
	return depthval; // 返回二叉树的深度
}
// 11 判断一棵二叉树是否是完全二叉树
int BiTreeComplete( BiTree T ) // T二叉树的根节点
{
	BiTree Queen[100]; // 辅助数组，在此将数组的大小设为100，需要修改时，只需要修改此处即可
	// 没有利用Queen[0]
	int front = 1; // 首指针
	int rear = 1; // 尾指针
	BiTree p;
	int sign = 1; // 标记值
	int i;
	int a, b; // 辅助变量，a用于记录两数的商，b用于记录两数的余数

	if( T )
	{
		Queen[rear++] = T;
		while( front < rear )
		{
			p = Queen[front++];
			if( p->lchild )
				Queen[rear++] = p->lchild;
			if( p->rchild )
				Queen[rear++] = p->rchild;
		}
	}
	for( i = rear - 1; i > 1; i-- )
	{
		a = i / 2;
		b = i % 2;
		if( b == 1 )
		{
			if( Queen[a]->rchild != Queen[i] )
			{
				sign = 0;
				break;
			}
		}
		else
		{
			if( Queen[a]->lchild != Queen[i] )
			{
				sign = 0;
				break;

			}
		}
	}
	return sign; // 是完全二叉树返回1，否则返回0
}

//  12 先序遍历非递归算法;
void PreOrderUnrec(BiTNode *T) 
{
      BiTNode  *p = T,*Stack[MaxSize];
      int top = -1;
      while (p != NULL || top != -1)
      {
          while (p!=NULL) //遍历左子树;
         {
             printf("%c",p->data);
              Stack[++top] = p;
             p=p->lchild;
         }
           if (top != -1) //下次while内循环中实现右子树遍历；
          {
              p = Stack[top--];
              p=p->rchild;
          }
    }
    printf("\n");
}

// 13  中序遍历非递归算法；
void InOrderUnrec(BiTNode *T) 
{
     BiTNode *p = T,*Stack[MaxSize];
     int top = -1;
     while (p != NULL || top != -1)
     {
         while (p!=NULL)
        {
              Stack[++top] = p;
              p=p->lchild;
        }
         if (top != -1)
        {
              p = Stack[top--];
              printf("%c ",p->data);
              p=p->rchild;
        }
     }
}

// 14  后序非递归
void PostOrder2(BiTNode *b)
{
    BiTNode *St[MaxSize];
    BiTNode *p;
    int flag,top=-1;
    if(b!=NULL)
    {
        do
        {
            while(b!=NULL)
            {
                top++;
                St[top]=b;
                b=b->lchild;
            }
            p=NULL;
            flag=1;
            while(top!=-1&&flag)
            {
                b=St[top];
                if(b->rchild==p)
                {
                    printf("%c",b->data);
                    top--;
                    p=b;
                }
                else
                {
                    b=b->rchild;
                    flag=0;
                }
            }
        }while(top!=-1);
        printf("\n");
    }
}




























