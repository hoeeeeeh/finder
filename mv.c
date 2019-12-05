//파일 이름 바꾸는 시스템콜 함수
#include "myheader.h"

int mv_main(){
        pid_t childpid;
        char oldpath[256];
        char newpath[256];
        strcpy(oldpath, finder("이동시키고 싶은 파일을 선택해주세요"));
        strcpy(newpath, finder("이동시키고 싶은 위치를 선택해주세요"));
        childpid = fork();
        if(childpid == -1){
                perror("Failed to fork");
                return 1;
        }

        if(childpid==0){
        //      printf("기존 파일 명 : "); scanf("%s",oldpath);
        //      printf("중간 ");
        //      printf("바꿀 파일 명 : "); scanf("%s",newpath);

                execl("/bin/mv","mv",oldpath,newpath,NULL);
                perror("Child failed to rename");
                return 1;
        }
        if(childpid != wait(NULL)){
                perror("Parent failed to wait");
                return 1;
        }
        return 0;
}
