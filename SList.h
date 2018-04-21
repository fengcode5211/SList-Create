#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct SListPNode
{
	DataType _Data;
	struct SListPNode* _pNext;	//指向下一节点的指针
}Node, *PNode;


void SListInit(PNode *ppHead);						//初始化
void SListPushBack(PNode *ppHead, DataType data);	//
void SListPopBack(PNode *ppHead);					//
void SListPushFront(PNode *ppHead, DataType data);	//
void SListPopFront(PNode *ppHead);					//

PNode BuySListNode(DataType data);					//
PNode Find(PNode pHead, DataType data);				//
PNode FindBack_D(PNode pHead, DataType data);		//从尾递归查找结点

//data插入pos之前
void SListInsert(PNode *ppHead,PNode pos, DataType data);	//
void SListErase(PNode *ppHead, PNode pos);					//
unsigned long SListSize(PNode pHead);						//
int SListEmpty(PNode pHead);								//
void SListDestroy(PNode* ppHead);							//
void SListDestroy_D(PNode* ppHead);							//

void SListPrint(PNode pHead);								//

void TestSList();
void TestSList2();	//约瑟夫环
void TestSList3();	//单链表的逆置
void TestSList4();	//链表的合并
void TestSList5();	//链表带环



////////////////////////////////////////////////////////////


void SListPrintBack(PNode pHead);//逆向打印单链表
void EraseNotTail(PNode pos);//				//删除一个无头单链表的非尾节点（不能遍历链表）
void InsertFront(PNode pos, DataType data); //在无头单链表的一个节点前插入一个节点（不能遍历链表）
void JosephCircle(PNode *ppHead, int Step);	//单链表实现约瑟夫环
void ReverseSList(PNode *ppHead);			//三指针
PNode ReverseSList2(PNode pHead);			//新节点头插法
void ReverseSList3(PNode *ppHead);			//直接头插法
void BubbleSort(PNode pHead);				//冒泡排序
PNode FindMidNode(PNode pHead);				//找中间结点，只能遍历一次链表
PNode FindLastKNode(PNode pHead, int K);	//找倒数第K个节点的位置，只遍历一次链表  时间复杂度O(N)
int DeleteLastKNode(PNode *ppHead, int K);	//删除倒数第K个节点
PNode MergeList(PNode pHead1, PNode pHead2);	//有序链表合并
PNode HasCircle(PNode pHead);						//判断链表是否带环
int GetCircleLen(PNode pHead);					//环的长度
PNode GetEnterNode(PNode pHead, PNode pMeetNode);		//环的入口点，两个指针一个从Head处走一个从Meet处走，相遇即为相遇点
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);	//不带环链表的相交	//直接看最后一个结点即可
PNode GetCrossNode(PNode pHead1, PNode pHead2);			//不带环链表交点
//int IsCrossWithCircle(PNode pHead1, PNode pHead2);		//可能带环单链表的相交



////////////////////////////////////////////////////////////

#endif _SLIST_H_