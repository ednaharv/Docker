#include "fcgi_stdio.h"

int main(void) {
    int FCGI_Init(void);
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n\r\n");
        printf("Hello World!");
    }
    return 0;
}
