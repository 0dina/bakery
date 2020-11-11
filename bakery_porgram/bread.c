//
//  bread.c
//  bakery_porgram
//
//  Created by 최서영 on 2020/11/03.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "bread.h"
#include "ui.h"


//#define clear()


UI_BUTTON ButtonBuy={
    1,40,
    {{"╭―――――――――――――――――╮"},
     {"│   1. 구매하기     │"},
     {"╰―――――――――――――――――╯"}}
};

UI_BUTTON ButtonSearch={
    1,45,
    {{"╭―――――――――――――――――╮"},
     {"│   2. 검색하기     │"},
     {"╰―――――――――――――――――╯"}}
};







void DataLoad(BREAD_DATA *ptr, char *number, char *name, int price, char *preference,int count){
    strcpy(ptr->number, number);
    strcpy(ptr->name, name);
    ptr->price = price;
    strcpy(ptr->preference, preference);
    ptr->count = count;
}

void ContactMenuByPointer(BREAD_DATA *p){
    printf("%s : %s : %d : %s : %d \n", p->number, p->name,p->price, p->preference, p->count);
}

int MainData(BREAD_DATA *ptr, int NumOfpang){
    int select;

    
printf("██████╗  █████╗ ██╗  ██╗███████╗██████╗ ██╗   ██╗\n");
printf("██╔══██╗██╔══██╗██║ ██╔╝██╔════╝██╔══██╗╚██╗ ██╔╝\n");
printf("██████╔╝███████║█████╔╝ █████╗  ██████╔╝ ╚████╔╝\n");
printf("██╔══██╗██╔══██║██╔═██╗ ██╔══╝  ██╔══██╗  ╚██╔╝\n");
printf("██████╔╝██║  ██║██║  ██╗███████╗██║  ██║   ██║\n");
printf("╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝   ╚═╝\n");
    system('clear');
                        
    printf("번호 |  빵이름    |  가격  |   선호도 | 판매량 \n");
    for(int i=0; i<NumOfpang; i++){
        ContactMenuByPointer(ptr+i);
    }

           
    
    
printf(" ____  _____ ____  _   _  \n");
printf("|    || ___ |  _ || | | | \n");
printf("| | | | ____| | | | |_| | \n");
printf("|_|_|_|_____)_| |_|____/ \n");
    
/*
    printf("╭―――――――――――――――――╮ \n"
           "│   1. 구매하기     │ \n"
           "╰―――――――――――――――――╯\n");
    
    
    printf("╭―――――――――――――――――╮ \n");
    printf("│   2. 검색하기     │ \n");
    printf("╰―――――――――――――――――╯\n");
*/
    showButton(&ButtonBuy);
    showButton(&ButtonSearch);
    
    
    printf("╭―――――――――――――――――╮ \n");
    printf("│   3. 등록하기     │ \n");
    printf("╰―――――――――――――――――╯\n");
    printf("╭―――――――――――――――――╮ \n");
    printf("│   4. 정산하기     │ \n");
    printf("╰―――――――――――――――――╯\n");
    printf("╭―――――――――――――――――╮ \n");
    printf("│   0. 취소하기     │ \n");
    printf("╰―――――――――――――――――╯\n");
       
  /*  printf("1. 구매하기 \n");
    printf("2. 검색하기 \n");
    printf("3. 등록하기 \n");
    printf("4. 정산하기 \n");
    printf("0. 나가기 \n");
    printf("메뉴를 선택햐세요. 0번누르면 종료");*/
    
    scanf("%d", &select);

    if(select > 4)
    printf("없는 메뉴 입니다.\n");

    return select;
}

int addUser(BREAD_DATA AddrInfo[], int i){

  int result;
  char cmd[10];

    char name[20];
    char number[20];
    int price;
    char preference[10];
    
    printf("빵이름을 입력하세요: ");
    scanf("%s", &name[0] );
    printf("빵번호를 입력하세요: ");
    scanf("%s", &number[0]);
    printf("가격을 입력하세요: ");
    scanf("%d", &price );
    printf("선호도 입력하세요: ");
    scanf("%s", &preference[0]);

  printf("등록을 하시겠습니까? (yes/no) ");
  scanf("%s", &cmd[0]);

  if(  strcmp(cmd, "yes") == 0){

    strcpy(AddrInfo[i].name, name);
    strcpy(AddrInfo[i].number, number);

    printf("등록되었습니다.\n");
    result = 1;
  }
  else{
    printf("취소 되었습니다. \n");
    result =0;
  }

  return result;
    
}

//int calculate()


int search(BREAD_DATA breads[], char searchMethod, char *breadNumber)
{
    char name[20];
    int i=0;
    if(searchMethod == 'n'){
        printf("빵 입력: ");
        scanf("%s", &name[0]);
        
        while(strcmp(breads[i].name, name) != 0){
            i++;
        }
        printf("__________________________________________\n");
        printf("이름 : %s 번호 : %s  가격 : %d 선호도 : %s 판매량 : %d  \n ",
                breads[i].name,breads[i].number,breads[i].price,breads[i].preference,breads[i].count);
     
        printf("__________________________________________\n");
    }
    else if(searchMethod == 'b'){
        while(strcmp(breads[i].number, breadNumber) != 0){
            i++;
        }
        
    }
    
    return i;

}


int buyBread(BREAD_DATA breads[]){

    int result;
    char cmd[10];
    int price=0;
    char number[20];
    int count;
    int dataNumber;

    while(1){
        printf("빵번호를 입력하세요: ");
        scanf("%s", &number[0]);
        printf("몇 개 구매하실건가요: ");
        scanf("%d", &count);

        dataNumber=search(breads, 'b', &number[0]);

        price = price + breads[dataNumber].price * count ;
        printf("총 %d 원 입니다",price);

        printf("구매를 마치시겠습니까? (yes/no) ");
        scanf("%s", &cmd[0]);

        if(  strcmp(cmd, "yes") == 0){

        // strcpy(AddrInfo[i].name, name);
        // strcpy(AddrInfo[i].number, number);

         printf("구매가 완료됐습니다. 감사합니다.\n");
         result = 1;
         breads[dataNumber].count = breads[dataNumber].count + count;
           break;
        }
        else{
         //printf("취소 되었습니다. \n");
      // 질문 계속
         result =0;
        }
    }
    return result;
     
 }
