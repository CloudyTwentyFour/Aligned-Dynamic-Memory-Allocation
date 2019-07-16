#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct str
{
	struct str *prev;
	uint32_t act_addr;
	uint32_t cur_addr;
	struct str *next;
}alStr;

void print_all_nodes(void);
void add_node_begin(uint32_t act_addr, uint32_t cur_addr);
void add_node_last(uint32_t act_addr, uint32_t cur_addr);
void add_node_middle(uint32_t act_addr, uint32_t cur_addr);
uint32_t find_addr_delete_node(uint32_t cur_addr);
int8_t checkIfpowerOfNumber(uint32_t num1, uint32_t num2);
uint32_t findPowerOfNumberedAddress(uint32_t addr, uint32_t alignedNum);
void *aligned_malloc(uint32_t alignedNumber, uint32_t numOfBytes);
int32_t aligned_free(void *cur_addr);
