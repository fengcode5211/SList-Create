#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

PNode BuySListNode(DataType data)
{
	PNode NewNode = (PNode)malloc(sizeof(Node));
	if (NULL == NewNode)
	{
		return NULL;
	}
	NewNode->_Data = data;
	NewNode->_pNext = NULL;
	return NewNode;
}

void SListInit(PNode *ppHead)
{
	assert(ppHead);
	*ppHead = NULL;
}

void SListPushBack(PNode *ppHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(ppHead);

	pNewNode = BuySListNode(data);
	if (NULL == pNewNode)
	{
		return;
	}
	if (NULL == *ppHead)
	{
		*ppHead = pNewNode;
	}
	else
	{
		PNode  pTailNode = *ppHead;
		while (pTailNode->_pNext)
		{
			pTailNode = pTailNode->_pNext;
		}
		pTailNode->_pNext = pNewNode;
	}
}

void SListPopBack(PNode *ppHead)
{
	assert(ppHead);
	if (NULL == *ppHead)
	{
		return;
	}
	else if (NULL ==(*ppHead)->_pNext)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		PNode pTail = *ppHead;		
		PNode pPreTail = NULL;
		while (pTail->_pNext)
		{
			pPreTail = pTail;
			pTail = pTail->_pNext;
		}
		free(pTail);
		pPreTail->_pNext = NULL;
	}

}

void SListPushFront(PNode *ppHead, DataType data)
{
	assert(ppHead);
	PNode NewNode = BuySListNode(data);
	if (NULL == NewNode)
	{
		return;
	}
	NewNode->_pNext = *ppHead;
	*ppHead = NewNode;
}

void SListPopFront(PNode *ppHead)
{
	PNode pDel = NULL;
	assert(ppHead);
	if (NULL == *ppHead)
	{
		return;
	}
	else
	{
		PNode pDel = *ppHead;
		*ppHead = pDel->_pNext;
		free(pDel);
	}
}

PNode Find(PNode pHead, DataType data)
{
	PNode pCur = pHead;
	while (pCur)
	{
		if (data == pCur->_Data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}

PNode FindBack_D(PNode pHead, DataType data)
{
	if (pHead)
	{
		if (data == pHead->_Data)
		{
			return pHead;
		}
		FindBack_D(pHead->_pNext, data);
	}
	return NULL; 
}

void SListInsert(PNode *ppHead, PNode pos, DataType data)
{
	assert(ppHead);

	PNode pPreNode = NULL;
	if (NULL == pos || NULL == *ppHead)
	{
		return;
	}
	else
	{
		PNode pNewNode = BuySListNode(data);
		if (*ppHead == pos)	//头插
		{
			pNewNode->_pNext = *ppHead;
			*ppHead = pNewNode;
		}
		else
		{
			pPreNode = *ppHead;
			while (pPreNode && pPreNode->_pNext != pos)//找到pos前一个节点
			{
				pPreNode = pPreNode->_pNext;
			}
			if (pPreNode)
			{
				pNewNode->_pNext = pos;
				pPreNode->_pNext = pNewNode;
			}
			else
			{
				return;
			}
		}
	}
}


void SListErase(PNode *ppHead, PNode pos)
{
	assert(ppHead);
	if (NULL == *ppHead || NULL == pos)
	{
		return;
	}
	else
	{
		if (*ppHead == pos)//头删
		{
			*ppHead = pos->_pNext;
			free(pos);
		}
		else
		{
			PNode pPrepos = *ppHead;
			while (pPrepos && pPrepos->_pNext != pos)
			{
				pPrepos = pPrepos->_pNext;
			}
			if (pPrepos)
			{
				pPrepos->_pNext = pos->_pNext;
				free(pos);
			}
			else
			{
				return;
			}
		}
	}
}


int SListEmpty(PNode pHead)
{
	return NULL == pHead;
}

unsigned long SListSize(PNode pHead)
{
	unsigned long count = 0;
	PNode pCur = pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}

//正向销毁
void SListDestroy(PNode* ppHead)
{
	PNode pCur = NULL;
	PNode pPreCur = NULL;
	assert(ppHead);
	pCur = *ppHead;
	while (pCur)
	{
		pPreCur = pCur;
		pCur = pCur->_pNext;
		free(pPreCur);
	}
	*ppHead = NULL;

	//while (pCur)
	//{
	//	*ppHead = pCur->_pNext;
	//	free(pCur);
	//	pCur = *ppHead;
	//}

}

//逆向销毁
void SListDestroy_D(PNode* ppHead)
{
	assert(ppHead);
	if (*ppHead)
	{
		SListDestroy_D(&(*ppHead)->_pNext);
		free(*ppHead);
		*ppHead = NULL;
	}
}



void SListPrint(PNode pHead)
{
	PNode pCur = pHead;
	while (pCur)
	{
		printf(" %d->", pCur->_Data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////
void SListPrintBack(PNode pHead)	//时间复杂度O(N)
{
	if (pHead)
	{
		SListPrintBack(pHead->_pNext);
		printf("%d   ", pHead->_Data);
	}
}

void EraseNotTail(PNode pos)		//替换法删除	
{
	PNode pDel = NULL;
	if (NULL == pos)
	{
		printf("error! not found %d!\n", pos->_Data);
		return;
	}
	pDel = pos->_pNext;	//pos的后一个节点
	pos->_Data = pDel->_Data;	//赋值
	pos->_pNext = pDel->_pNext;	
	free(pDel);
}


void InsertFront(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
	{
		printf("error! not found %d!\n", pos->_Data);
		return;
	}
	pNewNode = BuySListNode(pos->_Data);//直接创建一个值和pos一样的新节点，省去swap
	pNewNode->_pNext = pos->_pNext;		//链接
	pos->_pNext = pNewNode;			
	pos->_Data = data;					//直接将data赋值给pos
}

void JosephCircle(PNode *ppHead, int Step)
{
	PNode pDel = NULL;
	PNode pCur = NULL;
	assert(ppHead);
	pCur = *ppHead;
	while (pCur->_pNext != pCur)	//只剩一个元素
	{
		//报数
		int count = Step;
		while (--count)		//移动step-1次
		{
			pCur = pCur->_pNext;
		}
		//删除(替换法删除，删除后一个节点)
		pDel = pCur->_pNext;
		pCur->_Data = pDel->_Data;
		pCur->_pNext = pDel->_pNext;
		free(pDel);	//最后会被销毁，可以不置空
	}
	*ppHead = pCur;		//只剩最后一个节点
}


void ReverseSList(PNode *ppHead)		//三指针法
{
	PNode pPreCur = NULL;
	PNode pCur = NULL;
	PNode pCurTail = NULL;
	assert(ppHead);
	if (NULL == *ppHead && NULL == (*ppHead)->_pNext)
	{
		return;
	}
	pCur = *ppHead;

	while (pCur)					//  p1   p2   p3  
	{
		pCurTail = pCur->_pNext;		//p3 = p2->next
		pCur->_pNext = pPreCur;			//p2->next = p1、断开
		pPreCur = pCur;					//p1 = p2;
		pCur = pCurTail;				//p2 = p3
	}
	*ppHead = pPreCur;					//更新头结点
}

PNode ReverseSList2(PNode pHead)		//新节点头插法
{
	PNode pCur = pHead;
	PNode pCurNext = NULL;
	PNode pNewHead = NULL;

	while (pCur)
	{
		pCurNext = pCur->_pNext;	
		pCur->_pNext = pNewHead;
		pNewHead = pCur;
		pCur = pCurNext;
	}
	return pNewHead;
}

void ReverseSList3(PNode *ppHead)	//头插法
{
	//标记头结点的下一个节点
	//将其插入到头结点之前
	PNode pCur = NULL;
	PNode pCurNext = NULL;
	assert(ppHead);
	pCur = (*ppHead)->_pNext;	//标记头结点的后一个节点
	(*ppHead)->_pNext = NULL;	//将头结点的Next域置空
	while (pCur)	
	{
		pCurNext = pCur->_pNext;	//标记待头插的结点的下一个节点，防止找不到
		pCur->_pNext = *ppHead;		//头插
		*ppHead = pCur;
		pCur = pCurNext;			
	}
}

void BubbleSort(PNode pHead)
{
	PNode pCur = NULL;			
	PNode pNext = NULL;				
	PNode pTail = NULL;				//尾结点
	int flag = 0;
	if (NULL == pHead || NULL == pHead->_pNext)
	{
		return;
	}

	while (pHead != pTail)		//控制循环次数
	{
		flag = 0;
		pCur = pHead;
		pNext = pCur->_pNext;
		while (pNext != pTail)	//每一次循环
		{
			if (pCur->_Data > pNext->_Data)
			{
				DataType tmp = pCur->_Data;
				pCur->_Data = pNext->_Data;
				pNext->_Data = tmp;
				flag = 1;
			}
			pCur = pCur->_pNext;
			pNext = pCur->_pNext;
		}
		if (!flag)			//未发生交换
		{
			return;
		}
		pTail = pCur;					//将循环控制的尾指针向前移动
	}
}

PNode FindMidNode(PNode pHead)	//快慢指针
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	PNode pPreSlow = NULL;
	if (NULL == pHead)
	{
		return NULL;
	}
	while(pFast && pFast->_pNext)		//奇数个（fast->next 为空）、偶数个（fast为空）
	{
		pPreSlow = pSlow;
		pSlow = pSlow->_pNext;			//走一次	
		pFast = pFast->_pNext->_pNext;	//走两次
	}
	if (pFast)
	{
		return pSlow;
	}
	else
	{
		return pPreSlow;	//偶数个返回前一个节点
	}
//	return pSlow;					//偶数个节点时返回后一个节点
}

PNode FindLastKNode(PNode pHead, int K)		
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if (NULL == pHead || 0 == K)
	{
		return NULL;
	}
	//让快指针先走K步
	while (K--)
	{
		if (NULL == pFast)
			return NULL;
		pFast = pFast->_pNext;
	}
	//快慢指针一起走，快指针为空时停止
	while (pFast)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}

int DeleteLastKNode(PNode *ppHead, int K)
{
	PNode pFast = NULL;
	PNode pPreSlow = NULL;
	PNode pSlow = NULL;
	assert(ppHead);
	if (NULL == *ppHead || 0 == K)
	{
		return 0;
	}
	pFast = *ppHead;
	pSlow = *ppHead;
	//快指针先走K步
	while (K--)
	{
		if (NULL == pFast)
		{
			return 0;
		}
		pFast = pFast->_pNext;
	}
	//快慢指针一起走
	while (pFast)
	{
		pPreSlow = pSlow;
		pSlow = pSlow->_pNext;
		pFast = pFast->_pNext;
	}
	if (*ppHead == pSlow)	//删头结点
	{
		*ppHead = pSlow->_pNext;
	}
	else                   //非头结点
	{
		pPreSlow->_pNext = pSlow->_pNext;
	}
	free(pSlow);
	return 1;
}

PNode MergeList(PNode pHead1, PNode pHead2)
{
	PNode pNewHead = NULL;
	PNode pTail = NULL;
	PNode pNode1 = pHead1;		//第一个链表的指针
	PNode pNode2 = pHead2;		//第二个链表的指针
	if (NULL == pHead1 || NULL == pHead2)
	{
		return (pHead1) ? pHead1 : pHead2;
	}
	if (pNode1->_Data < pNode2->_Data)		//将头结点和值较小链表的头结点先连接起来
	{
		pNewHead = pNode1;
		pTail = pNode1;
		pNode1 = pNode1->_pNext;
	}
	else
	{
		pNewHead = pNode2;
		pTail = pNode2;
		pNode2 = pNode2->_pNext;
	}

	while (pNode1 && pNode2)			//两个链表都未插完
	{
		if (pNode1->_Data < pNode2->_Data)		//将值较小的插入
		{
			pTail->_pNext = pNode1;
			pNode1 = pNode1->_pNext;
		}
		else
		{
			pTail->_pNext = pNode2;
			pNode2 = pNode2->_pNext;
		}
		pTail = pTail->_pNext;			//尾指针向后移动
	}
	if (pNode1)							//第一个链表未插完
	{
		pTail->_pNext = pNode1;
	}
	if (pNode2)							//第二个链表未插完
	{
		pTail->_pNext = pNode2;
	}
	return pNewHead;
}

PNode HasCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while (pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;	//指针先走
		pSlow = pSlow->_pNext;

		if (pFast == pSlow)				//判断是否相遇
		{
			return pFast;
		}
	}
	return NULL;
}

int GetCircleLen(PNode pHead)
{
	PNode pCur = NULL;
	int size = 1;			//计算大小时 会少计算meet的前一个节点
	PNode MeetNode = HasCircle(pHead);
	if (NULL == MeetNode)
	{
		return 0;
	}
	pCur = MeetNode;
	while (pCur->_pNext != MeetNode)		//从meetNode开始计算
	{
		size++;
		pCur = pCur->_pNext;
	}
	return size;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;		//从头结点
	PNode pM = pMeetNode;

	if (pH == NULL || pM  == NULL)
	{
		return NULL;
	}
	while (pM != pH)
	{
		pM = pM->_pNext;
		pH = pH->_pNext;
	}
	return pM;
}


int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)
{
	PNode pTail1 = pHead1;
	PNode pTail2 = pHead2;
	if (NULL == pHead1 || NULL == pTail2)
	{
		return 0;
	}
	while (pTail1->_pNext)
	{
		pTail1 = pTail1->_pNext;
	}
	while (pTail2->_pNext)
	{
		pTail2 = pTail2->_pNext;
	}
	return pTail1 == pTail2;
}

PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int size1 = 0;
	int size2 = 0;
	PNode pCur1 = NULL;
	PNode PCur2 = NULL;
	int k = 0;
	if (NULL == pHead1 || NULL == pHead2)
	{
		return NULL;
	}
	if (!IsCrossWithoutCircle(pHead1, pHead2))
	{
		return 0;
	}
	size1 = SListSize(pHead1);
	size2 = SListSize(pHead2);
	k = size1 - size2;
	if (k > 0)			//长的先走长度差值步
	{
		while (k--)
		{
			pCur1 = pCur1->_pNext;
		}
	}
	else
	{
		while (k++)		//从负值++
		{
			PCur2 = PCur2->_pNext;
		}
	}
	while (pCur1 != PCur2)		//两指针一起走	//肯定有交点最后一定相遇
	{
		pCur1 = pCur1->_pNext;
		PCur2 = PCur2->_pNext;
	}
	return pCur1;
}

int IsCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = HasCircle(pHead1);
	PNode pMeetNode2 = HasCircle(pHead2);
	
	if (NULL == pMeetNode1 && NULL == pMeetNode2)	//两个都不带环
	{
		if (!IsCrossWithoutCircle(pHead1, pHead2))
		{
			return 0;
		}
		else
		{
			return 1;
		}
		PNode pTail1 = pHead1;
		PNode pTail2 = pHead2;
		while (pTail1->_pNext)
			pTail1 = pTail1->_pNext;
		while(pTail2->_pNext)
			pTail2 = pTail2->_pNext;
		if (pTail1 == pTail2)
			return 1;
		else
			return 0;
	}
	else if (pMeetNode1 && pMeetNode2)		//两个都带环
	{
		PNode pCur = pMeetNode1;
		while (pCur->_pNext != pMeetNode1)	//未判断PM2的下一个节点是PM1的情况
		{
			if (pCur == pMeetNode2)
			{
				return 2;			//与不带环的相交区分
			}
			pCur = pCur->_pNext;
		}
		if (pCur == pMeetNode2)
		{
			return 2;
		}
	}
	// 一个带环一个不带环，直接返回0；
	return 0;
}







void TestSList5()
{
	PNode pHead = NULL;
	PNode pTail = NULL;
	PNode MeetNode = NULL;
	PNode EnterNode = NULL;
	int size = 0;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	pTail = Find(pHead, 8);
	pTail->_pNext = Find(pHead, 5);
	MeetNode = HasCircle(pHead);
	if (MeetNode)
	{
		printf("HasCircle!  ----  data: %d\n",MeetNode->_Data);
	}
	else
	{
		printf("no!\n");
	}
	size = GetCircleLen(pHead);
	printf("Circlelen:  %d\n", size);
	EnterNode = GetEnterNode(pHead, MeetNode);
	if (EnterNode)
	{
		printf("EnterNode : %d\n", EnterNode->_Data);
	}
	else
	{
		printf("No Enternode!\n");
	}
}




void TestSList4()
{
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	PNode pNewHead = NULL;
	SListInit(&pHead1);
	SListInit(&pHead2);
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 9);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 8);
	SListPushBack(&pHead2, 10);
	SListPrint(pHead1);
	SListPrint(pHead2);
	pNewHead = MergeList(pHead1, pHead2);
	SListPrint(pNewHead);
}



void TestSList3()
{
	PNode pHead = NULL;
	PNode pNewNode = NULL;
	SListInit(&pHead);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 7);
	SListPrint(pHead);
	//	 ReverseSList(&pHead);
	//	 pNewNode = ReverseSList2(pHead);
	//	 ReverseSList3(&pHead);
	//	 BubbleSort(pHead);
	//	 pNewNode = FindLastKNode(pHead, 6);
	if (pNewNode)
	{
		printf("Find = %d\n", pNewNode->_Data);
	}
	DeleteLastKNode(&pHead, 6);


	SListPrint(pHead);

}

//void TestSList2()
//{
//	PNode pHead = NULL;
//	PNode pTail = NULL;
//
//	SListInit(&pHead);
//	SListPushBack(&pHead, 1);
//	SListPushBack(&pHead, 2);
//	SListPushBack(&pHead, 3);
//	SListPushBack(&pHead, 4);
//	SListPushBack(&pHead, 5);
//	SListPushBack(&pHead, 6);
//	SListPushBack(&pHead, 7);
//
//	pTail = Find(pHead, 7);
//	pTail->_pNext = pHead;
//	JosephCircle(&pHead, 3);
//
//	pHead->_pNext = NULL;	//只剩最后一个节点
//	SListPrint(pHead);
//}



///////////////////////////////////////////////////////////////////////////////
void TestSList()
{
	PNode pHead;
	PNode pos;
	SListInit(&pHead);	//第一个节点的地址
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPrint(pHead);
	SListPopBack(&pHead);
	SListPrint(pHead);
	SListPushFront(&pHead, 0);
	SListPrint(pHead);
	SListPopFront(&pHead);
	SListPrint(pHead);
	pos = FindBack_D(pHead, 2);
	SListInsert(&pHead, pos, 4);
	SListPrint(pHead);
	pos = Find(pHead, 4);
	SListErase(&pHead, pos);
	SListPrint(pHead);
	printf("size = %d\n", SListSize(pHead));
	SListPrintBack(pHead);
}