#include "Functions.h"

struct TransitionRule* validRule(char* rule){
    struct TransitionRule *rtnRule = malloc(sizeof (struct TransitionRule));

    char *token = strtok(rule, ",");
    if(token == NULL){
        free(rtnRule); 
        return NULL;
    }else{
        int currState = strtol(token, NULL, 10);
        if(currState == 0 && *token != '0' ){
            free(rtnRule);
            return NULL;
        }
        rtnRule->currState = currState;
    }

    token = strtok(NULL, ",");
    if(token == NULL || strlen(token) > 1){
        free(rtnRule);
        return NULL;
    }else{
        rtnRule->symbol = *token;
    }

    token = strtok(NULL, ",");
    if(token == NULL){
        free(rtnRule);
        return NULL;
    }else{
        int newState = strtol(token, NULL, 10);
        if(newState == 0 && *token != '0' ){
            free(rtnRule);
            return NULL;
        }
        rtnRule->newState = newState;
    }

    if (strtok(NULL, ",") != NULL){
        free(rtnRule);
        return NULL;
    }
    
   return rtnRule;
}
void setTable(char table[][129], int numStats){
    for (int i = 0; i < numStats; i++){
        for (int j = 0; j < 129; j++){
            table[i][j]=-1;
        }
        
    }
}
bool fillTable(char stateTable[][129], int numStats, int numSymb){
    char transRule[INP_RULE_LGTH];
    struct TransitionRule *decRule;
    for(int i=0;i<numStats*numSymb; i++){
        printf("Write the %d rule: ", i+1);
        fgets(transRule, INP_RULE_LGTH, stdin);

        if(*transRule == '.')
            return true;

        decRule = validRule(transRule);
        if(decRule == NULL){
            printf("Syntax Error");
            return false;
        }else{
            stateTable[decRule->currState][decRule->symbol] = decRule->newState;
        }
    }
    return true;
}
bool setAcpStates(char stateTable[][129], int numStats){
    char stateStr[INPUT_LENGTH];
    int state;
    for (int i = 0; i < numStats; i++){
        fgets(stateStr, INPUT_LENGTH, stdin);
        
        if(*stateStr == '.')
            return true;

        state = strtol(stateStr, NULL, 10);
        if(state == 0 && *stateStr != '0'){
            printf("Syntax error");
            return false;
        }
        stateTable[state][0]=1;
        

    }
    return true;
}
bool DFA(char stateTable[][129]){
    char startStateStr[INPUT_LENGTH], strDFA[STR_LENGTH];
    int startSatate;
    int currState, posHead;
    char respInp[INPUT_LENGTH];

    printf("Write the start state: ");
    fgets(startStateStr, INPUT_LENGTH, stdin);
    startSatate = strtol(startStateStr, NULL, 10);
    if(startSatate == 0 && *startStateStr != '0'){
        printf("Syntax error");
        return false;
    }

    do{    
        system("clear");
        printf("Write the string: ");
        fgets(strDFA, STR_LENGTH, stdin);

        currState = startSatate;
        posHead = 0;

        while (strDFA[posHead] !='\n'){
            currState = stateTable[currState][strDFA[posHead]];
            if(currState == -1){
                break;
            }
            posHead++;
        }

        if(stateTable[currState][0] == 1){
            printf("DFA accepts\n");
        }else{
            printf("DFA rejects\n");
        }
        printf("Try other input?(y/n) ");
        fgets(respInp, INPUT_LENGTH, stdin);
    }while(*respInp != 'n');
    
    return true;
}
