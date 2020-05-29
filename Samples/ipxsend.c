#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <linux/ipx.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

int main(int argc, char **argv)
{
	struct sockaddr_ipx	sipx;
	int	s;
	int	rc;
	char	msg[100] = "Hello world!";
	int	len = sizeof(sipx);

	s = socket(AF_IPX, SOCK_DGRAM, AF_IPX);
	if (s < 0) {
		perror("IPX: socket: ");
		exit(-1);
	}
	memset(&sipx, 0, sizeof(sipx));
	sipx.sipx_family = AF_IPX;
	sipx.sipx_network = 0;
	sipx.sipx_port = 0;
	sipx.sipx_type = 17;

	rc = bind(s, (struct sockaddr *)&sipx, sizeof(sipx));
	if (rc < 0) {
		perror("IPX: bind: ");
		exit(-1);
	}

	rc = getsockname(s, (struct sockaddr *)&sipx, &len);
	sipx.sipx_port = htons(0x5000);
	sipx.sipx_node[0] = 0xFF;
	sipx.sipx_node[1] = 0xFF;
	sipx.sipx_node[2] = 0xFF;
	sipx.sipx_node[3] = 0xFF;
	sipx.sipx_node[4] = 0xFF;
	sipx.sipx_node[5] = 0xFF;

	rc = sendto(s, msg, strlen(msg), 0, (struct sockaddr *)&sipx,
		    sizeof(sipx));
	if (rc < 0) {
		perror("IPX: send: ");
		exit(-1);
	}
	return 0;
}
