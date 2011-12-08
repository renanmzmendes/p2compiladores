#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"

#define MAX 30
#define MAX_SIZE 50

int main() {
    
	Token *token;
	token = (Token*) malloc(sizeof(Token));
    
        
    
	FILE *entrada;
    entrada = fopen("/Users/renanmzmendes/newcompilador/Projeto/in.txt", "r");
    //verificando se arquivo existe
    if(entrada == NULL) {
        printf("arquivo nao encontrado\n\n");
        return 1;
    }
    
	
	InicializaLexico();

	//ImprimirTabelaLexico(); //se quiser ver a tabela de estados
	
    
	token = getNextToken(entrada);
	while (token->tipo != EoF) {
//        
//        // Procura transição
//        if(!procuraTransicao(estadoCorrente, token, &trans)) {
//            
//            // Se não encontrar transição procura chamada de submáquina
//            if(!procuraChamadaSubmaquina(estadoCorrente, token, &chamada)) {
//                // Caso não encontra chamada de submáquina, verifica se é estado final,
//                // se for aceita, senão dá erro
//                if(estadoFinal(estadoCorrente)) {       
//                    estadoAnterior = estadoCorrente;
//                    estadoCorrente = desempilha();
//                    executarAcaoSemantica(estadoAnterior, estadoCorrente, token);
//
//                } else {
//                    printf("Erro no reconhecimento de sintaxe, linha %d", token->linha);
//                    getchar();
//                    exit(1);
//                }
//            } else { // Se acha chamada de submáquina
//                estadoAnterior = estadoCorrente;
//                estadoCorrente = chamada.estadoDestino;
//                executarAcaoSemantica(estadoAnterior, estadoCorrente, token);
//                empilha(chamada.estadoRetorno);
//            }
//            
//        } else { // Se encontrar transição
//            estadoAnterior = estadoCorrente;
//            estadoCorrente = trans.estadoDestino;    
//            executarAcaoSemantica(estadoAnterior, estadoCorrente, token);
//            token = getNextToken(entrada);
//            
//        }
	}
    
    // Dump das variáveis e constantes no fim do programa
	//declararVariaveisConstantes();	
	//escreveFuncoesMvn();
	//imprimeFim();
	
    free(token);
	return 0;
}
