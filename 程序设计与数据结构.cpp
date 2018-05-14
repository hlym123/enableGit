/**********************************************************************************************
	
	《程序设计与数据结构》-- 周立功
	
	@date: 2017.11.21
	
	
	
**********************************************************************************************/




/**********************************************************************************************
	第三章 算法与数据结构
**********************************************************************************************/

//==============================
//	3.1 算法问题
//==============================


 

//==============================
//	3.2 单向链表
//==============================
struct _slist_node {
	int data;
	struct _slist_node *p_next;
}

typedef struct _slist_node {
	int data;
	struct _slist_node *p_next;
} slist_node_t;


typedef int element_type_t;
typedef struct _slist_node {
	element_type_t data;
	struct _slist_node *p_next;
} slist_node_t; 
slist_node_t *p_head;  // 头节点


/**
 * 新增节点
 */
int slist_add_tail(slist_node_t **p_head, slist_node_t *p_node)
{
	if (*p_head == NULL) {  // 判断当前链表是否为空
		*p_head = p_node;
		p_node->p_next = NULL;
	} else {
		slist_node_t *p_tmp = *p_head;
		while (p_tmp->p_next != NULL) {
			p_tmp = p_tmp->p_next;
		}
		p_tmp->p_next = p_node;
		p_node->p_next = NULL;
	}
	return 0;
}

 
//==============================
//	3.3 双向链表
//==============================
 
 
//==============================
//	3.4 迭代器模式
//==============================
 
 
//==============================
//	3.5 哈希表
//============================== 
 
 
 
//==============================
//	3.6 队列 ADT
//==============================
 
 
 




/**********************************************************************************************
	第四章 面向对象编程
**********************************************************************************************/


//==============================
//	4.1 OO思想
//==============================


//==============================
//	4.2 类与对象
//==============================



//==============================
//	4.3 继承与多态
//==============================


//==============================
//	4.4 虚函数
//==============================


//==============================
//	4.1 框架与重用
//==============================








