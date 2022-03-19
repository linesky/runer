#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc,char *argv[]){
	int rets=0;
	void *handler;
	int (*starter)(int,char*[]);
	if(argc<2)exit(0);
	handler=dlopen("./torun.run",RTLD_LAZY);
	if (!handler){
		puts("error on load to run file");
		exit(1);
	}
	starter=dlsym(handler,"start");
	if(dlerror()!=NULL){
		puts("error not a runer file");
		exit(1);
	}
	rets=starter(argc,argv);
	dlclose(handler);
	return rets;
}
