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

int charTonum(char x){
    switch(x){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;

    }
}

int numTochar(int x){
    switch(x){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        //case -1:
            //return '-';
        default:
            //printf("awlk-->%d , ",x);
            return '#';         //N O T E --> " H A N D L E    T H I S "

    }
}


int char_toint(char *num){
    int n=0;
    int res = 0,pow=1,negative = 0;
    if(*(num+0)=='-'){
        negative = 1;
        num = (num +1);
    }

    while(*(num+n) != '\0'){
        n++;
    }
    //printf("%d\n",n);
    for(int i=n-1;i>=0;i--){
        int number = charTonum(*(num+i));
        res = res + number *pow;
        pow *= 10;
    }
    if(negative){
        return -res;
    }
    return res;
}

char* int_Tochar(int x){                // N O T E --> H / W
    int negative = 0;
    if(x<0){
        negative = 1;
        x = -x;
    }
    char buffer[10];
    int r,i=0;
    while(x != 0){
        r = x%10;
        buffer[i] = numTochar(r);
        x /= 10;
        i++;
    }
    buffer[i] = '\0';
    char *res;
    int j;
    if(negative){
        i+=1;
        res = (char*)malloc((i+1)*sizeof(char));
        *(res+0) = '-';
        j=i-2;
    }
    else{
        res = (char*)malloc((i+1)*sizeof(char));
        j=i-1;
    }
    
    while(j >= 0){
        res[i-1-j] = buffer[j];
        //printf("buffer[%d] = %c\n",i-1-j,res[i-1-j]);
        j--;
    }
    res[i] = '\0';

    return res;
}


int stringtoenum(char *arr){
      if(strcmp(arr,"a")==0){
          //printf("\na\n");
          return 0;
      }
      else if(strcmp(arr,"b")==0){
          //printf("\nb\n");
          return 1;
      }
      else if(strcmp(arr,"c")==0){
          //printf("\nc\n");
          return 2;
      }
      else if(strcmp(arr,"d")==0){
          //printf("\nd\n");
          return 3;
      }
      else if(strcmp(arr,"e")==0){
          //printf("\ne\n");
          return 4;
      }
      else if(strcmp(arr,"f")==0){
          //printf("\nf\n");
          return 5;
      }
      else if(strcmp(arr,"sp")==0){
          //printf("\nsp\n");
          return 6;
      }
      else if(strcmp(arr,"acc")==0){
          //printf("\nacc\n");
          return 7;
      }
      else if(strcmp(arr,"pc")==0){
          //printf("\npc\n");
          return 8;
      }
      else if(strcmp(arr,"ivec")==0){
          //printf("\nivec\n");
          return 9;
      }
      else if(strcmp(arr,"int")==0){
          //printf("\nInt\n");
          return 10;
      }
      else if(strcmp(arr,"timer")==0){
          //printf("\ntimer\n");
          return 11;
      }
      else if(strcmp(arr,"halt")==0){
          //printf("\nhalt\n");
          return 12;
      }
}