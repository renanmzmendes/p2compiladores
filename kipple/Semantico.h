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
static int contaIfs = 0;
static int contaExp = 0;
static int contaTemp = 0;
static int contaComp = 0;
FILE* out;

stackT pilhaIfs;
stackT pilhaElses;
stackT pilhaWhiles;

//stackToken pilhaOperadores;
//stackToken pilhaOperandos;
stackT pilhaExpressoes;


void executarAcaoSemantica(Estado anterior, Estado atual, Token* t);
AcaoSemantica decidirAcaoSemantica(Estado e, Estado atual);

void imprimeCabecalho();
void declararVariaveisConstantes();
void escreveFuncoesMvn();
void imprimeFim();



// Tabela de relação entre estados correntes e ações semânticas

typedef struct {
    Estado atual;
    Estado anterior;
    AcaoSemantica a;
} EstadoAcao;

static EstadoAcao relacoes[] = {
    
    
};

#define NUMRELACOES (sizeof(relacoes)/sizeof(*relacoes))

#endif