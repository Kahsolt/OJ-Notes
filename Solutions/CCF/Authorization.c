#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARRAY 10
#define MAXARRAY2 100
#define MAXLEN 35

typedef struct privilege {
    char* name;
    char class;
} Privilege;

typedef struct role {
    char* name;
    char privilege_top;
    struct privilege* privileges[MAXARRAY];
} Role;

typedef struct user {
    char* name;
    char roles_top;
    struct role* roles[MAXARRAY];
} User;

Privilege *Privileges[MAXARRAY2];
Role *Roles[MAXARRAY2];
User *Users[MAXARRAY2];
int PrivilegeTop=-1, RolesTop=-1, UsersTop=-1;

void print()
{
    int i, j;

    printf("=== Privileges ===\n");
    for(i=0;i<=PrivilegeTop;i++)
    printf("%s %d\n", Privileges[i]->name, Privileges[i]->class);
    
    printf("=== Roles ===\n");
    for(i=0;i<=RolesTop;i++)
    {
        printf("%s: ", Roles[i]->name);
        for(j=0;j<=Roles[i]->privilege_top;j++)
            printf("%s:%d ", Roles[i]->privileges[j]->name, Roles[i]->privileges[j]->class);
        printf("\n");
    }

    printf("=== Users ===\n");
    for(i=0;i<=UsersTop;i++)
    {
        printf("%s: ", Users[i]->name);
        for(j=0;j<=Users[i]->roles_top;j++)
            printf("%s ", Users[i]->roles[j]->name);
        printf("\n");
    }
}

int main()
{
    int N, count, len;
    char* text=malloc(MAXLEN*sizeof(char));
    
    /* Privilege */
    scanf("%d\n", &N);
    while(N--)
    {
        scanf("%s", text);
        getchar();
    }
     /* Role */
    scanf("%d\n", &N);
    while(N--)
    {
        scanf("%s %d", text, &count);
        len=strlen(text);
        Roles[++RolesTop]=malloc(sizeof(Role));
        Role* r=Roles[RolesTop];
        r->name=malloc((len+1)*sizeof(char));
        strcpy(r->name, text);
        r->privilege_top=-1;
        while(count--)
        {
            scanf("%s", text);
            len=strlen(text);
            char *name, class;
            if(len>2 && text[len-2]==':')
            {
                name=malloc((len-1)*sizeof(char));
                strncpy(name, text, len-2);
                class=text[strlen(text)-1]-'0';
            }
            else
            {
                name=malloc((len+1)*sizeof(char));            
                strcpy(name, text);
                class=-1;
            }

            int i, replaced=0;
            for(i=0;replaced==0 && i<=r->privilege_top;i++)
            {
                if(strcmp(name, r->privileges[i]->name)==0 && class>r->privileges[i]->class)
                {
                    r->privileges[i]->class=class;
                    replaced=1;
                }
            }
            if(replaced==0)
            {
                r->privileges[++r->privilege_top]=malloc(sizeof(Privilege));
                Privilege *p=r->privileges[r->privilege_top];
                p->name=name;
                p->class=class;
            }
        }
        getchar();
    }
    /* User */
    scanf("%d\n", &N);
    while(N--)
    {
        scanf("%s %d", text, &count);
        len=strlen(text);
        Users[++UsersTop]=malloc(sizeof(User));
        User* u=Users[UsersTop];
        u->name=malloc((len+1)*sizeof(char));
        strcpy(u->name, text);
        u->roles_top=-1;
        while(count--)
        {
            scanf("%s", text);
            int i;
            for(i=0;i<=RolesTop;i++)
                if(strcmp(text, Roles[i]->name)==0)
                {
                    u->roles[++u->roles_top]=Roles[i];
                    break;
                }
        }
        getchar();
    }
    
    /* print(); */

    /* Query */
    scanf("%d\n", &N);
    char* username=malloc(MAXLEN*sizeof(char));
    while(N--)
    {
        scanf("%s %s", username, text);
        getchar();

        /* find user */
        int i, userFound=0;
        for(i=0;userFound==0 && i<=UsersTop;i++)
        {
            if(strcmp(username, Users[i]->name)==0)
            {
                userFound=1;

                /* parse request privilege */
                char *name, class;
                len=strlen(text);
                if(len>2 && text[len-2]==':')
                {
                    name=malloc((len-1)*sizeof(char));
                    strncpy(name, text, len-2);
                    class=text[strlen(text)-1]-'0';
                }
                else
                {
                    name=malloc((len+1)*sizeof(char));            
                    strcpy(name, text);
                    class=-1;
                }

                /* printf("User: %s trying: %s:%d\n", username, name, class); */

                /* try every role */
                int j, authOK=0, maxClass=-1, complexQuery=0;
                for(j=0;authOK==0 && j<=Users[i]->roles_top;j++)
                {
                    /* find request privilege */
                    int k, privilegeFound=0;
                    for(k=0;privilegeFound==0 && k<=Users[i]->roles[j]->privilege_top;k++)
                    {
                        if(strcmp(name, Users[i]->roles[j]->privileges[k]->name)==0)
                        {
                            privilegeFound=1;

                            if(Users[i]->roles[j]->privileges[k]->class==-1)
                            {
                                printf("true\n");
                                authOK=1;
                            }
                            else
                            {
                                char c=Users[i]->roles[j]->privileges[k]->class;
                                if(class==-1)   /* complex query mode */
                                {
                                    complexQuery=1;
                                    if(c>maxClass) maxClass=c;
                                }
                                else if(class<=c)   /* simple auth mode */
                                {
                                    printf("true\n"); 
                                    authOK=1;
                                }
                            }
                        }
                    }
                }
                if(complexQuery==1) printf("%d\n", maxClass);
                else if(authOK==0) printf("false\n");
            }
        }
        if(userFound==0) printf("false\n");
    }
    
    return 0;
}
