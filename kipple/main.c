#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"

#define MAX 30
#define MAX_SIZE 50

#include "Sintatico.h"
#include "TabelasSintatico.h"

int main() {
    
	Token *token;
	token = (Token*) malloc(sizeof(Token));
    
        
    
	FILE *entrada;
    entrada = fopen("in.txt", "r");
    //verificando se arquivo existe
    if(entrada == NULL) {
        printf("arquivo nao encontrado\n\n");
        return 1;
    }
    
    StackInit(&pilhaEstado, MAX_SIZE);

	//ImprimirTabelaLexico(); //se quiser ver a tabela de estados
	
    Estado estadoCorrente = CODE_INICIAL;
    Estado estadoAnterior = 0;
	token = getNextToken(entrada);
	while (token->tipo != EoF) {
        
        transicao trans;
        chamadaSubmaquina chamada;
        
        // Procura transição
        if(!procuraTransicao(estadoCorrente, token, &trans)) {
            
            // Se não encontrar transição procura chamada de submáquina
            if(!procuraChamadaSubmaquina(estadoCorrente, token, &chamada)) {
                // Caso não encontra chamada de submáquina, verifica se é estado final,
                // se for aceita, senão dá erro
                if(estadoFinal(estadoCorrente)) {       
                    estadoAnterior = estadoCorrente;
                    estadoCorrente = desempilha();
                    //executarAcaoSemantica(estadoAnterior, estadoCorrente, token);
                    semantico_tbd();

                } else {
                    printf("Erro no reconhecimento de sintaxe, linha %d", token->linha);
                    getchar();
                    exit(1);
                }
            } else { // Se acha chamada de submáquina
                estadoAnterior = estadoCorrente;
                estadoCorrente = chamada.estadoDestino;
                //executarAcaoSemantica(estadoAnterior, estadoCorrente, token);
                semantico_tbd();
                empilha(chamada.estadoRetorno);
            }
            
        } else { // Se encontrar transição
            estadoAnterior = estadoCorrente;
            estadoCorrente = trans.estadoDestino;    
            //executarAcaoSemantica(estadoAnterior, estadoCorrente, token);
            semantico_tbd();
            token = getNextToken(entrada);
            
        }
	}
    
    // Dump das variáveis e constantes no fim do programa
	//declararVariaveisConstantes();	
	//escreveFuncoesMvn();
	//imprimeFim();
	
    free(token);
	return 0;
}
