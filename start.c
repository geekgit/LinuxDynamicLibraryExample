#include <stdio.h>
#include <dlfcn.h>
void HelloWorld()
{
	void* Handle;
	void (*HelloWorld)(void);
	Handle = dlopen ("libHello.so", RTLD_LAZY);
	HelloWorld = dlsym (Handle, "HelloWorld");
	HelloWorld();
	dlclose (Handle);
}
void Sum(int A, int B)
{
	void* Handle;
	int (*Sum)(int,int);
	Handle = dlopen ("libHello.so", RTLD_LAZY);
	Sum = dlsym (Handle, "Sum");
	int C=Sum(A,B);
	printf("%d+%d=%d\n",A,B,C);
	dlclose (Handle);
}
int main()
{
	HelloWorld();
	Sum(2,2);
	Sum(100,1);
}
