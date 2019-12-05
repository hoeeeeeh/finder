
/* 공통 라이브러리 */
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
/* 공통 라이브러리 */

/* rename 에 필요한 헤더 */
#include <sys/wait.h>
/* rename 에 필요한 헤더 */

/* 콘솔 창 (console.c) 에 필요한 헤더 */
#include <termios.h>
/* 콘솔 창 (console.c) 에 필요한 헤더 */


/* 복사/붙여넣기 에 필요한 헤더 */
#include <utime.h> 
/* 복사/붙여넣기 에 필요한 헤더 */




/* 콘솔 창 (console.c) 에 정의된 함수 */
char* finder(char* text);
void list_dir(const char *path, int index);
int getch();
/* 콘솔 창 (console.c) 에 정의된 함수 */

/* 복사/붙여넣기 에 정의된 함수 */
int copy_paste(char* originFile, char* folder_dir, char* filename);
void copy_main();
/* 복사/붙여넣기 에 정의된 함수 */

/* sort.c 에 정의된 함수 */
int chmods(char * filemode,char * filename);
int sort_size(void);
int sort_modification_time(void);
int sort_reverse(void);
void clearScreen();
int sort_main();
/* sort.c 에 정의된 함수 */

/* makefile.c 에 정의된 함수 */
int makefiles();
void mkrm_main();
/* makefile.c 에 정의된 함수 */

/* mkdir.c 에 정의된 함수 */
int makedirectory();
/* mkdir.c 에 정의된 함수 */

/* mv.c 에 정의된 함수 */
int mv_main();
/* mv.c 에 정의된 함수 */

/* rmdir.c 에 정의된 함수 */
int rmdirs(const char *path, int force);
int rmdir_main();
/* rmdir.c 에 정의된 함수 */

/* search.c 에 정의된 함수 */
void search_main();
/* search.c 에 정의된 함수 */
