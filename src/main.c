#include "noob_libx.h"

int main(void) {
    size_t id = create_window(200, 200, NULL);

    while( has_windows_oppened() ) {

       sleep(3);

       close_window(id);

    }

    deinit_buffer();
    return 0;
}