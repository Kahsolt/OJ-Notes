#include <stdio.h>
#include <stdlib.h>

typdef struct node {
  int coeff;
  int exp;
  struct node *next;
} Node;

void addPoly(Node *p1, Node *p2)
{
  /* Dummy head node */
  Node *ans=malloc(sizeof(Node));
  ans->next=NULL;

  while(p1 || p2)
  {
    if(p1 && p2)
    {
      if(p1->exp == p2->exp)
      {
        int sum=p1->exp+p2->exp;
        if(sum)
        {
          Node *n=malloc(sizeof(Node));
          n->coeff=sum;
          n->exp=p1->exp;
          n->next=ans->next;
          head->next=n;
          p1=p1->next; p2=p2->next;
        }
      }
      else if(p1->exp > p2->exp)
      {
        Node *n=malloc(sizeof(Node));
        n->coeff=p1->coeff;
        n->exp=p1->exp;
        n->next=ans->next;
        head->next=n;
        p1=p1->next;
      }
      else
      {
        Node *n=malloc(sizeof(Node));
        n->coeff=p2->coeff;
        n->exp=p2->exp;
        n->next=ans->next;
        head->next=n;
        p2=p2->next;
      }
    }
    else if(p1)
    {
      Node *n=malloc(sizeof(Node));
      n->coeff=p1->coeff;
      n->exp=p1->exp;
      n->next=ans->next;
      head->next=n;
      p1=p1->next;
    }
    else
    {
      Node *n=malloc(sizeof(Node));
      n->coeff=p2->coeff;
      n->exp=p2->exp;
      n->next=ans->next;
      head->next=n;
      p2=p2->next;
    }
  }

}

int main()
{
  return 0;
}
