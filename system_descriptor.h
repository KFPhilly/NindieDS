#ifndef _SYSTEM_DESCRIPTOR_H_
#define _SYSTEM_DESCRIPTOR_H_

typedef void* (*open_func)(char* rom_path);
typedef void (*close_func)(void* system);
typedef void (*frame_func)(void* system);

typedef struct {
    char* name;
    int screen_width;
    int screen_height;
    open_func open;
    close_func close;
    frame_func frame;
} system_descriptor;

#endif
