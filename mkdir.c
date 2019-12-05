#include "myheader.h"

int makedirectory()
{
	char input[256];
	char dir[256];
	int fd;

	strcpy(dir, finder("생성할 디렉토리를 선택해주세요 "));
	printf("디렉토리 이름을 설정하세요:  ");

	while(1){
	fgets(input , sizeof(input) , stdin );
	if(!(strlen(input)==1 && input[0]=='\n')) break;
	}
	input[strlen(input) - 1] = '\0';

	strcat(dir, "/");
	strcat(dir,input);
	if((fd=mkdir(input,0777))== -1 && errno !=EEXIST){
		perror("makeDirectoryError!");
	}else printf("디렉토리 생성 완료\n");

	return 0;
}
