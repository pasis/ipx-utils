#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netipx/ipx.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

int main(int argc, char **argv)
{
	struct sockaddr_ipx	sipx;
	int	s;
	int	rc;
	char	msg[100];
	int	len;

	s = socket(AF_IPX, SOCK_DGRAM, AF_IPX);
	if (s < 0) {
		perror("IPX: socket: ");
		exit(-1);
	}
	memset(&sipx, 0, sizeof(sipx));
	sipx.sipx_family = AF_IPX;
	sipx.sipx_network = 0;
	sipx.sipx_port = htons(0x5000);
	sipx.sipx_type = 17;
	len = sizeof(sipx);
	rc = bind(s, (struct sockaddr *)&sipx, sizeof(sipx));
	if (rc < 0) {
		perror("IPX: bind: ");
		exit(-1);
	}

	msg[0] = '\0';
	rc = recvfrom(s, msg, sizeof(msg), 0, (struct sockaddr *)&sipx, &len);
	if (rc < 0) {
		perror("IPX: recvfrom: ");
	}

	printf("From %08lX:%02X%02X%02X%02X%02X%02X:%04X\n",
		(unsigned long)ntohl(sipx.sipx_network),
		sipx.sipx_node[0], sipx.sipx_node[1],
		sipx.sipx_node[2], sipx.sipx_node[3],
		sipx.sipx_node[4], sipx.sipx_node[5],
		ntohs(sipx.sipx_port));
	printf("\tGot \"%s\"\n", msg);
	return 0;
}
