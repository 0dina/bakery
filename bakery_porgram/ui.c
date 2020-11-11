//
//  ui.c
//  bakery_porgram
//
//  Created by 최서영 on 2020/11/09.
//

#include <stdio.h>
#include "ui.h"



void showButton(UI_BUTTON *p){

    gotoxy(p->x,p->y);
    printf("%s\n",p->shape[0]);
    
    gotoxy(p->x,p->y+1);
    printf("%s\n",p->shape[1]);
    
    gotoxy(p->x,p->y+2);
    printf("%s\n",p->shape[2]);
    
}

void showInputBox(UI_INPUT_TEXT *p){
    
    gotoxy(p->x,p->y);
    printf("%s\n",p->text);
    
    gotoxy(p->x,p->y+1);
    printf("%s\n",p->shape[0]);
    
    gotoxy(p->x,p->y+2);
    printf("%s\n",p->shape[1]);
    
    gotoxy(p->x,p->y+3);
    printf("%s\n",p->shape[2]);
    
    //goto cursor to input area
    gotoxy(33,21);  //gotoxy(p->x+1,p->y+2);
    
    
    
}

