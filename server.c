#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
//sürec yönetim fonksiyonlari
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
//struct in_addr yapisini belirler
#define PORT 8080
#define BACKLOG 4
int main()
{
	//istemcileri dinleyen socket
	int sock1;
	//iletisim socketi
	int a,b;
	struct sockaddr_in serveraddr;
	FILE *client;
	int count=0;
	if( (sock1=socket(AF_INET,SOCK_STREAM,0))<0 )
		{
			perror("socket");
			return 1;
		}
		bzero(&serveraddr,sizeof(serveraddr));
		serveraddr.sin_family=AF_INET;
		serveraddr.sin_port=htons(PORT);
		if(INADDR_ANY)
			serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
			//sadece belirli porta gelen istekleri karsilamak icin
		if(bind(sock1,(struct addr *)&serveraddr,sizeof(serveraddr))<0)
		{
			perror("bind");
			return 2;
		}
		listen(sock1,BACKLOG);
		for(;;)
		{
			b=sizeof(serveraddr);
			if(a=accept(sock1,(struct addr *)&serveraddr,&b)<0)
			{
				perror("fdopen");
				return 5;
			}
			fprintf(client,"%d.cevap",++count);
			fclose(client);
		}
		
}
