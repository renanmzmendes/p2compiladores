//
//  Sintatico.c
//  Compilador
//
//  Created by Renan Mendes on 10/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Sintatico.h"
#include "TabelasSintatico.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

void empilha(Estado estadoRetorno) {
    StackPush(&pilhaEstado, estadoRetorno);
}

int desempilha() {
    return StackPop(&pilhaEstado);
}

int procuraTransicao(Estado estadoCorrente, Token* token, transicao* trans) {
    int i;
    for(i = 0; i < NUMTRANSICOES; ++i) {
        if(transicoes[i].estadoOrigem == estadoCorrente || transicoes[i].estadoOrigem == QUALQUER_ESTADO) {
            if(transicoes[i].tipo == token->tipo || transicoes[i].tipo == NDEF) {
                *trans = transicoes[i];
                return 1;
            }
        }
    }
    
    return 0;
}

int procuraChamadaSubmaquina(Estado estadoCorrente, Token* token, chamadaSubmaquina* chamada) {
    int i;
    for(i = 0; i < NUMCHAMADAS; ++i) {
        if(chamadas[i].estadoOrigem == estadoCorrente) {
            if(chamadas[i].tipo == token->tipo || chamadas[i].tipo == NDEF) {
                *chamada = chamadas[i];
                return 1;
            }
        }
    }
    
    return 0;
}

int estadoFinal(Estado estado) {
    if(estado == CODE_1_AC
       || estado == CODE_INICIAL
       || estado == LOOP_4_AC
       || estado == NUM_1_AC
       || estado == OP_DOIS_1_AC
       || estado == OP_DOIS_2_AC
       || estado == OPERATION_1_AC
       || estado == REST_ADD_2_AC
       || estado == REST_CLR_1_AC
       || estado == REST_PL_2_AC
       || estado == REST_PR_2_AC
       || estado == REST_SUB_2_AC
       || estado == STACK_ID_1_AC) {
        return 1;
    }
    
    return 0;
}

Submaquina obterSubmaquina(Estado estado) {
    if(estado == CODE_1_AC || estado == CODE_INICIAL) {
        return CODE;
    } else if(estado >= LOOP_INICIAL && estado <= LOOP_1) {
        return LOOP;
    } else if(estado >= OP_DOIS_INICIAL && estado <= OP_DOIS_2_AC) {
        return OP_DOIS;
    } else if(estado >= OP_UM_INICIAL && estado <= OP_UM_2_AC) {
        return OP_UM;
    } else if(estado == OPERATION_INICIAL || estado == OPERATION_1_AC) {
        return OPERATION;
    } else if(estado >= REST_ADD_INICIAL && estado <= REST_ADD_2_AC) {
        return REST_ADD;
    } else if(estado >= REST_CLR_INICIAL && estado <= REST_CLR_1_AC) {
        return REST_CLR;
    } else if(estado >= REST_PL_INICIAL && estado <= REST_PL_2_AC) {
        return REST_PL;
    } else if(estado >= REST_PR_INICIAL && estado <= REST_PR_2_AC) {
        return REST_PR;
    } else if(estado >= REST_SUB_INICIAL && estado <= REST_SUB_2_AC) {
        return REST_SUB;
    }
    
    return 0;
}

void semantico_tbd() {
    printf("SMP\n");
}