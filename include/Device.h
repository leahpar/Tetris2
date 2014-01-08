
#if defined WIN32 || defined _WIN32
#include <windows.h>
#define Alert(a,b,c,d) MessageBox(a,b,c,d)
#undef main
#endif

#ifdef __linux__
#define Alert(a,b,c,d)
#endif

#ifdef MAC
#define Alert(a,b,c,d)
#endif
