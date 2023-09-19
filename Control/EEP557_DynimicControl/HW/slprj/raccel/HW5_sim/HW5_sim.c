#include "HW5_sim.h"
#include "mwmathutil.h"
#include "rtwtypes.h"
#include "HW5_sim_private.h"
#include <string.h>
#include "rt_logging_mmi.h"
#include "HW5_sim_capi.h"
#include "HW5_sim_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.6 (R2022b) 13-May-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 6 ; const int_T
gblNumModelInputs = 6 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ 0 , 0 , 0 , 0 , 0 , 0 } ; const int_T gblInportDims [ ] = { 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; const int_T gblInportComplex [ ] = { 0 , 0
, 0 , 0 , 0 , 0 } ; const int_T gblInportInterpoFlag [ ] = { 1 , 1 , 1 , 1 ,
1 , 1 } ; const int_T gblInportContinuous [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ;
int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; ExtU rtU ; ExtY rtY ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; void MdlInitialize ( void ) { rtX .
louenfu4j3 = rtP . Integrator2_IC ; rtX . ovba1lixn5 = rtP . Integrator5_IC ;
rtDW . mtuo1v54ty = ( rtInf ) ; rtDW . hxub5saz4o = ( rtInf ) ; rtDW .
f0fjdbsara = ( rtInf ) ; rtDW . irtdsvamki = ( rtInf ) ; rtX . ml2cz0kqyc =
rtP . Integrator_IC ; rtX . cnaguseta4 = rtP . Integrator3_IC ; rtX .
n15ezeuncm = rtP . Integrator4_IC ; rtX . pn4ythp3ee = rtP . Integrator1_IC ;
} void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ;
void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) {
rtwISigstreamManagerSetDestinationBase ( pISigstreamManager , 0 , & rtU .
ce1kq1rqey ) ; rtwISigstreamManagerSetDestinationBase ( pISigstreamManager ,
1 , & rtU . eblh3fznxy ) ; rtwISigstreamManagerSetDestinationBase (
pISigstreamManager , 2 , & rtU . l4rpivvxbk ) ;
rtwISigstreamManagerSetDestinationBase ( pISigstreamManager , 3 , & rtU .
anmcxa5dhs ) ; rtwISigstreamManagerSetDestinationBase ( pISigstreamManager ,
4 , & rtU . mxa5sihpkd ) ; rtwISigstreamManagerSetDestinationBase (
pISigstreamManager , 5 , & rtU . fqntl21wl0 ) ; } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "HW5_sim/V_s" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. no03ghugi2 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b553f592-43c7-4b43-b0e2-227fe04b4e12" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . no03ghugi2 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . no03ghugi2 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . no03ghugi2 . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
no03ghugi2 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . no03ghugi2 .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . no03ghugi2 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . no03ghugi2 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . no03ghugi2 . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . no03ghugi2 . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "HW5_sim/Z_s" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. mv25iqug5i . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"5adb5ad9-f4a2-401e-a844-47d94ca8d472" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . mv25iqug5i . AQHandles , hDT , & srcInfo ) ; if ( rtDW . mv25iqug5i .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . mv25iqug5i . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
mv25iqug5i . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . mv25iqug5i .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . mv25iqug5i . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . mv25iqug5i . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . mv25iqug5i . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . mv25iqug5i . AQHandles , 2 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "HW5_sim/Theta_s" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. gxvvjf4hyo . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"4936925e-8276-4414-b4d1-d3d9fc07d2cb" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . gxvvjf4hyo . AQHandles , hDT , & srcInfo ) ; if ( rtDW . gxvvjf4hyo .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . gxvvjf4hyo . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
gxvvjf4hyo . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . gxvvjf4hyo .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . gxvvjf4hyo . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . gxvvjf4hyo . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . gxvvjf4hyo . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . gxvvjf4hyo . AQHandles , 3 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "HW5_sim/Omega_s" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. ck1wyygg4j . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"10ad5899-d9b1-43ee-b3ef-f860433de5fb" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . ck1wyygg4j . AQHandles , hDT , & srcInfo ) ; if ( rtDW . ck1wyygg4j .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ck1wyygg4j . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
ck1wyygg4j . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ck1wyygg4j .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . ck1wyygg4j . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . ck1wyygg4j . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . ck1wyygg4j . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . ck1wyygg4j . AQHandles , 4 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T lastTime ; real_T lc3brqegeu ; real_T *
lastU ; if ( gblInportFileName != ( NULL ) ) { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( slIsRapidAcceleratorSimulating ( ) &&
externalInputIsInDatasetFormat ) { const int maxErrorBufferSize = 16384 ;
char errMsg [ 16384 ] ; bool bSetErrorStatus = false ; if ( 1 ) { { real_T
time = ssGetTaskTime ( rtS , 0 ) ; if ( !
rtwISigstreamManagerIsPeriodicFcnCall ( pISigstreamManager , 0 ) ) { int_T
sampleHit = 0U ; bSetErrorStatus = rtwISigstreamManagerInjectDataMultiRate (
pISigstreamManager , 0 , time , 1 , "<Root>/Z_ast_s" , "[t, u]" , & sampleHit
, errMsg , maxErrorBufferSize ) ; } } } if ( 1 ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; if ( ! rtwISigstreamManagerIsPeriodicFcnCall (
pISigstreamManager , 1 ) ) { int_T sampleHit = 0U ; bSetErrorStatus =
rtwISigstreamManagerInjectDataMultiRate ( pISigstreamManager , 1 , time , 1 ,
"<Root>/V_ast_s" , "[t, u]" , & sampleHit , errMsg , maxErrorBufferSize ) ; }
} } if ( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; if ( !
rtwISigstreamManagerIsPeriodicFcnCall ( pISigstreamManager , 2 ) ) { int_T
sampleHit = 0U ; bSetErrorStatus = rtwISigstreamManagerInjectDataMultiRate (
pISigstreamManager , 2 , time , 1 , "<Root>/Q_ast_s" , "[t, u]" , & sampleHit
, errMsg , maxErrorBufferSize ) ; } } } if ( 1 ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; if ( ! rtwISigstreamManagerIsPeriodicFcnCall (
pISigstreamManager , 3 ) ) { int_T sampleHit = 0U ; bSetErrorStatus =
rtwISigstreamManagerInjectDataMultiRate ( pISigstreamManager , 3 , time , 1 ,
"<Root>/Omega_ast_s" , "[t, u]" , & sampleHit , errMsg , maxErrorBufferSize )
; } } } if ( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; if ( !
rtwISigstreamManagerIsPeriodicFcnCall ( pISigstreamManager , 4 ) ) { int_T
sampleHit = 0U ; bSetErrorStatus = rtwISigstreamManagerInjectDataMultiRate (
pISigstreamManager , 4 , time , 1 , "<Root>/F_d" , "[t, u]" , & sampleHit ,
errMsg , maxErrorBufferSize ) ; } } } if ( 1 ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; if ( ! rtwISigstreamManagerIsPeriodicFcnCall (
pISigstreamManager , 5 ) ) { int_T sampleHit = 0U ; bSetErrorStatus =
rtwISigstreamManagerInjectDataMultiRate ( pISigstreamManager , 5 , time , 1 ,
"<Root>/T_d" , "[t, u]" , & sampleHit , errMsg , maxErrorBufferSize ) ; } } }
if ( bSetErrorStatus ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } }
else { int_T currTimeIdx ; int_T i ; if ( gblInportTUtables [ 0 ] .
nTimePoints > 0 ) { if ( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ;
int k = 1 ; if ( gblInportTUtables [ 0 ] . nTimePoints == 1 ) { k = 0 ; }
currTimeIdx = rt_getTimeIdx ( gblInportTUtables [ 0 ] . time , time ,
gblInportTUtables [ 0 ] . nTimePoints , * ( gblInportTUtables [ 0 ] .
currTimeIdx ) , 1 , 0 ) ; ( * gblInportTUtables [ 0 ] . currTimeIdx ) =
currTimeIdx ; for ( i = 0 ; i < 1 ; i ++ ) { real_T * realPtr1 = ( real_T * )
gblInportTUtables [ 0 ] . ur + i * gblInportTUtables [ 0 ] . nTimePoints +
currTimeIdx ; real_T * realPtr2 = realPtr1 + 1 * k ; ( void )
rt_Interpolate_Datatype ( realPtr1 , realPtr2 , & rtU . ce1kq1rqey , time ,
gblInportTUtables [ 0 ] . time [ currTimeIdx ] , gblInportTUtables [ 0 ] .
time [ currTimeIdx + k ] , gblInportTUtables [ 0 ] . uDataType ) ; } } } } if
( gblInportTUtables [ 1 ] . nTimePoints > 0 ) { if ( 1 ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if ( gblInportTUtables [ 1 ] .
nTimePoints == 1 ) { k = 0 ; } currTimeIdx = rt_getTimeIdx (
gblInportTUtables [ 1 ] . time , time , gblInportTUtables [ 1 ] . nTimePoints
, * ( gblInportTUtables [ 1 ] . currTimeIdx ) , 1 , 0 ) ; ( *
gblInportTUtables [ 1 ] . currTimeIdx ) = currTimeIdx ; for ( i = 0 ; i < 1 ;
i ++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 1 ] . ur + i *
gblInportTUtables [ 1 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . eblh3fznxy , time , gblInportTUtables [ 1 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 1 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 1 ]
. uDataType ) ; } } } } if ( gblInportTUtables [ 2 ] . nTimePoints > 0 ) { if
( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 2 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 2 ] . time , time , gblInportTUtables [ 2
] . nTimePoints , * ( gblInportTUtables [ 2 ] . currTimeIdx ) , 1 , 0 ) ; ( *
gblInportTUtables [ 2 ] . currTimeIdx ) = currTimeIdx ; for ( i = 0 ; i < 1 ;
i ++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 2 ] . ur + i *
gblInportTUtables [ 2 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . l4rpivvxbk , time , gblInportTUtables [ 2 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 2 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 2 ]
. uDataType ) ; } } } } if ( gblInportTUtables [ 3 ] . nTimePoints > 0 ) { if
( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 3 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 3 ] . time , time , gblInportTUtables [ 3
] . nTimePoints , * ( gblInportTUtables [ 3 ] . currTimeIdx ) , 1 , 0 ) ; ( *
gblInportTUtables [ 3 ] . currTimeIdx ) = currTimeIdx ; for ( i = 0 ; i < 1 ;
i ++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 3 ] . ur + i *
gblInportTUtables [ 3 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . anmcxa5dhs , time , gblInportTUtables [ 3 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 3 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 3 ]
. uDataType ) ; } } } } if ( gblInportTUtables [ 4 ] . nTimePoints > 0 ) { if
( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 4 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 4 ] . time , time , gblInportTUtables [ 4
] . nTimePoints , * ( gblInportTUtables [ 4 ] . currTimeIdx ) , 1 , 0 ) ; ( *
gblInportTUtables [ 4 ] . currTimeIdx ) = currTimeIdx ; for ( i = 0 ; i < 1 ;
i ++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 4 ] . ur + i *
gblInportTUtables [ 4 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . mxa5sihpkd , time , gblInportTUtables [ 4 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 4 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 4 ]
. uDataType ) ; } } } } if ( gblInportTUtables [ 5 ] . nTimePoints > 0 ) { if
( 1 ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 5 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 5 ] . time , time , gblInportTUtables [ 5
] . nTimePoints , * ( gblInportTUtables [ 5 ] . currTimeIdx ) , 1 , 0 ) ; ( *
gblInportTUtables [ 5 ] . currTimeIdx ) = currTimeIdx ; for ( i = 0 ; i < 1 ;
i ++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 5 ] . ur + i *
gblInportTUtables [ 5 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . fqntl21wl0 , time , gblInportTUtables [ 5 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 5 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 5 ]
. uDataType ) ; } } } } } } rtB . hwmoizm0ye = rtX . louenfu4j3 ; rtB .
kzvy3titto = rtP . K_theta * rtB . hwmoizm0ye ; rtB . lp1qgfnuuz = rtX .
ovba1lixn5 ; rtB . h3josjzur5 = rtP . K_theta * rtB . lp1qgfnuuz ; rtB .
fmqavzboq1 = rtB . kzvy3titto + rtB . h3josjzur5 ; rtB . hjhmihyuud = rtP .
Multiply10_Gain * rtB . fmqavzboq1 ; if ( ( rtDW . mtuo1v54ty >= ssGetT ( rtS
) ) && ( rtDW . hxub5saz4o >= ssGetT ( rtS ) ) ) { rtB . iocckuocqg = 0.0 ; }
else { lastTime = rtDW . mtuo1v54ty ; lastU = & rtDW . hybk40orem ; if ( rtDW
. mtuo1v54ty < rtDW . hxub5saz4o ) { if ( rtDW . hxub5saz4o < ssGetT ( rtS )
) { lastTime = rtDW . hxub5saz4o ; lastU = & rtDW . bywaizwgzx ; } } else if
( rtDW . mtuo1v54ty >= ssGetT ( rtS ) ) { lastTime = rtDW . hxub5saz4o ;
lastU = & rtDW . bywaizwgzx ; } rtB . iocckuocqg = ( rtB . hjhmihyuud - *
lastU ) / ( ssGetT ( rtS ) - lastTime ) ; } rtY . bnevnxqxd2 = rtB .
iocckuocqg ; rtY . hlnfv1c050 = rtB . hjhmihyuud ; rtB . il4ayqxmuy = rtB .
kzvy3titto - rtB . h3josjzur5 ; rtB . jld2awi0jx = 1.0 / rtP . L * rtB .
il4ayqxmuy ; rtY . izy2lzutgr = rtB . jld2awi0jx ; if ( ( rtDW . f0fjdbsara
>= ssGetT ( rtS ) ) && ( rtDW . irtdsvamki >= ssGetT ( rtS ) ) ) { rtB .
jtelzehcmu = 0.0 ; } else { lastTime = rtDW . f0fjdbsara ; lastU = & rtDW .
kv4jq3tyb1 ; if ( rtDW . f0fjdbsara < rtDW . irtdsvamki ) { if ( rtDW .
irtdsvamki < ssGetT ( rtS ) ) { lastTime = rtDW . irtdsvamki ; lastU = & rtDW
. cy0m2oiya3 ; } } else if ( rtDW . f0fjdbsara >= ssGetT ( rtS ) ) { lastTime
= rtDW . irtdsvamki ; lastU = & rtDW . cy0m2oiya3 ; } rtB . jtelzehcmu = (
rtB . jld2awi0jx - * lastU ) / ( ssGetT ( rtS ) - lastTime ) ; } rtY .
g4inypf1hv = rtB . jtelzehcmu ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . no03ghugi2 . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . no03ghugi2 . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. iocckuocqg + 0 ) ; } } { if ( rtDW . mv25iqug5i . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . mv25iqug5i . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . hjhmihyuud + 0 ) ; } } { if (
rtDW . gxvvjf4hyo . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . gxvvjf4hyo . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. jld2awi0jx + 0 ) ; } } { if ( rtDW . ck1wyygg4j . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . ck1wyygg4j . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . jtelzehcmu + 0 ) ; } } } rtB .
iy3tu24wjk = muDoubleScalarSin ( 6.2831853071795862 * rtP . f_z *
ssGetTaskTime ( rtS , 0 ) + rtP . Z_ast_s_Phase ) * rtP . z_mag + rtP .
Z_ast_s_Bias ; rtB . hl2hchyres = rtB . iy3tu24wjk - rtB . hjhmihyuud ; rtB .
oozgi2njxu = rtX . ml2cz0kqyc ; rtB . kkhraxukkn = rtP . K_isz * rtB .
oozgi2njxu ; rtB . lsleczrjje = rtP . K_sz * rtB . hl2hchyres ; rtB .
ka05nlngqp = ( muDoubleScalarSin ( 6.2831853071795862 * rtP . f_z *
ssGetTaskTime ( rtS , 0 ) + rtP . V_ast_s_Phase ) * rtP . z_mag + rtP .
V_ast_s_Bias ) - rtB . iocckuocqg ; rtB . gftxfha5ro = rtP . b_z * rtB .
ka05nlngqp ; rtB . hv5trkptnw = ( rtB . kkhraxukkn + rtB . lsleczrjje ) + rtB
. gftxfha5ro ; rtB . jsyknjiify = rtP . Multiply3_Gain * rtB . hv5trkptnw ;
rtB . csez4l45o3 = rtX . cnaguseta4 ; rtB . bvcuag0d3p = rtP . K_is_theta *
rtB . csez4l45o3 ; rtB . p2kizzvjy3 = rtB . jld2awi0jx - ( muDoubleScalarSin
( 6.2831853071795862 * rtP . f_theta * ssGetTaskTime ( rtS , 0 ) + rtP .
Theta_ast_s_Phase ) * rtP . theta_mag + rtP . Theta_ast_s_Bias ) ; rtB .
h2ramy4d1c = rtP . K_s_theta * rtB . p2kizzvjy3 ; rtB . bctyn0yrqa = (
muDoubleScalarSin ( 6.2831853071795862 * rtP . f_theta * ssGetTaskTime ( rtS
, 0 ) + rtP . Omega_ast_s_Phase ) * rtP . theta_mag + rtP . Omega_ast_s_Bias
) - rtB . jtelzehcmu ; rtB . ab0mykk1co = rtP . b_theta * rtB . bctyn0yrqa ;
rtB . bonrdawaw5 = ( rtB . bvcuag0d3p + rtB . h2ramy4d1c ) + rtB . ab0mykk1co
; rtB . naqbe3u3ud = 1.0 / rtP . L * rtB . bonrdawaw5 ; rtB . iajjiyogfp =
rtB . jsyknjiify - rtB . naqbe3u3ud ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtDW . hwrcjed54g = ( ssGetTaskTime ( rtS , 1 ) >= rtP . F_d_Time ) ; if (
rtDW . hwrcjed54g == 1 ) { lastTime = rtP . F_d_YFinal ; } else { lastTime =
rtP . F_d_Y0 ; } lc3brqegeu = rtP . Multiply11_Gain * lastTime ; rtB .
ddrthqauz4 = ( lc3brqegeu - rtB . jebxurxfgo ) * rtP . K_theta ; } rtB .
jaiyzyldok = rtP . K_theta * rtB . iajjiyogfp ; rtB . ks3e0svdtz = 1.0 / rtP
. K_t * rtB . jaiyzyldok ; rtB . nyceo035lz = rtP . Multiply23_Gain * rtB .
ks3e0svdtz ; rtB . nsvzg5algh = rtP . K_t * rtB . nyceo035lz ; rtB .
ihosm1pz0g = rtX . n15ezeuncm ; rtB . dejjiejrin = rtP . b_p * rtB .
ihosm1pz0g ; rtB . cizscq1sw4 = ( rtB . ddrthqauz4 + rtB . nsvzg5algh ) - rtB
. dejjiejrin ; rtB . fsvnxj5ynv = rtB . jsyknjiify + rtB . naqbe3u3ud ; rtB .
lafdwvckf2 = rtX . pn4ythp3ee ; rtB . mwqwzainfe = rtP . b_p * rtB .
lafdwvckf2 ; rtB . lros0otsma = rtP . K_theta * rtB . fsvnxj5ynv ; rtB .
ozztfn05zr = 1.0 / rtP . K_t * rtB . lros0otsma ; rtB . l2ksnmiraw = rtP .
Multiply5_Gain * rtB . ozztfn05zr ; rtB . ix2nvwe0x2 = rtP . K_t * rtB .
l2ksnmiraw ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . aacdsvzieh = (
lc3brqegeu + rtB . jebxurxfgo ) * rtP . K_theta ; } rtB . kd0ya5vcjw = ( rtB
. ix2nvwe0x2 - rtB . mwqwzainfe ) + rtB . aacdsvzieh ; rtB . cpvj421e05 = 1.0
/ rtP . J_p * rtB . cizscq1sw4 ; rtB . gq5jpt5p2u = 1.0 / rtP . J_p * rtB .
kd0ya5vcjw ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) {
rtB . jebxurxfgo = 1.0 / rtP . L * rtP . T_d_Value ; UNUSED_PARAMETER ( tid )
; } void MdlUpdate ( int_T tid ) { real_T * lastU ; if ( rtDW . mtuo1v54ty ==
( rtInf ) ) { rtDW . mtuo1v54ty = ssGetT ( rtS ) ; lastU = & rtDW .
hybk40orem ; } else if ( rtDW . hxub5saz4o == ( rtInf ) ) { rtDW . hxub5saz4o
= ssGetT ( rtS ) ; lastU = & rtDW . bywaizwgzx ; } else if ( rtDW .
mtuo1v54ty < rtDW . hxub5saz4o ) { rtDW . mtuo1v54ty = ssGetT ( rtS ) ; lastU
= & rtDW . hybk40orem ; } else { rtDW . hxub5saz4o = ssGetT ( rtS ) ; lastU =
& rtDW . bywaizwgzx ; } * lastU = rtB . hjhmihyuud ; if ( rtDW . f0fjdbsara
== ( rtInf ) ) { rtDW . f0fjdbsara = ssGetT ( rtS ) ; lastU = & rtDW .
kv4jq3tyb1 ; } else if ( rtDW . irtdsvamki == ( rtInf ) ) { rtDW . irtdsvamki
= ssGetT ( rtS ) ; lastU = & rtDW . cy0m2oiya3 ; } else if ( rtDW .
f0fjdbsara < rtDW . irtdsvamki ) { rtDW . f0fjdbsara = ssGetT ( rtS ) ; lastU
= & rtDW . kv4jq3tyb1 ; } else { rtDW . irtdsvamki = ssGetT ( rtS ) ; lastU =
& rtDW . cy0m2oiya3 ; } * lastU = rtB . jld2awi0jx ; UNUSED_PARAMETER ( tid )
; } void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> louenfu4j3 = rtB . lafdwvckf2 ; _rtXdot -> ovba1lixn5 =
rtB . ihosm1pz0g ; _rtXdot -> ml2cz0kqyc = rtB . hl2hchyres ; _rtXdot ->
cnaguseta4 = rtB . p2kizzvjy3 ; _rtXdot -> n15ezeuncm = rtB . cpvj421e05 ;
_rtXdot -> pn4ythp3ee = rtB . gq5jpt5p2u ; } void MdlProjection ( void ) { }
void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> iyircbjly2 = ssGetT ( rtS )
- rtP . F_d_Time ; } void MdlTerminate ( void ) { { if ( rtDW . no03ghugi2 .
AQHandles ) { sdiTerminateStreaming ( & rtDW . no03ghugi2 . AQHandles ) ; } }
{ if ( rtDW . mv25iqug5i . AQHandles ) { sdiTerminateStreaming ( & rtDW .
mv25iqug5i . AQHandles ) ; } } { if ( rtDW . gxvvjf4hyo . AQHandles ) {
sdiTerminateStreaming ( & rtDW . gxvvjf4hyo . AQHandles ) ; } } { if ( rtDW .
ck1wyygg4j . AQHandles ) { sdiTerminateStreaming ( & rtDW . ck1wyygg4j .
AQHandles ) ; } } } static void mr_HW5_sim_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_HW5_sim_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_HW5_sim_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_HW5_sim_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_HW5_sim_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_HW5_sim_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_HW5_sim_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_HW5_sim_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_HW5_sim_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_HW5_sim_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_HW5_sim_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_HW5_sim_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_HW5_sim_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_HW5_sim_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_HW5_sim_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_HW5_sim_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_HW5_sim_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_HW5_sim_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 9 ] = {
"rtDW.mtuo1v54ty" , "rtDW.hybk40orem" , "rtDW.hxub5saz4o" , "rtDW.bywaizwgzx"
, "rtDW.f0fjdbsara" , "rtDW.kv4jq3tyb1" , "rtDW.irtdsvamki" ,
"rtDW.cy0m2oiya3" , "rtDW.hwrcjed54g" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 9 , rtdwDataFieldNames ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW
. mtuo1v54ty ) , sizeof ( rtDW . mtuo1v54ty ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW
. hybk40orem ) , sizeof ( rtDW . hybk40orem ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. hxub5saz4o ) , sizeof ( rtDW . hxub5saz4o ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. bywaizwgzx ) , sizeof ( rtDW . bywaizwgzx ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW
. f0fjdbsara ) , sizeof ( rtDW . f0fjdbsara ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW
. kv4jq3tyb1 ) , sizeof ( rtDW . kv4jq3tyb1 ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW
. irtdsvamki ) , sizeof ( rtDW . irtdsvamki ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW
. cy0m2oiya3 ) , sizeof ( rtDW . cy0m2oiya3 ) ) ;
mr_HW5_sim_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & ( rtDW
. hwrcjed54g ) , sizeof ( rtDW . hwrcjed54g ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_HW5_sim_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_HW5_sim_restoreDataFromMxArray ( ( void
* ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_HW5_sim_restoreDataFromMxArray ( (
void * ) & ( rtDW . mtuo1v54ty ) , rtdwData , 0 , 0 , sizeof ( rtDW .
mtuo1v54ty ) ) ; mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hybk40orem ) , rtdwData , 0 , 1 , sizeof ( rtDW . hybk40orem ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . hxub5saz4o ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . hxub5saz4o ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . bywaizwgzx ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . bywaizwgzx ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . f0fjdbsara ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . f0fjdbsara ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . kv4jq3tyb1 ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . kv4jq3tyb1 ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . irtdsvamki ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . irtdsvamki ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . cy0m2oiya3 ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . cy0m2oiya3 ) ) ;
mr_HW5_sim_restoreDataFromMxArray ( ( void * ) & ( rtDW . hwrcjed54g ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . hwrcjed54g ) ) ; } } mxArray *
mr_HW5_sim_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 1 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 1 ] = { "Scope" , } ; static const char * blockPath [ 1 ]
= { "HW5_sim/Subsystem/Scope" , } ; static const int reason [ 1 ] = { 0 , } ;
for ( subs [ 0 ] = 0 ; subs [ 0 ] < 1 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0
; offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
6 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 4 ) ;
ssSetNumU ( rtS , 6 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 65 ) ;
ssSetNumBlockIO ( rtS , 48 ) ; ssSetNumBlockParams ( rtS , 38 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 985608106U ) ; ssSetChecksumVal ( rtS , 1 ,
3895850409U ) ; ssSetChecksumVal ( rtS , 2 , 1789772628U ) ; ssSetChecksumVal
( rtS , 3 , 649543201U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { ssSetU ( rtS , ( ( void * ) & rtU ) ) ; ( void ) memset ( & rtU
, 0 , sizeof ( ExtU ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( &
rtY , 0 , sizeof ( ExtY ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtY ) ,
"YOut" ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x )
; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
HW5_sim_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "HW5_sim" ) ; ssSetPath (
rtS , "HW5_sim" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 10.0 ) ;
{ static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval
= ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static
int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T
* rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "HW5_sim/Subsystem/Integrator2" , "HW5_sim/Subsystem/Integrator5" ,
"HW5_sim/Subsystem/Integrator" , "HW5_sim/Subsystem/Integrator3" ,
"HW5_sim/Subsystem/Integrator4" , "HW5_sim/Subsystem/Integrator1" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . louenfu4j3 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . ovba1lixn5 ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ml2cz0kqyc ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . cnaguseta4 ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . n15ezeuncm ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . pn4ythp3ee ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; { static void * rt_LoggedOutputSignalPtrs [ ] = { & rtY .
bnevnxqxd2 , & rtY . hlnfv1c050 , & rtY . izy2lzutgr , & rtY . g4inypf1hv } ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( ( LogSignalPtrsType )
rt_LoggedOutputSignalPtrs ) ) ; } { static int_T rt_LoggedOutputWidths [ ] =
{ 1 , 1 , 1 , 1 } ; static int_T rt_LoggedOutputNumDimensions [ ] = { 1 , 1 ,
1 , 1 } ; static int_T rt_LoggedOutputDimensions [ ] = { 1 , 1 , 1 , 1 } ;
static boolean_T rt_LoggedOutputIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static
void * rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) , ( NULL
) , ( NULL ) } ; static int_T rt_LoggedCurrentSignalDimensionsSize [ ] = { 4
, 4 , 4 , 4 } ; static BuiltInDTypeId rt_LoggedOutputDataTypeIds [ ] = {
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedOutputComplexSignals [ ] = { 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedOutputLabels_0 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_0 [ ] = { "HW5_sim/V_s" } ; static const char_T *
rt_LoggedOutputLabels_1 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_1 [ ] = { "HW5_sim/Z_s" } ; static const char_T *
rt_LoggedOutputLabels_2 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_2 [ ] = { "HW5_sim/Theta_s" } ; static const char_T
* rt_LoggedOutputLabels_3 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_3 [ ] = { "HW5_sim/Omega_s" } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedOutputSignalInfo [ ] = { { 1 ,
rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) ,
rt_LoggingPreprocessingFcnPtrs , { rt_LoggedOutputLabels_0 } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames_0 } , { ( NULL ) } , ( NULL )
, rt_RTWLogDataTypeConvert , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 1 ,
rt_LoggedOutputNumDimensions + 1 , rt_LoggedOutputDimensions + 1 ,
rt_LoggedOutputIsVarDims + 1 , rt_LoggedCurrentSignalDimensions + 1 ,
rt_LoggedCurrentSignalDimensionsSize + 1 , rt_LoggedOutputDataTypeIds + 1 ,
rt_LoggedOutputComplexSignals + 1 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 1 , { rt_LoggedOutputLabels_1 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_1 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 1 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 2 ,
rt_LoggedOutputNumDimensions + 2 , rt_LoggedOutputDimensions + 2 ,
rt_LoggedOutputIsVarDims + 2 , rt_LoggedCurrentSignalDimensions + 2 ,
rt_LoggedCurrentSignalDimensionsSize + 2 , rt_LoggedOutputDataTypeIds + 2 ,
rt_LoggedOutputComplexSignals + 2 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 2 , { rt_LoggedOutputLabels_2 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_2 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 2 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 3 ,
rt_LoggedOutputNumDimensions + 3 , rt_LoggedOutputDimensions + 3 ,
rt_LoggedOutputIsVarDims + 3 , rt_LoggedCurrentSignalDimensions + 3 ,
rt_LoggedCurrentSignalDimensionsSize + 3 , rt_LoggedOutputDataTypeIds + 3 ,
rt_LoggedOutputComplexSignals + 3 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 3 , { rt_LoggedOutputLabels_3 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_3 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 3 , ( NULL ) } } ; rtliSetLogYSignalInfo (
ssGetRTWLogInfo ( rtS ) , rt_LoggedOutputSignalInfo ) ;
rt_LoggedCurrentSignalDimensions [ 0 ] = & rt_LoggedOutputWidths [ 0 ] ;
rt_LoggedCurrentSignalDimensions [ 1 ] = & rt_LoggedOutputWidths [ 1 ] ;
rt_LoggedCurrentSignalDimensions [ 2 ] = & rt_LoggedOutputWidths [ 2 ] ;
rt_LoggedCurrentSignalDimensions [ 3 ] = & rt_LoggedOutputWidths [ 3 ] ; }
rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
"tmp_raccel_yout1,tmp_raccel_yout2,tmp_raccel_yout3,tmp_raccel_yout4" ) ; } {
static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , &
statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ;
static real_T absTol [ 6 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 6 ] = { 0U , 0U , 0U , 0U , 0U , 0U
} ; static real_T contStateJacPerturbBoundMinVec [ 6 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 6 ] ; static uint8_T zcAttributes [ 1 ] = {
( ZC_EVENT_ALL_UP ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 2
] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . aacdsvzieh ) , ( NULL )
} , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . ddrthqauz4 ) , ( NULL ) }
} ; { int i ; for ( i = 0 ; i < 6 ; ++ i ) { contStateJacPerturbBoundMinVec [
i ] = 0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS ,
0.033333333333333333 ) ; ssSetSolverMaxOrder ( rtS , 5 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
2 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode15s" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 1 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 1 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 985608106U ) ; ssSetChecksumVal ( rtS , 1 ,
3895850409U ) ; ssSetChecksumVal ( rtS , 2 , 1789772628U ) ; ssSetChecksumVal
( rtS , 3 , 649543201U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_HW5_sim_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_HW5_sim_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_HW5_sim_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
