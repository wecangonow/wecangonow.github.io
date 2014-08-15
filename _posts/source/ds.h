#define MAXSIZE 10 

typedef struct  {

	int r[MAXSIZE+1];

	int length;

}SqList;

void swap (SqList *,int , int);

void swap (SqList *L, int i, int j)
{
	int tmp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = tmp;

}
