/*
 Copyright (C) 2017 Wolfgang Hotwagner <code@feedyourhead.at>       
                                                                
 This file is part of statx-fun                                
 
 This program is free software; you can redistribute it and/or 
 modify it under the terms of the GNU General Public License 
 as published by the Free Software Foundation; either version 2 
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License          
 along with this program; if not, write to the 
 Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, 
 Boston, MA  02110-1301  USA 
*/

#define _GNU_SOURCE
#define _ATFILE_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "statx.h"
#include <time.h>
#include <getopt.h>
#include <string.h>

#define VERSION 1.0.1

/*
   does not (yet) provide a wrapper for the statx() system call 
*/
#include <sys/syscall.h>

/* this code works ony with x86, arm64 and x86_64 */
#if __x86_64__
#define __NR_statx 332
#else
  #if __aarch64__
    #define __NR_statx 291
  #else
    #define __NR_statx 383
  #endif
#endif

#define statx(a,b,c,d,e) syscall(__NR_statx,(a),(b),(c),(d),(e))

/* from kernel-sources(samples/statx/test-statx.c) */
static void print_time(const char *field, struct statx_timestamp *ts)
{
        struct tm tm;
        time_t tim;
        char buffer[100];
        int len;

        tim = ts->tv_sec;
        localtime_r(&tim, &tm); 
        len = strftime(buffer, 100, "%s", &tm);
        fwrite(buffer, 1, len, stdout);
}

/* from kernel-sources(samples/statx/test-statx.c) */
static void dump_statx(struct statx *stx)
{
	if (stx->stx_mask & STATX_BTIME)
		print_time(" Birth: ", &stx->stx_btime);
}


int main(int argc, char *argv[])
{
	int dirfd = AT_FDCWD;
	int flags = AT_SYMLINK_NOFOLLOW;
	unsigned int mask = STATX_ALL;
	struct statx stxbuf;
	long ret = 0;
	int i = 0;

	if (optind >= argc) {
		exit(EXIT_FAILURE);
	}

  	for (i = optind; i < argc; i++)
	{
		memset(&stxbuf, 0xbf, sizeof(stxbuf));
		ret = statx(dirfd,argv[i],flags,mask,&stxbuf);
		if( ret < 0)
		{
			perror("statx");
			return EXIT_FAILURE;
		}
		dump_statx(&stxbuf);
		printf("\n");
	}
	return EXIT_SUCCESS;
}
