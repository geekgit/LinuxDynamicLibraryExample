#include <stdio.h>
#include <dlfcn.h>
int main()
{
	void* Handle;
	void (*HelloWorld)(void);
	Handle = dlopen("libHello.so", RTLD_LAZY);
	HelloWorld = dlsym(Handle, "HelloWorld");
	HelloWorld();
	dlclose(Handle);
}
