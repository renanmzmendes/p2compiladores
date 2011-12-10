//
//  TabelasSintatico.h
//  Compilador
//
//  Created by Renan Mendes on 10/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TABELAS_SINTATICO_H
#define TABELAS_SINTATICO_H

#include "Token.h"
#include "ConstantesSintatico.h"

typedef struct {
	Estado estadoOrigem;
    tipoToken tipo;
	Estado estadoDestino;
    
} transicao;

static transicao transicoes[] = {
    // LOOP
    {LOOP_INICIAL, L_PAR, LOOP_1},
    {LOOP_3, R_PAR, LOOP_4_AC},
    
    // OP_DOIS
    {OP_DOIS_INICIAL, ID, OP_DOIS_1_AC},
    {OP_DOIS_1_AC, ID, OP_DOIS_1_AC},
    {OP_DOIS_1_AC, NUM, OP_DOIS_1_AC},
    
    // OP_UM
    {OP_UM_INICIAL, NUM, OP_UM_1_AC},
    {OP_UM_1_AC, NUM, OP_UM_1_AC},
    {OP_UM_1_AC, ID, OP_UM_1_AC},
    
    // REST_ADD
    {REST_ADD_INICIAL, PLUS, REST_ADD_1},
    
    // REST_CLR
    {REST_CLR_INICIAL, QUESTION_MARK, REST_CLR_1_AC},
    
    // REST_PL
    {REST_PL_INICIAL, TO_LEFT, REST_PL_1},
    
    // REST_PR
    {REST_PR_INICIAL, TO_RIGHT, REST_PR_1},
    
    // REST_SUB
    {REST_SUB_INICIAL, MINUS, REST_SUB_1},
    
    // Se receber pontuação volta pra CODE_INICAL
    {QUALQUER_ESTADO, PONTUACAO, CODE_INICIAL}
};

#define NUMTRANSICOES (sizeof(transicoes)/sizeof(*transicoes))

typedef struct {
    Estado estadoOrigem;
    tipoToken tipo;
    Estado estadoDestino;
    Estado estadoRetorno;
} chamadaSubmaquina;

// Na definição desta tabela de chamada de submáquina, introduzimos o token auxiliar
// NDEF que indica que a submáquina terá de ser chamada sem ser necessário olhar
// o tipo do token atual
static chamadaSubmaquina chamadas[] = {
    // CODE
    {CODE_INICIAL, ID, OPERATION_INICIAL, CODE_1_AC},
    {CODE_INICIAL, NUM, OPERATION_INICIAL, CODE_1_AC},
    {CODE_INICIAL, L_PAR, LOOP_INICIAL, CODE_1_AC},
    
    // LOOP
    {LOOP_1, NDEF, OP_DOIS_INICIAL, LOOP_2},
    {LOOP_2, NDEF, CODE_INICIAL, LOOP_3},
    
    // OP_DOIS
    {OP_DOIS_1_AC, QUESTION_MARK, REST_CLR_INICIAL, OP_DOIS_2_AC},
    {OP_DOIS_1_AC, MINUS, REST_SUB_INICIAL, OP_DOIS_2_AC},
    {OP_DOIS_1_AC, PLUS, REST_ADD_INICIAL, OP_DOIS_2_AC},
    {OP_DOIS_1_AC, TO_LEFT, REST_PL_INICIAL, OP_DOIS_2_AC},
    {OP_DOIS_1_AC, TO_RIGHT, REST_PR_INICIAL, OP_DOIS_2_AC},
    
    // OP_UM
    {OP_UM_1_AC, TO_RIGHT, REST_PR_INICIAL, OP_UM_2_AC},
    
    // OPERATION
    {OPERATION_INICIAL, NUM, OP_UM_INICIAL, OPERATION_1_AC},
    {OPERATION_INICIAL, ID, OP_DOIS_INICIAL, OPERATION_1_AC},
    
    // REST_ADD
    {REST_ADD_1, NUM, OP_UM_INICIAL, REST_ADD_2_AC},
    {REST_ADD_1, ID, OP_DOIS_INICIAL, REST_ADD_2_AC},
    
    // REST_PL
    {REST_PL_1, NUM, OP_UM_INICIAL, REST_PL_2_AC},
    {REST_PL_1, ID, OP_DOIS_INICIAL, REST_PL_2_AC},
    
    // REST_PR
    {REST_PR_1, ID, OP_DOIS_INICIAL, REST_PR_2_AC},
    
    // REST_SUB
    {REST_SUB_1, NUM, OP_UM_INICIAL, REST_SUB_2_AC},
    {REST_SUB_1, ID, OP_DOIS_INICIAL, REST_SUB_2_AC}    
};

#define NUMCHAMADAS (sizeof(chamadas)/sizeof(*chamadas))

#endif

