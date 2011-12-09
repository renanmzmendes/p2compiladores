//
//  ConstantesSintatico2.h
//  Compilador
//
//  Created by Renan Mendes on 10/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef CONSTANTES_SINTATICO_H
#define CONSTANTES_SINTATICO_H

typedef enum {
    
    CODE_INICIAL = 1,
    CODE_1_AC,
    
    LOOP_INICIAL,
    LOOP_1,
    LOOP_2,
    LOOP_3,
    LOOP_4_AC,
    
    NUM_INICIAL,
    NUM_1_AC,
    
    OP_DOIS_INICIAL,
    OP_DOIS_1_AC,
    OP_DOIS_2_AC,
    
    OP_UM_INICIAL,
    OP_UM_1_AC,
    OP_UM_2_AC,
    
    OPERATION_INICIAL,
    OPERATION_1_AC,
    
    REST_ADD_INICIAL,
    REST_ADD_1,
    REST_ADD_2_AC,
    
    REST_CLR_INICIAL,
    REST_CLR_1_AC,
    
    REST_PL_INICIAL,
    REST_PL_1,
    REST_PL_2_AC,
    
    REST_PR_INICIAL,
    REST_PR_1,
    REST_PR_2_AC,
    
    REST_SUB_INICIAL,
    REST_SUB_1,
    REST_SUB_2_AC,
    
    STACK_ID_INICIAL,
    STACK_ID_1_AC,
    
    QUALQUER_ESTADO
    
    
} Estado;

typedef enum {
    CODE = 1,
    LOOP,
    OP_DOIS,
    OP_UM,
    OPERATION,
    REST_ADD,
    REST_CLR,
    REST_PL,
    REST_PR,
    REST_SUB,
} Submaquina;

#endif