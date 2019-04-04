#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
	char server_msg[256] = "Ni hao ma:";
	char server_respond[256];
	int network_socket;
	network_socket = socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons (10000);
	server_address.sin_addr.s_addr = inet_addr("192.168.190.132");

	int status = connect(network_socket,(struct sockaddr *) 
&server_address, sizeof(server_address));

	if(status == 1){
		printf("there was an error %s\n");
	}
	send(network_socket,server_msg,sizeof(server_msg),0);	
		
	recv(network_socket,server_respond,sizeof(server_respond),0);

	printf("server message : %s\n", server_respond);
	close(network_socket);
	return 0;
}
