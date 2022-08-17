#include <stdio.h>
void numVer(char **str){
    printf("|num:");
    while(**str){
        printf("%c", **str);
        if(*(*str+1) > 45 && *(*str+1) < 58){
            (*str)++;
        }else{
            break;
        }
    }
    printf("|");
}
int main(){
    char *str;
    scanf("%[^\n]s",str);
    while (*str){
        char currCh = *str;
        if(currCh == '('){
            printf("%s", "|rpts:(|");
        }else if (currCh == ')'){
            printf("%s", "|lpts:)|");
        }else if (currCh == '+'){
            printf("%s", "|sig:+|");
        }else if (currCh == '-'){
            printf("%s", "|sig:-|");
        }else if(currCh > 45 && currCh < 58){
            numVer(&str);        
        }else if(currCh != ' '){
            printf("|unw:%c|", currCh);
        }
        str++;
    }
	return 0;
}
