#include "noob_libx.h"

size_t  create_window(size_t width, size_t height, t_coliseu* coliseu) {
    BufferErro e;

    (void) coliseu;

    if ( buffer_unitialized() && ( (e = init_buffer()) != NO_ERRORS)) return e;

    Window window = XCreateSimpleWindow(
        global_buffer.display, 
        XDefaultRootWindow(global_buffer.display),
        0, 0,
        width, height,
        0,
        0,
        0
    );

    XMapWindow(global_buffer.display, window);
    

    XSync(global_buffer.display, 0);   
  
    return buffer_push_window(window);
}

uint8_t has_windows_oppened( void ) {
    return global_buffer.size > 0;
}

size_t  close_window(size_t id) {
    return buffer_remove_window(id);
}