#include"assembly_functions.h"

void initialize_memory(char** memory,int max_len){

    for(int i = 0;i<SIZE;i++){
        *(memory+i) = (char*)malloc(max_len*sizeof(char));
        *(*(memory+i)+0) = '0';
    }

}

void initialize_reg(){
    for(int i=0;i<REG_SIZE;i++){
        reg[i] = 0;
    }
}

void store_into(FILE *fd,char** memory){

    if(fd){
        printf("FILE opened\n");
    }
    else{
        printf("FILE not opened\n");
        exit(1);
    }

    while(!feof(fd)){
        char ch;
        char command[70];
        int i = 0;
        
        while((ch = fgetc(fd)) != '\n' && !feof(fd) ){
            command[i] = ch;
            i++;
        }
        command[i] = '\n';

        if(command[0] == '#' || command[0] == '\n'){
            //printf(" --> COMMENTED\n");
            continue;
        }
        else{
            int mem_address;

            int k = 0;
            char *num = (char*)malloc(10*sizeof(char));
            while((command[k] >= '0' && command[k] <= '9')){        // || command[k] == ' '
                *(num + k) = command[k];
                //printf(" --> COMMENTED\n");
                k++;
            }
            *(num+k) = '\0';

            while(command[k] == ' '){       //skip spaces...
                k++;
            }

            mem_address = char_toint(num);
            //printf("mm = %d\n",mem_address);

            //store in the memory...
            int j = 0;
            while(command[k] != '\n'){
                *(*(memory+mem_address)+j) = command[k];
                j++;
                k++;
            }
            *(*(memory+mem_address)+j) = '\0';
        }

    }

}

void print_memory(char** memory){

    printf("\n{ ");
    for(int i = 0;i<SIZE;i++){
        if(memory[i][0] == '\0'){
            printf("[ %d : 0 ] ,",i);
        }
        else if(memory[i][0] != '0'){
            printf("[ %d : %s ] ,",i,memory[i]);
        }
        else if(memory[i][0] == '0'){
            printf("[ %d : EMPTY ] ,",i);
        }
        if(i == SIZE-1){
            printf("\b\b");
        }          
    }
    printf(" }\n");

}

void print_registers(int* reg){

    printf("\n{ ");
    for(int i = 0;i<REG_SIZE;i++){
        printf("%s = %d ,",reg_names[i],reg[i]);
        if(i ==REG_SIZE-1){
            printf("\b\b");
        }
    }
    printf(" }\n");
}

void op_run(int mem){
    //memory[mem]
    //printf("\nopcode is = %s\n\n",memory[mem]);

    char opcode[10],arg1[10],arg2[10];

            int j = 0,k = 0;
            while(memory[mem][k] != ' ' && memory[mem][k] != '\0'){
                *(opcode + j) = memory[mem][k];
                //printf("%c",*(opcode + j));
                j++;
                k++;
            }
            *(opcode + j) = '\0';
            //printf("\n");

            while(memory[mem][k] == ' '){       //skip spaces...
                k++;
            }

            j = 0;
            while(memory[mem][k] != ' ' && memory[mem][k] != '\0'){
                *(arg1 + j) = memory[mem][k];
                //printf("%c",*(arg1 + j));
                j++;
                k++;
            }
            *(arg1 + j) = '\0';
            //printf("\n");

            while(memory[mem][k] == ' '){       //skip spaces...
                k++;
            }

            j = 0;
            while(memory[mem][k] != ' ' && memory[mem][k] != '\0'){
                *(arg2 + j) = memory[mem][k];
                //printf("%c",*(arg2 + j));
                j++;
                k++;
            }
            *(arg2 + j) = '\0';

            pass(opcode,arg1,arg2);	// have to implement
}
