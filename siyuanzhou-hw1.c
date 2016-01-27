//  Siyuan Zhou
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

void hex_recursion(char input[], int n){
    if (*input == '\0')
        return;
    hex_recursion(input + 2, n + 1);
    input[1] = strtol(input, NULL, 16);
    *input = '\0';
}

void hextoAB(int type){
    printf("Enter your hex input.\n");
    char input[100];
    getchar();
    fgets(input,100,stdin);
    if(type == 1){
        int i;
        hex_recursion(input, 0);
        for (i = 1; input[i] != '\0'; i += 2){
            printf("%c", (unsigned char)input[i]);
        }
    }
    else if(type == 2){
        int n = 0;
        while(input[n]){
            switch(input[n]){
                case '0': printf("0000"); break;
                case '1': printf("0001"); break;
                case '2': printf("0010"); break;
                case '3': printf("0011"); break;
                case '4': printf("0100"); break;
                case '5': printf("0101"); break;
                case '6': printf("0110"); break;
                case '7': printf("0111"); break;
                case '8': printf("1000"); break;
                case '9': printf("1001"); break;
                case 'A': printf("1010"); break;
                case 'B': printf("1011"); break;
                case 'C': printf("1100"); break;
                case 'D': printf("1101"); break;
                case 'E': printf("1110"); break;
                case 'F': printf("1111"); break;
            }
            n++;
        }
    }
    puts("");
}

void alphatoHB(int type){
    char input[100];
    printf("Enter your alpha input.\n");
    int initial=0;
    getchar();
    fgets(input,100,stdin);
    if(type == 1){
        while(input[initial] && input[initial]!= '$'){
            printf("%02X",input[initial++]);
        }
    }
    else if(type == 2){
        char *pointer;
        for(pointer = input; *pointer != '\0'; pointer++){
            if(*pointer != '$' && *pointer != '\n'){
                unsigned i, x = (sizeof(*pointer) * CHAR_BIT) - 1;
                for (i = 0; i <= x; i++) {
                    printf("%d",(*pointer >> (x-i)) & 1);
                }
            }
        }
    }
    puts("");
}

void bintoHA(int type){
    printf("Enter your bin input.\n");
    if(type == 1){
        char bininput[100];
        scanf("%s",bininput);
        char hex[100];
        int temp, i=0,j = 0;
        while(bininput[i] && bininput[i] != '$'){
            bininput[i] = bininput[i] -48;
            ++i;
        }
        --i;
        while(i-2>=0){
            temp =  bininput[i-3] *8 + bininput[i-2] *4 +  bininput[i-1] *2 + bininput[i] ;
            if(temp > 9)
                hex[j++] = temp + 55;
            else
                hex[j++] = temp + 48;
            i=i-4;
        }
        if(i ==1)
            hex[j] = bininput[i-1] *2 + bininput[i] + 48 ;
        else if(i==0)
            hex[j] =  bininput[i] + 48 ;
        else
            --j;
        while(j>=0){
            printf("%c",hex[j--]);
        }
    }
    else if(type == 2){
        int i, sum =0;
        char input;
        scanf(" %c", &input);
            while(input != '$') {
                for(i = 7; i >=0; i--) {
                    if(input == '1') {
                        sum += pow(2, i);
                    }
                    scanf("%c", &input);
                }
                printf("%c", sum);
                sum = 0;
            }
    }
    puts("");
}

void sameinput_output(char input){
    char Input[100];
    int initial=0;
    switch(input){
        case 'H':
            printf("Enter your hex input.\n");
            break;
        case 'A':
            printf("Enter your alpha input.\n");
            break;
        case 'B':
            printf("Enter your bin input.\n");
            break;
    }
    getchar();
    fgets(Input,100,stdin);
    while(Input[initial] && Input[initial]!= '$'){
        printf("%c",Input[initial++]);
    }
    puts("");
}

int main(){
    char input,output;
    printf("Welcome to the Coder!\n");
    while(input != 'Q'){
        printf("Choose Input (H,A,B,Q): ");
        scanf(" %c", &input);
        if(input != 'Q'){
            printf("Choose Output (H,A,B): ");
            scanf(" %c", &output);
            if(input == 'H' && output == 'A')
                hextoAB(1);
            else if(input == 'H' && output == 'B')
                hextoAB(2);
            else if(input == 'A' && output == 'H')
                alphatoHB(1);
            else if(input == 'A' && output == 'B')
                alphatoHB(2);
            else if(input == 'B' && output == 'H')
                bintoHA(1);
            else if(input == 'B' && output == 'A')
                bintoHA(2);
            else if(input == output)
                sameinput_output(input);
        }
    }
}

