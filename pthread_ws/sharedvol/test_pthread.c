#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int g_JitterMax;
int g_IntrProcMax;
int g_IntrCallMax;

int main(void)
{
        pthread_t thread;
        int i, s;

        pthread_attr_t attr;
        struct sched_param param;

        mlockall(MCL_CURRENT | MCL_FUTURE);

        //cpu_dma_latency write start
        int latency_target_fd;
        int latency_target_value = 0;
        int ret;

	latency_target_fd = open("/dev/cpu_dma_latency", O_RDWR);
	if(latency_target_fd == -1)
	{
		printf("open failed /dev/cpu_dma_latency\n");
		exit(1);
	}
	ret = write(latency_target_fd, &latency_target_value, 4);

	if(ret < 1)
	{
		printf("write faild /dev/cpu_dma_latency\n");
		close(latency_target_fd);
		exit(1);
	}
	printf("# /dev/cpu_dma_latency set to %dus\n", latency_target_value);
}
