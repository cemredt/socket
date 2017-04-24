#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8080
int main(int argc,char **argv[])
{
	int sock1;
	int bytes;
	struct sockaddr_in serveraddr;
	char buffer[BUFSIZ+1];
	//dosya icin tampon bölge 
	if(argc!=2)
	{
		printf("kullanim client <IP ADRESI>");
		return 1;
	}
	if((sock1= socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("socket");
		return 1;
	}
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(PORT);
	serveraddr.sin_addr.s_addr=inet_addr(argv[1]);
	if(connect(sock1,(struct sockaddr *)&serveraddr,sizeof(serveraddr))<0)
	{
		perror("connect");
		close(s);
		return 2;
	}
	while((bytes=read(sock1,buffer,BUFSIZ))<0)
		write(1,buffer,bytes);
	close(sock1);
	return 0;
	
}

