
#ifdef WIN32
#include <Windows.h>
#define Alert(a,b,c,d) MessageBox(a,b,c,d)
#endif

#ifdef LINUX
#define Alert(a,b,c,d)
#endif

#ifdef MAC
#define Alert(a,b,c,d)
#endif
