#include<iostream>
#include<cstdio>
#include<algorithm>
#define max(a,b) (a>b?a:b)

#define N 500
// 2018/08/13
// graham: 求最远点对(凸包)

int stack[100], top;    // 存凸包中的点
typedef struct point {
	int x , y;
} Point;
Point p[100];

double dis(const Point &a , const Point &b) {
	return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}
inline int xmult(const Point &p1 , const Point &p2 , const Point &p0) {
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}

int cmp(const void * a , const void * b) {	//逆时针排序 返回正数要交换
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;
	int ans = xmult(*p1 , *p2 , p[0]);   //向量叉乘
	if (ans < 0) return 1;		//p0p1线段在p0p2线段的上方，需要交换
	else if (ans==0 && p1->x>=p2->x)     //斜率相等时，距离近的点在先
		return 1;
	else return -1;
}
void graham(int n) {	//形成凸包
	qsort(p+1 , n-1 , sizeof(point) , cmp);
	stack[0] = 0 , stack[1] = 1;
	top = 1;
	for(int i = 2 ; i < n ; ++i) {
		while(top > 0 && xmult( p[stack[top]] , p[i] , p[stack[top-1]]) <= 0)
			top--;           //顺时针方向--删除栈顶元素
		stack[++top] = i;    //新元素入栈
	}
	int temp = top;
	for(int i = n-2 ; i >= 0 ; --i) {
		while(top > temp && xmult(p[stack[top]] , p[i] , p[stack[top-1]]) <= 0)
			top--;
		stack[++top] = i;    //新元素入栈
	}
}
int rotating_calipers() { //卡壳
	int i , q=1;
	int ans = 0;
	stack[top]=0;
	for(i = 0 ; i < top ; i++) {
		while( xmult( p[stack[i+1]] , p[stack[q+1]] , p[stack[i]] ) > xmult( p[stack[i+1]] , p[stack[q]] , p[stack[i]] ) )
			q = (q+1)%(top);
		ans = max(ans , max( dis(p[stack[i]] , p[stack[q]]) , dis(p[stack[i+1]] , p[stack[q+1]])));
	}
	return ans;
}

int main() {
	int n , leftdown; 
	while(scanf("%d",&n) != EOF) {
		leftdown = 0;
		for(int i = 0 ; i < n ; ++i) {
			scanf("%d %d",&p[i].x,&p[i].y);
			if(p[i].y < p[leftdown].y || (p[i].y == p[leftdown].y && p[i].x < p[leftdown].x))  //找到最左下角的点
				leftdown = i;
		}
		swap(p[0] , p[leftdown]);
		graham(n);
		printf("%d\n", rotating_calipers());  
	}
	return 0;
}
