#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge(List L1, List L2){
    PtrToNode rear, front, temp;
    rear = (List)malloc(sizeof(struct Node));
    front = rear;
    while (L1 && L2)
    {
        switch(L1->Data-L2->Data >= 0){
            case 1:
                rear ->Next = L2;
                L2 = L2 -> Next;
                break;
            case 0:
                rear -> Next = L1;
                L1 = L1 -> Next;
        }
    }
    for(; L1;L1 = L1 -> Next) rear -> Next = L1;
    for(; L2;L2 = L2 -> Next) rear -> Next = L2;

    rear -> Next =NULL;
    temp = front;
    front = front -> Next;
    free(temp);
    return front;
}