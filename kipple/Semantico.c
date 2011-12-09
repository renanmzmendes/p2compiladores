//
//  Semantico.c
//  Compilador
//
//  Created by Renan Mendes on 12/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "stdio.h"
#include "Semantico.h"
#include "Token.h"
#include "stdlib.h"
#include "string.h"

#define MAX_LABEL 100
#define MAX_COMANDO 120
    
Token* lvalue; // Para guardar a variável da atribuição
Token* varUltimaExp; // Para guardar a variável temporária da expressão
                       // da última expressao calculada
Token* tempComp; // Variável temporária da comparação
Token* opcomp; // Guarda o token do operador de comparação

char* getEmptyString(int length) {
    char* s = (char*)malloc(length*sizeof(char));
    int i;
    for(i = 0; i < length; ++i) {
        s[i] = '\0';
    }
    
    return s;
}

// Funções para imprimir comandos em Java bytecode

void escreve(char* comando) {
    printf("%s\n", comando);
//    fprintf(out, "%s\n", comando);
}

void SC(char* subrotina, char* label) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "%s SC %s", label, subrotina);
    escreve(comando);
    free(comando);
}


void FIM() {
    escreve(".end method");
}

////////////////////////////

// Retorna o label/valor da variável temporária
char* criaVariavelTemporaria() {
    char* label = getEmptyString(MAX_LABEL);
    strcat(label, "TEMP");
    char* idx = getEmptyString(5);
    sprintf(idx, "%d", contaTemp);
    strcat(label, idx);
    //adicionarSimbolo(ID, label, label, escopoAtual);
    
    contaTemp++;
    
    return label;
}

//char* recuperaLabel(Token* t) {
//    char* label;
//    if(t->tipo == NUM) {
//        int c = atoi(t->valor);
//        label = recuperaLabelConstante(c, &constTab);
//        if(label == 0) {
//            printf("Constante %s nao presente na tabela de constantes", t->valor);
//            exit(1);
//        }
//    } else if(t->tipo == ID) {
//        label = recuperaLabelSimbolo(t->valor, escopoAtual);
//        if(label == 0) {
//            printf("Variavel '%s' nao declarada\n", t->valor);
//            exit(1);
//        }
//    }
//    
//    return label;
//}

// Gera código da operação e 
void geraCodigoOperacao(Token* topo, Token* abaixo, Token* operador) {
    // Cria variável temporária
//    char* labelTemp = criaVariavelTemporaria();
//    
//    char* labelTopo = recuperaLabel(topo);
//    char* labelAbaixo = recuperaLabel(abaixo);
    
//    char* comando = getEmptyString(MAX_COMANDO);
//    sprintf(comando, "%s %s", operador->valor, labelTopo);
//    escreve(comando);
////    free(comando);
//    
//    Token* t = (Token*) malloc(sizeof(Token));
//    t->tipo = ID;
//    strcpy(t->valor, labelTemp);
}


void executarAcaoSemantica(Estado anterior, Estado atual, Token* t) {
    AcaoSemantica a = decidirAcaoSemantica(anterior, atual);
    
    
    if(a == 0) {
        return;
    }
    

}

AcaoSemantica decidirAcaoSemantica(Estado anterior, Estado atual) {    
    int i;
    for(i = 0; i < NUMRELACOES; ++i) {
        if((relacoes[i].anterior == anterior || relacoes[i].anterior == QUALQUER_ESTADO) && (relacoes[i].atual == atual || relacoes[i].atual == QUALQUER_ESTADO)) {
            return relacoes[i].a;
        }
    }
    
    return 0;
}



void escreveFuncoesMvn() {    
    // OUTPUT
    // Instruções:
    // 1. A variável já vai estar no acumulador quando
    //    a subrotina for chamada
    // 2. A subroutine call (SC) é feita para o label
    //    "output"
	
	
}

void imprimeCabecalho() {
    escreve(".class public examples/MainProgram");
    escreve(".super java/lang/Object");
    escreve("");
    escreve(".method public <init>()V");
    escreve("\taload_0");
    escreve("\tinvokenonvirtual java/lang/Object/<init>()V");
    escreve("\treturn");
    escreve(".end method");
    escreve("");
    escreve("");
    escreve(".method public static main([Ljava/lang/String;)V");
}

void imprimeFim() {
    FIM();
}
