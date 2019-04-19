#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h>

#define SERVER_PORT 123321 
#define MAX_LINE 256

int main(int argc, char * argv[]) 
{ 
	FILE *fp; 
	struct hostent *hp; 
	struct sockaddr_in sin; 
	char *host; 
	char buf[MAX_LINE]; 
	int s; 
	int len; 
	host = argv[1];
	
	/* translate host name into peer’s IP address */ 
	hp = gethostbyname(host);
	
	/* build address data structure */ 
	bzero((char *)&sin, sizeof(sin)); 
	sin.sin_family = AF_INET; /* Internet Address*/ 
	bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length); 
	sin.sin_port = htons(SERVER_PORT);
	
	/* active open  PF_INET is protocol family*/ 
	//fill your code the create the socket 
	s = socket(PF_INET, SOCK_STREAM, 0);
	//fill your code the connect the socket with server
	connect(s, (struct sockaddr *)&sin, sizeof(sin)); 
	
	/* main loop: get and send lines of text */ 
	while (fgets(buf, sizeof(buf), stdin)) 
	{ 
		buf[MAX_LINE-1] = '\0'; 
		len = strlen(buf) + 1; 
		send(s, buf, len, 0); 
	}
}
	