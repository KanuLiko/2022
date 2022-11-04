#include "list.h"

void vListInitialiseItem(ListItem_t *const pxItem){
	//Initialise List is empty,the node has not insert any list;
	pxItem->pvContainer = NULL;
}

//list root listNode Initialisation
void vListInitialise(List_t *const pxList){
	pxList->pxIndex = (ListItem_t*) & (pxList->xListEnd); //指向末尾
	pxList->xListEnd.xItemValue = portMAX_DELAY; //是该节点的辅助排序值最大,位于链表尾部
	//最后一个节点的pxNext和pxPrevious都指向自身
	pxList->xListEnd.pxNext = (ListItem_t*) & (pxList->xListEnd);
	pxList->xListEnd.pxPrevious = (ListItem_t*)&(pxList->xListEnd);
	pxList->uxNumberOfItems = (UBaseType_t) 0U;//节点链表节点计数器为0
}

//将节点插入到链表的尾部
void vListInsertEnd(List_t *const pxList,ListItem_t *const pxNewListItem){
	ListItem_t * const pxIndex = pxList->pxIndex;
	pxNewListItem->pxNext = pxIndex;
	pxNewListItem->pxPrevious = pxIndex->pxPrevious;
	pxIndex->pxPrevious->pxNext = pxNewListItem;
	pxIndex->pxPrevious = pxNewListItem;

	//记住该节点所在的链表
	pxNewListItem->pvContainer = (void *)pxList;
	//链表节点计数器++
	(pxList->uxNumberOfItems)++;
}

//将节点按照升序排列插入到链表
void vListInsert(List_t *const pxList,ListItem_t *const pxNewListItem){
	ListItem_t *pxIterator;
	//获取节点的排序辅助值
	const TickType_t xValueOfInsertion = pxNewListItem->xItemValue;
	//寻找需要插入的位置
	if(xValueOfInsertion==portMAX_DELAY){
		pxIterator = pxList->xListEnd.pxPrevious;
	}else{
		for(pxIterator=(ListItem_t*)(&pxList->xListEnd);pxIterator->pxNext->xItemValue <= xValueOfInsertion;pxIterator = pxIterator->pxNext){/*Blank*/}
	}
	pxNewListItem->pvContainer = (void*)pxList;
	//链表节点计数器++
	(pxList->uxNumberOfItems)++;
}


