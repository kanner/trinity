#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "config.h"
#include "compat.h"
#include "net.h"
#include "random.h"

void nfc_gen_sockaddr(struct sockaddr **addr, socklen_t *addrlen)
{
	struct sockaddr_nfc *nfc;

	// TODO: See also sockaddr_nfc_llcp
	nfc = malloc(sizeof(struct sockaddr_nfc));
	if (nfc == NULL)
		return;

	nfc->sa_family = PF_NFC;
	nfc->dev_idx = rand();
	nfc->target_idx = rand();
	nfc->nfc_protocol = rand() % 5;
	*addr = (struct sockaddr *) nfc;
	*addrlen = sizeof(struct sockaddr_nfc);
}

void nfc_rand_socket(struct socket_triplet *st)
{
	if (rand_bool()) {
		st->protocol = NFC_SOCKPROTO_LLCP;
		if (rand_bool())
			st->type = SOCK_DGRAM;
		else
			st->type = SOCK_STREAM;
		return;
	}

	st->protocol = NFC_SOCKPROTO_RAW;
	st->type = SOCK_SEQPACKET;
}

#define SOL_NFC 280

void nfc_setsockopt(struct sockopt *so)
{
	so->level = SOL_NFC;
}
