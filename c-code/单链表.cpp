//创建单链表 
void CreateList L(LinkList &L,ElemType A[],int n)
{
	L = NULL;
	for(i = n-1; i>-0;i--)
	{
		s = new LNode;
		s->data = A[i];
		s->next = L;
	}
}
//初始化 

//插入 
void Insert(LinkList &L,LNode* p,LNode* s){
	if(p == L)
	{
		s->next = L;
		L = s;
	}
	else{
		q = L;
		while(q->next! = p) q = q ->next;
		q->next = s;
		s->next = p;
	}
}
//删除 
void Delete(LinkList &L,LNode* p){
	
}

