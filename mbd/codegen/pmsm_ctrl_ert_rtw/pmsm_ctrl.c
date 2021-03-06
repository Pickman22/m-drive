/*
 * pmsm_ctrl.c
 *
 * Code generation for model "pmsm_ctrl".
 *
 * Model version              : 1.816
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 *
 */

#include "pmsm_ctrl.h"
#include "pmsm_ctrl_private.h"

/* Named constants for Chart: '<S10>/ResIdCal' */
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_done                        ((uint8_T)1U)
#define IN_res_id_actv                 ((uint8_T)2U)
#define IN_res_id_init                 ((uint8_T)3U)
#define TICK_R_CAL                     (100U)
#define TICK_R_CAL_WAIT_SETTLE         (30U)

/* Named constants for Chart: '<S9>/IndIdCal' */
#define IN_ind_id_actv                 ((uint8_T)2U)
#define IN_neg_cycle                   ((uint8_T)1U)
#define IN_pos_cycle                   ((uint8_T)2U)
#define TICK_L_CAL                     (1000U)
#define TICK_L_CAL_WAIT_SETTLE         (30U)

/* Named constants for Chart: '<S8>/ResIdCal' */
#define IN_mtr_angl_ofs_cal_actv       ((uint8_T)1U)
#define IN_mtr_angl_ofs_cal_done       ((uint8_T)2U)
#define TICK_IFBK_OFS_WAIT_SETTLE      (500U)

/* Named constants for Chart: '<S7>/EncOfsCal' */
#define IN_calc_enc_ofs_move_forward   ((uint8_T)1U)
#define IN_calc_n_poles                ((uint8_T)2U)
#define IN_done_m                      ((uint8_T)3U)
#define IN_enc_cnts_err                ((uint8_T)4U)
#define IN_move_back_calc_enc_ofs      ((uint8_T)5U)
#define IN_mtr_n_poles_enc_ofs_init    ((uint8_T)6U)
#define POLES_CAL_MAX                  (20)
#define POLES_CAL_MIN                  (1)
#define TICK_ENC_OFS_WAIT_SETTLE       (1000U)
#define TICK_INC_MIN                   (100)
#define TICK_OFS_CAL_RAMP              (500U)

const Calib_OutType pmsm_ctrl_rtZCalib_OutType = {
  CTRL_MD_OFF,                         /* ctrl_md_rqst */
  ST_FAILED,                           /* cal_mgr_st_rqst */

  {
    0.0F, 0.0F, 0.0F }
  /* mtr_cmd_rqst */
} ;                                    /* Calib_OutType ground */

/* Exported block signals */
Calib_ParamType CALIB_PARAM_BUS;       /* '<S2>/Bus Creator' */

/* Exported block states */
boolean_T _pmsm_ctrl_SharedDataInit_ = false;/* synthesized block */

/* Exported data definition */

/* Definition for custom storage class: Struct */
DBG_Struct_type DBG_Struct;

/* data stores shared across model instances */
SharedDSM rtSharedDSM;
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

uint32_T div_nzp_usu32_sat(int32_T numerator, uint32_T denominator)
{
  uint32_T quotient;
  if (numerator < 0) {
    quotient = 0U;
  } else {
    quotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)numerator)
      / denominator;
  }

  return quotient;
}

/*
 * Output and update for atomic system:
 *    '<S26>/calc_pwm_dc'
 *    '<S23>/calc_pwm_dc'
 *    '<S15>/calc_pwm_dc'
 *    '<S66>/calc_pwm_dc'
 */
void calc_pwm_dc(RT_MODEL * const pmsm_ctrl_M, const real32_T rtu_pwm_abc[3],
                 real32_T rty_pwm_dc[3])
{
  real32_T rtb_Gain_j;
  real32_T rtb_Subtract_g_idx_0;
  real32_T rtb_Subtract_g_idx_1;
  (void) (pmsm_ctrl_M);

  /* MinMax: '<S27>/Max' */
  rtb_Gain_j = rtu_pwm_abc[0];
  rtb_Subtract_g_idx_0 = rtu_pwm_abc[1];
  if (!(rtb_Gain_j > rtb_Subtract_g_idx_0)) {
    rtb_Gain_j = rtb_Subtract_g_idx_0;
  }

  rtb_Subtract_g_idx_0 = rtu_pwm_abc[2];
  if (!(rtb_Gain_j > rtb_Subtract_g_idx_0)) {
    rtb_Gain_j = rtb_Subtract_g_idx_0;
  }

  /* MinMax: '<S27>/Max1' */
  rtb_Subtract_g_idx_1 = rtu_pwm_abc[0];
  rtb_Subtract_g_idx_0 = rtu_pwm_abc[1];
  if (!(rtb_Subtract_g_idx_1 < rtb_Subtract_g_idx_0)) {
    rtb_Subtract_g_idx_1 = rtb_Subtract_g_idx_0;
  }

  rtb_Subtract_g_idx_0 = rtu_pwm_abc[2];
  if (!(rtb_Subtract_g_idx_1 < rtb_Subtract_g_idx_0)) {
    rtb_Subtract_g_idx_1 = rtb_Subtract_g_idx_0;
  }

  /* Gain: '<S27>/Gain' incorporates:
   *  MinMax: '<S27>/Max'
   *  MinMax: '<S27>/Max1'
   *  Sum: '<S27>/Add'
   */
  rtb_Gain_j = (rtb_Gain_j + rtb_Subtract_g_idx_1) * 0.5F;

  /* Sum: '<S27>/Subtract' */
  rtb_Subtract_g_idx_0 = rtu_pwm_abc[0] - rtb_Gain_j;
  rtb_Subtract_g_idx_1 = rtu_pwm_abc[1] - rtb_Gain_j;
  rtb_Gain_j = rtu_pwm_abc[2] - rtb_Gain_j;

  /* DataTypeConversion: '<S27>/Data Type Conversion' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   *  Gain: '<S27>/Gain2'
   *  Product: '<S27>/Divide'
   *  Sum: '<S27>/Add1'
   */
  rty_pwm_dc[0] = (rtb_Subtract_g_idx_0 / 0.5F + 1.0F) * 0.5F;
  rty_pwm_dc[1] = (rtb_Subtract_g_idx_1 / 0.5F + 1.0F) * 0.5F;
  rty_pwm_dc[2] = (rtb_Gain_j / 0.5F + 1.0F) * 0.5F;
}

/* System reset for function-call system: '<S18>/get_mtr_ifbk_sum' */
void get_mtr_ifbk_sum_Reset(self_get_mtr_ifbk_sum *pmsm_ctrl_self_arg)
{
  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[0] = 0.0F;
  pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[1] = 0.0F;
  pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[2] = 0.0F;
}

/* Output and update for function-call system: '<S18>/get_mtr_ifbk_sum' */
void get_mtr_ifbk_sum(self_get_mtr_ifbk_sum *pmsm_ctrl_self_arg, const real32_T
                      rtu_mtr_ifbk_abc[3], real32_T rty_mtr_ifbk_sum_abc[3])
{
  /* Sum: '<S21>/Add' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   */
  rty_mtr_ifbk_sum_abc[0] = rtu_mtr_ifbk_abc[0] +
    pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[0];

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[0] = rty_mtr_ifbk_sum_abc[0];

  /* Sum: '<S21>/Add' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   */
  rty_mtr_ifbk_sum_abc[1] = rtu_mtr_ifbk_abc[1] +
    pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[1];

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[1] = rty_mtr_ifbk_sum_abc[1];

  /* Sum: '<S21>/Add' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   */
  rty_mtr_ifbk_sum_abc[2] = rtu_mtr_ifbk_abc[2] +
    pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[2];

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  pmsm_ctrl_self_arg->dwork.UnitDelay_DSTATE[2] = rty_mtr_ifbk_sum_abc[2];
}

/* Output and update for function-call system: '<S18>/get_mtr_ifbk_avg' */
void get_mtr_ifbk_avg(RT_MODEL * const pmsm_ctrl_M, const real32_T
                      rtu_mtr_ifbk_sum_abc[3], real32_T rtu_ncycles, real32_T
                      rty_mtr_ifbk_avg_abc[3])
{
  real32_T rtb_Saturation_m;
  (void) (pmsm_ctrl_M);

  /* Saturate: '<S20>/Saturation' */
  if (rtu_ncycles > 1.0E+6F) {
    rtb_Saturation_m = 1.0E+6F;
  } else if (rtu_ncycles < 1.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    rtb_Saturation_m = rtu_ncycles;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Product: '<S20>/Divide' */
  rty_mtr_ifbk_avg_abc[0] = rtu_mtr_ifbk_sum_abc[0] / rtb_Saturation_m;
  rty_mtr_ifbk_avg_abc[1] = rtu_mtr_ifbk_sum_abc[1] / rtb_Saturation_m;
  rty_mtr_ifbk_avg_abc[2] = rtu_mtr_ifbk_sum_abc[2] / rtb_Saturation_m;
}

/*
 * Output and update for atomic system:
 *    '<S7>/calc_mod_wave'
 *    '<S33>/calc_mod_wave'
 */
void calc_mod_wave(RT_MODEL * const pmsm_ctrl_M, const real32_T rtu_dq0[3],
                   real32_T rtu_elec_angle, real32_T rty_pwm_dc[3], real32_T
                   rty_mod_wave[3])
{
  /* Gain: '<S16>/Gain1' incorporates:
   *  Fcn: '<S16>/a'
   *  Fcn: '<S16>/b'
   *  Fcn: '<S16>/c'
   */
  rty_mod_wave[0] = (arm_sin_f32(rtu_elec_angle + 1.57079637F) * rtu_dq0[0] +
                     arm_cos_f32(rtu_elec_angle + 1.57079637F) * rtu_dq0[1]) +
    rtu_dq0[2];
  rty_mod_wave[1] = (arm_sin_f32((rtu_elec_angle + 1.57079637F) - 2.09439516F) *
                     rtu_dq0[0] + arm_cos_f32((rtu_elec_angle + 1.57079637F) -
    2.09439516F) * rtu_dq0[1]) + rtu_dq0[2];
  rty_mod_wave[2] = (arm_sin_f32((rtu_elec_angle + 1.57079637F) + 2.09439516F) *
                     rtu_dq0[0] + arm_cos_f32((rtu_elec_angle + 1.57079637F) +
    2.09439516F) * rtu_dq0[1]) + rtu_dq0[2];

  /* Outputs for Atomic SubSystem: '<S15>/calc_pwm_dc' */
  calc_pwm_dc(pmsm_ctrl_M, rty_mod_wave, rty_pwm_dc);

  /* End of Outputs for SubSystem: '<S15>/calc_pwm_dc' */
}

/* Output and update for atomic system: '<S28>/calc_elec_angle' */
void calc_elec_angle(RT_MODEL * const pmsm_ctrl_M, int32_T rtu_mtr_enc_cnts,
                     real32_T *rty_elec_angle, real32_T *rty_mtr_pos, int32_T
                     rtp_enc_cnts_int, uint8_T rtp_n_poles)
{
  real32_T rtb_Divide_b;
  int32_T u0;
  (void) (pmsm_ctrl_M);

  /* Product: '<S30>/Divide' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S30>/Constant3'
   *  DataTypeConversion: '<S30>/Data Type Conversion'
   */
  rtb_Divide_b = 6.28318548F / (real32_T)rtp_enc_cnts_int;

  /* Gain: '<S30>/Gain' */
  u0 = rtp_n_poles * rtu_mtr_enc_cnts;

  /* Math: '<S30>/Mod' incorporates:
   *  Constant: '<S30>/Constant1'
   */
  if (rtp_enc_cnts_int != 0) {
    u0 -= div_nde_s32_floor(u0, rtp_enc_cnts_int) * rtp_enc_cnts_int;
  }

  /* End of Math: '<S30>/Mod' */

  /* Product: '<S30>/Divide1' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion2'
   */
  *rty_elec_angle = (real32_T)u0 * rtb_Divide_b;

  /* Product: '<S30>/Divide2' incorporates:
   *  DataTypeConversion: '<S30>/Data Type Conversion1'
   */
  *rty_mtr_pos = (real32_T)rtu_mtr_enc_cnts * rtb_Divide_b;
}

/*
 * System reset for atomic system:
 *    '<S50>/PI-Ctrl-Varying-Gains'
 *    '<S51>/PI-Ctrl-Varying-Gains'
 *    '<S58>/PI-Ctrl-Varying-Gains'
 *    '<S59>/PI-Ctrl-Varying-Gains'
 *    '<S73>/PI-Ctrl-Varying-Gains'
 */
void PI_Ctrl_Reset(self_PI_Ctrl *pmsm_ctrl_self_arg)
{
  /* InitializeConditions for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
  pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S50>/PI-Ctrl-Varying-Gains'
 *    '<S51>/PI-Ctrl-Varying-Gains'
 *    '<S58>/PI-Ctrl-Varying-Gains'
 *    '<S59>/PI-Ctrl-Varying-Gains'
 *    '<S73>/PI-Ctrl-Varying-Gains'
 */
void PI_Ctrl(self_PI_Ctrl *pmsm_ctrl_self_arg, real32_T rtu_y_tgt, real32_T
             rtu_y_act, real32_T rtu_Kp, real32_T rtu_Ki, real32_T *rty_PI_out,
             real32_T rtp_max_lim, real32_T rtp_min_lim)
{
  real32_T rtb_Subtract_ie;

  /* Sum: '<S53>/Subtract' */
  rtb_Subtract_ie = rtu_y_tgt - rtu_y_act;

  /* Sum: '<S53>/Add' incorporates:
   *  DiscreteIntegrator: '<S54>/Discrete-Time Integrator'
   *  Product: '<S53>/Product'
   */
  *rty_PI_out = rtu_Kp * rtb_Subtract_ie +
    pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
   *  Product: '<S53>/Product1'
   */
  pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE += rtb_Subtract_ie *
    rtu_Ki * 0.0001F;
  if (pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE >= rtp_max_lim) {
    pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE = rtp_max_lim;
  } else {
    if (pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE <= rtp_min_lim)
    {
      pmsm_ctrl_self_arg->dwork.DiscreteTimeIntegrator_DSTATE = rtp_min_lim;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
}

/* Model step function */
void Trig_Pmsm_SetIn(RT_MODEL *const pmsm_ctrl_M, int32_T rtU_MtrIf_EncCnts,
                     real32_T rtU_MtrIf_IfbkAct[3], real32_T rtU_MtrIf_SpdSns,
                     MtrCtrlMd_T rtU_MtrIf_CtrlMd, real32_T rtU_MtrIf_Tgt[3],
                     real32_T rtU_MtrIf_VBus, MtrCtrlCal_T rtU_MtrIf_CtrlCalRqst)
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_SetIn_at_outport_1' incorporates:
   *  SubSystem: '<Root>/SetInputs'
   */
  /* Sum: '<S99>/Subtract' incorporates:
   *  Inport: '<Root>/MtrIf_EncCnts'
   */
  DBG_Struct.mtr_if_enc_cnts = rtU_MtrIf_EncCnts - CALIB_PARAM_BUS.enc_ofs;

  /* Sum: '<S98>/Add1' incorporates:
   *  Constant: '<S98>/Constant'
   *  Inport: '<Root>/MtrIf_VBus'
   *  Product: '<S98>/Product'
   *  Product: '<S98>/Product1'
   *  UnitDelay: '<S98>/Unit Delay'
   */
  DBG_Struct.mtrif_v_bus = rtU_MtrIf_VBus * 0.00990092754F + 0.990099072F *
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE;

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Inport: '<Root>/MtrIf_CtrlMd'
   *  Inport: '<Root>/MtrIf_SpdSns'
   */
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts = DBG_Struct.mtr_if_enc_cnts;
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_spd_sns = rtU_MtrIf_SpdSns;
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_ctrl_md = rtU_MtrIf_CtrlMd;

  /* Sum: '<S100>/Subtract' incorporates:
   *  Inport: '<Root>/MtrIf_IfbkAct'
   */
  DBG_Struct.mtrif_ifbk_act[0] = rtU_MtrIf_IfbkAct[0] -
    CALIB_PARAM_BUS.ifbk_ofs[0];

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Inport: '<Root>/MtrIf_Tgt'
   */
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0] = DBG_Struct.mtrif_ifbk_act
    [0];
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_tgt[0] = rtU_MtrIf_Tgt[0];

  /* Sum: '<S100>/Subtract' incorporates:
   *  Inport: '<Root>/MtrIf_IfbkAct'
   */
  DBG_Struct.mtrif_ifbk_act[1] = rtU_MtrIf_IfbkAct[1] -
    CALIB_PARAM_BUS.ifbk_ofs[1];

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Inport: '<Root>/MtrIf_Tgt'
   */
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[1] = DBG_Struct.mtrif_ifbk_act
    [1];
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_tgt[1] = rtU_MtrIf_Tgt[1];

  /* Sum: '<S100>/Subtract' incorporates:
   *  Inport: '<Root>/MtrIf_IfbkAct'
   */
  DBG_Struct.mtrif_ifbk_act[2] = rtU_MtrIf_IfbkAct[2] -
    CALIB_PARAM_BUS.ifbk_ofs[2];

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Inport: '<Root>/MtrIf_CtrlCalRqst'
   *  Inport: '<Root>/MtrIf_Tgt'
   */
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[2] = DBG_Struct.mtrif_ifbk_act
    [2];
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_tgt[2] = rtU_MtrIf_Tgt[2];
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_cal_rqst = rtU_MtrIf_CtrlCalRqst;
  pmsm_ctrl_M->blockIO.BusCreator.mtrif_v_bus = DBG_Struct.mtrif_v_bus;

  /* Update for UnitDelay: '<S98>/Unit Delay' */
  pmsm_ctrl_M->dwork.UnitDelay_DSTATE = DBG_Struct.mtrif_v_bus;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_SetIn_at_outport_1' */
}

/* Model step function */
void Trig_Pmsm_CtrlMgr(RT_MODEL *const pmsm_ctrl_M)
{
  boolean_T rtb_LogicalOperator2;
  boolean_T rtb_Compare_p;
  MtrCtrlMd_T rtb_ctrl_md_act;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_CtrlMgr_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CtrlMgr'
   */
  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  RelationalOperator: '<S89>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   */
  rtb_LogicalOperator2 = ((pmsm_ctrl_M->blockIO.BusCreator.mtrif_cal_rqst !=
    CAL_NONE) && (pmsm_ctrl_M->blockIO.BusCreator.mtrif_ctrl_md == CTRL_MD_CAL));

  /* Switch: '<S5>/Switch1' */
  if (rtb_LogicalOperator2) {
    pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[0] =
      pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[0];
    pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[1] =
      pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[1];
    pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[2] =
      pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[2];
  } else {
    pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[0] =
      pmsm_ctrl_M->blockIO.BusCreator.mtrif_tgt[0];
    pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[1] =
      pmsm_ctrl_M->blockIO.BusCreator.mtrif_tgt[1];
    pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[2] =
      pmsm_ctrl_M->blockIO.BusCreator.mtrif_tgt[2];
  }

  /* End of Switch: '<S5>/Switch1' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  pmsm_ctrl_M->blockIO.ctrl_cal_act =
    pmsm_ctrl_M->blockIO.BusCreator.mtrif_cal_rqst;

  /* Switch: '<S5>/Switch' */
  if (rtb_LogicalOperator2) {
    rtb_ctrl_md_act = pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst;
  } else {
    rtb_ctrl_md_act = pmsm_ctrl_M->blockIO.BusCreator.mtrif_ctrl_md;
  }

  /* End of Switch: '<S5>/Switch' */

  /* RelationalOperator: '<S94>/Compare' incorporates:
   *  Constant: '<S94>/Constant'
   */
  rtb_Compare_p = (rtb_ctrl_md_act == CTRL_MD_OFF);

  /* Logic: '<S91>/Logical Operator2' */
  rtb_LogicalOperator2 = !rtb_Compare_p;

  /* Logic: '<S91>/Logical Operator1' incorporates:
   *  Constant: '<S93>/Constant'
   *  RelationalOperator: '<S93>/Compare'
   */
  pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_raw_pwm =
    (rtb_LogicalOperator2 && (rtb_ctrl_md_act == CTRL_MD_RAW_PWM));

  /* Logic: '<S91>/Logical Operator3' incorporates:
   *  Constant: '<S95>/Constant'
   *  RelationalOperator: '<S95>/Compare'
   */
  pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_mod_wave =
    (rtb_LogicalOperator2 && (rtb_ctrl_md_act >= CTRL_MD_DQ_PWM));

  /* Logic: '<S91>/Logical Operator4' incorporates:
   *  Constant: '<S92>/Constant'
   *  RelationalOperator: '<S92>/Compare'
   */
  pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_ifbk_ctrl =
    (rtb_LogicalOperator2 && (rtb_ctrl_md_act >= CTRL_MD_DQ_PWM));

  /* Logic: '<S91>/Logical Operator5' incorporates:
   *  Constant: '<S96>/Constant'
   *  RelationalOperator: '<S96>/Compare'
   */
  pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_spd_ctrl =
    (rtb_LogicalOperator2 && (rtb_ctrl_md_act >= CTRL_MD_SPD));

  /* Logic: '<S91>/Logical Operator6' incorporates:
   *  Constant: '<S97>/Constant'
   *  RelationalOperator: '<S97>/Compare'
   */
  pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_pos_ctrl =
    (rtb_LogicalOperator2 && (rtb_ctrl_md_act >= CTRL_MD_POS));

  /* BusCreator: '<S5>/BusConversion_InsertedFor_Bus Creator2_at_inport_3' */
  pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.ctrl_md_off = rtb_Compare_p;

  /* BusCreator: '<S5>/Bus Creator2' */
  pmsm_ctrl_M->blockIO.BusCreator2.ctrl_cal_act =
    pmsm_ctrl_M->blockIO.ctrl_cal_act;
  pmsm_ctrl_M->blockIO.BusCreator2.ctrl_md_act = rtb_ctrl_md_act;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_CtrlMgr_at_outport_1' */
}

/* Model step function */
void Trig_Pmsm_Cal(RT_MODEL *const pmsm_ctrl_M, CalMgrSt_T *rtY_CalMgr_Status)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  real32_T rtb_TmpSignalConversionAtcalc_i[3];
  real32_T rtb_PwmRqst_l;
  int32_T qY;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Cal_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CalibRoutines'
   */
  /* SwitchCase: '<S2>/Switch Case' */
  rtPrevAction = pmsm_ctrl_M->dwork.SwitchCase_ActiveSubsystem;
  rtAction = -1;
  switch (pmsm_ctrl_M->blockIO.ctrl_cal_act) {
   case CAL_NONE:
    rtAction = 0;
    break;

   case CAL_RES_ID:
    rtAction = 1;
    break;

   case CAL_IND_ID:
    rtAction = 2;
    break;

   case CAL_IFBK_OFS:
    rtAction = 3;
    break;

   case CAL_ENC_OFS:
    rtAction = 4;
    break;
  }

  pmsm_ctrl_M->dwork.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/not_active' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* BusCreator: '<S11>/Bus Creator' incorporates:
     *  Constant: '<S11>/Zero1'
     *  Constant: '<S11>/Zero2'
     */
    pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = CTRL_MD_OFF;
    pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst = ST_DONE;
    pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[0] = 0.0F;
    pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[1] = 0.0F;
    pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[2] = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/not_active' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S2>/mtr_res_ident' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S2>/Switch Case' incorporates:
       *  Chart: '<S10>/ResIdCal'
       */
      pmsm_ctrl_M->dwork.temporalCounter_i1_l = 0U;
      pmsm_ctrl_M->dwork.is_active_c5_pmsm_ctrl = 0U;
      pmsm_ctrl_M->dwork.is_c5_pmsm_ctrl = IN_NO_ACTIVE_CHILD;
      pmsm_ctrl_M->dwork.ifbk_sum = 0.0F;
      pmsm_ctrl_M->blockIO.CtrlMdRqst_p = CTRL_MD_OFF;
      pmsm_ctrl_M->blockIO.CalMgrStRqst_h = ST_FAILED;
      pmsm_ctrl_M->blockIO.PwmRqst_g = 0.0F;

      /* End of SystemReset for SubSystem: '<S2>/mtr_res_ident' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/mtr_res_ident' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Chart: '<S10>/ResIdCal' */
    if (pmsm_ctrl_M->dwork.temporalCounter_i1_l < 127U) {
      pmsm_ctrl_M->dwork.temporalCounter_i1_l++;
    }

    if (pmsm_ctrl_M->dwork.is_active_c5_pmsm_ctrl == 0U) {
      pmsm_ctrl_M->dwork.is_active_c5_pmsm_ctrl = 1U;
      pmsm_ctrl_M->dwork.is_c5_pmsm_ctrl = IN_res_id_init;
      pmsm_ctrl_M->dwork.temporalCounter_i1_l = 0U;
      pmsm_ctrl_M->blockIO.CtrlMdRqst_p = CTRL_MD_RAW_PWM;
      pmsm_ctrl_M->blockIO.PwmRqst_g = Cfg_ResCalPwmDuty;
      pmsm_ctrl_M->blockIO.CalMgrStRqst_h = ST_RES_ID;
      pmsm_ctrl_M->dwork.ifbk_sum = 0.0F;
      rtSharedDSM.CalData_Res = -1.0F;
    } else {
      switch (pmsm_ctrl_M->dwork.is_c5_pmsm_ctrl) {
       case IN_done:
        pmsm_ctrl_M->blockIO.CtrlMdRqst_p = CTRL_MD_OFF;
        pmsm_ctrl_M->blockIO.CalMgrStRqst_h = ST_DONE;
        pmsm_ctrl_M->blockIO.PwmRqst_g = (real32_T)0.;
        rtSharedDSM.CalData_Res = (real32_T)(Cfg_ResCalPwmDuty *
          0.66666666666666663 * 6.0 / (pmsm_ctrl_M->dwork.ifbk_sum / (real32_T)
          TICK_R_CAL));
        break;

       case IN_res_id_actv:
        if (pmsm_ctrl_M->dwork.temporalCounter_i1_l >= (int32_T)TICK_R_CAL) {
          pmsm_ctrl_M->dwork.is_c5_pmsm_ctrl = IN_done;
          pmsm_ctrl_M->blockIO.CtrlMdRqst_p = CTRL_MD_OFF;
          pmsm_ctrl_M->blockIO.CalMgrStRqst_h = ST_DONE;
          pmsm_ctrl_M->blockIO.PwmRqst_g = (real32_T)0.;
          rtSharedDSM.CalData_Res = (real32_T)(Cfg_ResCalPwmDuty *
            0.66666666666666663 * 6.0 / (pmsm_ctrl_M->dwork.ifbk_sum / (real32_T)
            TICK_R_CAL));
        } else {
          pmsm_ctrl_M->dwork.ifbk_sum +=
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
        }
        break;

       default:
        if (pmsm_ctrl_M->dwork.temporalCounter_i1_l >= (int32_T)
            TICK_R_CAL_WAIT_SETTLE) {
          /*  Wait for current / motor to settle. */
          pmsm_ctrl_M->dwork.is_c5_pmsm_ctrl = IN_res_id_actv;
          pmsm_ctrl_M->dwork.temporalCounter_i1_l = 0U;
          pmsm_ctrl_M->dwork.ifbk_sum +=
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
        } else {
          pmsm_ctrl_M->blockIO.CtrlMdRqst_p = CTRL_MD_RAW_PWM;
          pmsm_ctrl_M->blockIO.PwmRqst_g = Cfg_ResCalPwmDuty;
          pmsm_ctrl_M->blockIO.CalMgrStRqst_h = ST_RES_ID;
          pmsm_ctrl_M->dwork.ifbk_sum = 0.0F;
          rtSharedDSM.CalData_Res = -1.0F;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/ResIdCal' */

    /* SignalConversion: '<S26>/TmpSignal ConversionAtcalc_pwm_dcInport1' incorporates:
     *  Constant: '<S26>/Zero'
     */
    rtb_TmpSignalConversionAtcalc_i[0] = pmsm_ctrl_M->blockIO.PwmRqst_g;
    rtb_TmpSignalConversionAtcalc_i[1] = 0.0F;
    rtb_TmpSignalConversionAtcalc_i[2] = 0.0F;

    /* Outputs for Atomic SubSystem: '<S26>/calc_pwm_dc' */

    /* BusCreator: '<S10>/Bus Creator' */
    calc_pwm_dc(pmsm_ctrl_M, rtb_TmpSignalConversionAtcalc_i,
                pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst);

    /* End of Outputs for SubSystem: '<S26>/calc_pwm_dc' */
    pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = pmsm_ctrl_M->blockIO.CtrlMdRqst_p;
    pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst =
      pmsm_ctrl_M->blockIO.CalMgrStRqst_h;

    /* End of Outputs for SubSystem: '<S2>/mtr_res_ident' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S2>/mtr_ind_ident' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S2>/Switch Case' incorporates:
       *  Chart: '<S9>/IndIdCal'
       */
      pmsm_ctrl_M->dwork.is_ind_id_actv = IN_NO_ACTIVE_CHILD;
      pmsm_ctrl_M->dwork.temporalCounter_i1_n = 0U;
      pmsm_ctrl_M->dwork.is_active_c1_pmsm_ctrl = 0U;
      pmsm_ctrl_M->dwork.is_c1_pmsm_ctrl = IN_NO_ACTIVE_CHILD;
      pmsm_ctrl_M->dwork.ifbk_neg = 0.0F;
      pmsm_ctrl_M->dwork.ifbk_pos = 0.0F;
      pmsm_ctrl_M->dwork.di_dt = 0.0F;
      pmsm_ctrl_M->blockIO.CtrlMdRqst_i = CTRL_MD_OFF;
      pmsm_ctrl_M->blockIO.CalMgrStRqst_i = ST_FAILED;

      /* End of SystemReset for SubSystem: '<S2>/mtr_ind_ident' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/mtr_ind_ident' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Chart: '<S9>/IndIdCal' */
    if (pmsm_ctrl_M->dwork.temporalCounter_i1_n < 1023U) {
      pmsm_ctrl_M->dwork.temporalCounter_i1_n++;
    }

    if (pmsm_ctrl_M->dwork.is_active_c1_pmsm_ctrl == 0U) {
      pmsm_ctrl_M->dwork.is_active_c1_pmsm_ctrl = 1U;
      pmsm_ctrl_M->dwork.is_c1_pmsm_ctrl = IN_res_id_init;
      pmsm_ctrl_M->dwork.temporalCounter_i1_n = 0U;
      pmsm_ctrl_M->blockIO.CtrlMdRqst_i = CTRL_MD_RAW_PWM;

      /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
      rtb_TmpSignalConversionAtcalc_i[0] = Cfg_IndCalPwmDuty;
      pmsm_ctrl_M->blockIO.CalMgrStRqst_i = ST_IND_ID;
      rtSharedDSM.CalData_L = -1.0F;
    } else {
      switch (pmsm_ctrl_M->dwork.is_c1_pmsm_ctrl) {
       case IN_done:
        pmsm_ctrl_M->blockIO.CtrlMdRqst_i = CTRL_MD_OFF;
        pmsm_ctrl_M->blockIO.CalMgrStRqst_i = ST_DONE;

        /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
        rtb_TmpSignalConversionAtcalc_i[0] = (real32_T)0.;
        pmsm_ctrl_M->dwork.di_dt = (real32_T)((pmsm_ctrl_M->dwork.ifbk_pos -
          pmsm_ctrl_M->dwork.ifbk_neg) / 500.0 / TsMain);
        rtSharedDSM.CalData_L = (real32_T)(Cfg_VBus / 2. * Cfg_IndCalPwmDuty /
          pmsm_ctrl_M->dwork.di_dt);
        break;

       case IN_ind_id_actv:
        if (pmsm_ctrl_M->dwork.temporalCounter_i1_n >= (int32_T)TICK_L_CAL) {
          pmsm_ctrl_M->dwork.is_ind_id_actv = IN_NO_ACTIVE_CHILD;
          pmsm_ctrl_M->dwork.is_c1_pmsm_ctrl = IN_done;
          pmsm_ctrl_M->blockIO.CtrlMdRqst_i = CTRL_MD_OFF;
          pmsm_ctrl_M->blockIO.CalMgrStRqst_i = ST_DONE;

          /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
          rtb_TmpSignalConversionAtcalc_i[0] = (real32_T)0.;
          pmsm_ctrl_M->dwork.di_dt = (real32_T)((pmsm_ctrl_M->dwork.ifbk_pos -
            pmsm_ctrl_M->dwork.ifbk_neg) / 500.0 / TsMain);
          rtSharedDSM.CalData_L = (real32_T)(Cfg_VBus / 2. * Cfg_IndCalPwmDuty /
            pmsm_ctrl_M->dwork.di_dt);
        } else if (pmsm_ctrl_M->dwork.is_ind_id_actv == IN_neg_cycle) {
          pmsm_ctrl_M->dwork.is_ind_id_actv = IN_pos_cycle;

          /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
          rtb_TmpSignalConversionAtcalc_i[0] = Cfg_IndCalPwmDuty;
          pmsm_ctrl_M->dwork.ifbk_pos +=
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
        } else {
          pmsm_ctrl_M->dwork.is_ind_id_actv = IN_neg_cycle;

          /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
          rtb_TmpSignalConversionAtcalc_i[0] = -Cfg_IndCalPwmDuty;
          pmsm_ctrl_M->dwork.ifbk_neg +=
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
        }
        break;

       default:
        if (pmsm_ctrl_M->dwork.temporalCounter_i1_n >= (int32_T)
            TICK_L_CAL_WAIT_SETTLE) {
          /*  Wait for current / motor to settle. */
          pmsm_ctrl_M->dwork.is_c1_pmsm_ctrl = IN_ind_id_actv;
          pmsm_ctrl_M->dwork.temporalCounter_i1_n = 0U;
          pmsm_ctrl_M->dwork.ifbk_pos = 0.0F;
          pmsm_ctrl_M->dwork.ifbk_neg = 0.0F;
          pmsm_ctrl_M->dwork.is_ind_id_actv = IN_pos_cycle;

          /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
          rtb_TmpSignalConversionAtcalc_i[0] = Cfg_IndCalPwmDuty;
          pmsm_ctrl_M->dwork.ifbk_pos +=
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
        } else {
          pmsm_ctrl_M->blockIO.CtrlMdRqst_i = CTRL_MD_RAW_PWM;

          /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' */
          rtb_TmpSignalConversionAtcalc_i[0] = Cfg_IndCalPwmDuty;
          pmsm_ctrl_M->blockIO.CalMgrStRqst_i = ST_IND_ID;
          rtSharedDSM.CalData_L = -1.0F;
        }
        break;
      }
    }

    /* End of Chart: '<S9>/IndIdCal' */

    /* SignalConversion: '<S23>/TmpSignal ConversionAtcalc_pwm_dcInport1' incorporates:
     *  Constant: '<S23>/Zero'
     */
    rtb_TmpSignalConversionAtcalc_i[1] = 0.0F;
    rtb_TmpSignalConversionAtcalc_i[2] = 0.0F;

    /* Outputs for Atomic SubSystem: '<S23>/calc_pwm_dc' */

    /* BusCreator: '<S9>/Bus Creator' */
    calc_pwm_dc(pmsm_ctrl_M, rtb_TmpSignalConversionAtcalc_i,
                pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst);

    /* End of Outputs for SubSystem: '<S23>/calc_pwm_dc' */
    pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = pmsm_ctrl_M->blockIO.CtrlMdRqst_i;
    pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst =
      pmsm_ctrl_M->blockIO.CalMgrStRqst_i;

    /* End of Outputs for SubSystem: '<S2>/mtr_ind_ident' */
    break;

   case 3:
    if (rtAction != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S2>/mtr_ifbk_ofs_ident' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S2>/Switch Case' incorporates:
       *  Chart: '<S8>/ResIdCal'
       */
      pmsm_ctrl_M->dwork.temporalCounter_i1_i = 0U;
      pmsm_ctrl_M->dwork.is_active_c2_pmsm_ctrl = 0U;
      pmsm_ctrl_M->dwork.is_c2_pmsm_ctrl = IN_NO_ACTIVE_CHILD;
      pmsm_ctrl_M->dwork.ifbk_abc_sum[0] = 0.0F;
      pmsm_ctrl_M->dwork.ifbk_abc_sum[1] = 0.0F;
      pmsm_ctrl_M->dwork.ifbk_abc_sum[2] = 0.0F;

      /* End of SystemReset for SubSystem: '<S2>/mtr_ifbk_ofs_ident' */

      /* Enable for IfAction SubSystem: '<S2>/mtr_ifbk_ofs_ident' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */

      /* SystemReset for Function Call SubSystem: '<S18>/get_mtr_ifbk_sum' */

      /* Enable for SwitchCase: '<S2>/Switch Case' incorporates:
       *  Chart: '<S8>/ResIdCal'
       */
      get_mtr_ifbk_sum_Reset(&pmsm_ctrl_M->self_get_mtr_ifbk_sum_f);

      /* End of SystemReset for SubSystem: '<S18>/get_mtr_ifbk_sum' */

      /* End of Enable for SubSystem: '<S2>/mtr_ifbk_ofs_ident' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/mtr_ifbk_ofs_ident' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Chart: '<S8>/ResIdCal' */
    if (pmsm_ctrl_M->dwork.temporalCounter_i1_i < 511U) {
      pmsm_ctrl_M->dwork.temporalCounter_i1_i++;
    }

    if (pmsm_ctrl_M->dwork.is_active_c2_pmsm_ctrl == 0U) {
      pmsm_ctrl_M->dwork.is_active_c2_pmsm_ctrl = 1U;
      pmsm_ctrl_M->dwork.is_c2_pmsm_ctrl = IN_mtr_angl_ofs_cal_actv;
      pmsm_ctrl_M->dwork.temporalCounter_i1_i = 0U;

      /* BusCreator: '<S8>/Bus Creator' */
      pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = CTRL_MD_RAW_PWM;
      pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst = ST_IFBK_OFS_CAL;
      rtb_TmpSignalConversionAtcalc_i[0] =
        pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
      rtb_TmpSignalConversionAtcalc_i[1] =
        pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[1];
      rtb_TmpSignalConversionAtcalc_i[2] =
        pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[2];

      /* Outputs for Function Call SubSystem: '<S18>/get_mtr_ifbk_sum' */
      get_mtr_ifbk_sum(&pmsm_ctrl_M->self_get_mtr_ifbk_sum_f,
                       rtb_TmpSignalConversionAtcalc_i, pmsm_ctrl_M->blockIO.Add);

      /* End of Outputs for SubSystem: '<S18>/get_mtr_ifbk_sum' */
      pmsm_ctrl_M->dwork.ifbk_abc_sum[0] = pmsm_ctrl_M->blockIO.Add[0];
      pmsm_ctrl_M->dwork.ifbk_abc_sum[1] = pmsm_ctrl_M->blockIO.Add[1];
      pmsm_ctrl_M->dwork.ifbk_abc_sum[2] = pmsm_ctrl_M->blockIO.Add[2];
      rtSharedDSM.CalData_IfbkOfs_Abc[0] = (real32_T)0.;
      rtSharedDSM.CalData_IfbkOfs_Abc[1] = (real32_T)0.;
      rtSharedDSM.CalData_IfbkOfs_Abc[2] = (real32_T)0.;
    } else if (pmsm_ctrl_M->dwork.is_c2_pmsm_ctrl == IN_mtr_angl_ofs_cal_actv) {
      if (pmsm_ctrl_M->dwork.temporalCounter_i1_i >= (int32_T)
          TICK_IFBK_OFS_WAIT_SETTLE) {
        /*  Wait for motor to settle. */
        pmsm_ctrl_M->dwork.is_c2_pmsm_ctrl = IN_mtr_angl_ofs_cal_done;

        /* BusCreator: '<S8>/Bus Creator' */
        pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = CTRL_MD_OFF;
        pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst = ST_DONE;
        rtb_TmpSignalConversionAtcalc_i[0] = pmsm_ctrl_M->dwork.ifbk_abc_sum[0];
        rtb_TmpSignalConversionAtcalc_i[1] = pmsm_ctrl_M->dwork.ifbk_abc_sum[1];
        rtb_TmpSignalConversionAtcalc_i[2] = pmsm_ctrl_M->dwork.ifbk_abc_sum[2];

        /* Outputs for Function Call SubSystem: '<S18>/get_mtr_ifbk_avg' */
        get_mtr_ifbk_avg(pmsm_ctrl_M, rtb_TmpSignalConversionAtcalc_i, (real32_T)
                         TICK_IFBK_OFS_WAIT_SETTLE,
                         rtSharedDSM.CalData_IfbkOfs_Abc);

        /* End of Outputs for SubSystem: '<S18>/get_mtr_ifbk_avg' */
      } else {
        /* BusCreator: '<S8>/Bus Creator' */
        pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = CTRL_MD_RAW_PWM;
        pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst = ST_IFBK_OFS_CAL;
        rtb_TmpSignalConversionAtcalc_i[0] =
          pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0];
        rtb_TmpSignalConversionAtcalc_i[1] =
          pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[1];
        rtb_TmpSignalConversionAtcalc_i[2] =
          pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[2];

        /* Outputs for Function Call SubSystem: '<S18>/get_mtr_ifbk_sum' */
        get_mtr_ifbk_sum(&pmsm_ctrl_M->self_get_mtr_ifbk_sum_f,
                         rtb_TmpSignalConversionAtcalc_i,
                         pmsm_ctrl_M->blockIO.Add);

        /* End of Outputs for SubSystem: '<S18>/get_mtr_ifbk_sum' */
        pmsm_ctrl_M->dwork.ifbk_abc_sum[0] = pmsm_ctrl_M->blockIO.Add[0];
        pmsm_ctrl_M->dwork.ifbk_abc_sum[1] = pmsm_ctrl_M->blockIO.Add[1];
        pmsm_ctrl_M->dwork.ifbk_abc_sum[2] = pmsm_ctrl_M->blockIO.Add[2];
        rtSharedDSM.CalData_IfbkOfs_Abc[0] = (real32_T)0.;
        rtSharedDSM.CalData_IfbkOfs_Abc[1] = (real32_T)0.;
        rtSharedDSM.CalData_IfbkOfs_Abc[2] = (real32_T)0.;
      }
    } else {
      /* BusCreator: '<S8>/Bus Creator' */
      pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = CTRL_MD_OFF;
      pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst = ST_DONE;
      rtb_TmpSignalConversionAtcalc_i[0] = pmsm_ctrl_M->dwork.ifbk_abc_sum[0];
      rtb_TmpSignalConversionAtcalc_i[1] = pmsm_ctrl_M->dwork.ifbk_abc_sum[1];
      rtb_TmpSignalConversionAtcalc_i[2] = pmsm_ctrl_M->dwork.ifbk_abc_sum[2];

      /* Outputs for Function Call SubSystem: '<S18>/get_mtr_ifbk_avg' */
      get_mtr_ifbk_avg(pmsm_ctrl_M, rtb_TmpSignalConversionAtcalc_i, (real32_T)
                       TICK_IFBK_OFS_WAIT_SETTLE,
                       rtSharedDSM.CalData_IfbkOfs_Abc);

      /* End of Outputs for SubSystem: '<S18>/get_mtr_ifbk_avg' */
    }

    /* End of Chart: '<S8>/ResIdCal' */

    /* BusCreator: '<S8>/Bus Creator' incorporates:
     *  Constant: '<S19>/Zero'
     *  SignalConversion: '<S8>/TmpSignal ConversionAtBus CreatorInport3'
     */
    pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[0] = 0.0F;
    pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[1] = 0.0F;
    pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst[2] = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/mtr_ifbk_ofs_ident' */
    break;

   case 4:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/enc_ofs_cal_routine' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S2>/Switch Case' incorporates:
       *  UnitDelay: '<S12>/Unit Delay'
       */
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_j = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/enc_ofs_cal_routine' */

      /* SystemReset for IfAction SubSystem: '<S2>/enc_ofs_cal_routine' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S2>/Switch Case' incorporates:
       *  Chart: '<S7>/EncOfsCal'
       */
      pmsm_ctrl_M->dwork.temporalCounter_i1 = 0U;
      pmsm_ctrl_M->dwork.is_active_c3_pmsm_ctrl = 0U;
      pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_NO_ACTIVE_CHILD;
      pmsm_ctrl_M->dwork.ticks_inc = 0;
      pmsm_ctrl_M->dwork.ticks_start = 0;
      pmsm_ctrl_M->dwork.ticks_end = 0;
      pmsm_ctrl_M->dwork.TICK_TGT = 0;
      pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
      pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_FAILED;
      pmsm_ctrl_M->blockIO.PwmRqst = 0.0F;
      pmsm_ctrl_M->blockIO.Ticks = 0;

      /* End of SystemReset for SubSystem: '<S2>/enc_ofs_cal_routine' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/enc_ofs_cal_routine' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Chart: '<S7>/EncOfsCal' */
    if (pmsm_ctrl_M->dwork.temporalCounter_i1 < 1023U) {
      pmsm_ctrl_M->dwork.temporalCounter_i1++;
    }

    if (pmsm_ctrl_M->dwork.is_active_c3_pmsm_ctrl == 0U) {
      pmsm_ctrl_M->dwork.is_active_c3_pmsm_ctrl = 1U;
      pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_mtr_n_poles_enc_ofs_init;
      pmsm_ctrl_M->dwork.temporalCounter_i1 = 0U;
      if (Cfg_EncCnts > 268435455) {
        pmsm_ctrl_M->dwork.TICK_TGT = MAX_int32_T;
      } else if (Cfg_EncCnts <= -268435456) {
        pmsm_ctrl_M->dwork.TICK_TGT = MIN_int32_T;
      } else {
        pmsm_ctrl_M->dwork.TICK_TGT = Cfg_EncCnts << 3;
      }

      pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_RAW_PWM;
      pmsm_ctrl_M->blockIO.PwmRqst = Cfg_AnglOfsCalPwmDuty;
      pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_ENC_OFS;
      rtSharedDSM.CalData_nPoles = -1;
      pmsm_ctrl_M->blockIO.Ticks = 0;
      pmsm_ctrl_M->dwork.ticks_inc = (int32_T)div_nzp_usu32_sat
        (pmsm_ctrl_M->dwork.TICK_TGT, TICK_OFS_CAL_RAMP);
      rtSharedDSM.CalData_EncOfs =
        pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts;
      pmsm_ctrl_M->dwork.ticks_start = 0;
      pmsm_ctrl_M->dwork.ticks_end = 0;
    } else {
      switch (pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl) {
       case IN_calc_enc_ofs_move_forward:
        if ((pmsm_ctrl_M->dwork.ticks_end >= 0) &&
            (pmsm_ctrl_M->dwork.ticks_start < pmsm_ctrl_M->dwork.ticks_end -
             MAX_int32_T)) {
          qY = MAX_int32_T;
        } else if ((pmsm_ctrl_M->dwork.ticks_end < 0) &&
                   (pmsm_ctrl_M->dwork.ticks_start >
                    pmsm_ctrl_M->dwork.ticks_end - MIN_int32_T)) {
          qY = MIN_int32_T;
        } else {
          qY = pmsm_ctrl_M->dwork.ticks_end - pmsm_ctrl_M->dwork.ticks_start;
        }

        if (qY < 0) {
          if (qY <= MIN_int32_T) {
            qY = MAX_int32_T;
          } else {
            qY = -qY;
          }
        }

        if ((pmsm_ctrl_M->blockIO.Ticks >= pmsm_ctrl_M->dwork.TICK_TGT) && (qY <
             TICK_INC_MIN)) {
          pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_enc_cnts_err;

          /*  When state machine goes into this state, it means that no encoder movement
             was detected; either because the encoder is not connected, motor has no
             power or something else. So calibration is finished here.
             TODO: Signal & handle error. */
          pmsm_ctrl_M->dwork.ticks_end = 0;
          rtSharedDSM.CalData_nPoles = -1;
          pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
          pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_FAILED;
          if (Cfg_EncCnts <= MIN_int32_T) {
            rtSharedDSM.CalData_EncOfs = MAX_int32_T;
          } else {
            rtSharedDSM.CalData_EncOfs = -Cfg_EncCnts;
          }
        } else if (pmsm_ctrl_M->blockIO.Ticks >= pmsm_ctrl_M->dwork.TICK_TGT) {
          pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_calc_n_poles;
          pmsm_ctrl_M->dwork.temporalCounter_i1 = 0U;
          if ((pmsm_ctrl_M->dwork.ticks_end >= 0) &&
              (pmsm_ctrl_M->dwork.ticks_start < pmsm_ctrl_M->dwork.ticks_end -
               MAX_int32_T)) {
            qY = MAX_int32_T;
          } else if ((pmsm_ctrl_M->dwork.ticks_end < 0) &&
                     (pmsm_ctrl_M->dwork.ticks_start >
                      pmsm_ctrl_M->dwork.ticks_end - MIN_int32_T)) {
            qY = MIN_int32_T;
          } else {
            qY = pmsm_ctrl_M->dwork.ticks_end - pmsm_ctrl_M->dwork.ticks_start;
          }

          if (qY < 0) {
            if (qY <= MIN_int32_T) {
              qY = MAX_int32_T;
            } else {
              qY = -qY;
            }
          }

          rtSharedDSM.CalData_nPoles = pmsm_ctrl_M->blockIO.Ticks / qY;
        } else {
          pmsm_ctrl_M->blockIO.PwmRqst = Cfg_EncOfsCalPwmDuty;
          if ((pmsm_ctrl_M->blockIO.Ticks < 0) && (pmsm_ctrl_M->dwork.ticks_inc <
               MIN_int32_T - pmsm_ctrl_M->blockIO.Ticks)) {
            pmsm_ctrl_M->blockIO.Ticks = MIN_int32_T;
          } else if ((pmsm_ctrl_M->blockIO.Ticks > 0) &&
                     (pmsm_ctrl_M->dwork.ticks_inc > MAX_int32_T
                      - pmsm_ctrl_M->blockIO.Ticks)) {
            pmsm_ctrl_M->blockIO.Ticks = MAX_int32_T;
          } else {
            pmsm_ctrl_M->blockIO.Ticks += pmsm_ctrl_M->dwork.ticks_inc;
          }

          pmsm_ctrl_M->dwork.ticks_end =
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts;
        }
        break;

       case IN_calc_n_poles:
        if ((rtSharedDSM.CalData_nPoles < POLES_CAL_MIN) ||
            (rtSharedDSM.CalData_nPoles > POLES_CAL_MAX)) {
          pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_enc_cnts_err;

          /*  When state machine goes into this state, it means that no encoder movement
             was detected; either because the encoder is not connected, motor has no
             power or something else. So calibration is finished here.
             TODO: Signal & handle error. */
          pmsm_ctrl_M->dwork.ticks_end = 0;
          rtSharedDSM.CalData_nPoles = -1;
          pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
          pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_FAILED;
          if (Cfg_EncCnts <= MIN_int32_T) {
            rtSharedDSM.CalData_EncOfs = MAX_int32_T;
          } else {
            rtSharedDSM.CalData_EncOfs = -Cfg_EncCnts;
          }
        } else if (pmsm_ctrl_M->dwork.temporalCounter_i1 >= 1) {
          pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_move_back_calc_enc_ofs;
          if ((pmsm_ctrl_M->blockIO.Ticks >= 0) && (pmsm_ctrl_M->dwork.ticks_inc
               < pmsm_ctrl_M->blockIO.Ticks - MAX_int32_T)) {
            pmsm_ctrl_M->blockIO.Ticks = MAX_int32_T;
          } else if ((pmsm_ctrl_M->blockIO.Ticks < 0) &&
                     (pmsm_ctrl_M->dwork.ticks_inc > pmsm_ctrl_M->blockIO.Ticks
                      - MIN_int32_T)) {
            pmsm_ctrl_M->blockIO.Ticks = MIN_int32_T;
          } else {
            pmsm_ctrl_M->blockIO.Ticks -= pmsm_ctrl_M->dwork.ticks_inc;
          }
        } else {
          if ((pmsm_ctrl_M->dwork.ticks_end >= 0) &&
              (pmsm_ctrl_M->dwork.ticks_start < pmsm_ctrl_M->dwork.ticks_end -
               MAX_int32_T)) {
            qY = MAX_int32_T;
          } else if ((pmsm_ctrl_M->dwork.ticks_end < 0) &&
                     (pmsm_ctrl_M->dwork.ticks_start >
                      pmsm_ctrl_M->dwork.ticks_end - MIN_int32_T)) {
            qY = MIN_int32_T;
          } else {
            qY = pmsm_ctrl_M->dwork.ticks_end - pmsm_ctrl_M->dwork.ticks_start;
          }

          if (qY < 0) {
            if (qY <= MIN_int32_T) {
              qY = MAX_int32_T;
            } else {
              qY = -qY;
            }
          }

          rtSharedDSM.CalData_nPoles = pmsm_ctrl_M->blockIO.Ticks / qY;
        }
        break;

       case IN_done_m:
        pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
        pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_DONE;
        pmsm_ctrl_M->blockIO.PwmRqst = (real32_T)0.;
        break;

       case IN_enc_cnts_err:
        /*  When state machine goes into this state, it means that no encoder movement
           was detected; either because the encoder is not connected, motor has no
           power or something else. So calibration is finished here.
           TODO: Signal & handle error. */
        pmsm_ctrl_M->dwork.ticks_end = 0;
        rtSharedDSM.CalData_nPoles = -1;
        pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
        pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_FAILED;
        if (Cfg_EncCnts <= MIN_int32_T) {
          rtSharedDSM.CalData_EncOfs = MAX_int32_T;
        } else {
          rtSharedDSM.CalData_EncOfs = -Cfg_EncCnts;
        }
        break;

       case IN_move_back_calc_enc_ofs:
        if (pmsm_ctrl_M->blockIO.Ticks <= 0) {
          pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_done_m;
          pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
          pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_DONE;
          pmsm_ctrl_M->blockIO.PwmRqst = (real32_T)0.;
        } else if ((pmsm_ctrl_M->blockIO.Ticks >= 0) &&
                   (pmsm_ctrl_M->dwork.ticks_inc < pmsm_ctrl_M->blockIO.Ticks -
                    MAX_int32_T)) {
          pmsm_ctrl_M->blockIO.Ticks = MAX_int32_T;
        } else if ((pmsm_ctrl_M->blockIO.Ticks < 0) &&
                   (pmsm_ctrl_M->dwork.ticks_inc > pmsm_ctrl_M->blockIO.Ticks -
                    MIN_int32_T)) {
          pmsm_ctrl_M->blockIO.Ticks = MIN_int32_T;
        } else {
          pmsm_ctrl_M->blockIO.Ticks -= pmsm_ctrl_M->dwork.ticks_inc;
        }
        break;

       default:
        if (pmsm_ctrl_M->dwork.temporalCounter_i1 >= (int32_T)
            TICK_ENC_OFS_WAIT_SETTLE) {
          /*  Wait for motor / current to settle. */
          pmsm_ctrl_M->dwork.is_c3_pmsm_ctrl = IN_calc_enc_ofs_move_forward;
          pmsm_ctrl_M->blockIO.PwmRqst = Cfg_EncOfsCalPwmDuty;
          pmsm_ctrl_M->dwork.ticks_start =
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts;
        } else {
          pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_RAW_PWM;
          pmsm_ctrl_M->blockIO.PwmRqst = Cfg_AnglOfsCalPwmDuty;
          pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_ENC_OFS;
          rtSharedDSM.CalData_nPoles = -1;
          pmsm_ctrl_M->blockIO.Ticks = 0;
          pmsm_ctrl_M->dwork.ticks_inc = (int32_T)div_nzp_usu32_sat
            (pmsm_ctrl_M->dwork.TICK_TGT, TICK_OFS_CAL_RAMP);
          rtSharedDSM.CalData_EncOfs =
            pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts;
          pmsm_ctrl_M->dwork.ticks_start = 0;
          pmsm_ctrl_M->dwork.ticks_end = 0;
        }
        break;
      }
    }

    /* End of Chart: '<S7>/EncOfsCal' */

    /* Sum: '<S12>/Add1' incorporates:
     *  Constant: '<S12>/Constant'
     *  Product: '<S12>/Product'
     *  Product: '<S12>/Product1'
     *  UnitDelay: '<S12>/Unit Delay'
     */
    rtb_PwmRqst_l = pmsm_ctrl_M->blockIO.PwmRqst * 0.038500011F + 0.9615F *
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_j;

    /* SignalConversion: '<S7>/TmpSignal ConversionAtcalc_mod_waveInport1' incorporates:
     *  Constant: '<S14>/Constant'
     */
    rtb_TmpSignalConversionAtcalc_i[0] = rtb_PwmRqst_l;
    rtb_TmpSignalConversionAtcalc_i[1] = 0.0F;
    rtb_TmpSignalConversionAtcalc_i[2] = 0.0F;

    /* Outputs for Atomic SubSystem: '<S7>/calc_mod_wave' */

    /* BusCreator: '<S7>/Bus Creator' incorporates:
     *  Constant: '<S7>/Constant'
     *  DataTypeConversion: '<S7>/Data Type Cnversion1'
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     *  Gain: '<S7>/Gain'
     *  Product: '<S7>/Divide'
     */
    calc_mod_wave(pmsm_ctrl_M, rtb_TmpSignalConversionAtcalc_i, 6.28318548F *
                  (real32_T)pmsm_ctrl_M->blockIO.Ticks / (real32_T)Cfg_EncCnts,
                  pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst,
                  pmsm_ctrl_M->blockIO.Merge.mtr_cmd_rqst);

    /* End of Outputs for SubSystem: '<S7>/calc_mod_wave' */
    pmsm_ctrl_M->blockIO.Merge.ctrl_md_rqst = pmsm_ctrl_M->blockIO.CtrlMdRqst;
    pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst =
      pmsm_ctrl_M->blockIO.CalMgrStRqst;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_j = rtb_PwmRqst_l;

    /* End of Outputs for SubSystem: '<S2>/enc_ofs_cal_routine' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* DataStoreRead: '<S2>/Data Store Read4' */
  CALIB_PARAM_BUS.ifbk_ofs[0] = rtSharedDSM.CalData_IfbkOfs_Abc[0];
  CALIB_PARAM_BUS.ifbk_ofs[1] = rtSharedDSM.CalData_IfbkOfs_Abc[1];
  CALIB_PARAM_BUS.ifbk_ofs[2] = rtSharedDSM.CalData_IfbkOfs_Abc[2];

  /* DataStoreRead: '<S2>/Data Store Read' */
  CALIB_PARAM_BUS.enc_ofs = rtSharedDSM.CalData_EncOfs;

  /* DataStoreRead: '<S2>/Data Store Read1' */
  CALIB_PARAM_BUS.inductance = rtSharedDSM.CalData_L;

  /* DataStoreRead: '<S2>/Data Store Read2' */
  CALIB_PARAM_BUS.pole_pairs = rtSharedDSM.CalData_nPoles;

  /* DataStoreRead: '<S2>/Data Store Read3' */
  CALIB_PARAM_BUS.resistance = rtSharedDSM.CalData_Res;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Cal_at_outport_1' */

  /* Outport: '<Root>/CalMgr_Status' */
  *rtY_CalMgr_Status = pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst;
}

/* Model step function */
void Trig_Pmsm_Foc(RT_MODEL *const pmsm_ctrl_M)
{
  real32_T rtb_mtr_cnts_obs;
  real32_T rtb_Subtract_b;
  real32_T rtb_Switch1;
  real32_T rtb_Switch_nt[3];
  real32_T rtb_MultiportSwitch;
  int8_T rtPrevAction;
  int8_T rtAction;
  real32_T rtb_Switch_m_idx_0;
  real32_T rtb_Switch_m_idx_1;
  real32_T rtb_Switch_f_idx_1;
  real32_T u1_tmp;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Foc_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CtrlFast'
   */
  /* Switch: '<S29>/Switch' incorporates:
   *  Gain: '<S29>/Gain'
   *  Logic: '<S29>/Logical Operator'
   *  Logic: '<S29>/Logical Operator1'
   */
  if (!(pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_spd_ctrl ||
        pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_pos_ctrl)) {
    rtb_Switch_nt[0] = pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[0];
    rtb_Switch_nt[1] = pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[1];
    rtb_Switch_nt[2] = pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[2];
  } else {
    rtb_Switch_nt[0] = pmsm_ctrl_M->blockIO.BusCreator_c.motn_ctrl_cmd;
    rtb_Switch_nt[1] = 0.0F;
    rtb_Switch_nt[2] = 0.0F;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Outputs for Enabled SubSystem: '<S28>/raw_pwm_calc' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  /* SignalConversion: '<S28>/HiddenBuf_InsertedFor_raw_pwm_calc_at_inport_1' */
  if (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_raw_pwm) {
    /* Saturate: '<S34>/Saturation' */
    if (rtb_Switch_nt[0] > 1.0F) {
      pmsm_ctrl_M->blockIO.Saturation_g[0] = 1.0F;
    } else if (rtb_Switch_nt[0] < 0.0F) {
      pmsm_ctrl_M->blockIO.Saturation_g[0] = 0.0F;
    } else {
      pmsm_ctrl_M->blockIO.Saturation_g[0] = rtb_Switch_nt[0];
    }

    /* SignalConversion: '<S34>/OutportBufferFormod_wave' */
    pmsm_ctrl_M->blockIO.OutportBufferFormod_wave[0] = 0.0F;

    /* Saturate: '<S34>/Saturation' */
    if (rtb_Switch_nt[1] > 1.0F) {
      pmsm_ctrl_M->blockIO.Saturation_g[1] = 1.0F;
    } else if (rtb_Switch_nt[1] < 0.0F) {
      pmsm_ctrl_M->blockIO.Saturation_g[1] = 0.0F;
    } else {
      pmsm_ctrl_M->blockIO.Saturation_g[1] = rtb_Switch_nt[1];
    }

    /* SignalConversion: '<S34>/OutportBufferFormod_wave' */
    pmsm_ctrl_M->blockIO.OutportBufferFormod_wave[1] = 0.0F;

    /* Saturate: '<S34>/Saturation' */
    if (rtb_Switch_nt[2] > 1.0F) {
      pmsm_ctrl_M->blockIO.Saturation_g[2] = 1.0F;
    } else if (rtb_Switch_nt[2] < 0.0F) {
      pmsm_ctrl_M->blockIO.Saturation_g[2] = 0.0F;
    } else {
      pmsm_ctrl_M->blockIO.Saturation_g[2] = rtb_Switch_nt[2];
    }

    /* SignalConversion: '<S34>/OutportBufferFormod_wave' */
    pmsm_ctrl_M->blockIO.OutportBufferFormod_wave[2] = 0.0F;
  }

  /* End of SignalConversion: '<S28>/HiddenBuf_InsertedFor_raw_pwm_calc_at_inport_1' */
  /* End of Outputs for SubSystem: '<S28>/raw_pwm_calc' */

  /* Outputs for Atomic SubSystem: '<S28>/calc_elec_angle' */

  /* SignalConversion: '<S28>/TmpSignal ConversionAtcalc_elec_angleOutport1' incorporates:
   *  DataTypeConversion: '<S28>/Data Type Conversion3'
   */
  calc_elec_angle(pmsm_ctrl_M, pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts,
                  &(DBG_Struct.e_angl), &rtb_mtr_cnts_obs, Cfg_EncCnts,
                  Cfg_PolePairs);

  /* End of Outputs for SubSystem: '<S28>/calc_elec_angle' */

  /* Sum: '<S42>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
   */
  rtb_Subtract_b = rtb_mtr_cnts_obs -
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_h;

  /* Sum: '<S42>/Add' incorporates:
   *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
   *  Gain: '<S42>/Gain1'
   */
  DBG_Struct.mtr_spd_pll = 800.0F * rtb_Subtract_b +
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_k;

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */
  DBG_Struct.mtr_spd_obs = pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_kg;

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S31>/Constant'
   *  Switch: '<S31>/Switch'
   */
  if (Cfg_SpdSnsEnbl) {
    rtb_Switch1 = pmsm_ctrl_M->blockIO.BusCreator.mtrif_spd_sns;
  } else if (Cfg_UseSpdPll) {
    /* Switch: '<S31>/Switch' */
    rtb_Switch1 = DBG_Struct.mtr_spd_pll;
  } else {
    rtb_Switch1 = DBG_Struct.mtr_spd_obs;
  }

  /* End of Switch: '<S28>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S28>/ifbk_trq_ctrl' incorporates:
   *  EnablePort: '<S32>/Enable'
   */
  /* SignalConversion: '<S28>/HiddenBuf_InsertedFor_ifbk_trq_ctrl_at_inport_5' */
  if (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_ifbk_ctrl) {
    if (!pmsm_ctrl_M->dwork.ifbk_trq_ctrl_MODE) {
      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[0] = 0.0F;
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[1] = 0.0F;
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[2] = 0.0F;
      pmsm_ctrl_M->dwork.ifbk_trq_ctrl_MODE = true;
    }

    /* Sum: '<S47>/Add1' incorporates:
     *  Constant: '<S47>/Constant'
     *  Product: '<S47>/Product'
     *  Product: '<S47>/Product1'
     *  UnitDelay: '<S47>/Unit Delay'
     */
    DBG_Struct.i_abc_lpf[0] = pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[0] *
      0.5F + 0.5F * pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[0];
    DBG_Struct.i_abc_lpf[1] = pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[1] *
      0.5F + 0.5F * pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[1];
    DBG_Struct.i_abc_lpf[2] = pmsm_ctrl_M->blockIO.BusCreator.mtrif_ifbk_act[2] *
      0.5F + 0.5F * pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[2];

    /* Gain: '<S48>/Gain1' incorporates:
     *  Fcn: '<S48>/0'
     *  Fcn: '<S48>/d'
     *  Fcn: '<S48>/q'
     */
    DBG_Struct.i_dq0[0] = ((arm_sin_f32((DBG_Struct.e_angl + 1.57079637F) -
      2.09439516F) * DBG_Struct.i_abc_lpf[1] + arm_sin_f32(DBG_Struct.e_angl +
      1.57079637F) * DBG_Struct.i_abc_lpf[0]) + arm_sin_f32((DBG_Struct.e_angl +
      1.57079637F) + 2.09439516F) * DBG_Struct.i_abc_lpf[2]) * 0.666666687F;
    DBG_Struct.i_dq0[1] = ((arm_cos_f32((DBG_Struct.e_angl + 1.57079637F) -
      2.09439516F) * DBG_Struct.i_abc_lpf[1] + arm_cos_f32(DBG_Struct.e_angl +
      1.57079637F) * DBG_Struct.i_abc_lpf[0]) + arm_cos_f32((DBG_Struct.e_angl +
      1.57079637F) + 2.09439516F) * DBG_Struct.i_abc_lpf[2]) * 0.666666687F;
    DBG_Struct.i_dq0[2] = ((DBG_Struct.i_abc_lpf[0] + DBG_Struct.i_abc_lpf[1]) +
      DBG_Struct.i_abc_lpf[2]) * 0.5F * 0.666666687F;

    /* MultiPortSwitch: '<S32>/Multiport Switch' incorporates:
     *  Constant: '<S32>/Constant2'
     *  Constant: '<S32>/Constant3'
     */
    switch (pmsm_ctrl_M->blockIO.BusCreator2.ctrl_md_act) {
     case CTRL_MD_TRQ:
      rtb_MultiportSwitch = 1.0F / Cfg_MtrKtrq;
      break;

     case CTRL_MD_IFBK:
      rtb_MultiportSwitch = 1.0F;
      break;

     default:
      rtb_MultiportSwitch = 1.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S32>/Multiport Switch' */

    /* If: '<S32>/If' incorporates:
     *  Abs: '<S57>/Abs'
     *  Abs: '<S57>/Abs1'
     *  Constant: '<S44>/Constant'
     *  Constant: '<S45>/Constant'
     *  Constant: '<S46>/Constant'
     *  Constant: '<S49>/Constant6'
     *  Product: '<S32>/Product'
     *  RelationalOperator: '<S44>/Compare'
     */
    rtPrevAction = pmsm_ctrl_M->dwork.If_ActiveSubsystem;
    rtAction = (int8_T)(pmsm_ctrl_M->blockIO.BusCreator2.ctrl_md_act ==
                        CTRL_MD_DQ_PWM);
    pmsm_ctrl_M->dwork.If_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      if (rtAction != rtPrevAction) {
        /* SystemReset for IfAction SubSystem: '<S32>/Current_Control_Mode' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */

        /* SystemReset for Atomic SubSystem: '<S50>/PI-Ctrl-Varying-Gains' */

        /* SystemReset for If: '<S32>/If' */
        PI_Ctrl_Reset(&pmsm_ctrl_M->self_PICtrlVaryingGains);

        /* End of SystemReset for SubSystem: '<S50>/PI-Ctrl-Varying-Gains' */

        /* SystemReset for Atomic SubSystem: '<S51>/PI-Ctrl-Varying-Gains' */
        PI_Ctrl_Reset(&pmsm_ctrl_M->self_PICtrlVaryingGains_p);

        /* End of SystemReset for SubSystem: '<S51>/PI-Ctrl-Varying-Gains' */

        /* End of SystemReset for SubSystem: '<S32>/Current_Control_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S32>/Current_Control_Mode' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* Switch: '<S51>/Switch' incorporates:
       *  Constant: '<S49>/Constant3'
       *  Constant: '<S49>/Constant4'
       *  Constant: '<S50>/Constant'
       *  Constant: '<S50>/Constant1'
       *  Constant: '<S51>/Constant'
       *  Constant: '<S51>/Constant2'
       *  Product: '<S50>/Product'
       *  Product: '<S51>/Product'
       *  Switch: '<S50>/Switch'
       */
      if (Cfg_AutoCalEnbl) {
        rtb_Switch_m_idx_0 = 0.0F;
        rtb_Switch_m_idx_1 = 0.0F;
        rtb_Switch_f_idx_1 = 0.0F;
      } else {
        rtb_Switch_m_idx_0 = Cfg_Ls * Cfg_IfbkCtrlBW;
        rtb_Switch_m_idx_1 = 0.0013F * Cfg_IfbkCtrlBW;
        rtb_Switch_f_idx_1 = 0.9F * Cfg_IfbkCtrlBW;
      }

      /* End of Switch: '<S51>/Switch' */

      /* Outputs for Atomic SubSystem: '<S50>/PI-Ctrl-Varying-Gains' */
      PI_Ctrl(&pmsm_ctrl_M->self_PICtrlVaryingGains, 0.0F, DBG_Struct.i_dq0[0],
              rtb_Switch_m_idx_1, rtb_Switch_f_idx_1, &rtb_Switch_f_idx_1, 3.0F,
              -3.0F);

      /* End of Outputs for SubSystem: '<S50>/PI-Ctrl-Varying-Gains' */

      /* Outputs for Enabled SubSystem: '<S49>/mtr_coupling_bemf_comp' incorporates:
       *  EnablePort: '<S52>/Enable'
       */
      if (Cfg_EnblDynComp) {
        /* Gain: '<S52>/Gain4' */
        rtb_Switch_m_idx_1 = (real32_T)Cfg_PolePairs * rtb_Switch1;

        /* Gain: '<S52>/Gain3' incorporates:
         *  Gain: '<S52>/Gain2'
         *  Product: '<S52>/Product1'
         *  Sum: '<S52>/Add1'
         */
        pmsm_ctrl_M->blockIO.Gain3 = (Cfg_MFlux / Cfg_Ls * rtb_Switch_m_idx_1 +
          DBG_Struct.i_dq0[0] * rtb_Switch_m_idx_1) * Cfg_Ls;

        /* Product: '<S52>/Product' */
        rtb_Switch_m_idx_1 *= DBG_Struct.i_dq0[1];

        /* Gain: '<S52>/Gain' */
        pmsm_ctrl_M->blockIO.Gain = -Cfg_Ls * rtb_Switch_m_idx_1;
      }

      /* End of Outputs for SubSystem: '<S49>/mtr_coupling_bemf_comp' */

      /* DataTypeConversion: '<S49>/Data Type Conversion' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S49>/Constant6'
       *  Sum: '<S49>/Add1'
       */
      DBG_Struct.ifbk_ctrl_v_dq0[0] = pmsm_ctrl_M->blockIO.Gain +
        rtb_Switch_f_idx_1;

      /* Outputs for Atomic SubSystem: '<S51>/PI-Ctrl-Varying-Gains' */
      PI_Ctrl(&pmsm_ctrl_M->self_PICtrlVaryingGains_p, rtb_Switch_nt[0] *
              rtb_MultiportSwitch, DBG_Struct.i_dq0[1], rtb_Switch_m_idx_0,
              rtb_Switch_m_idx_1, &rtb_Switch_f_idx_1, 3.0F, -3.0F);

      /* End of Outputs for SubSystem: '<S51>/PI-Ctrl-Varying-Gains' */

      /* DataTypeConversion: '<S49>/Data Type Conversion' incorporates:
       *  Constant: '<S49>/Constant2'
       *  Product: '<S32>/Product'
       *  Sum: '<S49>/Add'
       */
      DBG_Struct.ifbk_ctrl_v_dq0[1] = rtb_Switch_f_idx_1 +
        pmsm_ctrl_M->blockIO.Gain3;
      DBG_Struct.ifbk_ctrl_v_dq0[2] = 0.0F;

      /* End of Outputs for SubSystem: '<S32>/Current_Control_Mode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S32>/Current_Limiter_Mode' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      /* Switch: '<S59>/Switch' incorporates:
       *  Constant: '<S57>/Constant3'
       *  Constant: '<S57>/Constant4'
       *  Constant: '<S59>/Constant'
       *  Constant: '<S59>/Constant1'
       *  Constant: '<S59>/Constant2'
       *  Product: '<S59>/Product'
       */
      if (Cfg_AutoCalEnbl) {
        rtb_Switch_m_idx_0 = 0.0F;
        rtb_Switch_m_idx_1 = 0.0F;
      } else {
        rtb_Switch_m_idx_0 = Cfg_Ls * Cfg_IfbkCtrlBW;
        rtb_Switch_m_idx_1 = Cfg_Rs * Cfg_IfbkCtrlBW;
      }

      /* End of Switch: '<S59>/Switch' */

      /* Outputs for Atomic SubSystem: '<S59>/PI-Ctrl-Varying-Gains' */
      PI_Ctrl(&pmsm_ctrl_M->self_PICtrlVaryingGains_b, Cfg_OverCurProtMax,
              (real32_T)fabs(DBG_Struct.i_dq0[1]), rtb_Switch_m_idx_0,
              rtb_Switch_m_idx_1, &rtb_MultiportSwitch, 6.0F, -6.0F);

      /* End of Outputs for SubSystem: '<S59>/PI-Ctrl-Varying-Gains' */

      /* Saturate: '<S59>/Saturation' incorporates:
       *  Abs: '<S57>/Abs'
       *  Constant: '<S46>/Constant'
       *  Saturate: '<S58>/Saturation'
       */
      u1_tmp = -Cfg_VBus / 2.0F;
      if (rtb_MultiportSwitch > 0.0F) {
        rtb_Switch_f_idx_1 = 0.0F;
      } else if (rtb_MultiportSwitch < u1_tmp) {
        rtb_Switch_f_idx_1 = u1_tmp;
      } else {
        rtb_Switch_f_idx_1 = rtb_MultiportSwitch;
      }

      /* End of Saturate: '<S59>/Saturation' */

      /* Switch: '<S58>/Switch' incorporates:
       *  Constant: '<S57>/Constant3'
       *  Constant: '<S57>/Constant4'
       *  Constant: '<S58>/Constant'
       *  Constant: '<S58>/Constant1'
       *  Constant: '<S58>/Constant2'
       *  Product: '<S58>/Product'
       */
      if (Cfg_AutoCalEnbl) {
        rtb_Switch_m_idx_0 = 0.0F;
        rtb_Switch_m_idx_1 = 0.0F;
      } else {
        rtb_Switch_m_idx_0 = Cfg_Ls * Cfg_IfbkCtrlBW;
        rtb_Switch_m_idx_1 = Cfg_Rs * Cfg_IfbkCtrlBW;
      }

      /* End of Switch: '<S58>/Switch' */

      /* Outputs for Atomic SubSystem: '<S58>/PI-Ctrl-Varying-Gains' */
      PI_Ctrl(&pmsm_ctrl_M->self_PICtrlVaryingGains_m, Cfg_OverCurProtMax,
              (real32_T)fabs(DBG_Struct.i_dq0[0]), rtb_Switch_m_idx_0,
              rtb_Switch_m_idx_1, &rtb_MultiportSwitch, 6.0F, -6.0F);

      /* End of Outputs for SubSystem: '<S58>/PI-Ctrl-Varying-Gains' */

      /* Saturate: '<S58>/Saturation' incorporates:
       *  Abs: '<S57>/Abs1'
       *  Constant: '<S46>/Constant'
       */
      if (rtb_MultiportSwitch > 0.0F) {
        rtb_MultiportSwitch = 0.0F;
      } else {
        if (rtb_MultiportSwitch < u1_tmp) {
          rtb_MultiportSwitch = u1_tmp;
        }
      }

      /* Signum: '<S57>/Sign' */
      if (DBG_Struct.i_dq0[0] < 0.0F) {
        rtb_Switch_m_idx_0 = -1.0F;
      } else if (DBG_Struct.i_dq0[0] > 0.0F) {
        rtb_Switch_m_idx_0 = 1.0F;
      } else {
        rtb_Switch_m_idx_0 = DBG_Struct.i_dq0[0];
      }

      /* DataTypeConversion: '<S57>/Data Type Conversion' incorporates:
       *  Product: '<S57>/Multiply'
       */
      DBG_Struct.ifbk_ctrl_v_dq0[0] = rtb_MultiportSwitch * rtb_Switch_m_idx_0;

      /* Signum: '<S57>/Sign' */
      if (DBG_Struct.i_dq0[1] < 0.0F) {
        rtb_Switch_m_idx_0 = -1.0F;
      } else if (DBG_Struct.i_dq0[1] > 0.0F) {
        rtb_Switch_m_idx_0 = 1.0F;
      } else {
        rtb_Switch_m_idx_0 = DBG_Struct.i_dq0[1];
      }

      /* DataTypeConversion: '<S57>/Data Type Conversion' incorporates:
       *  Constant: '<S57>/Constant2'
       *  Product: '<S57>/Multiply'
       */
      DBG_Struct.ifbk_ctrl_v_dq0[1] = rtb_Switch_f_idx_1 * rtb_Switch_m_idx_0;
      DBG_Struct.ifbk_ctrl_v_dq0[2] = 0.0F;

      /* End of Outputs for SubSystem: '<S32>/Current_Limiter_Mode' */
      break;
    }

    /* End of If: '<S32>/If' */

    /* Gain: '<S32>/Gain5' */
    rtb_MultiportSwitch = 2.0F / Cfg_VBus;
    DBG_Struct.ifbk_ctrl_dq0[0] = rtb_MultiportSwitch *
      DBG_Struct.ifbk_ctrl_v_dq0[0];

    /* Update for UnitDelay: '<S47>/Unit Delay' */
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[0] = DBG_Struct.i_abc_lpf[0];

    /* Gain: '<S32>/Gain5' */
    DBG_Struct.ifbk_ctrl_dq0[1] = rtb_MultiportSwitch *
      DBG_Struct.ifbk_ctrl_v_dq0[1];

    /* Update for UnitDelay: '<S47>/Unit Delay' */
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[1] = DBG_Struct.i_abc_lpf[1];

    /* Gain: '<S32>/Gain5' */
    DBG_Struct.ifbk_ctrl_dq0[2] = rtb_MultiportSwitch *
      DBG_Struct.ifbk_ctrl_v_dq0[2];

    /* Update for UnitDelay: '<S47>/Unit Delay' */
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_o[2] = DBG_Struct.i_abc_lpf[2];
  } else {
    if (pmsm_ctrl_M->dwork.ifbk_trq_ctrl_MODE) {
      /* Disable for If: '<S32>/If' */
      pmsm_ctrl_M->dwork.If_ActiveSubsystem = -1;
      pmsm_ctrl_M->dwork.ifbk_trq_ctrl_MODE = false;
    }
  }

  /* End of SignalConversion: '<S28>/HiddenBuf_InsertedFor_ifbk_trq_ctrl_at_inport_5' */
  /* End of Outputs for SubSystem: '<S28>/ifbk_trq_ctrl' */

  /* Outputs for Enabled SubSystem: '<S28>/mod_wave_calc' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  /* SignalConversion: '<S28>/HiddenBuf_InsertedFor_mod_wave_calc_at_inport_5' */
  if (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_mod_wave) {
    if (!pmsm_ctrl_M->dwork.mod_wave_calc_MODE) {
      /* InitializeConditions for UnitDelay: '<S65>/Unit Delay' */
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[0] = 0.0F;
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[1] = 0.0F;
      pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[2] = 0.0F;
      pmsm_ctrl_M->dwork.mod_wave_calc_MODE = true;
    }

    /* Sum: '<S65>/Add1' incorporates:
     *  Constant: '<S65>/Constant'
     *  Product: '<S65>/Product'
     *  Product: '<S65>/Product1'
     *  UnitDelay: '<S65>/Unit Delay'
     */
    DBG_Struct.pwm_ctrl_dq0_lpf[0] = rtb_Switch_nt[0] * 0.00199598074F +
      0.998004F * pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[0];
    DBG_Struct.pwm_ctrl_dq0_lpf[1] = rtb_Switch_nt[1] * 0.00199598074F +
      0.998004F * pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[1];
    DBG_Struct.pwm_ctrl_dq0_lpf[2] = rtb_Switch_nt[2] * 0.00199598074F +
      0.998004F * pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[2];

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S64>/Compare'
     *  Sum: '<S33>/Add'
     */
    if (pmsm_ctrl_M->blockIO.BusCreator2.ctrl_md_act == CTRL_MD_DQ_PWM) {
      DBG_Struct.pwm_dq0[0] = DBG_Struct.ifbk_ctrl_dq0[0] +
        DBG_Struct.pwm_ctrl_dq0_lpf[0];
      DBG_Struct.pwm_dq0[1] = DBG_Struct.ifbk_ctrl_dq0[1] +
        DBG_Struct.pwm_ctrl_dq0_lpf[1];
      DBG_Struct.pwm_dq0[2] = DBG_Struct.ifbk_ctrl_dq0[2] +
        DBG_Struct.pwm_ctrl_dq0_lpf[2];
    } else {
      DBG_Struct.pwm_dq0[0] = DBG_Struct.ifbk_ctrl_dq0[0];
      DBG_Struct.pwm_dq0[1] = DBG_Struct.ifbk_ctrl_dq0[1];
      DBG_Struct.pwm_dq0[2] = DBG_Struct.ifbk_ctrl_dq0[2];
    }

    /* End of Switch: '<S33>/Switch' */

    /* Saturate: '<S33>/Saturation1' */
    if (DBG_Struct.pwm_dq0[0] > 1.0F) {
      rtb_Switch_nt[0] = 1.0F;
    } else if (DBG_Struct.pwm_dq0[0] < -1.0F) {
      rtb_Switch_nt[0] = -1.0F;
    } else {
      rtb_Switch_nt[0] = DBG_Struct.pwm_dq0[0];
    }

    if (DBG_Struct.pwm_dq0[1] > 1.0F) {
      rtb_Switch_nt[1] = 1.0F;
    } else if (DBG_Struct.pwm_dq0[1] < -1.0F) {
      rtb_Switch_nt[1] = -1.0F;
    } else {
      rtb_Switch_nt[1] = DBG_Struct.pwm_dq0[1];
    }

    if (DBG_Struct.pwm_dq0[2] > 1.0F) {
      rtb_Switch_nt[2] = 1.0F;
    } else if (DBG_Struct.pwm_dq0[2] < -1.0F) {
      rtb_Switch_nt[2] = -1.0F;
    } else {
      rtb_Switch_nt[2] = DBG_Struct.pwm_dq0[2];
    }

    /* End of Saturate: '<S33>/Saturation1' */

    /* Outputs for Atomic SubSystem: '<S33>/calc_mod_wave' */
    calc_mod_wave(pmsm_ctrl_M, rtb_Switch_nt, DBG_Struct.e_angl,
                  pmsm_ctrl_M->blockIO.DataTypeConversion,
                  pmsm_ctrl_M->blockIO.Gain1);

    /* End of Outputs for SubSystem: '<S33>/calc_mod_wave' */

    /* Update for UnitDelay: '<S65>/Unit Delay' */
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[0] = DBG_Struct.pwm_ctrl_dq0_lpf[0];
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[1] = DBG_Struct.pwm_ctrl_dq0_lpf[1];
    pmsm_ctrl_M->dwork.UnitDelay_DSTATE_h[2] = DBG_Struct.pwm_ctrl_dq0_lpf[2];
  } else {
    if (pmsm_ctrl_M->dwork.mod_wave_calc_MODE) {
      pmsm_ctrl_M->dwork.mod_wave_calc_MODE = false;
    }
  }

  /* End of SignalConversion: '<S28>/HiddenBuf_InsertedFor_mod_wave_calc_at_inport_5' */
  /* End of Outputs for SubSystem: '<S28>/mod_wave_calc' */

  /* Switch: '<S28>/Switch2' */
  if (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_raw_pwm) {
    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    pmsm_ctrl_M->blockIO.MtrIf_ModWave[0] =
      pmsm_ctrl_M->blockIO.OutportBufferFormod_wave[0];

    /* DataTypeConversion: '<S28>/Data Type Conversion5' */
    pmsm_ctrl_M->blockIO.MtrIf_PwmDc[0] = pmsm_ctrl_M->blockIO.Saturation_g[0];

    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    pmsm_ctrl_M->blockIO.MtrIf_ModWave[1] =
      pmsm_ctrl_M->blockIO.OutportBufferFormod_wave[1];

    /* DataTypeConversion: '<S28>/Data Type Conversion5' */
    pmsm_ctrl_M->blockIO.MtrIf_PwmDc[1] = pmsm_ctrl_M->blockIO.Saturation_g[1];

    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    pmsm_ctrl_M->blockIO.MtrIf_ModWave[2] =
      pmsm_ctrl_M->blockIO.OutportBufferFormod_wave[2];

    /* DataTypeConversion: '<S28>/Data Type Conversion5' */
    pmsm_ctrl_M->blockIO.MtrIf_PwmDc[2] = pmsm_ctrl_M->blockIO.Saturation_g[2];
  } else {
    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    pmsm_ctrl_M->blockIO.MtrIf_ModWave[0] = pmsm_ctrl_M->blockIO.Gain1[0];

    /* DataTypeConversion: '<S28>/Data Type Conversion5' */
    pmsm_ctrl_M->blockIO.MtrIf_PwmDc[0] =
      pmsm_ctrl_M->blockIO.DataTypeConversion[0];

    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    pmsm_ctrl_M->blockIO.MtrIf_ModWave[1] = pmsm_ctrl_M->blockIO.Gain1[1];

    /* DataTypeConversion: '<S28>/Data Type Conversion5' */
    pmsm_ctrl_M->blockIO.MtrIf_PwmDc[1] =
      pmsm_ctrl_M->blockIO.DataTypeConversion[1];

    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    pmsm_ctrl_M->blockIO.MtrIf_ModWave[2] = pmsm_ctrl_M->blockIO.Gain1[2];

    /* DataTypeConversion: '<S28>/Data Type Conversion5' */
    pmsm_ctrl_M->blockIO.MtrIf_PwmDc[2] =
      pmsm_ctrl_M->blockIO.DataTypeConversion[2];
  }

  /* End of Switch: '<S28>/Switch2' */

  /* Gain: '<S28>/Gain2' */
  rtb_MultiportSwitch = Cfg_MtrKtrq * DBG_Struct.i_dq0[1];

  /* Sum: '<S35>/Add3' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_mtr_cnts_obs -= pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke;

  /* Product: '<S35>/Product1' incorporates:
   *  Constant: '<S31>/ObsInertia'
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
   */
  DBG_Struct.mtr_load_obs = pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p *
    DistObs_J;

  /* DataTypeConversion: '<S37>/Data Type Conversion4' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant2'
   *  DataTypeConversion: '<S37>/Data Type Conversion8'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Product: '<S37>/Product'
   */
  DBG_Struct.obs_enc_cnts = (int32_T)
    (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke * (real32_T)Cfg_EncCnts /
     6.28318548F);

  /* DataTypeConversion: '<S28>/Data Type Conversion2' */
  pmsm_ctrl_M->blockIO.MtrIf_TrqAct = rtb_MultiportSwitch;

  /* DataTypeConversion: '<S28>/Data Type Conversion1' */
  pmsm_ctrl_M->blockIO.MtrIf_SpdOut = rtb_Switch1;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_h += 0.0001F *
    DBG_Struct.mtr_spd_pll;
  if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_h >= 1.0E+6F) {
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_h = 1.0E+6F;
  } else {
    if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_h <= -1.0E+6F) {
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_h = -1.0E+6F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S42>/Gain'
   */
  pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_k += 160000.0F *
    rtb_Subtract_b * 0.0001F;
  if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_k >= 1.0E+6F) {
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_k = 1.0E+6F;
  } else {
    if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_k <= -1.0E+6F) {
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_k = -1.0E+6F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S31>/ObsInertia'
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
   *  Gain: '<S35>/Gain1'
   *  Product: '<S35>/Product'
   *  Sum: '<S35>/Add'
   *  Sum: '<S35>/Add1'
   */
  pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_kg += ((DistObs_K2 *
    rtb_mtr_cnts_obs + pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p) +
    rtb_MultiportSwitch / DistObs_J) * 0.0001F;
  if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_kg >= 1.0E+7F) {
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_kg = 1.0E+7F;
  } else {
    if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_kg <= -1.0E+7F) {
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_kg = -1.0E+7F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain3'
   *  Sum: '<S35>/Add2'
   */
  pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke += (DistObs_K1 *
    rtb_mtr_cnts_obs + DBG_Struct.mtr_spd_obs) * 0.0001F;
  if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke >= 1.0E+7F) {
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke = 1.0E+7F;
  } else {
    if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke <= -1.0E+7F) {
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTAT_ke = -1.0E+7F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain'
   */
  pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p += DistObs_K3 *
    rtb_mtr_cnts_obs * 0.0001F;
  if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p >= 1.0E+7F) {
    pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p = 1.0E+7F;
  } else {
    if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p <= -1.0E+7F) {
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_p = -1.0E+7F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Foc_at_outport_1' */
}

/* Model step function */
void Trig_Pmsm_MotnCtrl(RT_MODEL *const pmsm_ctrl_M)
{
  real32_T rtb_Product_f;
  real32_T rtb_Add_gh;
  real32_T rtb_Sign_k;
  real32_T rtb_Add1_j;
  real32_T rtb_Sign_g;
  int32_T tmp;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_MotnCtrl_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CtrlMain'
   */
  /* Logic: '<S4>/Logical Operator' */
  DBG_Struct.enbl_motn_ctrl =
    (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_spd_ctrl ||
     pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_pos_ctrl);

  /* Outputs for Enabled SubSystem: '<S4>/MotnCtrl' incorporates:
   *  EnablePort: '<S70>/Enable'
   */
  if (DBG_Struct.enbl_motn_ctrl) {
    if (!pmsm_ctrl_M->dwork.MotnCtrl_MODE) {
      pmsm_ctrl_M->dwork.MotnCtrl_MODE = true;
    }

    /* Gain: '<S70>/Gain3' incorporates:
     *  DataTypeConversion: '<S70>/Data Type Conversion6'
     */
    DBG_Struct.mtr_cnts_tgt = Cfg_StepToEncCnts * (int32_T)
      pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[0];

    /* Product: '<S74>/Product' incorporates:
     *  Constant: '<S74>/Constant'
     *  Constant: '<S74>/Constant1'
     *  DataTypeConversion: '<S74>/Data Type Conversion8'
     *  DataTypeConversion: '<S74>/Data Type Conversion9'
     */
    rtb_Product_f = (real32_T)DBG_Struct.mtr_cnts_tgt / (real32_T)Cfg_EncCnts *
      6.28318548F;

    /* Logic: '<S72>/Logical Operator' incorporates:
     *  Constant: '<S72>/Constant'
     */
    DBG_Struct.traj_plan_is_enbl = (Cfg_EnblTrajPlan &&
      pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_pos_ctrl);

    /* Outputs for Enabled SubSystem: '<S72>/PosTrackDiff' incorporates:
     *  EnablePort: '<S79>/Enable'
     */
    if (DBG_Struct.traj_plan_is_enbl) {
      if (!pmsm_ctrl_M->dwork.PosTrackDiff_MODE) {
        /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator1_DSTATE = 0.0F;

        /* InitializeConditions for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE = 0.0F;
        pmsm_ctrl_M->dwork.PosTrackDiff_MODE = true;
      }

      /* DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
      pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator1 =
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator1_DSTATE;

      /* DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
      pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator =
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE;

      /* Gain: '<S80>/Gain3' */
      rtb_Add_gh = TsMain * pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator;

      /* Sum: '<S80>/Add8' incorporates:
       *  Sum: '<S79>/Add'
       */
      rtb_Sign_k = (pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator1 - rtb_Product_f)
        + rtb_Add_gh;

      /* Sqrt: '<S81>/Sqrt' incorporates:
       *  Abs: '<S81>/Abs'
       *  Constant: '<S80>/d'
       *  Gain: '<S81>/Gain'
       *  Product: '<S81>/Product'
       *  Sum: '<S81>/Add'
       */
      mw_arm_sqrt_f32((8.0F * (real32_T)fabs(rtb_Sign_k) + 0.000100000012F) *
                      0.000100000012F, &rtb_Add1_j);

      /* Signum: '<S82>/Sign' */
      if (rtb_Sign_k < 0.0F) {
        rtb_Sign_g = -1.0F;
      } else if (rtb_Sign_k > 0.0F) {
        rtb_Sign_g = 1.0F;
      } else {
        rtb_Sign_g = rtb_Sign_k;
      }

      /* End of Signum: '<S82>/Sign' */

      /* Sum: '<S82>/Add1' incorporates:
       *  Constant: '<S80>/d'
       *  Gain: '<S82>/Gain'
       *  Product: '<S82>/Product'
       *  Sum: '<S82>/Add'
       */
      rtb_Add1_j = (rtb_Add1_j - 0.000100000012F) * rtb_Sign_g * 0.5F +
        rtb_Add_gh;

      /* Sum: '<S83>/Add1' */
      rtb_Add_gh = (rtb_Add_gh + rtb_Sign_k) - rtb_Add1_j;

      /* Sum: '<S86>/Add1' incorporates:
       *  Constant: '<S80>/d'
       */
      rtb_Sign_g = 0.000100000012F + rtb_Sign_k;

      /* Sum: '<S86>/Add2' incorporates:
       *  Constant: '<S80>/d'
       */
      rtb_Sign_k -= 0.000100000012F;

      /* Signum: '<S86>/Sign' */
      if (rtb_Sign_g < 0.0F) {
        rtb_Sign_g = -1.0F;
      } else {
        if (rtb_Sign_g > 0.0F) {
          rtb_Sign_g = 1.0F;
        }
      }

      /* End of Signum: '<S86>/Sign' */

      /* Signum: '<S86>/Sign1' */
      if (rtb_Sign_k < 0.0F) {
        rtb_Sign_k = -1.0F;
      } else {
        if (rtb_Sign_k > 0.0F) {
          rtb_Sign_k = 1.0F;
        }
      }

      /* End of Signum: '<S86>/Sign1' */

      /* Sum: '<S83>/Add2' incorporates:
       *  Gain: '<S86>/Gain1'
       *  Product: '<S83>/Product'
       *  Sum: '<S86>/Add'
       */
      rtb_Add1_j += (rtb_Sign_g - rtb_Sign_k) * 0.5F * rtb_Add_gh;

      /* Signum: '<S84>/Sign' */
      if (rtb_Add1_j < 0.0F) {
        rtb_Sign_k = -1.0F;
      } else if (rtb_Add1_j > 0.0F) {
        rtb_Sign_k = 1.0F;
      } else {
        rtb_Sign_k = rtb_Add1_j;
      }

      /* End of Signum: '<S84>/Sign' */

      /* Sum: '<S84>/Add' incorporates:
       *  Constant: '<S80>/d'
       *  Product: '<S84>/Divide'
       */
      rtb_Add_gh = rtb_Add1_j / 0.000100000012F - rtb_Sign_k;

      /* Sum: '<S85>/Add' incorporates:
       *  Constant: '<S80>/d'
       */
      rtb_Sign_g = rtb_Add1_j + 0.000100000012F;

      /* Sum: '<S85>/Add1' incorporates:
       *  Constant: '<S80>/d'
       */
      rtb_Add1_j -= 0.000100000012F;

      /* SignalConversion: '<S79>/OutportBufferForGrd' */
      DBG_Struct.traj_plan_grd = pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator;

      /* SignalConversion: '<S79>/OutportBufferForRef' */
      DBG_Struct.traj_plan_ref = pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator1;

      /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator1_DSTATE += 0.001F *
        pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator;

      /* Signum: '<S85>/Sign' */
      if (rtb_Sign_g < 0.0F) {
        rtb_Sign_g = -1.0F;
      } else {
        if (rtb_Sign_g > 0.0F) {
          rtb_Sign_g = 1.0F;
        }
      }

      /* End of Signum: '<S85>/Sign' */

      /* Signum: '<S85>/Sign1' */
      if (rtb_Add1_j < 0.0F) {
        rtb_Add1_j = -1.0F;
      } else {
        if (rtb_Add1_j > 0.0F) {
          rtb_Add1_j = 1.0F;
        }
      }

      /* End of Signum: '<S85>/Sign1' */

      /* Update for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' incorporates:
       *  Gain: '<S84>/Gain'
       *  Gain: '<S85>/Gain'
       *  Product: '<S84>/Product'
       *  Sum: '<S84>/Add1'
       *  Sum: '<S85>/Add2'
       */
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE += ((rtb_Sign_g -
        rtb_Add1_j) * 0.5F * rtb_Add_gh + rtb_Sign_k) * -100.0F * 0.001F;
    } else {
      if (pmsm_ctrl_M->dwork.PosTrackDiff_MODE) {
        /* Disable for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator1_DSTATE =
          pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator1;

        /* Disable for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE =
          pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator;
        pmsm_ctrl_M->dwork.PosTrackDiff_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S72>/PosTrackDiff' */

    /* Switch: '<S72>/Switch' */
    if (DBG_Struct.traj_plan_is_enbl) {
      rtb_Product_f = DBG_Struct.traj_plan_ref;
    }

    /* End of Switch: '<S72>/Switch' */

    /* DataTypeConversion: '<S76>/Data Type Conversion4' incorporates:
     *  Constant: '<S76>/Constant'
     *  Constant: '<S76>/Constant2'
     *  DataTypeConversion: '<S76>/Data Type Conversion8'
     *  Product: '<S76>/Product'
     */
    DBG_Struct.mtr_cnts_ref = (int32_T)(rtb_Product_f * (real32_T)Cfg_EncCnts /
      6.28318548F);

    /* Outputs for Enabled SubSystem: '<S70>/PosCtl' incorporates:
     *  EnablePort: '<S71>/Enable'
     */
    /* Switch: '<S70>/Switch1' incorporates:
     *  SignalConversion: '<S70>/HiddenBuf_InsertedFor_PosCtl_at_inport_2'
     */
    if (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_pos_ctrl) {
      if (!pmsm_ctrl_M->dwork.PosCtl_MODE) {
        /* InitializeConditions for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o = 0.0F;
        pmsm_ctrl_M->dwork.PosCtl_MODE = true;
      }

      /* Switch: '<S70>/Switch2' incorporates:
       *  Constant: '<S70>/Constant3'
       *  DataTypeConversion: '<S70>/Data Type Conversion5'
       */
      if (Cfg_UseObsPosEst) {
        tmp = DBG_Struct.obs_enc_cnts;
      } else {
        tmp = pmsm_ctrl_M->blockIO.BusCreator.mtrif_enc_cnts;
      }

      /* End of Switch: '<S70>/Switch2' */

      /* Sum: '<S77>/Subtract' incorporates:
       *  Constant: '<S75>/Constant'
       *  Constant: '<S75>/Constant1'
       *  DataTypeConversion: '<S75>/Data Type Conversion8'
       *  DataTypeConversion: '<S75>/Data Type Conversion9'
       *  Product: '<S75>/Product'
       */
      rtb_Product_f -= (real32_T)tmp / (real32_T)Cfg_EncCnts * 6.28318548F;

      /* Sum: '<S77>/Add' incorporates:
       *  DiscreteIntegrator: '<S78>/Discrete-Time Integrator'
       *  Gain: '<S77>/Gain1'
       */
      rtb_Add_gh = PosCtrl_Kp * rtb_Product_f +
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o;

      /* Saturate: '<S71>/Saturation' */
      if (rtb_Add_gh > 400.0F) {
        pmsm_ctrl_M->blockIO.Saturation_b = 400.0F;
      } else if (rtb_Add_gh < -400.0F) {
        pmsm_ctrl_M->blockIO.Saturation_b = -400.0F;
      } else {
        pmsm_ctrl_M->blockIO.Saturation_b = rtb_Add_gh;
      }

      /* End of Saturate: '<S71>/Saturation' */

      /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' incorporates:
       *  Gain: '<S77>/Gain'
       */
      pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o += PosCtrl_Ki *
        rtb_Product_f * 0.001F;
      if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o >= 300.0F) {
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o = 300.0F;
      } else {
        if (pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o <= -300.0F) {
          pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE_o = -300.0F;
        }
      }

      /* End of Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
      rtb_Sign_g = pmsm_ctrl_M->blockIO.Saturation_b;
    } else {
      if (pmsm_ctrl_M->dwork.PosCtl_MODE) {
        pmsm_ctrl_M->dwork.PosCtl_MODE = false;
      }

      rtb_Sign_g = pmsm_ctrl_M->blockIO.BusCreator2.ctrl_tgt[0];
    }

    /* End of Switch: '<S70>/Switch1' */
    /* End of Outputs for SubSystem: '<S70>/PosCtl' */

    /* Sum: '<S70>/Add' */
    DBG_Struct.mtr_spd_tgt = DBG_Struct.traj_plan_grd + rtb_Sign_g;

    /* Outputs for Enabled SubSystem: '<S70>/SpdCtrl' incorporates:
     *  EnablePort: '<S73>/Enable'
     */
    /* SignalConversion: '<S70>/HiddenBuf_InsertedFor_SpdCtrl_at_inport_2' incorporates:
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S73>/Constant3'
     *  DataTypeConversion: '<S70>/Data Type Conversion1'
     */
    if (pmsm_ctrl_M->blockIO.BusCreator2.ENBL_CTRL_FLAGS.enbl_spd_ctrl) {
      if (!pmsm_ctrl_M->dwork.SpdCtrl_MODE) {
        /* SystemReset for Atomic SubSystem: '<S73>/PI-Ctrl-Varying-Gains' */
        PI_Ctrl_Reset(&pmsm_ctrl_M->self_PICtrlVaryingGains_mi);

        /* End of SystemReset for SubSystem: '<S73>/PI-Ctrl-Varying-Gains' */
        pmsm_ctrl_M->dwork.SpdCtrl_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S73>/PI-Ctrl-Varying-Gains' */
      PI_Ctrl(&pmsm_ctrl_M->self_PICtrlVaryingGains_mi, DBG_Struct.mtr_spd_tgt,
              pmsm_ctrl_M->blockIO.MtrIf_SpdOut, Cfg_SpdCtrlBW * Cfg_MtrJm,
              Cfg_SpdCtrlBW * Cfg_MtrKf, &rtb_Product_f, 0.5F, -0.5F);

      /* End of Outputs for SubSystem: '<S73>/PI-Ctrl-Varying-Gains' */

      /* Saturate: '<S73>/Saturation' incorporates:
       *  Constant: '<S73>/Constant1'
       *  Constant: '<S73>/Constant3'
       *  DataTypeConversion: '<S70>/Data Type Conversion1'
       */
      if (rtb_Product_f > 2.0F) {
        pmsm_ctrl_M->blockIO.Saturation = 2.0F;
      } else if (rtb_Product_f < -2.0F) {
        pmsm_ctrl_M->blockIO.Saturation = -2.0F;
      } else {
        pmsm_ctrl_M->blockIO.Saturation = rtb_Product_f;
      }

      /* End of Saturate: '<S73>/Saturation' */
    } else {
      if (pmsm_ctrl_M->dwork.SpdCtrl_MODE) {
        pmsm_ctrl_M->dwork.SpdCtrl_MODE = false;
      }
    }

    /* End of SignalConversion: '<S70>/HiddenBuf_InsertedFor_SpdCtrl_at_inport_2' */
    /* End of Outputs for SubSystem: '<S70>/SpdCtrl' */

    /* DataTypeConversion: '<S70>/Data Type Conversion4' */
    DBG_Struct.motn_ctrl_cmd = pmsm_ctrl_M->blockIO.Saturation;
  } else {
    if (pmsm_ctrl_M->dwork.MotnCtrl_MODE) {
      /* Disable for Enabled SubSystem: '<S72>/PosTrackDiff' */
      if (pmsm_ctrl_M->dwork.PosTrackDiff_MODE) {
        /* Disable for DiscreteIntegrator: '<S79>/Discrete-Time Integrator1' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator1_DSTATE =
          pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator1;

        /* Disable for DiscreteIntegrator: '<S79>/Discrete-Time Integrator' */
        pmsm_ctrl_M->dwork.DiscreteTimeIntegrator_DSTATE =
          pmsm_ctrl_M->blockIO.DiscreteTimeIntegrator;
        pmsm_ctrl_M->dwork.PosTrackDiff_MODE = false;
      }

      /* End of Disable for SubSystem: '<S72>/PosTrackDiff' */

      /* Disable for Enabled SubSystem: '<S70>/PosCtl' */
      if (pmsm_ctrl_M->dwork.PosCtl_MODE) {
        pmsm_ctrl_M->dwork.PosCtl_MODE = false;
      }

      /* End of Disable for SubSystem: '<S70>/PosCtl' */

      /* Disable for Enabled SubSystem: '<S70>/SpdCtrl' */
      if (pmsm_ctrl_M->dwork.SpdCtrl_MODE) {
        pmsm_ctrl_M->dwork.SpdCtrl_MODE = false;
      }

      /* End of Disable for SubSystem: '<S70>/SpdCtrl' */
      pmsm_ctrl_M->dwork.MotnCtrl_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S4>/MotnCtrl' */

  /* BusCreator: '<S4>/Bus Creator' */
  pmsm_ctrl_M->blockIO.BusCreator_c.motn_ctrl_cmd = DBG_Struct.motn_ctrl_cmd;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_MotnCtrl_at_outport_1' */
}

/* Model step function */
void Trig_Pmsm_GetOut(RT_MODEL *const pmsm_ctrl_M, real32_T rtY_MtrIf_PwmDc[3],
                      real32_T rtY_MtrIf_ModWave[3], real32_T *rtY_MtrIf_TrqAct,
                      real32_T *rtY_MtrIf_SpdAct)
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_GetOut_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CalcOutputs'
   */
  /* Saturate: '<S1>/Saturation' */
  if (pmsm_ctrl_M->blockIO.MtrIf_PwmDc[0] > 1.0F) {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[0] = 1.0F;
  } else if (pmsm_ctrl_M->blockIO.MtrIf_PwmDc[0] < 0.0F) {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[0] = 0.0F;
  } else {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[0] = pmsm_ctrl_M->blockIO.MtrIf_PwmDc[0];
  }

  /* Outport: '<Root>/MtrIf_ModWave' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  rtY_MtrIf_ModWave[0] = pmsm_ctrl_M->blockIO.MtrIf_ModWave[0];

  /* Saturate: '<S1>/Saturation' */
  if (pmsm_ctrl_M->blockIO.MtrIf_PwmDc[1] > 1.0F) {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[1] = 1.0F;
  } else if (pmsm_ctrl_M->blockIO.MtrIf_PwmDc[1] < 0.0F) {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[1] = 0.0F;
  } else {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[1] = pmsm_ctrl_M->blockIO.MtrIf_PwmDc[1];
  }

  /* Outport: '<Root>/MtrIf_ModWave' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  rtY_MtrIf_ModWave[1] = pmsm_ctrl_M->blockIO.MtrIf_ModWave[1];

  /* Saturate: '<S1>/Saturation' */
  if (pmsm_ctrl_M->blockIO.MtrIf_PwmDc[2] > 1.0F) {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[2] = 1.0F;
  } else if (pmsm_ctrl_M->blockIO.MtrIf_PwmDc[2] < 0.0F) {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[2] = 0.0F;
  } else {
    /* Outport: '<Root>/MtrIf_PwmDc' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    rtY_MtrIf_PwmDc[2] = pmsm_ctrl_M->blockIO.MtrIf_PwmDc[2];
  }

  /* Outport: '<Root>/MtrIf_ModWave' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  rtY_MtrIf_ModWave[2] = pmsm_ctrl_M->blockIO.MtrIf_ModWave[2];

  /* Outport: '<Root>/MtrIf_TrqAct' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   */
  *rtY_MtrIf_TrqAct = pmsm_ctrl_M->blockIO.MtrIf_TrqAct;

  /* Outport: '<Root>/MtrIf_SpdAct' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   */
  *rtY_MtrIf_SpdAct = pmsm_ctrl_M->blockIO.MtrIf_SpdOut;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_GetOut_at_outport_1' */
}

/* Model initialize function */
void Trig_Pmsm_Init(RT_MODEL *const pmsm_ctrl_M, CalMgrSt_T *rtY_CalMgr_Status)
{
  /* Registration code */
  {
    /* Storage classes */
    {
      ((B *) &(pmsm_ctrl_M->blockIO))->Merge = pmsm_ctrl_rtZCalib_OutType;
      ((B *) &(pmsm_ctrl_M->blockIO))->CalMgrStRqst = ST_FAILED;
      ((B *) &(pmsm_ctrl_M->blockIO))->CalMgrStRqst_i = ST_FAILED;
      ((B *) &(pmsm_ctrl_M->blockIO))->CalMgrStRqst_h = ST_FAILED;
    }

    /* external outputs */
    (*rtY_CalMgr_Status) = ST_FAILED;
  }

  /* Start for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Cal_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CalibRoutines'
   */
  /* Start for SwitchCase: '<S2>/Switch Case' */
  pmsm_ctrl_M->dwork.SwitchCase_ActiveSubsystem = -1;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory1' incorporates:
   *  DataStoreMemory: '<S2>/Data Store Memory3'
   */
  if (!_pmsm_ctrl_SharedDataInit_) {
    rtSharedDSM.CalData_L = -1.0F;
    rtSharedDSM.CalData_Res = -1.0F;
  }

  /* End of Start for DataStoreMemory: '<S2>/Data Store Memory1' */
  /* End of Start for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Cal_at_outport_1' */

  /* Start for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Foc_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CtrlFast'
   */
  /* Start for Enabled SubSystem: '<S28>/ifbk_trq_ctrl' */
  /* Start for If: '<S32>/If' */
  pmsm_ctrl_M->dwork.If_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S28>/ifbk_trq_ctrl' */
  /* End of Start for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Foc_at_outport_1' */

  /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Cal_at_outport_1' incorporates:
   *  SubSystem: '<Root>/CalibRoutines'
   */
  /* SystemInitialize for IfAction SubSystem: '<S2>/mtr_res_ident' */
  /* SystemInitialize for Chart: '<S10>/ResIdCal' */
  pmsm_ctrl_M->blockIO.CtrlMdRqst_p = CTRL_MD_OFF;
  pmsm_ctrl_M->blockIO.CalMgrStRqst_h = ST_FAILED;

  /* End of SystemInitialize for SubSystem: '<S2>/mtr_res_ident' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/mtr_ind_ident' */
  /* SystemInitialize for Chart: '<S9>/IndIdCal' */
  pmsm_ctrl_M->blockIO.CtrlMdRqst_i = CTRL_MD_OFF;
  pmsm_ctrl_M->blockIO.CalMgrStRqst_i = ST_FAILED;

  /* End of SystemInitialize for SubSystem: '<S2>/mtr_ind_ident' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/enc_ofs_cal_routine' */
  /* SystemInitialize for Chart: '<S7>/EncOfsCal' */
  pmsm_ctrl_M->blockIO.CtrlMdRqst = CTRL_MD_OFF;
  pmsm_ctrl_M->blockIO.CalMgrStRqst = ST_FAILED;

  /* End of SystemInitialize for SubSystem: '<S2>/enc_ofs_cal_routine' */

  /* SystemInitialize for Merge: '<S2>/Merge' */
  pmsm_ctrl_M->blockIO.Merge = pmsm_ctrl_rtZCalib_OutType;

  /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_Trig_Pmsm_Cal_at_outport_1' */

  /* SystemInitialize for Outport: '<Root>/CalMgr_Status' */
  *rtY_CalMgr_Status = pmsm_ctrl_M->blockIO.Merge.cal_mgr_st_rqst;

  /* SystemInitialize for DataStoreMemory: '<Root>/_pmsm_ctrl_SharedDataInit_' */
  if (!_pmsm_ctrl_SharedDataInit_) {
    _pmsm_ctrl_SharedDataInit_ = true;
  }

  /* End of SystemInitialize for DataStoreMemory: '<Root>/_pmsm_ctrl_SharedDataInit_' */
}
