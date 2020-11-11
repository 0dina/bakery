//
//  ui.c
//  bakery_porgram
//
//  Created by 최서영 on 2020/11/09.
//

#include <stdio.h>
#include "ui.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

void showButton(UI_BUTTON *p){
    
    int x,y;
    x =p->x;
    y = p->y;
    gotoxy(x,y);
    printf("%s\n",p->shape[0]);
    
    gotoxy(p->x,p->y+1);
    printf("%s\n",p->shape[1]);
    
    gotoxy(p->x,p->y+2);
    printf("%s\n",p->shape[2]);
    
}
