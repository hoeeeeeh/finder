#include "myheader.h"
int main(){
    int select;
    printf("1.복사/붙여넣기\t\t2.검색\t\t3.생성/제거\t\t4.이동\t\t5.권한 수정/정렬\n");
    scanf("%d",&select);

    switch(select){
        case 1:
            copy_main();
            break;
        case 2:
            search_main();
            break;
        case 3:
            mkrm_main();
            break;
        case 4:
            mv_main();
            break;
        case 5:
            sort_main();
            break;
    }
    return 0;
}