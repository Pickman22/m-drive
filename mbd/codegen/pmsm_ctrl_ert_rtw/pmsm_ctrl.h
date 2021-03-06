/*
 * pmsm_ctrl.h
 *
 * Code generation for model "pmsm_ctrl".
 *
 * Model version              : 1.816
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 *
 */

#ifndef RTW_HEADER_pmsm_ctrl_h_
#define RTW_HEADER_pmsm_ctrl_h_
#include <math.h>
#ifndef pmsm_ctrl_COMMON_INCLUDES_
# define pmsm_ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pmsm_ctrl_COMMON_INCLUDES_ */

#include "pmsm_ctrl_types.h"

/* Includes for objects with custom storage classes. */
#include "cfg_params.h"
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<S18>/get_mtr_ifbk_sum' */
typedef struct {
  real32_T UnitDelay_DSTATE[3];        /* '<S21>/Unit Delay' */
} DW_get_mtr_ifbk_sum;

/* Block states (default storage) for system '<S50>/PI-Ctrl-Varying-Gains' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S54>/Discrete-Time Integrator' */
} DW_PI_Ctrl;

/* Block signals (default storage) */
typedef struct {
  MtrIf_InType BusCreator;             /* '<S6>/Bus Creator' */
  CtrlMgr_OutType BusCreator2;         /* '<S5>/Bus Creator2' */
  Calib_OutType Merge;                 /* '<S2>/Merge' */
  MotnCtrl_OutType BusCreator_c;       /* '<S4>/Bus Creator' */
  real32_T MtrIf_ModWave[3];           /* '<S28>/Data Type Conversion' */
  real32_T MtrIf_PwmDc[3];             /* '<S28>/Data Type Conversion5' */
  real32_T Saturation_g[3];            /* '<S34>/Saturation' */
  real32_T OutportBufferFormod_wave[3];/* '<S34>/Zero1' */
  real32_T Gain1[3];                   /* '<S67>/Gain1' */
  real32_T DataTypeConversion[3];      /* '<S68>/Data Type Conversion' */
  real32_T Add[3];                     /* '<S21>/Add' */
  real32_T Saturation;                 /* '<S73>/Saturation' */
  real32_T DiscreteTimeIntegrator1;    /* '<S79>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator;     /* '<S79>/Discrete-Time Integrator' */
  real32_T Saturation_b;               /* '<S71>/Saturation' */
  real32_T MtrIf_TrqAct;               /* '<S28>/Data Type Conversion2' */
  real32_T MtrIf_SpdOut;               /* '<S28>/Data Type Conversion1' */
  real32_T Gain3;                      /* '<S52>/Gain3' */
  real32_T Gain;                       /* '<S52>/Gain' */
  real32_T PwmRqst;                    /* '<S7>/EncOfsCal' */
  real32_T PwmRqst_g;                  /* '<S10>/ResIdCal' */
  int32_T Ticks;                       /* '<S7>/EncOfsCal' */
  MtrCtrlMd_T CtrlMdRqst;              /* '<S7>/EncOfsCal' */
  MtrCtrlMd_T CtrlMdRqst_i;            /* '<S9>/IndIdCal' */
  MtrCtrlMd_T CtrlMdRqst_p;            /* '<S10>/ResIdCal' */
  CalMgrSt_T CalMgrStRqst;             /* '<S7>/EncOfsCal' */
  CalMgrSt_T CalMgrStRqst_i;           /* '<S9>/IndIdCal' */
  CalMgrSt_T CalMgrStRqst_h;           /* '<S10>/ResIdCal' */
  MtrCtrlCal_T ctrl_cal_act;           /* '<S5>/Data Type Conversion' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE_h[3];      /* '<S65>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o[3];      /* '<S47>/Unit Delay' */
  real32_T ifbk_abc_sum[3];            /* '<S8>/ResIdCal' */
  real32_T UnitDelay_DSTATE;           /* '<S98>/Unit Delay' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S79>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S79>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_o;/* '<S78>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S41>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_k;/* '<S43>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_kg;/* '<S39>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTAT_ke;/* '<S40>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S38>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_j;         /* '<S12>/Unit Delay' */
  real32_T ifbk_neg;                   /* '<S9>/IndIdCal' */
  real32_T ifbk_pos;                   /* '<S9>/IndIdCal' */
  real32_T di_dt;                      /* '<S9>/IndIdCal' */
  real32_T ifbk_sum;                   /* '<S10>/ResIdCal' */
  int32_T ticks_inc;                   /* '<S7>/EncOfsCal' */
  int32_T ticks_start;                 /* '<S7>/EncOfsCal' */
  int32_T ticks_end;                   /* '<S7>/EncOfsCal' */
  int32_T TICK_TGT;                    /* '<S7>/EncOfsCal' */
  uint16_T temporalCounter_i1;         /* '<S7>/EncOfsCal' */
  uint16_T temporalCounter_i1_i;       /* '<S8>/ResIdCal' */
  uint16_T temporalCounter_i1_n;       /* '<S9>/IndIdCal' */
  int8_T If_ActiveSubsystem;           /* '<S32>/If' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S2>/Switch Case' */
  uint8_T is_active_c3_pmsm_ctrl;      /* '<S7>/EncOfsCal' */
  uint8_T is_c3_pmsm_ctrl;             /* '<S7>/EncOfsCal' */
  uint8_T is_active_c2_pmsm_ctrl;      /* '<S8>/ResIdCal' */
  uint8_T is_c2_pmsm_ctrl;             /* '<S8>/ResIdCal' */
  uint8_T is_active_c1_pmsm_ctrl;      /* '<S9>/IndIdCal' */
  uint8_T is_c1_pmsm_ctrl;             /* '<S9>/IndIdCal' */
  uint8_T is_ind_id_actv;              /* '<S9>/IndIdCal' */
  uint8_T is_active_c5_pmsm_ctrl;      /* '<S10>/ResIdCal' */
  uint8_T is_c5_pmsm_ctrl;             /* '<S10>/ResIdCal' */
  uint8_T temporalCounter_i1_l;        /* '<S10>/ResIdCal' */
  boolean_T MotnCtrl_MODE;             /* '<S4>/MotnCtrl' */
  boolean_T SpdCtrl_MODE;              /* '<S70>/SpdCtrl' */
  boolean_T PosTrackDiff_MODE;         /* '<S72>/PosTrackDiff' */
  boolean_T PosCtl_MODE;               /* '<S70>/PosCtl' */
  boolean_T mod_wave_calc_MODE;        /* '<S28>/mod_wave_calc' */
  boolean_T ifbk_trq_ctrl_MODE;        /* '<S28>/ifbk_trq_ctrl' */
} DW;

/* data stores shared across model instances, for system '<Root>' */
typedef struct {
  real32_T CalData_IfbkOfs_Abc[3];     /* '<S2>/Data Store Memory4' */
  real32_T CalData_L;                  /* '<S2>/Data Store Memory1' */
  real32_T CalData_Res;                /* '<S2>/Data Store Memory3' */
  int32_T CalData_EncOfs;              /* '<S2>/Data Store Memory' */
  int32_T CalData_nPoles;              /* '<S2>/Data Store Memory2' */
} SharedDSM;

/* Type definition for custom storage class: Struct */
typedef struct DBG_Struct_tag {
  int32_T mtr_cnts_ref;
  int32_T mtr_cnts_tgt;
  int32_T mtr_if_enc_cnts;
  int32_T obs_enc_cnts;
  real32_T e_angl;
  real32_T i_abc_lpf[3];
  real32_T i_dq0[3];
  real32_T ifbk_ctrl_dq0[3];
  real32_T ifbk_ctrl_v_dq0[3];
  real32_T motn_ctrl_cmd;
  real32_T mtr_load_obs;
  real32_T mtr_spd_obs;
  real32_T mtr_spd_pll;
  real32_T mtr_spd_tgt;
  real32_T mtrif_ifbk_act[3];
  real32_T mtrif_v_bus;
  real32_T pwm_ctrl_dq0_lpf[3];
  real32_T pwm_dq0[3];
  real32_T traj_plan_grd;
  real32_T traj_plan_ref;
  boolean_T enbl_motn_ctrl;
  boolean_T traj_plan_is_enbl;
} DBG_Struct_type;

/* model data, for system '<S18>/get_mtr_ifbk_sum' */
typedef struct {
  DW_get_mtr_ifbk_sum dwork;
} self_get_mtr_ifbk_sum;

/* model data, for system '<S50>/PI-Ctrl-Varying-Gains' */
typedef struct {
  DW_PI_Ctrl dwork;
} self_PI_Ctrl;

/* Self model data, for system '<Root>' */
struct tag_RTM {
  self_PI_Ctrl self_PICtrlVaryingGains_mi;
  self_PI_Ctrl self_PICtrlVaryingGains_b;
  self_PI_Ctrl self_PICtrlVaryingGains_m;
  self_PI_Ctrl self_PICtrlVaryingGains_p;
  self_PI_Ctrl self_PICtrlVaryingGains;
  self_get_mtr_ifbk_sum self_get_mtr_ifbk_sum_f;
  DW dwork;
  B blockIO;
};

/* data stores shared across model instances */
extern SharedDSM rtSharedDSM;

/* External data declarations for dependent source files */
extern const Calib_OutType pmsm_ctrl_rtZCalib_OutType;/* Calib_OutType ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern Calib_ParamType CALIB_PARAM_BUS;/* '<S2>/Bus Creator' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern boolean_T _pmsm_ctrl_SharedDataInit_;/* synthesized block */

/* Model entry point functions */
extern void Trig_Pmsm_Init(RT_MODEL *const pmsm_ctrl_M, CalMgrSt_T
  *rtY_CalMgr_Status);

/* Exported entry point function */
extern void Trig_Pmsm_SetIn(RT_MODEL *const pmsm_ctrl_M, int32_T
  rtU_MtrIf_EncCnts, real32_T rtU_MtrIf_IfbkAct[3], real32_T rtU_MtrIf_SpdSns,
  MtrCtrlMd_T rtU_MtrIf_CtrlMd, real32_T rtU_MtrIf_Tgt[3], real32_T
  rtU_MtrIf_VBus, MtrCtrlCal_T rtU_MtrIf_CtrlCalRqst);

/* Exported entry point function */
extern void Trig_Pmsm_CtrlMgr(RT_MODEL *const pmsm_ctrl_M);

/* Exported entry point function */
extern void Trig_Pmsm_Cal(RT_MODEL *const pmsm_ctrl_M, CalMgrSt_T
  *rtY_CalMgr_Status);

/* Exported entry point function */
extern void Trig_Pmsm_Foc(RT_MODEL *const pmsm_ctrl_M);

/* Exported entry point function */
extern void Trig_Pmsm_MotnCtrl(RT_MODEL *const pmsm_ctrl_M);

/* Exported entry point function */
extern void Trig_Pmsm_GetOut(RT_MODEL *const pmsm_ctrl_M, real32_T
  rtY_MtrIf_PwmDc[3], real32_T rtY_MtrIf_ModWave[3], real32_T *rtY_MtrIf_TrqAct,
  real32_T *rtY_MtrIf_SpdAct);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern DBG_Struct_type DBG_Struct;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion4' : Unused code path elimination
 * Block '<S1>/Data Type Conversion5' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S8>/Display' : Unused code path elimination
 * Block '<S9>/Display' : Unused code path elimination
 * Block '<S10>/Display' : Unused code path elimination
 * Block '<S28>/Data Type Conversion6' : Unused code path elimination
 * Block '<S28>/Data Type Conversion7' : Unused code path elimination
 * Block '<Root>/IfbkCtrl' : Unused code path elimination
 * Block '<S34>/Scope' : Unused code path elimination
 * Block '<Root>/DistObs' : Unused code path elimination
 * Block '<Root>/SpdCtrl' : Unused code path elimination
 * Block '<Root>/ElecAngl' : Unused code path elimination
 * Block '<S70>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion6' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pmsm_ctrl'
 * '<S1>'   : 'pmsm_ctrl/CalcOutputs'
 * '<S2>'   : 'pmsm_ctrl/CalibRoutines'
 * '<S3>'   : 'pmsm_ctrl/CtrlFast'
 * '<S4>'   : 'pmsm_ctrl/CtrlMain'
 * '<S5>'   : 'pmsm_ctrl/CtrlMgr'
 * '<S6>'   : 'pmsm_ctrl/SetInputs'
 * '<S7>'   : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine'
 * '<S8>'   : 'pmsm_ctrl/CalibRoutines/mtr_ifbk_ofs_ident'
 * '<S9>'   : 'pmsm_ctrl/CalibRoutines/mtr_ind_ident'
 * '<S10>'  : 'pmsm_ctrl/CalibRoutines/mtr_res_ident'
 * '<S11>'  : 'pmsm_ctrl/CalibRoutines/not_active'
 * '<S12>'  : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine/D-1LPF'
 * '<S13>'  : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine/EncOfsCal'
 * '<S14>'  : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine/Subsystem'
 * '<S15>'  : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine/calc_mod_wave'
 * '<S16>'  : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine/calc_mod_wave/Inverse Park Transform1'
 * '<S17>'  : 'pmsm_ctrl/CalibRoutines/enc_ofs_cal_routine/calc_mod_wave/calc_pwm_dc'
 * '<S18>'  : 'pmsm_ctrl/CalibRoutines/mtr_ifbk_ofs_ident/ResIdCal'
 * '<S19>'  : 'pmsm_ctrl/CalibRoutines/mtr_ifbk_ofs_ident/pwm_abc'
 * '<S20>'  : 'pmsm_ctrl/CalibRoutines/mtr_ifbk_ofs_ident/ResIdCal/get_mtr_ifbk_avg'
 * '<S21>'  : 'pmsm_ctrl/CalibRoutines/mtr_ifbk_ofs_ident/ResIdCal/get_mtr_ifbk_sum'
 * '<S22>'  : 'pmsm_ctrl/CalibRoutines/mtr_ind_ident/IndIdCal'
 * '<S23>'  : 'pmsm_ctrl/CalibRoutines/mtr_ind_ident/calc_dc'
 * '<S24>'  : 'pmsm_ctrl/CalibRoutines/mtr_ind_ident/calc_dc/calc_pwm_dc'
 * '<S25>'  : 'pmsm_ctrl/CalibRoutines/mtr_res_ident/ResIdCal'
 * '<S26>'  : 'pmsm_ctrl/CalibRoutines/mtr_res_ident/calc_dc'
 * '<S27>'  : 'pmsm_ctrl/CalibRoutines/mtr_res_ident/calc_dc/calc_pwm_dc'
 * '<S28>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller'
 * '<S29>'  : 'pmsm_ctrl/CtrlFast/det_ctrl_tgt'
 * '<S30>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_elec_angle'
 * '<S31>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est'
 * '<S32>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl'
 * '<S33>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/mod_wave_calc'
 * '<S34>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/raw_pwm_calc'
 * '<S35>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/DistObsJ'
 * '<S36>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/mtr_speed_pll_est'
 * '<S37>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/rads_to_cnts'
 * '<S38>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/DistObsJ/Integrator'
 * '<S39>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/DistObsJ/Integrator1'
 * '<S40>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/DistObsJ/Integrator2'
 * '<S41>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/mtr_speed_pll_est/Integrator'
 * '<S42>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/mtr_speed_pll_est/PI_Ctrl'
 * '<S43>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/calc_spd_load_est/mtr_speed_pll_est/PI_Ctrl/Integrator'
 * '<S44>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Compare To Constant'
 * '<S45>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode'
 * '<S46>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode'
 * '<S47>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/D-1LPF'
 * '<S48>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Park Transform'
 * '<S49>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl'
 * '<S50>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/ifbk_d_ctrl'
 * '<S51>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/ifbk_q_ctrl'
 * '<S52>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/mtr_coupling_bemf_comp'
 * '<S53>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/ifbk_d_ctrl/PI-Ctrl-Varying-Gains'
 * '<S54>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/ifbk_d_ctrl/PI-Ctrl-Varying-Gains/Integrator'
 * '<S55>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/ifbk_q_ctrl/PI-Ctrl-Varying-Gains'
 * '<S56>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Control_Mode/IfbkCtrl/ifbk_q_ctrl/PI-Ctrl-Varying-Gains/Integrator'
 * '<S57>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl'
 * '<S58>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl/ifbk_d_ctrl'
 * '<S59>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl/ifbk_q_ctrl'
 * '<S60>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl/ifbk_d_ctrl/PI-Ctrl-Varying-Gains'
 * '<S61>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl/ifbk_d_ctrl/PI-Ctrl-Varying-Gains/Integrator'
 * '<S62>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl/ifbk_q_ctrl/PI-Ctrl-Varying-Gains'
 * '<S63>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/ifbk_trq_ctrl/Current_Limiter_Mode/IfbkCtrl/ifbk_q_ctrl/PI-Ctrl-Varying-Gains/Integrator'
 * '<S64>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/mod_wave_calc/Compare To Constant'
 * '<S65>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/mod_wave_calc/D-1LPF'
 * '<S66>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/mod_wave_calc/calc_mod_wave'
 * '<S67>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/mod_wave_calc/calc_mod_wave/Inverse Park Transform1'
 * '<S68>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/mod_wave_calc/calc_mod_wave/calc_pwm_dc'
 * '<S69>'  : 'pmsm_ctrl/CtrlFast/Field_Oriented_Controller/raw_pwm_calc/raw_pwm_calc'
 * '<S70>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl'
 * '<S71>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosCtl'
 * '<S72>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan'
 * '<S73>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/SpdCtrl'
 * '<S74>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/cnts_to_rads1'
 * '<S75>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/cnts_to_rads2'
 * '<S76>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/rads_to_cnts'
 * '<S77>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosCtl/PI-Ctrl'
 * '<S78>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosCtl/PI-Ctrl/Integrator'
 * '<S79>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff'
 * '<S80>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan'
 * '<S81>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan/a1_calc'
 * '<S82>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan/a2_calc'
 * '<S83>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan/a_calc'
 * '<S84>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan/fhan_calc'
 * '<S85>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan/sa_calc'
 * '<S86>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/PosTrajPlan/PosTrackDiff/fhan/sy_calc'
 * '<S87>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/SpdCtrl/PI-Ctrl-Varying-Gains'
 * '<S88>'  : 'pmsm_ctrl/CtrlMain/MotnCtrl/SpdCtrl/PI-Ctrl-Varying-Gains/Integrator'
 * '<S89>'  : 'pmsm_ctrl/CtrlMgr/Compare To Constant10'
 * '<S90>'  : 'pmsm_ctrl/CtrlMgr/Compare To Constant3'
 * '<S91>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags'
 * '<S92>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags/Compare To Constant2'
 * '<S93>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags/Compare To Constant4'
 * '<S94>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags/Compare To Constant5'
 * '<S95>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags/Compare To Constant6'
 * '<S96>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags/Compare To Constant7'
 * '<S97>'  : 'pmsm_ctrl/CtrlMgr/calc_enbl_flags/Compare To Constant8'
 * '<S98>'  : 'pmsm_ctrl/SetInputs/D-1LPF'
 * '<S99>'  : 'pmsm_ctrl/SetInputs/enc_ofs_comp'
 * '<S100>' : 'pmsm_ctrl/SetInputs/ifbk_ofs_comp'
 */

/*-
 * Requirements for '<Root>': pmsm_ctrl
 */
#endif                                 /* RTW_HEADER_pmsm_ctrl_h_ */
