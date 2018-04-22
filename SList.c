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
		if (*ppHead == pos)	//ͷ��
		{
			pNewNode->_pNext = *ppHead;
			*ppHead = pNewNode;
		}
		else
		{
			pPreNode = *ppHead;
			while (pPreNode && pPreNode->_pNext != pos)//�ҵ�posǰһ���ڵ�
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
		if (*ppHead == pos)//ͷɾ
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

//��������
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

//��������
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
void SListPrintBack(PNode pHead)	//ʱ�临�Ӷ�O(N)
{
	if (pHead)
	{
		SListPrintBack(pHead->_pNext);
		printf("%d   ", pHead->_Data);
	}
}

void EraseNotTail(PNode pos)		//�滻��ɾ��	
{
	PNode pDel = NULL;
	if (NULL == pos)
	{
		printf("error! not found %d!\n", pos->_Data);
		return;
	}
	pDel = pos->_pNext;	//pos�ĺ�һ���ڵ�
	pos->_Data = pDel->_Data;	//��ֵ
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
	pNewNode = BuySListNode(pos->_Data);//ֱ�Ӵ���һ��ֵ��posһ�����½ڵ㣬ʡȥswap
	pNewNode->_pNext = pos->_pNext;		//����
	pos->_pNext = pNewNode;			
	pos->_Data = data;					//ֱ�ӽ�data��ֵ��pos
}

void JosephCircle(PNode *ppHead, int Step)
{
	PNode pDel = NULL;
	PNode pCur = NULL;
	assert(ppHead);
	pCur = *ppHead;
	while (pCur->_pNext != pCur)	//ֻʣһ��Ԫ��
	{
		//����
		int count = Step;
		while (--count)		//�ƶ�step-1��
		{
			pCur = pCur->_pNext;
		}
		//ɾ��(�滻��ɾ����ɾ����һ���ڵ�)
		pDel = pCur->_pNext;
		pCur->_Data = pDel->_Data;
		pCur->_pNext = pDel->_pNext;
		free(pDel);	//���ᱻ���٣����Բ��ÿ�
	}
	*ppHead = pCur;		//ֻʣ���һ���ڵ�
}


void ReverseSList(PNode *ppHead)		//��ָ�뷨
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
		pCur->_pNext = pPreCur;			//p2->next = p1���Ͽ�
		pPreCur = pCur;					//p1 = p2;
		pCur = pCurTail;				//p2 = p3
	}
	*ppHead = pPreCur;					//����ͷ���
}

PNode ReverseSList2(PNode pHead)		//�½ڵ�ͷ�巨
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

void ReverseSList3(PNode *ppHead)	//ͷ�巨
{
	//���ͷ������һ���ڵ�
	//������뵽ͷ���֮ǰ
	PNode pCur = NULL;
	PNode pCurNext = NULL;
	assert(ppHead);
	pCur = (*ppHead)->_pNext;	//���ͷ���ĺ�һ���ڵ�
	(*ppHead)->_pNext = NULL;	//��ͷ����Next���ÿ�
	while (pCur)	
	{
		pCurNext = pCur->_pNext;	//��Ǵ�ͷ��Ľ�����һ���ڵ㣬��ֹ�Ҳ���
		pCur->_pNext = *ppHead;		//ͷ��
		*ppHead = pCur;
		pCur = pCurNext;			
	}
}

void BubbleSort(PNode pHead)
{
	PNode pCur = NULL;			
	PNode pNext = NULL;				
	PNode pTail = NULL;				//β���
	int flag = 0;
	if (NULL == pHead || NULL == pHead->_pNext)
	{
		return;
	}

	while (pHead != pTail)		//����ѭ������
	{
		flag = 0;
		pCur = pHead;
		pNext = pCur->_pNext;
		while (pNext != pTail)	//ÿһ��ѭ��
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
		if (!flag)			//δ��������
		{
			return;
		}
		pTail = pCur;					//��ѭ�����Ƶ�βָ����ǰ�ƶ�
	}
}

PNode FindMidNode(PNode pHead)	//����ָ��
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	PNode pPreSlow = NULL;
	if (NULL == pHead)
	{
		return NULL;
	}
	while(pFast && pFast->_pNext)		//��������fast->next Ϊ�գ���ż������fastΪ�գ�
	{
		pPreSlow = pSlow;
		pSlow = pSlow->_pNext;			//��һ��	
		pFast = pFast->_pNext->_pNext;	//������
	}
	if (pFast)
	{
		return pSlow;
	}
	else
	{
		return pPreSlow;	//ż��������ǰһ���ڵ�
	}
//	return pSlow;					//ż�����ڵ�ʱ���غ�һ���ڵ�
}

PNode FindLastKNode(PNode pHead, int K)		
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if (NULL == pHead || 0 == K)
	{
		return NULL;
	}
	//�ÿ�ָ������K��
	while (K--)
	{
		if (NULL == pFast)
			return NULL;
		pFast = pFast->_pNext;
	}
	//����ָ��һ���ߣ���ָ��Ϊ��ʱֹͣ
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
	//��ָ������K��
	while (K--)
	{
		if (NULL == pFast)
		{
			return 0;
		}
		pFast = pFast->_pNext;
	}
	//����ָ��һ����
	while (pFast)
	{
		pPreSlow = pSlow;
		pSlow = pSlow->_pNext;
		pFast = pFast->_pNext;
	}
	if (*ppHead == pSlow)	//ɾͷ���
	{
		*ppHead = pSlow->_pNext;
	}
	else                   //��ͷ���
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
	PNode pNode1 = pHead1;		//��һ�������ָ��
	PNode pNode2 = pHead2;		//�ڶ��������ָ��
	if (NULL == pHead1 || NULL == pHead2)
	{
		return (pHead1) ? pHead1 : pHead2;
	}
	if (pNode1->_Data < pNode2->_Data)		//��ͷ����ֵ��С�����ͷ�������������
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

	while (pNode1 && pNode2)			//��������δ����
	{
		if (pNode1->_Data < pNode2->_Data)		//��ֵ��С�Ĳ���
		{
			pTail->_pNext = pNode1;
			pNode1 = pNode1->_pNext;
		}
		else
		{
			pTail->_pNext = pNode2;
			pNode2 = pNode2->_pNext;
		}
		pTail = pTail->_pNext;			//βָ������ƶ�
	}
	if (pNode1)							//��һ������δ����
	{
		pTail->_pNext = pNode1;
	}
	if (pNode2)							//�ڶ�������δ����
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
		pFast = pFast->_pNext->_pNext;	//ָ������
		pSlow = pSlow->_pNext;

		if (pFast == pSlow)				//�ж��Ƿ�����
		{
			return pFast;
		}
	}
	return NULL;
}

int GetCircleLen(PNode pHead)
{
	PNode pCur = NULL;
	int size = 1;			//�����Сʱ ���ټ���meet��ǰһ���ڵ�
	PNode MeetNode = HasCircle(pHead);
	if (NULL == MeetNode)
	{
		return 0;
	}
	pCur = MeetNode;
	while (pCur->_pNext != MeetNode)		//��meetNode��ʼ����
	{
		size++;
		pCur = pCur->_pNext;
	}
	return size;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;		//��ͷ���
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
	if (k > 0)			//�������߳��Ȳ�ֵ��
	{
		while (k--)
		{
			pCur1 = pCur1->_pNext;
		}
	}
	else
	{
		while (k++)		//�Ӹ�ֵ++
		{
			PCur2 = PCur2->_pNext;
		}
	}
	while (pCur1 != PCur2)		//��ָ��һ����	//�϶��н������һ������
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
	
	if (NULL == pMeetNode1 && NULL == pMeetNode2)	//������������
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
	else if (pMeetNode1 && pMeetNode2)		//����������
	{
		PNode pCur = pMeetNode1;
		while (pCur->_pNext != pMeetNode1)	//δ�ж�PM2����һ���ڵ���PM1�����
		{
			if (pCur == pMeetNode2)
			{
				return 2;			//�벻�������ཻ����
			}
			pCur = pCur->_pNext;
		}
		if (pCur == pMeetNode2)
		{
			return 2;
		}
	}
	// һ������һ����������ֱ�ӷ���0��
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
//	pHead->_pNext = NULL;	//ֻʣ���һ���ڵ�
//	SListPrint(pHead);
//}



///////////////////////////////////////////////////////////////////////////////
void TestSList()
{
	PNode pHead;
	PNode pos;
	SListInit(&pHead);	//��һ���ڵ�ĵ�ַ
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