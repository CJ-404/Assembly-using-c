#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define SIZE 100	// maximum size of the memory... 
#define REG_SIZE 13

enum Registers {a=0, b, c, d, e,f,sp,acc, pc, ivec, Int, timer, halt};
char reg_names[REG_SIZE][10] = {"a","b","c","d","e","f","sp","acc","pc","ivec","Int","timer","halt"};


int reg[REG_SIZE];
char *memory[SIZE];
