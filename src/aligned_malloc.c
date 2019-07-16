/*
 * aligned_malloc.c
 *
 *  Created on: Jul 12, 2019
 *      Author: ubuntu
 */

#include "../inc/header.h"
int8_t checkIfpowerOfNumber(uint32_t num1, uint32_t num2)
{
	uint32_t count = 0;
	if(num1 % num2 == 0)
	{
		count = 1;
	}
	else
	{
		for (count = 0; num1 > 0; num1 >>= 1)
		{
			count += num1 & 1;
		}
	}
	return count;
}


uint32_t findPowerOfNumberedAddress(uint32_t addr, uint32_t alignedNum)
{
	uint32_t retval = 0;

	if(addr != 0)
	{
		while(1)
		{
			if(checkIfpowerOfNumber(addr, alignedNum) == 1)
			{
				break;
			}
			addr += 1;
		}
	}

	return addr;
}


void *aligned_malloc(uint32_t alignedNumber, uint32_t numOfBytes)
{
	void *act_addr = NULL;
	void *cur_addr = NULL;
	if(alignedNumber > 0)
	{
		act_addr = malloc((numOfBytes + alignedNumber));
		cur_addr = (void *)findPowerOfNumberedAddress((uint32_t)act_addr, alignedNumber);
		if(cur_addr >= act_addr)
		{
			add_node_last(act_addr, cur_addr);
		}
	}

	return cur_addr;
}


int32_t aligned_free(void *cur_addr)
{
	int32_t retval = 0;
	void *ptr = NULL;

	if(cur_addr != NULL)
	{
		ptr = find_addr_delete_node(cur_addr);
		if(ptr != NULL)
		{
			free(ptr);
		}
	}
	else
	{
		retval = -1;
	}

	return retval;
}
