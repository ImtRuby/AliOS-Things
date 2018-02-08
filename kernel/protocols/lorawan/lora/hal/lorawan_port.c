/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */

/* Includes ------------------------------------------------------------------*/
#include "lorawan_port.h"
#include "hw_msp.h"
#include "hw_rtc.h"


static void enter_stop_mode()
{
    HW_EnterStopMode();
}

static void exit_stop_mode()
{
    HW_ExitStopMode();
}

static void enter_sleep_mode()
{
    HW_EnterSleepMode();
}

static void delay_ms(uint32_t delay)
{
    HW_RTC_DelayMs(delay);
}

static uint32_t set_timer_context()
{
    return (uint32_t)HW_RTC_SetTimerContext();
}

static uint32_t get_timer_context()
{
    return (uint32_t)HW_RTC_GetTimerContext();
}

static uint32_t get_timer_elapsed_time()
{
    return (uint32_t)HW_RTC_GetTimerElapsedTime();
}

static uint32_t ms2tick(TimerTime_t u_sec)
{
    return (uint32_t)HW_RTC_ms2Tick(u_sec);

}

static TimerTime_t tick2ms(uint32_t tick) 
{
    return (TimerTime_t)HW_RTC_Tick2ms(tick);
}

static uint32_t get_min_timeout()
{
    return (uint32_t)HW_RTC_GetMinimumTimeout(); 
}

static uint32_t get_timer_val()
{
    return (uint32_t)HW_RTC_GetTimerValue();
}

static void set_uc_wakeup_time()
{
    HW_RTC_setMcuWakeUpTime();
}

static void set_alarm(uint32_t timeout)
{
    HW_RTC_SetAlarm(timeout);
}

static void stop_alarm()
{
    HW_RTC_StopAlarm();
}

hal_lrwan_dev_chg_mode_t aos_lrwan_chg_mode = {
    .enter_stop_mode  = enter_stop_mode,
    .exit_stop_mode   = exit_stop_mode, 
    .enter_sleep_mode = enter_sleep_mode,
};

hal_lrwan_time_itf_t aos_lrwan_time_itf = {
    .delay_ms = delay_ms,
    .set_timer_context = set_timer_context,
    .get_timer_context = get_timer_context,
    .get_timer_elapsed_time = get_timer_elapsed_time,
    .ms2tick = ms2tick,
    .tick2ms = tick2ms,
    .get_min_timeout = get_min_timeout,
    .get_timer_val = get_timer_val,
    .stop_alarm = stop_alarm,
    .set_alarm = set_alarm,
    .set_uc_wakeup_time = set_uc_wakeup_time,
};
