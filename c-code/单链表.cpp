//���������� 
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
//��ʼ�� 

//���� 
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
//ɾ�� 
void Delete(LinkList &L,LNode* p){
	
}

