#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
}*first, *last, *second, *third;

void Create (int A[], int n);

void Display(const struct Node *const ptr);

void DisplayRecursively(const struct Node *ptr);

int Count(struct Node *p);

int CountRecursively(struct Node *p);

int Sum(struct Node *p);

int SumRecursively(struct Node *p);

int Max(struct Node *p);

int MaxRecursively(struct Node *p);

int Min(struct Node *p);

int MinRecursively(struct Node *p);

struct Node *Search(struct Node *p, int key);

struct Node *SearchRecursively(struct Node *p, int key);

struct Node *SearchBringToHead(struct Node *p, int key);

void Insert(struct Node *p, int idx, int val);

void InsertLast(int val);

void InsertSorted(struct Node *p, int val);

int Delete(struct Node *p, int idx);

bool IsSorted(const struct Node *p);

void DeleteDuplicates(struct Node *p);

void ReverseCopy(struct Node *p);

void ReverseLinks(struct Node *p);

void ReverseRecursive(struct Node *q, struct Node *p);

void Concatenate(struct Node *p, struct Node *q);

void Merge(struct Node *first, struct Node *second);

bool IsLoop(struct Node *p);

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);
    second = first;
    int B[] = {10, 20, 30, 40, 50};
    Create(B, 5);
    Search(first, 50)->next = Search(first, 30);
    printf("Is Loop = %d\n", IsLoop(first));
    printf("Is Loop = %d\n", IsLoop(second));
    return 0;
}

void Create (int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void Display(const struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void DisplayRecursively(const struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        DisplayRecursively(ptr->next);
    }
}

int Count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int CountRecursively(struct Node *p)
{
    if (p != NULL)
        return CountRecursively(p->next) + 1;
    else
        return 0;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int SumRecursively(struct Node *p)
{
    if (p != NULL)
        return SumRecursively(p->next) + p->data;
    else
        return 0;
}

int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int MaxRecursively(struct Node *p)
{
    int max = 0;
    if (p != NULL)
    {
        max = MaxRecursively(p->next);
        return p->data > max ? p->data : max;
    }
    else
        return INT_MIN;
}

int Min(struct Node *p)
{
    int min = INT_MAX;
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int MinRecursively(struct Node *p)
{
    int min = 0;
    if (p != NULL)
    {
        min = MinRecursively(p->next);
        return p->data < min ? p->data : min;
    }
    else
        return INT_MAX;
}

struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        else
            p = p->next;
    }
    return p;
}

struct Node *SearchRecursively(struct Node *p, int key)
{
    if (p == NULL)
        return p;
    if (p->data == key)
        return p;
    return Search(p->next, key);
}


struct Node *SearchBringToHead(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key && q != NULL)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else if (p->data == key && q == NULL)
        {
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return p;
}

void Insert(struct Node *p, int idx, int val)
{
    if (idx < 0 || idx > Count(p))
        return;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    if (idx == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < idx - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

void InsertSorted(struct Node *p, int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = p;
    t->data = val;
    t->next = NULL;
    if (p == NULL)
        first = t;
    else
    {
        while (p != NULL && p->data < val)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = p;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int idx)
{
    struct Node *q = p;
    int x = 0;
    if (idx < 1 || idx > Count(p))
        x = -999;
    else
    {
        if (idx == 1)
        {
            x = first->data;
            first = first->next;
            free(p);
        }
        else
        {
            for (int i = 1; i < idx; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

bool IsSorted(const struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return false;
        else
        {
            x = p->data;
            p = p->next;
        }
    }
    return true;
}

void DeleteDuplicates(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

void ReverseCopy(struct Node *p)
{
    int arr[Count(p)];
    int i = 0;
    struct Node *q = p;
    while (p != NULL)
    {
        arr[i++] = p->data;
        p = p->next;
    }
    p = q;
    i--;
    while (p != NULL)
    {
        p->data = arr[i--];
        p = p->next;
    }
}

void ReverseLinks(struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void ReverseRecursive(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        ReverseRecursive(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concatenate(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
    q = NULL;
}

void Merge(struct Node *first, struct Node *second)
{
    struct Node *last;
    if (first->data < second->data)
    {

        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
}

bool IsLoop(struct Node *p)
{
    struct Node *q;
    do
    {
        q = q->next;
        p = p->next;
        p = p ? p->next : p;

    } while (p && q  && p != q);
    return p == q ? true : false;
}
