#include "myheader.h"


int chmods(char * filemode,char * filename){
    printf("chmod running...");
    pid_t childpid;
    
    // char *filename = argv[1];
    // char *filemode = argv[0];
    childpid = fork();
    if(childpid == -1){
        perror("Failed to fork");
        return 1;
    }
    if(childpid == 0){
        printf("%s", filename);
        printf("%s", filemode);
        
        execl("/bin/chmod","chmod",filemode, filename,NULL);
        perror("Child failed to exec ls");
        return 1;
    }
    if (childpid != wait(NULL)){
        perror("Parent failed to wait due to signal or error");
        return 1;
    }
    return 0;
    
    
}

int sort_size(void){
    pid_t childpid;

    childpid = fork();
    if(childpid == -1){
        perror("Failed to fork");
        return 1;
    }
    if(childpid == 0){
        execl("/bin/ls","ls","-lS",NULL);
        perror("Child failed to exec ls");
        return 1;
    }
    if (childpid != wait(NULL)){
        perror("Parent failed to wait due to signal or error");
        return 1;
    }
    return 0;
}


int sort_modification_time(void){
    pid_t childpid;

    childpid = fork();
    if(childpid == -1){
        perror("Failed to fork");
        return 1;
    }
    if(childpid == 0){
        execl("/bin/ls","ls","-lt",NULL);
        perror("Child failed to exec ls");
        return 1;
    }
    if (childpid != wait(NULL)){
        perror("Parent failed to wait due to signal or error");
        return 1;
    }
    return 0;
    
    
}

int sort_reverse(void){
    pid_t childpid;

    childpid = fork();
    if(childpid == -1){
        perror("Failed to fork");
        return 1;
    }
    if(childpid == 0){
        execl("/bin/ls","ls","-lr",NULL);
        perror("Child failed to exec ls");
        return 1;
    }
    if (childpid != wait(NULL)){
        perror("Parent failed to wait due to signal or error");
        return 1;
    }
    return 0;
    
    
}
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
int sort_main(){
    int aa=1;
    while(aa==1 ){
        // clearScreen();
        printf("\n1. 권한변경\t2. 크기 졍렬\t3. 수정시간 순 정렬\t4.크기 순 정렬\t5.종료\n");
        int a; 
        scanf("%d", &a);
        if(a == 1){
            char* test;
            test = finder("권한을 변경할 파일을 선택하세요.");
            printf("%s",test);
            list_dir(test, 0);
            
        
            printf("\n변경할 권한을 입력하세요\n");
            char filemode[10];
            gets(filemode);
            printf("%s",filemode);
            chmods(filemode, test);
            

        }else if(a ==2){
            char* test;
            test = finder("");
            printf("%s",test);
            list_dir(test, 0);
            int nResult = chdir( test );
            printf("\n크기 순 정렬\n\n");
            sort_size();
            
        }else if(a ==3){
            
            char* test;
            test = finder("");
            printf("%s",test);
            list_dir(test, 0);
            int nResult = chdir( test );
            printf("\n수정시간 순 정렬\n\n");
            sort_modification_time();
            
        }else if(a ==4){
            
            char* test;
            test = finder("");
            printf("%s",test);
            list_dir(test, 0);
            int nResult = chdir( test );
            printf("\n역순 정렬\n\n");
            sort_reverse();
            
        }else{
            break;
        }
    }
    return 0;
}