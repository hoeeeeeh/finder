#include "myheader.h"

#define ARROW_FIRST     27
#define ARROW_SECOND    91

#define UP      65
#define DOWN    66

#define ROOT    "/"

int fileSize = 0;
char* files[] = {};
char dir[256] = "/";
/*
    우선 char* 형태나 char[] 형태나 반환은 똑같다.
    다만 지역변수로 선언된 char* / char[] 를 반환하게 되면, 해당 함수가 return 되면서 선언해 두었던 char* / char[] 가 사라지게 될 것이다.
    즉 stack 영역에 있는 char* / char[] 가 사라져 버린다는 뜻이다. 따라서 heap 영역 / data 영역에 등록할 수 있어야 한다. 따라서 동적할당이 필요한 것으로 보인다.
    또 다른 방법은 data 영역에 선언하는, 즉 전역변수로 선언하는 것이다. 이 경우에도 char* / char[] 이 사라지지 않고 남아있기 때문에 반환할 수 있다.
    data 영역은 프로그램이 종료될 때 소멸된다.
    동적할당으로 heap 영역에 선언하는것이 메모리 효율상 유리하다. 다만 다른 모든 코드에서도 동적할당을 안하려고 노력했기 때문에 여기서도 동적할당을 피하고 전역변수로 선언한다.
*/

int getch()
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);           // 현재 터미널 설정 읽음
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);         // CANONICAL과 ECHO 끔
    newattr.c_cc[VMIN] = 1;                      // 최소 입력 문자 수를 1로 설정
    newattr.c_cc[VTIME] = 0;                     // 최소 읽기 대기 시간을 0으로 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  // 터미널에 설정 입력
    c = getchar();                               // 키보드 입력 읽음
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  // 원래의 설정으로 복구
    return c;
}

void list_dir(const char *path, int index)
{
    fileSize = 0;


    int count = 0;
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if(count == index){
            printf("▶");
        } else {
            printf("  ");
        }
        printf("%s\n",entry->d_name);
        fileSize++;
        files[count++] = entry->d_name;
    }

    closedir(dir);
}

char* finder(char* text)
{ 

    char temp[256] = ROOT;
    char ptr_temp[256] = "";
    int num = 0;
    int index = 0;
    int error = 0;

    strcpy(dir, "/");

    system("clear");
    printf("%s\n",text);
    printf("%s\n",dir);   
    printf("Press ENTER to enter directory\nPress S or s to select\n");
    printf("Press Q or q to quit\n\n");
    list_dir(dir, index);

    while(num != 's' && num != 'S'){
        
        num = getch();
        if(num == ARROW_FIRST){
            num = getch();
            if(num == ARROW_SECOND){
                num = getch();
                if(num == UP && index > 0){
                    index--;
                } else if (num == DOWN && index < fileSize-1){
                    index++;
                }
            }
        } else if (num == 10 && index > 1){
            if(strcmp(temp, "/") != 0){
                strcat(temp,"/");
            }
            strcat(temp,files[index]);

            DIR *isDir = opendir(temp);
            if(isDir != NULL){
                closedir(isDir);
                strcpy(dir,temp);
            } else {
                strcpy(temp, dir);
                error = 1;
            }
            index = 0;
            //files = {};
        } else if ( num == 10 && index == 1){

            strcpy(temp, dir);
            strcpy(ptr_temp, "");
            strcpy(dir, ROOT);
           
            char *ptr = strtok(temp, "/");
         
            while(ptr != NULL){
                if(strcmp(dir,ROOT) != 0){
                    strcat(dir, "/");
                }
                strcat(dir, ptr_temp);
            
                if(ptr != NULL){
                    strcpy(ptr_temp, ptr);
                }
                ptr = strtok(NULL, "/");        
            }
            strcpy(temp, dir);
            
        }
        else if(num == 's' || num == 'S'){
            if(strcmp(dir,"/") != 0){
                strcat(dir, "/");
            }
            strcat(dir,files[index]);
            return dir;
        }
        else if(num == 'q' || num == 'Q'){
            return "Quit";
        }

        system("clear");
        if(error){
            printf("NOT a directory\n");
            error = 0;
        }
    
        printf("%s\n",text);
        printf("%s\n",dir);
        printf("Press ENTER to enter directory\nPress S or s to select\n");
        printf("Press Q or q to quit\n\n");
        list_dir(dir, index);
    }
    return dir;
    
}
/* aaa*/
