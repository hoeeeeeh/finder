#include "myheader.h"

int makedirectory()
{
	char input[256];
	int fd;

	printf("디렉토리 이름을 설정하세요:");
	fgets(input , sizeof(input) , stdin );
	if((fd=mkdir(input,0777))== -1 && errno !=EEXIST){
		perror("makeDirectoryError!");
	}else printf("디렉토리 생성 완료\n");

	return 0;
}