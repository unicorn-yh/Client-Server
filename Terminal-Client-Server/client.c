#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MYPORT 9999

char server_ip[] = "10.0.2.15";
char buf[200];

int main(int argc, char *argv[])
{
	int sockfd,new_sockfd;
	struct sockaddr_in sin_addr,pin_addr;
	int len, pin_addr_size,i;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <0)
	{
	   printf("can't create socket\n");
	   exit(1);
	}

	memset( &sin_addr, 0, sizeof(sin_addr));
	sin_addr.sin_family = AF_INET;
	sin_addr.sin_addr.s_addr = inet_addr(server_ip);
	sin_addr.sin_port = htons(MYPORT);
	if(connect(sockfd, (struct sockaddr *)
				&sin_addr, sizeof(sin_addr))<0)
	{
	   printf("can't connect socket\n");
	   exit(1);
	}

	while(1)
	{
	   printf("Me: ");
	   gets(buf);
	   if((len = send(sockfd, buf, 200, 0)) < 0)
	   {
	      printf("send error\n");
	      exit(1);
	   }

	   if(recv(sockfd, buf, 200, 0) == -1)
	   {  
	      printf("can't receive packet\n");
	      exit(1);
	   }
	   printf("Peer: %s\n", buf);
	}

	close(sockfd);
	return 0;
}