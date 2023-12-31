#ifndef SEND_PACKET_H
#define SEND_PACKET_H

#include "header.h"

/* This function is used to set the probability (a value between 0 and 1) for
 * dropping a packet in the send_packet function. You call set_loss_probability
 * once in your program, and send_packet will drop packets after that.
 */
void set_loss_probability(float x);

/* This is a lossy replacement for the sendto function. It uses a random
 * number generator to drop packets with the probability chosen with
 * set_loss_probability. If it doesn't drop the packet, it calls sendto.
 */
ssize_t send_packet(int sock, void *buffer, size_t size, int flags, struct sockaddr *addr, socklen_t addrlen);

#endif // SEND_PACKET_H
