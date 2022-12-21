int GetHeight(BinTree BT)
{
	intt HL,HR,MaxH;
	if(BT)
	{
		HL = GetHeight(BT->left);
		HR = GetHeight(BT->right);
		MaxH = HL > HR ? HL:HR;
		return MaxH + 1;
	}
	else{
		return 0;
	}
}

int GetHeight(BinTree BT)
{
	int d = 0,depL,depR;
	if(BT == NULL)
	return 0;
	if(bt->lchild == NULL && bt ->rchild == NULL)
	 return l;
	 depthL = GetHeight(BT->lchild);
	 depthR = GetHeight(BT->rchlid);
	 d = max(depthL,depthR)
	 return d + 1; 
}
