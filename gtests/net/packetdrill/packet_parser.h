/*
 * Copyright 2013 Google Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */
/*
 * Author: ncardwell@google.com (Neal Cardwell)
 *
 * Interface for a module to parse TCP/IP packets.
 */

#ifndef __PACKET_PARSER_H__
#define __PACKET_PARSER_H__

#include "packet.h"

enum packet_parse_result_t {
	PACKET_OK,		/* no errors detected */
	PACKET_BAD,		/* illegal header */
	PACKET_UNKNOWN_L4,	/* not SCTP or TCP or UDP or UDPLite */
};

/* Given an input packet of length 'in_bytes' stored in the buffer
 * whose location is given by the packet's 'buffer' field and whose
 * full size is given by the 'buffer_bytes' field, parses the packets
 * and fills in packet fields 'ip_bytes', 'ip', and 'tcp'. On success,
 * returns PACKET_OK; on error, returns a enum packet_parse_result_t error
 * code and fills in *error with a human-readable, malloc-allocated
 * error message.
 */
int parse_packet(struct packet *packet, int in_bytes,
		 u16 ether_type, u8 udp_encaps, char **error);

#endif /* __PACKET_PARSER_H__ */
