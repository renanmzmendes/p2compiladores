//
//  ConstantesSemantico.h
//  Compilador
//
//  Created by Renan Mendes on 12/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef CONSTANTES_SEMANTICO_H
#define CONSTANTES_SEMANTICO_H

typedef enum {
    
    ARMAZENA_VARIAVEL = 1,
    ARMAZENA_NUMERO,
    ARMAZENA_NUM_PUSH_LEFT,
    ARMAZENA_VAR_PUSH_LEFT,
    
    DEFINE_LOPERAND_NUM,
    DEFINE_LOPERAND_VAR,
    ARMAZENA_VAR_PUSH_RIGHT,
    
} AcaoSemantica;

#endif