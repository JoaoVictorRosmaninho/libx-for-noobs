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
  
    return push_window(window);
}

size_t  close_window(size_t id) {
   
    (void) id;
    
    return deinit_buffer();
}