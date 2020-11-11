//
//  ui.h
//  bakery_porgram
//
//  Created by 최서영 on 2020/11/09.
//

#ifndef ui_h
#define ui_h

typedef struct{
    int x;
    int y;
    
    char shape[3][80];

    
}UI_BUTTON;

void showButton(UI_BUTTON *p);

#endif /* ui_h */
