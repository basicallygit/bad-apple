#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "truncate.h"

#define FRAMECOUNT 6532
#define SLEEP_MICROSECS 32995

int main()
{
	char frame[2481];
	char fname[30] = "frames/BA";
	int len = strlen(fname);
	char fnum[6];
	
	for (int i = 40; i <= FRAMECOUNT; i++) {
		sprintf(fnum, "%d", i);
		strcat(fname, fnum);
		strcat(fname, ".txt");
		
		int fd = open(fname, O_RDONLY);
		int n = read(fd, frame, 2480);
		printf("%s", frame);
		printf("%s", fname);
		usleep(SLEEP_MICROSECS);
		close(fd);
		printf("\e[1;1H\e[2J");	
		strcpy(fname, strtrunc(fname, len));
	}
}
