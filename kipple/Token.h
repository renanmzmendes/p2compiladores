/*
 *  Token.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#ifndef TOKEN_H
#define TOKEN_H

// quase todos não são usados, mas vou deixar para o caso de agente resolver usar um dia,
// os não usados tao abaixo de EoF.
typedef enum tiposToken {
	TO_LEFT,
	TO_RIGHT,
	PLUS,
	MINUS,
	L_PAR,
	R_PAR,
    QUESTION_MARK,
	PONTUACAO,
	
	NUM,
	ID,
	
	ERRO,
	EoF,

    NDEF
} tipoToken;

typedef struct token {
	tipoToken tipo;
	char valor[256];
	int linha;
	int coluna;
} Token;


Token *criarToken(char *Lexema,tipoToken tipo, int linha, int coluna);

#endif
