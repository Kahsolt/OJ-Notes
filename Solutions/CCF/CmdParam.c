#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAXS 26
#define MAXLEN 257

char defines[53], cmd[MAXLEN];
char types[MAXS], presence[MAXS], *data[MAXS];
int N, i, j;
char *p;

#define D
#ifdef D
void def() {
  int i;
  printf("Definition Table:\n");
  for(i=0;i<26;i++) printf("|%c ", i+'a');
  printf("\n");
  for(i=0;i<26;i++) printf("|%d ", types[i]);
  printf("\n");
}
void pre() {
  int i;
  for(i=0;i<26;i++) printf("|%c ", i+'a');
  printf("\n");
  for(i=0;i<26;i++) printf("|%d ", presence[i]);
  printf("\n");
}
#endif

int main()
{
  memset(data, NULL, sizeof(data));
  memset(types, 0, sizeof(types));
  memset(presence, 0, sizeof(presence));

  scanf("%s", defines); getchar();
  p=defines;
  while(*p!='\0') {
    if(*(p+1)==':') {types[*p-'a']=2; p+=2;}
    else {types[*p-'a']=1; p++;}
  }

  scanf("%d", &N); getchar();
  for(i=1;i<=N;i++) {
    memset(cmd, '\0', sizeof(cmd));
    gets(cmd); p=cmd;
    while(*p!='\0' && *p!=' ') p++; if(*p==' ') p++;
    while(*p!='\0') {
      if(!(*p=='-'&&(*(p+2)==' '||*(p+2)=='\0'))) break;
      p++; if(*p < 'a'||*p > 'z') break;

      int idx=*p-'a', sel=types[idx];
      p+=2;
      if(sel==1) {
        presence[idx] = 1;
      } else if(sel==2) {
        char *k = p;
        int cnt = 0;
        while(*p!=' '&&*p!='\0') {p++; cnt++;}
        if(cnt>0) {
          data[idx]=(char*)realloc(data[idx], (cnt+1)*sizeof(char));
          strncpy(data[idx], k, cnt);
          data[idx][cnt]='\0';
          presence[idx] = 1;
        }
        if(*p!='\0') p++;
      } else break;
    }

    printf("Case %d:", i);
    for(j=0;j<MAXS;j++) {
      if(!presence[j]) continue;
      printf(" -%c", j+'a');
      if(types[j]==2) printf(" %s", data[j]);
      presence[j]=0;
    }
    printf("\n");
  }

  return 0;
}
