#ifndef _LIST_H_
#define _LIST_H_
#include "portmacro.h"

struct xLIST_ITEM{
	TickType_t xItemValue;
	struct xLIST_ITEM *pxNext;
	struct xLIST_ITEM *pxPrevious;
	void *pvOwner;
	void *pvContainer;
};

typedef struct xLIST_ITEM ListItem_t;

//Simplify the ListNode
struct xMINI_LIST_ITEM{
	TickType_t xItemValue;
	struct xLIST_ITEM *pxNext;
	struct xLIST_ITEM *pxPrevious;
};

typedef struct xMINI_LIST_ITEM MiniListItem_t;

//define root node
typedef struct xLIST{
	UBaseType_t uxNumberOfItems;
	ListItem_t *pxIndex;
	MiniListItem_t xListEnd;
}List_t;

//@func
//list node intialisation
void vListInitialiseItem(ListItem_t *const pxItem);
//list root listNode Initialisation
void vListInitialise(List_t *const pxList);
//将节点插入到链表的尾部
void vListInsertEnd(List_t *const pxList,ListItem_t *const pxNewListItem);
//将节点按照升序排列插入到链表
void vListInsert(List_t *const pxList,ListItem_t *const pxNewListItem);      
//从列表里删除节点
UBaseType_t vListRemove(ListItem_t* const pxItemToRemove){
	
}     

#endif
