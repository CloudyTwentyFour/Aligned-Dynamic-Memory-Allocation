/**
* @file header.h
* @brief This function contains implementation of the
* Aligned Dynamic Memory Allocation
*
* @author Sunil Kumar
*
* @date 16/7/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief structure used for doubly linked list
 *
 * Structure used for aligned memory allocation to store the
 * actual address
 */
typedef struct str
{
	struct str *prev;	/**< pointer to previous node */
	uint32_t act_addr;	/**< Actual address */
	uint32_t cur_addr;	/**< Aligned Address of the current address */
	struct str *next;	/**< pointer to next node */
}alStr;
/**
* @brief This function will print all the nodes in doubly linked list
* @author Sunil Kumar
* @param void
* @return NONE
* @date 16/7/2019
*/
void print_all_nodes(void);
/**
* @brief This function will add the given arguments into new node and add the
* new node to the beginning of the doubly linked list
* @author Sunil Kumar
* @param act_addr : actual address of the dynamically allocated memory
* @param cur_addr : current address of the dynamically allocated memory
* @return NONE
* @date 16/7/2019
*/
void add_node_begin(uint32_t act_addr, uint32_t cur_addr);
/**
* @brief This function will add the given arguments into new node and add the
* new node to the last of the doubly linked list
* @author Sunil Kumar
* @param act_addr : actual address of the dynamically allocated memory
* @param cur_addr : current address of the dynamically allocated memory
* @return NONE
* @date 16/7/2019
*/
void add_node_last(uint32_t act_addr, uint32_t cur_addr);
/**
* @brief This function will add the given information new node and 
* add the new node in to middle of the doubly linked list
* @author Sunil Kumar
* @param act_addr : actual address of Dynamically allocated memory
* @param cur_addr : current address of Dynamically allocated memory
* @return NONE
* @date 16/7/2019
*/
void add_node_middle(uint32_t act_addr, uint32_t cur_addr);
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
uint32_t find_addr_delete_node(uint32_t cur_addr);
/**
* @brief This function will check if given number is power of 2 or
* multiple of another given number
* @author Sunil Kumar
* @param num1: base number
* @param num2: exponent number
* @return 1 if given number is power of 2 or multiple of num2; 0 otherwise
* @date 16/7/2019
*/
int8_t checkIfpowerOfNumber(uint32_t num1, uint32_t num2);
/**
* @brief This function will find the power of 2 or multiple of aligned number
* @author Sunil Kumar
* @param addr: address
* @param alignedNum: aligned number
* @return aligned address
* @date 16/7/2019
*/
uint32_t findPowerOfNumberedAddress(uint32_t addr, uint32_t alignedNum);
/**
* @brief This function will allocate the address aligned for the given alignedNumber
* @author Sunil Kumar
* @param alignedNum: aligned number
* @param numOfBytes: number of bytes to be allocated
* @return aligned address
* @date 16/7/2019
*/
void *aligned_malloc(uint32_t alignedNumber, uint32_t numOfBytes);
/**
* @brief This function will find the actual address for given address in
* doubly linked list
* @author Sunil Kumar
* @param cur_addr: pointer to the address to be freed
* @return 0 if memory free is successful; -1 otherwise
* @date 16/7/2019
*/
int32_t aligned_free(void *cur_addr);
