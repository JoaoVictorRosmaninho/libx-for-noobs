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

size_t buffer_push_window( Window window ) {
    
    size_t id = global_buffer.size;
    
    global_buffer.windows[global_buffer.size++] = window;

    return id;
}

size_t buffer_remove_window( size_t id ) {
    
    XDestroyWindow(global_buffer.display, global_buffer.windows[id]);

    for ( size_t index = id; index < 3; index++) global_buffer.windows[index] = global_buffer.windows[index + 1];

    return  --global_buffer.size;

}