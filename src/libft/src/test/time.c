/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:10:24 by spenning      #+#    #+#                 */
/*   Updated: 2024/06/17 14:00:28 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

#include <time.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[1;32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define BMAG   "\x1B[1;35m"
#define CYN   "\x1B[36m"
#define BCYN   "\x1B[1;36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

//acknowledgement 
//https://medium.com/geekculture/rdtsc-the-only-way-to-benchmark-fc84562ef734

#define NS_PER_SECOND 1000000000

int	g_timing = 0;

void	sub_ts(struct timespec t1, struct timespec t2, struct timespec *td)
{
	td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
	td->tv_sec = t2.tv_sec - t1.tv_sec;
	if (td->tv_sec > 0 && td->tv_nsec < 0)
	{
		td->tv_nsec += NS_PER_SECOND;
		td->tv_sec--;
	}
	else if (td->tv_sec < 0 && td->tv_nsec > 0)
	{
		td->tv_nsec -= NS_PER_SECOND;
		td->tv_sec++;
	}
}

void	ft_time_print(struct tms *a, struct tms *b, struct timespec *d)
{
	double	systime;
	double	usrtime;
	clock_t	resolution;

	resolution = sysconf(_SC_CLK_TCK);
	systime = (double)(a->tms_stime - b->tms_stime) / resolution;
	usrtime = (double)(a->tms_utime - b->tms_utime) / resolution;
	printf(BCYN "SYS TIME: %f\n" RESET, systime);
	printf(BCYN "USR TIME: %f\n" RESET, usrtime);
	printf(BCYN "REA TIME: %d.%.9ld\n" RESET, (int)d->tv_sec, d->tv_nsec);
}

int	ft_time(void)
{
	static struct tms		before;
	struct tms				after;
	static struct timespec	start;
	struct timespec			finish;
	struct timespec			delta;

	if (g_timing == 0)
	{
		clock_gettime(CLOCK_REALTIME, &start);
		times(&before);
		g_timing = 1;
	}
	else
	{
		clock_gettime(CLOCK_REALTIME, &finish);
		times(&after);
		sub_ts(start, finish, &delta);
		ft_time_print(&before, &after, &delta);
		g_timing = 0;
	}
	return (0);
}
