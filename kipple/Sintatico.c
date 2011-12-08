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

void empilha(Estado estadoRetorno) {
    StackPush(&pilha, estadoRetorno);
}

int desempilha() {
    return StackPop(&pilha);
}

int procuraTransicao(Estado estadoCorrente, Token* token, transicao* trans) {
    int i;
    for(i = 0; i < NUMTRANSICOES; ++i) {
        if(transicoes[i].estadoOrigem == estadoCorrente) {
            if(transicoes[i].tipo == token->tipo && (!strcmp(transicoes[i].token, token->valor) || !strcmp("", transicoes[i].token)) || transicoes[i].tipo == NDEF) {
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
            if(chamadas[i].tipo == token->tipo && (!strcmp(chamadas[i].token, token->valor) || !strcmp("", chamadas[i].token)) || chamadas[i].tipo == NDEF) {
                *chamada = chamadas[i];
                return 1;
            }
        }
    }
    
    return 0;
}

int estadoFinal(Estado estado) {
    if(estado == CODE_1_AC
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