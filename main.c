#include"main_functions.h"

/*
 
 reminder...
                                                                        ***  N O T E  ***
Registers {a=0, b, c, d, e,f,sp,acc, pc, ivec, Int, timer, halt};     	   int --> Int

*/

int main(){

	// initialize the memory...
    	initialize_memory(memory,30);
    	initialize_reg();

	//open & store the assembly file
	FILE *fd = fopen("prog.asm","r");
    	store_into(fd,memory);
	fclose(fd);
	
	//run virtual machine
	runvm();

	print_memory(memory);
	print_registers(reg);


	printf("\nEnd of MY Virtual Machine\n");
	return 0;
}
