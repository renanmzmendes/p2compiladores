//
//  Semantico.h
//  Compilador
//
//  Created by Renan Mendes on 12/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SEMANTICO_H
#define SEMANTICO_H

#include "ConstantesSintatico.h"
#include "ConstantesSemantico.h"
#include "Token.h"
#include "stack.h"
#include "stdio.h"

#define MAX_ESCOPOS 50
#define MAX_TOKENS 50

typedef struct {
    Token* tokens[MAX_TOKENS];
    int tamanho;
} Tokens;

Tokens tokens;

static int contaWhiles = 0;
FILE* out;

stackT pilhaIfs;
stackT pilhaElses;
stackT pilhaWhiles;

//stackToken pilhaOperadores;
//stackToken pilhaOperandos;
stackT pilhaExpressoes;


void executarAcaoSemantica(Estado anterior, Estado atual, Submaquina ultimaSubmaquina, Token* t);
AcaoSemantica decidirAcaoSemantica(Estado e, Estado atual, Submaquina ultimaSubmaquina);

void inicializaSemantico();
void imprimeCabecalho();
void declararVariaveisConstantes();
void escreveFuncoesMvn();
void imprimeFim();



// Tabela de relação entre estados correntes e ações semânticas

typedef struct {
    Estado atual;
    Estado anterior;
    Submaquina submaquinaAnterior;
    AcaoSemantica a;
} EstadoAcao;

static EstadoAcao relacoes[] = {
    // OPERACAO DE PUSH LEFT
    {OP_DOIS_1_AC, OP_DOIS_INICIAL, OPERATION, ARMAZENA_VARIAVEL},
    {OP_UM_1_AC, OP_UM_INICIAL, OPERATION, ARMAZENA_NUMERO},
    {OP_UM_1_AC, OP_UM_INICIAL, REST_PL, ARMAZENA_NUM_PUSH_LEFT},
    {OP_DOIS_1_AC, OP_DOIS_INICIAL, REST_PL, ARMAZENA_VAR_PUSH_LEFT},
    
    // OPERACAO DE PUSH RIGHT
    {REST_PR_1, REST_PR_INICIAL, OP_UM, DEFINE_LOPERAND_NUM},
    {REST_PR_1, REST_PR_INICIAL, OP_DOIS, DEFINE_LOPERAND_VAR},
    {OP_DOIS_1_AC, OP_DOIS_INICIAL, REST_PR, ARMAZENA_VAR_PUSH_RIGHT},
    {OP_UM_1_AC, OP_UM_INICIAL, REST_PR, ARMAZENA_VAR_PUSH_RIGHT},
    
    // OPERACAO DE CLEAR
    {REST_CLR_1_AC, REST_CLR_INICIAL, OP_DOIS, CLEAR_STACK},
    
    // OPERACAO DE ADICAO
    {OP_DOIS_1_AC, OP_DOIS_INICIAL, REST_ADD, ARMAZENA_VAR_ADICIONA},
    {OP_UM_1_AC, OP_UM_INICIAL, REST_ADD, ARMAZENA_NUM_ADICIONA},
    
    // OPERACAO DE ADICAO
    {OP_DOIS_1_AC, OP_DOIS_INICIAL, REST_SUB, ARMAZENA_VAR_SUBTRAI},
    {OP_UM_1_AC, OP_UM_INICIAL, REST_SUB, ARMAZENA_NUM_SUBTRAI},
    
};

#define NUMRELACOES (sizeof(relacoes)/sizeof(*relacoes))

#endif