/**
* @file aligned_malloc.c
* @brief This function contains implementation of the
* Aligned Dynamic Memory Allocation
*
* @author Sunil Kumar
*
* @date 16/7/2019
*/


#include "../inc/header.h"

/**
* @brief This function will check if given number is power of 2 or
* multiple of another given number
* @author Sunil Kumar
* @param num1: base number
* @param num2: exponent number
* @return 1 if given number is power of 2 or multiple of num2; 0 otherwise
* @date 16/7/2019
*/
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

/**
* @brief This function will find the power of 2 or multiple of aligned number
* @author Sunil Kumar
* @param addr: address
* @param alignedNum: aligned number
* @return aligned address
* @date 16/7/2019
*/
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

/**
* @brief This function will allocate the address aligned for the given alignedNumber
* @author Sunil Kumar
* @param alignedNum: aligned number
* @param numOfBytes: number of bytes to be allocated
* @return aligned address
* @date 16/7/2019
*/
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

/**
* @brief This function will find the actual address for given address in
* doubly linked list
* @author Sunil Kumar
* @param cur_addr: pointer to the address to be freed
* @return 0 if memory free is successful; -1 otherwise
* @date 16/7/2019
*/
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
