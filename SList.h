#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct SListPNode
{
	DataType _Data;
	struct SListPNode* _pNext;	//ָ����һ�ڵ��ָ��
}Node, *PNode;


void SListInit(PNode *ppHead);						//��ʼ��
void SListPushBack(PNode *ppHead, DataType data);	//
void SListPopBack(PNode *ppHead);					//
void SListPushFront(PNode *ppHead, DataType data);	//
void SListPopFront(PNode *ppHead);					//

PNode BuySListNode(DataType data);					//
PNode Find(PNode pHead, DataType data);				//
PNode FindBack_D(PNode pHead, DataType data);		//��β�ݹ���ҽ��

//data����pos֮ǰ
void SListInsert(PNode *ppHead,PNode pos, DataType data);	//
void SListErase(PNode *ppHead, PNode pos);					//
unsigned long SListSize(PNode pHead);						//
int SListEmpty(PNode pHead);								//
void SListDestroy(PNode* ppHead);							//
void SListDestroy_D(PNode* ppHead);							//

void SListPrint(PNode pHead);								//

void TestSList();
void TestSList2();	//Լɪ��
void TestSList3();	//�����������
void TestSList4();	//����ĺϲ�
void TestSList5();	//�������



////////////////////////////////////////////////////////////


void SListPrintBack(PNode pHead);//�����ӡ������
void EraseNotTail(PNode pos);//				//ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
void InsertFront(PNode pos, DataType data); //����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
void JosephCircle(PNode *ppHead, int Step);	//������ʵ��Լɪ��
void ReverseSList(PNode *ppHead);			//��ָ��
PNode ReverseSList2(PNode pHead);			//�½ڵ�ͷ�巨
void ReverseSList3(PNode *ppHead);			//ֱ��ͷ�巨
void BubbleSort(PNode pHead);				//ð������
PNode FindMidNode(PNode pHead);				//���м��㣬ֻ�ܱ���һ������
PNode FindLastKNode(PNode pHead, int K);	//�ҵ�����K���ڵ��λ�ã�ֻ����һ������  ʱ�临�Ӷ�O(N)
int DeleteLastKNode(PNode *ppHead, int K);	//ɾ��������K���ڵ�
PNode MergeList(PNode pHead1, PNode pHead2);	//��������ϲ�
PNode HasCircle(PNode pHead);						//�ж������Ƿ����
int GetCircleLen(PNode pHead);					//���ĳ���
PNode GetEnterNode(PNode pHead, PNode pMeetNode);		//������ڵ㣬����ָ��һ����Head����һ����Meet���ߣ�������Ϊ������
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);	//������������ཻ	//ֱ�ӿ����һ����㼴��
PNode GetCrossNode(PNode pHead1, PNode pHead2);			//������������
//int IsCrossWithCircle(PNode pHead1, PNode pHead2);		//���ܴ�����������ཻ



////////////////////////////////////////////////////////////

#endif _SLIST_H_