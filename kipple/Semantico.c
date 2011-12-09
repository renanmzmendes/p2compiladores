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

#define MAX_LABEL 200
#define MAX_COMANDO 200
    
Token* lvalue; // Para guardar a variável da atribuição
Token* varUltimaExp; // Para guardar a variável temporária da expressão
                       // da última expressao calculada
Token* tempComp; // Variável temporária da comparação
Token* opcomp; // Guarda o token do operador de comparação

int var;
int num;
int variaveis[26];

void inicializaSemantico() {
    out = fopen("/Users/renanmzmendes/p2compiladores/out.txt", "wr");

    int i;
    for(i = 0; i < 26; ++i) {
        variaveis[i] = 0;
    }
}

int getVarIndex(char v) {
    return v - 97;
}

char getVarByIndex(int i) {
    return i + 97;
}

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
    fprintf(out, "%s\n", comando);
}

void new(char* class) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tnew %s", class);
    escreve(comando);
    free(comando);
}

void aload(int i) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\taload %d", i);
    escreve(comando);
    free(comando);
}

void astore(int i) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tastore %d", i);
    escreve(comando);
    free(comando);
}


void bipush(int i) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tbipush %d", i);
    escreve(comando);
    free(comando);
}

void invokespecial(char* method, char* returnType) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tinvokespecial %s%s", method, returnType);
    escreve(comando);
    free(comando);
}

void invokevirtual(char* method, char* returnType) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tinvokevirtual %s%s", method, returnType);
    escreve(comando);
    free(comando);
}


void dup() {
    escreve("\tdup");
}

void pop() {
    escreve("\tpop");
}

////////////////////////////

void declaraPilha(int idx) {
//    new java/util/Stack
//	  dup
//    invokespecial java/util/Stack/<init>()V
//    astore <idx>
    
    new("java/util/Stack");
    dup();
    invokespecial("java/util/Stack/<init>()", "V");
    astore(idx);
}

int incluiVariavel(char v) {
    int varIdx = getVarIndex(v);
    if(variaveis[varIdx] == 0) {
        declaraPilha(varIdx);
        variaveis[varIdx] = 1;
    }
    
    return varIdx;
}


// Retorna o label/valor da variável temporária
char* criaVariavelTemporaria() {
    char* label = getEmptyString(MAX_LABEL);
    strcat(label, "TEMP");
    char* idx = getEmptyString(5);
//    sprintf(idx, "%d", contaTemp);
    strcat(label, idx);
    //adicionarSimbolo(ID, label, label, escopoAtual);
    
//    contaTemp++;
    
    return label;
}

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

void geraPushLeft(int idxVar1, int idxVar2) {
    // Imprime código que faz var1 < var2
//    char* comando = getEmptyString(MAX_COMANDO);
//    sprintf(comando,,)
}

void geraPushLeftNum(int idxVar, int num) {
    
//    aload <idxVar>
//    new java/lang/Integer
//    dup
//    bipush 100
//    invokespecial java/lang/Integer/<init>(I)V
//    invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
//    pop
    
    aload(idxVar);
    new("java/lang/Integer");
    dup();
    bipush(num);
    invokespecial("java/lang/Integer/<init>(I)", "V");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();
}

void geraPushRightNum(int num, int idxVar) {
    
    //    aload <idxVar>
    //    new java/lang/Integer
    //    dup
    //    bipush 100
    //    invokespecial java/lang/Integer/<init>(I)V
    //    invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
    //    pop
    
    aload(idxVar);
    new("java/lang/Integer");
    dup();
    bipush(num);
    invokespecial("java/lang/Integer/<init>(I)", "V");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();
}



void executarAcaoSemantica(Estado anterior, Estado atual, Submaquina ultimaSubmaquina, Token* t) {
    AcaoSemantica a = decidirAcaoSemantica(anterior, atual, ultimaSubmaquina);
    
    
    if(a == 0) {
        return;
    }
    
    if(a == ARMAZENA_VARIAVEL) {
        // Instancia nova pilha caso essa já não tenha
        // sido utilizada anteriormente no programa
        var = incluiVariavel(t->valor[0]);

    } else if(a == ARMAZENA_NUMERO) {
        num = atoi(t->valor);
        
    } else if(a == ARMAZENA_NUM_PUSH_LEFT) {
        num = atoi(t->valor);
        
        geraPushLeftNum(var, num);
    }
    

}

AcaoSemantica decidirAcaoSemantica(Estado anterior, Estado atual, Submaquina ultimaSubmaquina) {    
    int i;
    for(i = 0; i < NUMRELACOES; ++i) {
        if((relacoes[i].anterior == anterior || relacoes[i].anterior == QUALQUER_ESTADO) 
           && (relacoes[i].atual == atual || relacoes[i].atual == QUALQUER_ESTADO)
           && (relacoes[i].submaquinaAnterior == ultimaSubmaquina)) {
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
    escreve("\t.limit locals 40");
    escreve("\t.limit stack 30");
}

void imprimeFim() {
    escreve(".end method");
}
