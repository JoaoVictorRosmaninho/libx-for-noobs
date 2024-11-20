#include "noob_libx.h"

WindowBuffer global_buffer = {
    .display = NULL,
    .memory  = NULL,
    .windows = NULL,
    .size    = 0,
    .flags   = BUFFER_UNITIALIZED
};
 
uint8_t buffer_unitialized( void ) {
    return global_buffer.flags ^ 1;
} 

BufferErro init_buffer( void ) {
    global_buffer.display = XOpenDisplay(NULL);

    if ( !global_buffer.display )
        return BAD_ALLOC_DISPLAY;

    global_buffer.memory  = ft_coliseu_manager(TAKE);

    global_buffer.windows = ft_calloc(4, sizeof(Window), global_buffer.memory);

    global_buffer.flags   = BUFFER_INITIALIZED;

    return NO_ERRORS;
}

BufferErro deinit_buffer( void ) {
    XCloseDisplay(global_buffer.display); 

    ft_coliseu_manager(GIVE_BACK);

    return NO_ERRORS;
}

size_t push_window( Window window ) {
    global_buffer.windows[global_buffer.size++] = window;

    return global_buffer.size;
}