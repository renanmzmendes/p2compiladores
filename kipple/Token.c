/*
 *  Token.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Token.h"

#define TRUE 1
#define FALSE 0

//cria o tal do token
Token *criarToken(char *Lexema, tipoToken	tipo, int linha, int coluna){
	Token *aux;
	aux = (Token *) malloc(sizeof(Token));
	
	strcpy(aux->valor, Lexema);
	aux->tipo = tipo;
	aux->linha = linha;
	aux->coluna = coluna;
	return (aux);
}