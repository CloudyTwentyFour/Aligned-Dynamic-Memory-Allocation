/**
* @file doubelLinkedList.c
* @brief This file contains implementation of doubly linked list
* and API to add, remove and find the nodes
*
* @author Sunil Kumar
*
* @date 16/7/2019
*/

#include "../inc/header.h"


/**
 * @brief alStr is Head pointer of the doubly linked list
 * 
 */
static alStr *headptr = NULL; /**< head pointer will be pointing to base node's address */


/**
* @brief This function will print all the nodes in doubly linked list
* @author Sunil Kumar
* @param void
* @return NONE
* @date 16/7/2019
*/
void print_all_nodes(void)
{
	alStr *temp = headptr;
	while(temp != NULL)
	{
		printf("%d %d\n",temp->act_addr, temp->cur_addr);
		temp = temp->next;
	}
}

/**
* @brief This function will add the given information new node and 
* add the new node in to middle of the doubly linked list
* @author Sunil Kumar
* @param act_addr : actual address of Dynamically allocated memory
* @param cur_addr : current address of Dynamically allocated memory
* @return NONE
* @date 16/7/2019
*/
void add_node_middle(uint32_t act_addr, uint32_t cur_addr)
{
	alStr *temp = malloc(sizeof(alStr));
	alStr *temp1 = headptr;
	alStr *temp2 = headptr;
	uint32_t i = 0;

	temp->act_addr = act_addr;
	temp->cur_addr = cur_addr;

	if(headptr != NULL)
	{
		if(temp1->next == NULL)
		{
			temp->next = temp1->next;
			temp->prev = temp1;
			temp1->next = temp;
		}
		else
		{
			while(temp1->next != NULL)
			{
				if(i & 0x01)
				{
					temp2 = temp2->next;
				}
				temp1 = temp1->next;
				i++;
			}
			if(temp2->prev != NULL)
			{
				temp->prev = temp2->prev;
				(temp2->prev)->next = temp;
				temp->next = temp2;
				temp2->prev = temp;
			}
			else
			{
				(temp2->next)->prev = temp;
				temp->next = temp2->next;
				temp2->next = temp;
				temp->prev = temp2;
			}
		}
	}
	else
	{
		temp->prev = NULL;
		temp->next = NULL;
		headptr = temp;
	}
}

/**
* @brief This function will find the node in the doubly linked list with
* given current address and delete that particular node after retrieving
* the actual address stored in that node
* @author Sunil Kumar
* @param cur_addr : current address of the dynamically allocation memory
* @return act_addr : returns actual address of dynamically allocated memory
* upon success; otherwise zero
* @date 16/7/2019
*/
uint32_t find_addr_delete_node(uint32_t cur_addr)
{
	uint32_t retval = 0;
	alStr *temp = headptr;
	while(temp != NULL)
	{
		if(temp->cur_addr == cur_addr)
		{
			if(temp->prev == NULL)
			{
				headptr = temp->next;
				(temp->next)->prev = NULL;
			}
			else if(temp->next == NULL)
			{
				(temp->prev)->next = NULL;
			}
			else
			{
				(temp->prev)->next = temp->next;
				(temp->next)->prev = temp->prev;
			}
			retval = temp->act_addr;
			free(temp);
			break;
		}
		temp = temp->next;
	}
	return retval;
}

/**
* @brief This function will add the given arguments into new node and add the
* new node to the last of the doubly linked list
* @author Sunil Kumar
* @param act_addr : actual address of the dynamically allocated memory
* @param cur_addr : current address of the dynamically allocated memory
* @return NONE
* @date 16/7/2019
*/
void add_node_last(uint32_t act_addr, uint32_t cur_addr)
{
	alStr *temp = malloc(sizeof(alStr));
	alStr *temp1 = headptr;

	temp->act_addr = act_addr;
	temp->cur_addr = cur_addr;

	if(headptr  != NULL)
	{
		while(temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->prev = temp1;
		temp->next = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = NULL;
		headptr = temp;
	}
}
/**
* @brief This function will add the given arguments into new node and add the
* new node to the beginning of the doubly linked list
* @author Sunil Kumar
* @param act_addr : actual address of the dynamically allocated memory
* @param cur_addr : current address of the dynamically allocated memory
* @return NONE
* @date 16/7/2019
*/
void add_node_begin(uint32_t act_addr, uint32_t cur_addr)
{
	alStr *temp = malloc(sizeof(alStr));

	temp->act_addr = act_addr;
	temp->cur_addr = cur_addr;

	temp->next = headptr;
	temp->prev = NULL;
	headptr = temp;
}

