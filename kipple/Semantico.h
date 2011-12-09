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
    {OP_DOIS_1_AC, OP_DOIS_INICIAL, OPERATION, ARMAZENA_VARIAVEL},
    {OP_UM_1_AC, OP_UM_INICIAL, OPERATION, ARMAZENA_NUMERO},
    {OP_UM_1_AC, OP_UM_INICIAL, REST_PL, ARMAZENA_NUM_PUSH_LEFT},
    
};

#define NUMRELACOES (sizeof(relacoes)/sizeof(*relacoes))

#endif