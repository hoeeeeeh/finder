#include "myheader.h"

int main(){

    int aa=1;
    while(aa==1){
        int select;
        printf("1.복사/붙여넣기\t\t2.검색\t\t3.생성/제거\t\t4.이동\t\t5.권한 수정/정렬\t\t6.종료\n");
        scanf("%d",&select);

        if(select == 1){
            copy_main();
        }else if(select ==2){
            search_main();
        }else if(select ==3){
            mkrm_main();
        }else if(select ==4){
            mv_main();
        }else if(select ==5){
            sort_main();
        }else if(select ==6){
            break;
        }


        // switch(select){
        //     case 1:
        //         copy_main();
        //         // break;
        //     case 2:
        //         search_main();
        //         // break;
        //     case 3:
        //         mkrm_main();
        //         // break;
        //     case 4:
        //         mv_main();
        //         // break;
        //     case 5:
        //         sort_main();
        //         // break;
        //     case 6:
        //         break;
        // }
    }
    return 0;
}
