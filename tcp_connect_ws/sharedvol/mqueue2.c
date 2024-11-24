#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
 
#define MQ_NAME "/mqueue"
#define MQ_NAME2 "/mqueue2"
 
#define MSGSIZE 1024
#define MODE 0666
 
int main(void)
{
  mqd_t mqd;
  char str[MSGSIZE], str2[MSGSIZE];
  struct mq_attr attr = {
    .mq_flags = 0,
    .mq_maxmsg = 10,
    .mq_msgsize = 8192,
    .mq_curmsgs = 0
  };
 
  while (true) {
    if ((mqd = mq_open(MQ_NAME2, O_CREAT | O_RDONLY, MODE, &attr)) == -1) {
      perror("mq_open");
      exit(1);
    }
 
    if (mq_receive(mqd, str, sizeof(str), NULL) == -1) {
      perror("mq_receive");
      exit(2);
    }
 
    if (mq_close(mqd) == -1) {
      perror("mq_close");
      exit(3);
    }
 
    printf("str = %s\n", str);
 
    if ((mqd = mq_open(MQ_NAME, O_CREAT | O_WRONLY, MODE, &attr)) == -1) {
      perror("mq_open");
      exit(4);
    }
 
    if (fgets(str2, sizeof(str2), stdin) == NULL) {
      fprintf(stderr, "Error: cannot success fgets()\n");
      exit(5);
    }
 
    str2[strlen(str2) - 1] = '\0';
 
    if (mq_send(mqd, str2, strlen(str2) + 1, 0) == -1) {
      perror("mq_send");
      exit(6);
    }
 
    if (mq_close(mqd) == -1) {
      perror("mq_close");
      exit(7);
    }
 
  }
 
  return 0;
}
