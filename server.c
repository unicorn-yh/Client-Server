//server.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MYPORT 9999
char buf[200];

int main(int argc , char *argv[])
{
	int sockfd,new_sockfd;
	struct sockaddr_in sin_addr,pin_addr;
	int len, pin_addr_size,i;

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) <0)
	{
	   printf("can’t create socket\n");
	   exit(1);
	}

	memset( &sin_addr, 0, sizeof(sin_addr));
	sin_addr.sin_family = AF_INET;
	sin_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sin_addr.sin_port = htons(MYPORT);
	if(bind(sockfd, (struct sockaddr *)
				&sin_addr, sizeof(sin_addr))<0)
	{
	   printf("can’t bind socket\n");
	   exit(1);
	}else{
	   printf("[Server is ready.]\n");
	}

	if(listen(sockfd, 5) < 0 )
	{
	   printf("listen error\n");
	   exit(1);
	}else{
	   printf("[Server is listening ... ]\n");
	}

	if((new_sockfd = accept(sockfd, 
				 (struct sockaddr *)&pin_addr, 
		                &pin_addr_size)) < 0) 
	{
	   printf("accept error\n");
	   exit(1);
	}

	while(1)
	{
	   //memset(buf, 0, 200);
	   if(recv(new_sockfd, buf, 200, 0) == -1)
	   {
	      printf("can’t receive packet\n");
	      break;
	   }
	   printf("Peer: %s\n", buf);
	   strcpy(buf, "you too");
	   printf("Me: %s\n", buf);
	   if(send(new_sockfd, buf, 200, 0) == -1)
	   {  
	      printf("can’t receive packet\n");
	      break;
	   }
	}

	close(new_sockfd);
	close(sockfd);
	return 0;
}