#include "Functions.h"

int main(){
    char numStats[INPUT_LENGTH], numSymb[INPUT_LENGTH];
    printf("Number of states of the DFA: ");
    fgets(numStats, INPUT_LENGTH, stdin);
    

    printf("Number of symbols: ");
    fgets(numSymb, INPUT_LENGTH, stdin);
    printf("\n\n");

    char stateTable[strtol(numStats, NULL, 10)][129];//Not error handling, DANGEROUS!!!!!!!!!!

    setTable(stateTable, strtol(numStats, NULL, INPUT_LENGTH));
    /*     | 0    1  ... 128
        --------------------
        q0 |[0] [-1] ... [0]
        q1 |[1]  [0] ... [-1]
        .  | .    .  ...  .
        .  | .    .  ...  .
        qn |[1] [-1] ... [2]

        col0, 0 reject state, 1 sceptance state
        col1-128, -1 not transition rule -> rejected, 0-n transition rule
        Transition rule (q0, a, q10) looks like stateTable[0,97]=10(ASCII a = 97)
    */

    printf("Write state,symbol,state for echa transition rule in the DFA \n");
    printf("Only numbers are valid for states \n");
    printf("Write . to stop \n\n");

    if(!fillTable(stateTable, strtol(numStats, NULL, 10), strtol(numSymb, NULL, 10)))
        return -1;//Wrong handling

    printf("\n Write acceptace states \n");
    printf(". to stop \n");

    if(!setAcpStates(stateTable, strtol(numStats, NULL, 10)))
        return -1;//Wrong handling
    
    system("clear");
    printf("Perfect! let's simulate the DFA \n");
    
    if(!DFA(stateTable))
        return -1;

    return 0;
}