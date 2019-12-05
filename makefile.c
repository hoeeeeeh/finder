#include "myheader.h"

int makefiles()
{
	int fd;
	char dir[256];
	char name[200];
	strcpy(dir, finder("생성할 디렉토리를 선택해주세요 "));
	printf("생성할 파일의 이름을 설정해주세요(10자) : ");
	while(1){
	fgets(name , sizeof(name) , stdin );
	if(!(strlen(name)==1 && name[0]=='\n')) break;
	}
	name[strlen(name)-1] = '\0';
	strcat(dir, "/");
	strcat(dir,name);
	if((fd=open(dir,O_RDWR | O_CREAT | O_TRUNC |  O_EXCL, 0777)) == -1){  
		perror("ERROR: Cannot open data.dat\n");
	}
	
	return 0;
}

void mkrm_main(){
	int select;
	printf("1.파일생성\t2.디렉토리생성\t3.제거\n");
	scanf("%d",&select);
	switch(select){
		case 1:
			makefiles();
			break;
		case 2:
			makedirectory();
			break;
		case 3:
			rmdir_main();
			break;
	}
}

int rmdirs(const char *path, int force) 
{ 
	DIR * dir_ptr = NULL;
	struct dirent *file = NULL; 
	struct stat buf; 
	char filename[1024]; 
	if((dir_ptr = opendir(path)) == NULL) { 
		return unlink(path); 
	}
	while((file = readdir(dir_ptr)) != NULL) { 
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) { 
			continue; 
	} 
	sprintf(filename, "%s/%s", path, file->d_name); 
	if(lstat(filename, &buf) == -1) { 
		continue; 
	} if(S_ISDIR(buf.st_mode)) { 
		if(rmdirs(filename, force) == -1 && !force) { 
			return -1; 
	} 
	} else if(S_ISREG(buf.st_mode) || S_ISLNK(buf.st_mode)) { 
		if(unlink(filename) == -1 && !force) { 
			return -1; 
		} 
	        } 
	}
	closedir(dir_ptr); 
	return rmdir(path); 
}
int rmdir_main()
{
	char input[256];
	strcpy(input, finder("삭제하실 파일/디렉토리를 선택해주세요:"));
	rmdirs(input,1);
	return 0;
}
