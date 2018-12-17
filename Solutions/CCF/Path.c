#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 101

char* simplify(char *path)
{
    char *tmp=malloc((strlen(path)+1)*sizeof(char));
    char *p=path, *t=tmp;
    while(*p!='\0')
        if(*p=='/') {
            if(*(p+1)=='\0' || *(p+1)=='/') { p++; }
            else if(*(p+1)=='.')  {
                if(*(p+2)=='.') {
                    p+=3;
                    while(t>=tmp && *t!='/') t--;
                } else { p+=2; }
            } else { *t=*p; t++; p++; }
        } else { *t=*p; t++; p++; }
    if(t==tmp) { *t='/'; t++; }
    *t='\0';

    return tmp;
}

char* normalize(char* home, char* cd)
{
    if(strlen(cd)==0) return simplify(home);
    if(strlen(cd)>=1 && cd[0]=='/') return simplify(cd);

    char* join=malloc((strlen(home)+strlen(cd)+2)*sizeof(char));
    strcat(join, home); strcat(join, "/"); strcat(join, cd);
    return simplify(join);
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    char* home=malloc(MAXSTR*sizeof(char));
    scanf("%s", home); getchar();
    home=simplify(home);

    while(N--) 
    {
        char* cd=malloc(MAXSTR*sizeof(char));
        scanf("%s", cd); getchar();
        printf("=> %s\n", normalize(home, cd));
    }
    
    return 0;
}