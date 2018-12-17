#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

// 2018/08/08
// 解决字符串匹配: O(n+m)
//   next[j]: 当s[i]!=t[j]时，j指针的下一步移动至的位置
//     next[0] = -1
//     next[j] = t[0:j-1]的最大匹配前后缀串长度
//   例如：t="abaabcac"
//          j   0  1  2  3  4  5  6  7
//        t[j]  a  b  a  a  b  c  a  c
//     next[j] -1  0  0  1  1  2  0  1
//   匹配时：
//     若在模式串指针j=0时失配，目标串指针i++，即平凡的暴力匹配
//     否则next特征向量可用，i不移动、j移动至next[j]

int next[N];	// 失配指针特征向量
void kmp(char* s, char* t) {	// find t in s, O(len(s) + len(t))
	int lent = strlen(t), j, k;
	
  /* calc next[j] */
	next[0] = -1; j = 0; k = -1;
	for (int j=1; j<lent; j++) {
		while (j>0 && t[j+1]!=t[k]) k = next[j];
		if (t[j+1] == t[k]) k++;
		next[k] = j;
	}
	
	j = 0;
	for(int i=0; i<strlen(s); i++) {
		while (j>0 && t[j+1]!=s[i]) j = next[j];
		if (t[j+1] == s[i]) j++;
		if (j == lent) {
			printf("match at %d\n", i);
			j = next[j];
		}
	}
}
void kmp_cmp(char* s, char* t) {
  char i = 0, j = 0;
  while (i < strlen(s) && j < strlen(t)) {
    if (s[i] == t[j]) { i++; j++; }   // 相等继续
    else if (j == 0) i++;             // 首字母失配，平凡的暴力推进1
    else j = next[j];                 // 其他地方失配，使用next特征向量
  }
}

int main() {
  kmp("acabaabaabcacaabc", "abaabcac");
}