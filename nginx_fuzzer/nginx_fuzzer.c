
#include"nginx_fuzzer.h"

//extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size){


int main(int argc, char *const *argv){		
	//ngx_main(argc,argv);
	//pintf("HElllo\n");
	ngx_cycle_t      *cycle;
	ngx_int_t		initial_value=-1;
	ngx_int_t		*returnValue=&initial_value;
	before_process_cycle(argc, argv, &cycle,returnValue);
	
	if(*returnValue==1){
		return 1;
	}else if(*returnValue==0){
		return 0;
	}
	
    // 启动单进程或者master/worker多进程，内部会调用fork
	// 子进程完全复制父进程的cycle，包括打开的文件、共享内存、监听的端口
    if (ngx_process == NGX_PROCESS_SINGLE) {
		// 如果master_process off那么就不是master进程
		// ngx_process_cycle.c
        ngx_single_process_cycle(cycle);

    } else {
		// ngx_process_cycle.c
        // 启动worker进程，数量由配置决定，即worker_processes指令
        // 核心操作是sigsuspend，暂时挂起进程，不占用CPU，只有收到信号时才被唤醒
        ngx_master_process_cycle(cycle);
    }
    // 只有退出无限循环才会走到这里，进程结束
    return 0;
	
}
