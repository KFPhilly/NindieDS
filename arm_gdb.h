#ifdef GDB_SUPPORT

#ifndef _GDB_H_
#define _GDB_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../arm_cpu.h"

#define GDB_STUB_MAX_LINE 1200

typedef struct {
    int socket;
    int socket2;
    struct sockaddr_in server;
    struct sockaddr_in client;
    arm_cpu* arm;
} arm_gdb;

arm_gdb* arm_gdb_make(arm_cpu* arm, int port);

#endif

#endif
