#include"main_functions.h"

/*
 
 reminder...
                                                                        ***  N O T E  ***
Registers {a=0, b, c, d, e,f,sp,acc, pc, ivec, Int, timer, halt};     	   int --> Int

*/


void runvm(){

    while(!reg[halt]){
        int mem = reg[pc];
        op_run(mem);

        reg[timer] -= 1;
        if(reg[Int] == 1 && reg[timer] == 0){
            reg[sp] += 1;
            //memory[reg[sp]] = reg[pc];        --> N O T E ....
            strcpy(memory[reg[sp]],int_Tochar(reg[pc]));
            reg[pc] = reg[ivec];
            reg[Int] = 0;
        }
    }
}

int main(){

	// initialize the memory...
    initialize_memory(30);
    initialize_reg();

	//open & store the assembly file
	FILE *fd = fopen("assembly.asm","r");
    store_into(fd,memory);
	fclose(fd);
	
	//run virtual machine
	runvm();

	print_memory();
	print_registers();


	printf("\nEnd of MY Virtual Machine\n");
	return 0;
}
