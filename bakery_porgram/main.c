//
//  main.c
//  bakery_porgram
//
//  Created by 최서영 on 2020/10/29.
//
#include <stdio.h>
#include <string.h>
#include "bread.h"
#include "ui.h"
#include "pthread.h"

int  NumOfpang = 7;





void * test(void *data)
{
    int i=0;
    char bar[102];
    memset(bar, 0, sizeof(bar));
    const char *lable = "|/-\\";
    
    while(1)
    {
        MainData((BREAD_DATA *)data, NumOfpang);
    }
    return (void *)0;
}









int main(){
    int result;
    
    int value =0;
    BREAD_DATA breads[10] = { {"chocosora", "123", 2500, "★★★★☆", 20, 0 },
                             {"soboropan", "124", 2000, "★★☆☆☆", 20, 0 },
                             {"melonpang", "125", 3500, "★★★★★", 20, 0 },
                             {"gamjapang", "126", 2500, "★★☆☆☆", 20, 0 },
                             {"raspberry", "127", 3000, "★★★★☆", 20, 0 },
                             {"coocookie", "128", 2000, "★★★☆☆", 20, 0 },
                             {"creamchee", "129", 3500, "★★★★★", 20, 0 } };
   
    
    
    pthread_t thread_t;
    int status;
    
    clear();
    sleep(2);
    
    if(pthread_create(&thread_t,NULL, test, (void * )&breads)<0)
    {
        perror("thread create error:");
        return(0);
    }
   
    
    
    
    
    while(1){
        
        value = getMenuNumber();
        printf("value: %d", value);
        sleep(2);
       // value = MainData(&breads[0], NumOfpang);
       
        if(value == 3){ //추가함수
            result = addUser(breads, NumOfpang);
            if( result == 1)
            {
                NumOfpang++;
            }
        }
        
        else if(value == 2){ //검색 함수호출
            search(breads, 'n',0);
        }
        else if(value == 1){
            buyBread(breads);
        }
            
        else if(value == 4){ //정산하기
           //추가해야함
        }
        
        else if(value == 0){
                break;
        }
        else{
            printf("잘못된 명령을 입력하였습니다 다시입력\n");
        }
        
    }
    printf("Have a nice day^^");
    
}

