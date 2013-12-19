
#ifdef WIN32
#include <windows.h>
#define Alert(a,b,c,d) MessageBox(a,b,c,d)
#undef main
#endif

#ifdef __linux__
#define Alert(a,b,c,d)
#endif

#ifdef __APPLE__
#define Alert(a,b,c,d)
#endif
