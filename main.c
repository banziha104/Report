#include <stdio.h>

typedef struct OrderedPair{//순서 쌍 선언
    int x;
    int y;
} OrderedPair;
struct OrderedPair instance[6];
struct OrderedPair R[3];

int MAX_INT = 4;
int MIN_INT = 1;

int main() {
     // 순서쌍 6개를 가진 S 선언
    instance[0].x = 1; instance[0].y = 1;  //예 1
    instance[1].x = 1; instance[1].y = 2;
    instance[2].x = 2; instance[2].y = 1;
    instance[3].x = 2; instance[3].y = 2;
    instance[4].x = 2; instance[4].y = 3;
    instance[5].x = 3; instance[5].y = 4;


//    instance[0].x = 1; instance[0].y = 1; // 예 2
//    instance[1].x = 1; instance[1].y = 2;
//    instance[2].x = 2; instance[2].y = 1;
//    instance[3].x = 2; instance[3].y = 2;
//    instance[4].x = 2; instance[4].y = 3;
//    instance[5].x = 3; instance[5].y = 4;
//
//    instance[0].x = 1; instance[0].y = 1;
//    instance[1].x = 1; instance[1].y = 2; //예 3
//    instance[2].x = 2; instance[2].y = 1;
//    instance[3].x = 2; instance[3].y = 2;
//    instance[4].x = 2; instance[4].y = 3;
//    instance[5].x = 3; instance[5].y = 4;

    R[0].x = 1; R[0].y = 2;
    R[1].x = 2; R[1].y = 1;
    R[2].x = 1; R[2].y = 1;
    getDomRan();
    getSum();
    isEqual();
    return 0;
}

 void getDomRan(){ //정의역과 치역
     for (int i = 0; i < 6; ++i) {
         for (int j = 0; j < 3; ++j) {
             if(instance[i].x== R[j].x && instance[i].y == R[j].y){//정의역이면
                 printf("%d,%d",R[j].x,R[j].y);
             }else{        //치역이면
                 printf("%d,%d",R[j].x,R[j].y);
             }
         }
     }
}

void getSum(){                                  //합성관계
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(instance[i].y == instance[j].x){
                printf("%d",instance[j].y);
            }
        }
    }
}

void isEqual(){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if(instance[i].x==instance[j].y && instance[i].y == instance[i].x) printf("대칭적"); //
            else if(instance[i].x == instance[j].y && instance[j].x == instance[i].y) printf("반사적"); // 반사적
            else if(instance[i].x == instance[j].y && instance[j].y == instance[i].x) printf("전이적"); //전이적
            else if(instance[i].x==instance[j].y && instance[i].y == instance[i].x) printf("반대칭적"); //반대칭적
         }
    }
}