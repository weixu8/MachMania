//
//  Common.h
//  MachMania
//
//  Created by Yogesh Swami on 2/3/12.
//  Copyright (c) 2012 Axelexic LLC. All rights reserved.
//

#ifndef MachMania_Common_h
#define MachMania_Common_h

#include <mach/mach_types.h>
#include <mach/message.h>
#include <stdio.h>

#define SERVER_NAME "com.axelexic.mach_ipc_server"
#define MAX_MSG_BODY_SIZE   512
#define MULTIPLEX_ID        500


typedef struct send_message{
    mach_msg_header_t msg_header;
    char        request[MAX_MSG_BODY_SIZE];
}send_message_t;

typedef struct receive_message{
    mach_msg_header_t msg_header;
    char        response[MAX_MSG_BODY_SIZE];
    mach_msg_trailer_t tailer;
}receive_message_t;

#define SEND_MSG_LEN sizeof(send_message_t)
#define RECV_MSG_LEN sizeof(receive_message_t)

void port_introspect(FILE* io, mach_port_name_t port_desc);
char* port_type_2_name(mach_port_type_t type);

void enumerate_ports_with_status(FILE* io);

#endif
