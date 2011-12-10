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

tipoToken tipoLOperand;

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

void iload(int i) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tiload %d", i);
    escreve(comando);
    free(comando);
}

void astore(int i) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tastore %d", i);
    escreve(comando);
    free(comando);
}

void istore(int i) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tistore %d", i);
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

void invokestatic(char* method, char* returnType) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tinvokestatic %s%s", method, returnType);
    escreve(comando);
    free(comando);
}

void invokevirtual(char* method, char* returnType) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tinvokevirtual %s%s", method, returnType);
    escreve(comando);
    free(comando);
}

void checkcast(char* typeName) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tcheckcast %s", typeName);
    escreve(comando);
    free(comando);
}

void ifne(int id) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tifne clear_%d", id);
    escreve(comando);
    free(comando);
}

void ifeq(int id) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tifeq clear_%d", id);
    escreve(comando);
    free(comando);
}

void fimclear(int id) {
    char* comando = getEmptyString(MAX_COMANDO);
    sprintf(comando, "\tclear_%d:", id);
    escreve(comando);
    free(comando);
}


void dup() {
    escreve("\tdup");
}

void pop() {
    escreve("\tpop");
}

void iadd() {
    escreve("\tiadd");
}

void isub() {
    escreve("\tisub");
}

void iconst_0() {
    escreve("\ticonst_0");
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

// Sempre faz recebe<fornece
void geraPushVar(int recebe, int fornece) {
    // Em Java tem que ser:
    // stack1.push(stack2.pop());
    //
    // O que se traduz para:
    // aload 1
    // aload 2
    // invokevirtual java/util/Stack/pop()Ljava/lang/Object;
    // invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object
    // pop
    
    aload(recebe);
    aload(fornece);
    invokevirtual("java/util/Stack/pop()", "Ljava/lang/Object;");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();
    
}

// Sempre faz idxVar<num
void geraPushNum(int idxVar, int num) {
    
//    aload <idxVar>
//    new java/lang/Integer
//    dup
//    bipush 100
//    invokespecial java/lang/Integer/<init>(I)V
//    invokevirtual java/util/Stack/push(Ljava/lang/Object;)Ljava/lang/Object;
//    pop
    
    aload(idxVar);
    bipush(num);
    invokestatic("java/lang/Integer.valueOf(I)", "Ljava/lang/Integer;");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();
}

void geraClear(int idxVar) {
    // Em java seria:
    // 
    // if(((Integer)stack.peek()).equals(0)) {
    //    stack.clear();
    // }
    
    aload(idxVar);
    invokevirtual("java/util/Stack.peek()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    iconst_0();
    invokestatic("java/lang/Integer.valueOf(I)Ljava/lang/Integer;", "");
    invokevirtual("java/lang/Integer.equals(Ljava/lang/Object;)", "Z");
    ifeq(contaIfs);
    aload(idxVar);
    invokevirtual("java/util/Stack.clear()", "V");
    fimclear(contaIfs);
}

// a+2
void geraAdicaoNum(int idxVar, int num) {
    // Em Java:
    // stack1.push((Integer) stack1.peek() + num);
    
    // Em bytecode:
    aload(idxVar);
    aload(idxVar);
    invokevirtual("java/util/Stack/peek()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    invokevirtual("java/lang/Integer/intValue()", "I");
    bipush(num);
    iadd();
    invokestatic("java/lang/Integer.valueOf(I)", "Ljava/lang/Integer;");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();


}

// a+2
void geraSubtracaoNum(int idxVar, int num) {
    // Em Java:
    // stack1.push((Integer) stack1.peek() + num);
    
    // Em bytecode:
    aload(idxVar);
    aload(idxVar);
    invokevirtual("java/util/Stack/peek()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    invokevirtual("java/lang/Integer/intValue()", "I");
    bipush(num);
    isub();
    invokestatic("java/lang/Integer.valueOf(I)", "Ljava/lang/Integer;");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();
    
    
}

// a+b
void geraAdicaoVar(int recebe, int fornece) {
    // Em Java:
    // stack1.push((Integer)stack.peek() + (Integer) stack2.pop());
    
    // Em bytecode:
    aload(recebe);
    aload(recebe);
    invokevirtual("java/util/Stack/peek()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    invokevirtual("java/lang/Integer.intValue()", "I");
    aload(fornece);
    invokevirtual("java/util/Stack/pop()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    invokevirtual("java/lang/Integer.intValue()", "I");
    iadd();
    invokestatic("java/lang/Integer.valueOf(I)", "Ljava/lang/Integer;");
    invokevirtual("java/util/Stack/push(Ljava/lang/Object;)", "Ljava/lang/Object;");
    pop();
}

// a+b
void geraSubtracaoVar(int recebe, int fornece) {
    // Em Java:
    // stack1.push((Integer)stack.peek() + (Integer) stack2.pop());
    
    // Em bytecode:
    aload(recebe);
    aload(recebe);
    invokevirtual("java/util/Stack/peek()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    invokevirtual("java/lang/Integer.intValue()", "I");
    aload(fornece);
    invokevirtual("java/util/Stack/pop()", "Ljava/lang/Object;");
    checkcast("java/lang/Integer");
    invokevirtual("java/lang/Integer.intValue()", "I");
    isub();
    invokestatic("java/lang/Integer.valueOf(I)", "Ljava/lang/Integer;");
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
        geraPushNum(var, num);
        
    } else if(a == ARMAZENA_VAR_PUSH_LEFT) {
        
        int loperand = var;
        var = incluiVariavel(t->valor[0]);
        geraPushVar(loperand, var);
        
    } else if(a == DEFINE_LOPERAND_NUM) {
        
        tipoLOperand = NUM;
        
    } else if(a == DEFINE_LOPERAND_VAR) {
        
        tipoLOperand = ID;
        
    } else if(a == ARMAZENA_VAR_PUSH_RIGHT) {
        
        if(tipoLOperand == NUM) {
            var = incluiVariavel(t->valor[0]);
            geraPushNum(var, num);
            
        } else {
            int loperand = var;
            var = incluiVariavel(t->valor[0]);
            geraPushVar(var, loperand);
            
        }
    } else if(a == CLEAR_STACK) {
        geraClear(var);
        
    } else if(a == ARMAZENA_NUM_ADICIONA) {
        num = atoi(t->valor);
        geraAdicaoNum(var, num);
        
    } else if(a == ARMAZENA_VAR_ADICIONA) {
        int loperand = var;
        var = incluiVariavel(t->valor[0]);
        geraAdicaoVar(loperand, var);
    } else if(a == ARMAZENA_NUM_SUBTRAI) {
        num = atoi(t->valor);
        geraSubtracaoNum(var, num);
        
    } else if(a == ARMAZENA_VAR_SUBTRAI) {
        int loperand = var;
        var = incluiVariavel(t->valor[0]);
        geraSubtracaoVar(loperand, var);
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
