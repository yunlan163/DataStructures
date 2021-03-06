typedef struct
	{HDataType *data;
	 int max;
	 int size;
	}Heap;
void FilterUp(Heap *H);
void FilterDown(Heap *H);
void SetHeap(Heap *H,int n);
void FreeHeap(Heap *H);
int HeapSize(Heap *H);
int HeapEmpty(Heap *H);
int HeapFull(Heap *H);
void HeapInsert(Heap *H,HDataType item);
HDataType HeapDelete(Heap *H);
void ClearHeap(Heap *H);

void FilterUp(Heap *H)
	{int c,p;
	 HDataType temp;
	 c=H->size-1;
	 p=(c-1)/2;
	 temp=H->data[c];
	 while(c!=0)
		{if(H->data[p]->data<=temp->data)
			break;
		 H->data[c]=H->data[p];
		 c=p;
		 p=(c-1)/2;
		}
	 H->data[c]=temp;
	}
void FilterDown(Heap *H)
	{int c,p;
	 HDataType temp;
	 p=0;
	 c=2*p+1;
	 temp=H->data[p];
	 while(c<H->size)
		{if(c+1<H->size&&H->data[c+1]->data<H->data[c]->data)
		 c=c+1;
		 if(temp->data<=H->data[c]->data)
			break;
		 H->data[p]=H->data[c];
		 p=c;
		 c=2*p+1;
		}
	 H->data[p]=temp;
	}
void SetHeap(Heap *H,int n)
	{H->data=(HDataType *)malloc(n*sizeof(HDataType));
	 H->max=n;
	 H->size=0;
	}
void FreeHeap(Heap *H)
	{free(H->data);
	}
int HeapSize(Heap *H)
	{return(H->size);
	}
int HeapEmpty(Heap *H)
	{if(H->size==0)
		return(1);
	 return(0);
	}
int HeapFull(Heap *H)
	{if(H->size==H->max)
		return(1);
	 return(0);
	}
void HeapInsert(Heap *H,HDataType item)
	{if(H->size==H->max)
		{printf("Heap is full");
		 exit(1);
		}
	 H->data[H->size]=item;
	 H->size++;
	 FilterUp(H);
	}
HDataType HeapDelete(Heap *H)
	{HDataType temp;
	 if(H->size==0)
		{printf("Heap is empty");
		 exit(1);
		}
	 temp=H->data[0];
	 H->data[0]=H->data[H->size-1];
	 H->size--;
	 FilterDown(H);
	 return(temp);
	}
void ClearHeap(Heap *H)
	{H->size=0;
	}
