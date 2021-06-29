#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    char a;
    int b;
} List;

typedef struct A
{
    int len;
    List *list;
} A;

void func(A **p)
{
    *p = (A *)malloc(sizeof(A));
}
void funcfree(A **p)
{
    free(*p);
    *p = NULL;
}

int main(void)
{
    int i;
    A *a = NULL;
    //a->len=1;
    func(&a);
    a->len = 1;
    a->list = (List *)malloc(sizeof(List));
    a->list->a = 'a';
    a->list->b = 9;
    for (i = 0; i < a->len; i++)

    {
        printf("a[%d]:\n", i);
        printf("send->list.a:%c\n", a->list->a);
        printf("send->list.b:%d\n", a->list->b);
        return 0;
    }
    free(a->list);
    a->list = NULL;
    funcfree(&a);
    return 0;
}