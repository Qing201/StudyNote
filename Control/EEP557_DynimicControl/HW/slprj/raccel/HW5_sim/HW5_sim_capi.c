#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "HW5_sim_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "HW5_sim.h"
#include "HW5_sim_capi.h"
#include "HW5_sim_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Derivative" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 1 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Derivative1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3
, 0 , TARGET_STRING ( "HW5_sim/Subsystem/Gain1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 6 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply10" ) , TARGET_STRING
( "Z_s" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply12" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 }
, { 8 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply14" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply15" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 10 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply16" ) , TARGET_STRING
( "Theta_s" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply17" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 }
, { 12 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply18" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 14 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply20" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply21" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 16 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply22" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply23" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 18 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply24" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply25" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 20 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply26" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply27" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 22 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply3" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 24 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply5" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 26 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply7" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply8" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 28 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply9" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 30 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Integrator2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 32 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Integrator3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Integrator4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 34 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Integrator5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Z_ast_s" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 36 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Add10" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
39 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add11" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add12" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Add2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
42 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Add5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
45 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add7" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING ( "HW5_sim/Subsystem/Add8" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
"HW5_sim/Subsystem/Add9" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 48 , TARGET_STRING (
"HW5_sim/Subsystem/T_d" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 49 ,
TARGET_STRING ( "HW5_sim/Subsystem/Multiply10" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 50 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply11" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"HW5_sim/Subsystem/Multiply23" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
52 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply3" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 53 , TARGET_STRING ( "HW5_sim/Subsystem/Multiply5" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"HW5_sim/Subsystem/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 ,
0 , 0 } , { 55 , TARGET_STRING ( "HW5_sim/Subsystem/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
"HW5_sim/Subsystem/Integrator2" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 57 , TARGET_STRING ( "HW5_sim/Subsystem/Integrator3" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"HW5_sim/Subsystem/Integrator4" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 59 , TARGET_STRING ( "HW5_sim/Subsystem/Integrator5" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"HW5_sim/Subsystem/Omega_ast_s" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } ,
{ 61 , TARGET_STRING ( "HW5_sim/Subsystem/Omega_ast_s" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"HW5_sim/Subsystem/Theta_ast_s" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } ,
{ 63 , TARGET_STRING ( "HW5_sim/Subsystem/Theta_ast_s" ) , TARGET_STRING (
"Phase" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING ( "HW5_sim/Subsystem/V_ast_s"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"HW5_sim/Subsystem/V_ast_s" ) , TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , {
66 , TARGET_STRING ( "HW5_sim/Subsystem/Z_ast_s" ) , TARGET_STRING ( "Bias" )
, 0 , 0 , 0 } , { 67 , TARGET_STRING ( "HW5_sim/Subsystem/Z_ast_s" ) ,
TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , { 68 , TARGET_STRING (
"HW5_sim/Subsystem/F_d" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 69 ,
TARGET_STRING ( "HW5_sim/Subsystem/F_d" ) , TARGET_STRING ( "Before" ) , 0 ,
0 , 0 } , { 70 , TARGET_STRING ( "HW5_sim/Subsystem/F_d" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 71 , 0 , TARGET_STRING ( "HW5_sim/Z_ast_s" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 72 , 0 , TARGET_STRING (
"HW5_sim/V_ast_s" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 73 , 0 ,
TARGET_STRING ( "HW5_sim/Q_ast_s" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 ,
0 } , { 74 , 0 , TARGET_STRING ( "HW5_sim/Omega_ast_s" ) , TARGET_STRING ( ""
) , 4 , 0 , 0 , 0 , 0 } , { 75 , 0 , TARGET_STRING ( "HW5_sim/F_d" ) ,
TARGET_STRING ( "" ) , 5 , 0 , 0 , 0 , 0 } , { 76 , 0 , TARGET_STRING (
"HW5_sim/T_d" ) , TARGET_STRING ( "" ) , 6 , 0 , 0 , 0 , 0 } , { 0 , 0 , (
NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals
rtRootOutputs [ ] = { { 77 , 0 , TARGET_STRING ( "HW5_sim/V_s" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 78 , 0 , TARGET_STRING (
"HW5_sim/Z_s" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 79 , 0 ,
TARGET_STRING ( "HW5_sim/Theta_s" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 ,
0 } , { 80 , 0 , TARGET_STRING ( "HW5_sim/Omega_s" ) , TARGET_STRING ( "" ) ,
4 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 81 ,
TARGET_STRING ( "J_p" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING ( "K_is_theta" )
, 0 , 0 , 0 } , { 83 , TARGET_STRING ( "K_isz" ) , 0 , 0 , 0 } , { 84 ,
TARGET_STRING ( "K_s_theta" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING ( "K_sz" )
, 0 , 0 , 0 } , { 86 , TARGET_STRING ( "K_t" ) , 0 , 0 , 0 } , { 87 ,
TARGET_STRING ( "K_theta" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING ( "L" ) , 0
, 0 , 0 } , { 89 , TARGET_STRING ( "b_p" ) , 0 , 0 , 0 } , { 90 ,
TARGET_STRING ( "b_theta" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING ( "b_z" ) ,
0 , 0 , 0 } , { 92 , TARGET_STRING ( "f_theta" ) , 0 , 0 , 0 } , { 93 ,
TARGET_STRING ( "f_z" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING ( "theta_mag" )
, 0 , 0 , 0 } , { 95 , TARGET_STRING ( "z_mag" ) , 0 , 0 , 0 } , { 0 , ( NULL
) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . iocckuocqg , & rtB . jtelzehcmu ,
& rtB . mwqwzainfe , & rtB . dejjiejrin , & rtB . lsleczrjje , & rtB .
kkhraxukkn , & rtB . hjhmihyuud , & rtB . aacdsvzieh , & rtB . h2ramy4d1c , &
rtB . bvcuag0d3p , & rtB . jld2awi0jx , & rtB . jebxurxfgo , & rtB .
ddrthqauz4 , & rtB . gftxfha5ro , & rtB . ab0mykk1co , & rtB . naqbe3u3ud , &
rtB . jaiyzyldok , & rtB . nyceo035lz , & rtB . nsvzg5algh , & rtB .
ks3e0svdtz , & rtB . cpvj421e05 , & rtB . h3josjzur5 , & rtB . jsyknjiify , &
rtB . lros0otsma , & rtB . l2ksnmiraw , & rtB . ix2nvwe0x2 , & rtB .
ozztfn05zr , & rtB . gq5jpt5p2u , & rtB . kzvy3titto , & rtB . oozgi2njxu , &
rtB . lafdwvckf2 , & rtB . hwmoizm0ye , & rtB . csez4l45o3 , & rtB .
ihosm1pz0g , & rtB . lp1qgfnuuz , & rtB . iy3tu24wjk , & rtB . hl2hchyres , &
rtB . hv5trkptnw , & rtB . iajjiyogfp , & rtB . cizscq1sw4 , & rtB .
il4ayqxmuy , & rtB . ka05nlngqp , & rtB . fsvnxj5ynv , & rtB . kd0ya5vcjw , &
rtB . fmqavzboq1 , & rtB . p2kizzvjy3 , & rtB . bonrdawaw5 , & rtB .
bctyn0yrqa , & rtP . T_d_Value , & rtP . Multiply10_Gain , & rtP .
Multiply11_Gain , & rtP . Multiply23_Gain , & rtP . Multiply3_Gain , & rtP .
Multiply5_Gain , & rtP . Integrator_IC , & rtP . Integrator1_IC , & rtP .
Integrator2_IC , & rtP . Integrator3_IC , & rtP . Integrator4_IC , & rtP .
Integrator5_IC , & rtP . Omega_ast_s_Bias , & rtP . Omega_ast_s_Phase , & rtP
. Theta_ast_s_Bias , & rtP . Theta_ast_s_Phase , & rtP . V_ast_s_Bias , & rtP
. V_ast_s_Phase , & rtP . Z_ast_s_Bias , & rtP . Z_ast_s_Phase , & rtP .
F_d_Time , & rtP . F_d_Y0 , & rtP . F_d_YFinal , & rtU . ce1kq1rqey , & rtU .
eblh3fznxy , & rtU . l4rpivvxbk , & rtU . anmcxa5dhs , & rtU . mxa5sihpkd , &
rtU . fqntl21wl0 , & rtY . bnevnxqxd2 , & rtY . hlnfv1c050 , & rtY .
izy2lzutgr , & rtY . g4inypf1hv , & rtP . J_p , & rtP . K_is_theta , & rtP .
K_isz , & rtP . K_s_theta , & rtP . K_sz , & rtP . K_t , & rtP . K_theta , &
rtP . L , & rtP . b_p , & rtP . b_theta , & rtP . b_z , & rtP . f_theta , &
rtP . f_z , & rtP . theta_mag , & rtP . z_mag , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0
} , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 48 , rtRootInputs , 6 , rtRootOutputs , 4 }
, { rtBlockParameters , 23 , rtModelParameters , 15 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 985608106U , 3895850409U , 1789772628U ,
649543201U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * HW5_sim_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void HW5_sim_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void HW5_sim_host_InitializeDataMapInfo ( HW5_sim_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
