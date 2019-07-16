#include "../inc/header.h"

static alStr *headptr = NULL;

void print_all_nodes(void)
{
	alStr *temp = headptr;
	while(temp != NULL)
	{
		printf("%d %d\n",temp->act_addr, temp->cur_addr);
		temp = temp->next;
	}
}

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

void add_node_begin(uint32_t act_addr, uint32_t cur_addr)
{
	alStr *temp = malloc(sizeof(alStr));

	temp->act_addr = act_addr;
	temp->cur_addr = cur_addr;

	temp->next = headptr;
	temp->prev = NULL;
	headptr = temp;
}

