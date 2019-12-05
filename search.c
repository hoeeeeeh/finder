#include "myheader.h"

void search_main(){
        DIR* dir_info;
        struct dirent* dir_entry;

        char input[256];
        printf("디렉토리/파일 이름의 일부분 또는 전체 입력 : ");
        scanf("%s",input);
        dir_info = opendir(finder("찾고 싶은 위치를 선택해주세요"));

		int flag = 0;
        if(NULL != dir_info){
                while((dir_entry = readdir(dir_info)) != NULL)
                {
                        char* ptr = strstr(dir_entry->d_name, input);

                        if(ptr != NULL){
                        printf(">> %s\n",dir_entry->d_name);
						flag = 1;
                        }
                }
				if (flag == 0) {
					printf("해당 이름의 파일이나 디렉토리가 없습니다.\n");
				}
                closedir(dir_info);
        }
}