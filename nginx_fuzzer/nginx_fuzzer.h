

#include <ngx_config.h>
#include <ngx_core.h>
#include <nginx.h>
//extern "C" int ngx_cdecl ngx_main(int argc, char *const *argv);
extern void before_process_cycle(int argc, char *const *argv,ngx_cycle_t** cycle,ngx_int_t	*returnValue);
extern void ngx_single_process_cycle(ngx_cycle_t *cycle);
extern  void ngx_master_process_cycle(ngx_cycle_t *cycle);
