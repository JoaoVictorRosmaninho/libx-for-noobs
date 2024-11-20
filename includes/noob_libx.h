#ifndef NOOB_LIBX_H
#define NOOB_LIBX_H

# include <X11/Xlib.h>
# include <stdint.h>
# include "libft.h"


/* Buffer */

typedef struct {
    Display*      display;
    t_coliseu*    memory;
    Window*       windows;
    uint8_t       size;
    unsigned char flags;
} WindowBuffer;


/* global buffer */
extern WindowBuffer global_buffer;

/* Buffer status*/
# define BUFFER_INITIALIZED 1 
# define BUFFER_UNITIALIZED 0 

/* Buffer Errors */
typedef enum {
    BAD_ALLOC_DISPLAY = 1,
    NO_ERRORS
} BufferErro;

/* Buffer API*/
size_t      buffer_push_window( Window window );

size_t      buffer_remove_window( size_t id );

uint8_t     buffer_unitialized( void );

BufferErro  init_buffer( void );

BufferErro  deinit_buffer( void );

/* Xorg API*/
size_t      create_window(size_t width, size_t height, t_coliseu* coliseu);

size_t      close_window(size_t id);

uint8_t     has_windows_oppened( void );


#endif