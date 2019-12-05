#include "myheader.h"

void copy_main(){
    int selectNum;

    char file_dir[256];
    char folder_dir[256];

    char filename[256];

    printf("1.복사\t2.한 파일을 여러 폴더에 복사");
    scanf("%d",&selectNum);

    printf("사본 파일의 이름을 정해주세요\n");
    scanf("%s", filename);
    
    strcpy(file_dir, finder("복사할 파일 선택"));
    printf("%s\n",file_dir);

    do{
        strcpy(folder_dir, finder("어떤 폴더에 복사할지 폴더 선택"));
        if(strcmp(folder_dir, "Quit") == 0){
            break;
        }
        copy_paste(file_dir, folder_dir, filename);
    }while(selectNum == 2);
}

int copy_paste(char* originFile, char* folder_dir, char* filename){
    char        copiedFile[256] = "";
    char        buf[4096];
    int         fdin;
    int         fdout;
    int         nb;
    struct stat st;

    strcpy(copiedFile, folder_dir);
    strcat(copiedFile, "/");
    strcat(copiedFile, filename);

    fdin = open(originFile, O_RDONLY);
    fstat(fdin, &st);

    if(fdin == -1){
        printf("error");
        perror("error while open origin source");
        exit(errno);
    }

    fdout = open(copiedFile, O_WRONLY|O_CREAT|O_EXCL, st.st_mode);

    if(fdout == -1){
        perror("해당 이름을 가진 파일이 이미 존재하거나 디렉토리가 아닙니다.");
        exit(errno);
    }

    while ((nb = read(fdin, buf, 4096)) > 0) {
        write(fdout, buf, nb);
    }
    close(fdin);
    close(fdout);

    //chmod(fdout, sts.st_mode);

    return 0;
}
