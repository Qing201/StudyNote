#ifndef RTW_HEADER_HW5_sim_h_
#define RTW_HEADER_HW5_sim_h_
#ifndef HW5_sim_COMMON_INCLUDES_
#define HW5_sim_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "HW5_sim_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME HW5_sim
#define NSAMPLE_TIMES (3) 
#define NINPUTS (6)       
#define NOUTPUTS (4)     
#define NBLOCKIO (48) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T hwmoizm0ye ; real_T kzvy3titto ; real_T lp1qgfnuuz ;
real_T h3josjzur5 ; real_T fmqavzboq1 ; real_T hjhmihyuud ; real_T iocckuocqg
; real_T il4ayqxmuy ; real_T jld2awi0jx ; real_T jtelzehcmu ; real_T
iy3tu24wjk ; real_T hl2hchyres ; real_T oozgi2njxu ; real_T kkhraxukkn ;
real_T lsleczrjje ; real_T ka05nlngqp ; real_T gftxfha5ro ; real_T hv5trkptnw
; real_T jsyknjiify ; real_T csez4l45o3 ; real_T bvcuag0d3p ; real_T
p2kizzvjy3 ; real_T h2ramy4d1c ; real_T bctyn0yrqa ; real_T ab0mykk1co ;
real_T bonrdawaw5 ; real_T naqbe3u3ud ; real_T iajjiyogfp ; real_T ddrthqauz4
; real_T jaiyzyldok ; real_T ks3e0svdtz ; real_T nyceo035lz ; real_T
nsvzg5algh ; real_T ihosm1pz0g ; real_T dejjiejrin ; real_T cizscq1sw4 ;
real_T fsvnxj5ynv ; real_T lafdwvckf2 ; real_T mwqwzainfe ; real_T lros0otsma
; real_T ozztfn05zr ; real_T l2ksnmiraw ; real_T ix2nvwe0x2 ; real_T
aacdsvzieh ; real_T kd0ya5vcjw ; real_T cpvj421e05 ; real_T gq5jpt5p2u ;
real_T jebxurxfgo ; } B ; typedef struct { real_T mtuo1v54ty ; real_T
hybk40orem ; real_T hxub5saz4o ; real_T bywaizwgzx ; real_T f0fjdbsara ;
real_T kv4jq3tyb1 ; real_T irtdsvamki ; real_T cy0m2oiya3 ; struct { void *
AQHandles ; } no03ghugi2 ; struct { void * AQHandles ; } mv25iqug5i ; struct
{ void * AQHandles ; } gxvvjf4hyo ; struct { void * AQHandles ; } ck1wyygg4j
; struct { void * LoggedData [ 2 ] ; } fr5oaab5kk ; int_T hwrcjed54g ; } DW ;
typedef struct { real_T louenfu4j3 ; real_T ovba1lixn5 ; real_T ml2cz0kqyc ;
real_T cnaguseta4 ; real_T n15ezeuncm ; real_T pn4ythp3ee ; } X ; typedef
struct { real_T louenfu4j3 ; real_T ovba1lixn5 ; real_T ml2cz0kqyc ; real_T
cnaguseta4 ; real_T n15ezeuncm ; real_T pn4ythp3ee ; } XDot ; typedef struct
{ boolean_T louenfu4j3 ; boolean_T ovba1lixn5 ; boolean_T ml2cz0kqyc ;
boolean_T cnaguseta4 ; boolean_T n15ezeuncm ; boolean_T pn4ythp3ee ; } XDis ;
typedef struct { real_T louenfu4j3 ; real_T ovba1lixn5 ; real_T ml2cz0kqyc ;
real_T cnaguseta4 ; real_T n15ezeuncm ; real_T pn4ythp3ee ; } CStateAbsTol ;
typedef struct { real_T louenfu4j3 ; real_T ovba1lixn5 ; real_T ml2cz0kqyc ;
real_T cnaguseta4 ; real_T n15ezeuncm ; real_T pn4ythp3ee ; } CXPtMin ;
typedef struct { real_T louenfu4j3 ; real_T ovba1lixn5 ; real_T ml2cz0kqyc ;
real_T cnaguseta4 ; real_T n15ezeuncm ; real_T pn4ythp3ee ; } CXPtMax ;
typedef struct { real_T iyircbjly2 ; } ZCV ; typedef struct { real_T
ce1kq1rqey ; real_T eblh3fznxy ; real_T l4rpivvxbk ; real_T anmcxa5dhs ;
real_T mxa5sihpkd ; real_T fqntl21wl0 ; } ExtU ; typedef struct { real_T
bnevnxqxd2 ; real_T hlnfv1c050 ; real_T izy2lzutgr ; real_T g4inypf1hv ; }
ExtY ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T J_p ; real_T K_is_theta ; real_T K_isz ; real_T K_s_theta ;
real_T K_sz ; real_T K_t ; real_T K_theta ; real_T L ; real_T b_p ; real_T
b_theta ; real_T b_z ; real_T f_theta ; real_T f_z ; real_T theta_mag ;
real_T z_mag ; real_T Integrator2_IC ; real_T Integrator5_IC ; real_T
Multiply10_Gain ; real_T Z_ast_s_Bias ; real_T Z_ast_s_Phase ; real_T
Integrator_IC ; real_T V_ast_s_Bias ; real_T V_ast_s_Phase ; real_T
Multiply3_Gain ; real_T Integrator3_IC ; real_T Theta_ast_s_Bias ; real_T
Theta_ast_s_Phase ; real_T Omega_ast_s_Bias ; real_T Omega_ast_s_Phase ;
real_T F_d_Time ; real_T F_d_Y0 ; real_T F_d_YFinal ; real_T Multiply11_Gain
; real_T Multiply23_Gain ; real_T Integrator4_IC ; real_T Integrator1_IC ;
real_T Multiply5_Gain ; real_T T_d_Value ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtU rtU ; extern ExtY rtY ; extern P rtP ; extern mxArray *
mr_HW5_sim_GetDWork ( ) ; extern void mr_HW5_sim_SetDWork ( const mxArray *
ssDW ) ; extern mxArray * mr_HW5_sim_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * HW5_sim_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
