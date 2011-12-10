/*
 *  Lexico.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 15/10/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#define NumEstados 8
#define QTDE_Palavras_Reservadas 10

static int linha = 0;
static int coluna = 0;
static char ch='\0';

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lexico.h"


Token *getNextToken(FILE *inputFile){
	if (ch == '\0') {// se é primeira chamada Lê o primeiro caractere do arquivo de entrada
		ch = fgetc(inputFile);
		coluna++;
	}
	tipoToken tipo = NDEF;
	char BufferLexema[256] = {};
    
	
	if (ch == '#') {//se for comentário retorna tokem fim de linha
		while (ch != '\n') {
			ch = getc(inputFile);
		}
		tipo = PONTUACAO;
		BufferLexema[strlen(BufferLexema)] = ch;
		coluna=0;
		linha++;
	}else {
		BufferLexema[strlen(BufferLexema)] = ch;
		//identificando tiposToken
		if (ch == '\377') {
			tipo = EoF;
		}else if (ch == '>') {
			tipo = TO_RIGHT;
		}else if (ch == '<') {
			tipo = TO_LEFT;
		}else if (ch == '+') {
			tipo = PLUS;
		}else if (ch == '-') {
			tipo = MINUS;
		}else if (ch == ')') {
			tipo = R_PAR;
		}else if (ch == '(') {
			tipo = L_PAR;
		}else if (ch == ' ' || ch == '\t') {
			tipo = PONTUACAO;
		}else if (ch == '\n') {
			tipo = PONTUACAO;
			coluna=0;
			linha++;
		}else if (ch >= '0' && ch <= '9') {
			while (ch >= '0' && ch <= '9') {
				ch = getc(inputFile);
				BufferLexema[strlen(BufferLexema)] = ch;
			}
			tipo = NUM;
		}else if (ch >= 'a' && ch<= 'z' || ch >= 'A' && ch<= 'Z'){
			tipo = ID;
		}else if (ch == '?') {
			tipo = QUESTION_MARK;
		}else {
            tipo = ERRO;
            printf("ERRO LEXICO - caractere não identificado -> %c\nlinha: %d\ncoluna: %d",ch, linha, coluna);
            exit(1);
        }
	}
	
	if (tipo == NUM) {
		BufferLexema[strlen(BufferLexema)-1] = '\0';
	}else {
		ch = getc(inputFile);
		coluna++;
	}
	
	return criarToken(BufferLexema, tipo, linha, coluna);
}
