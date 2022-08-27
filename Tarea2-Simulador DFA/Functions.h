#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define INPUT_LENGTH 10
#define INP_RULE_LGTH 32
#define STR_LENGTH 10000
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct TransitionRule{
    int currState, newState;
    char symbol;
};
struct TransitionRule* validRule(char* rule);
void setTable(char table[][129], int numStats);
bool fillTable(char stateTable[][129], int numStats, int numSymb);
bool setAcpStates(char stateTable[][129], int numStats);
bool DFA(char stateTable[][129]);
int transitionFunction(int currState, char symbol);
#endif