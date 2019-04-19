#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h> 

#define SERVER_PORT 123321 
#define MAX_PENDING 5 
#define MAX_LINE 256

int main() 
{ 
	struct sockaddr_in sin; 
	char buf[MAX_LINE]; 
	int len; 
	int s, new_s;
	/* build address data structure */ 
	bzero((char *)&sin, sizeof(sin));
	sin.sin_family = AF_INET; 
	sin.sin_addr.s_addr = INADDR_ANY; 
	sin.sin_port = htons(SERVER_PORT);
	/* setup passive open */ 
	//fill your code here to create the socket
	s = socket(PF_INET, SOCK_STREAM, 0);

	//fill your code to bind the socket to the address data structure; 
	bind (s, (struct sockaddr *)&sin, sizeof(sin)); 
	//fill your code to make the socket to listen;
	listen (s, MAX_PENDING);
	/* wait for connection, then receive and print text */ 
	while(1) 
	{ 
		//fill your code to accept connections;
		new_s = accept (s, (struct sockaddr *)&sin, &len);
		//fill your code to receive and print text;
		while (len = recv (new_s, buf, sizeof(buf), 0))
			fputs(buf,stdout);
		close(new_s);
	}
	
}