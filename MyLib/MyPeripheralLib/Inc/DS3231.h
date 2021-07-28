/*
 * DS3231.h
 *
 *  Created on: Jul 16, 2021
 *      Author: tuang
 */

#ifndef DS3231_H_
#define DS3231_H_
#ifndef I2C_H_
	#include "I2C.h"
#endif
#ifndef TIMER_H_
	#include "timer.h"
#endif

#define DS3231_ADDRESS	0x68

#define SECONDS_ADDRESS		0x00
#define MINUTES_ADDRESS		0x01
#define HOUR_ADDRESS		0x02
#define DAY_ADDRESS			0x03
#define DATE_ADDRESS		0x04
#define MONTH_ADDRESS		0x05
#define YEAR_ADDRESS		0x06

#define ALARM1_SECONDS_ADDRESS	0x07
#define ALARM1_MINUTES_ADDRESS	0x08
#define ALARM1_HOUR_ADDRESS		0x09
#define ALARM1_DAY_ADDRESS		0x0A


#define ALARM2_MINUTES_ADDRESS	0x0B
#define ALARM2_HOUR_ADDRESS		0x0C
#define ALARM2_DAY_ADDRESS		0x0D

#define CONTROL_ADDRESS			0x0E
#define CONTROL_STATUS_ADDRESS	0x0F
#define AGING_OFFSET_ADDRESS	0x10

#define AM		2
#define PM		3
#define H_24H	0

typedef struct
{
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
	uint8_t AM_PM_24H;
}RTC_Time;

uint8_t BCD2DEC(uint8_t bcd) {
	return (bcd >> 4) * 10 + (bcd & 0x0F);
}
uint8_t DEC2BCD(uint8_t dec) {
	return ((dec / 10) << 4) + (dec % 10);
}

void DS3231_SetTime(I2C_TypeDef *I2Cx, RTC_Time *rtc_time) {
	I2C_Write(I2Cx, DS3231_ADDRESS, SECONDS_ADDRESS, DEC2BCD(rtc_time->sec));
	TIM6_Delay_ms(1);
	I2C_Write(I2Cx, DS3231_ADDRESS, MINUTES_ADDRESS, DEC2BCD(rtc_time->min));
	TIM6_Delay_ms(1);
	I2C_Write(I2Cx, DS3231_ADDRESS, HOUR_ADDRESS, (rtc_time->AM_PM_24H << 6)
												  + DEC2BCD(rtc_time->hour));
	TIM6_Delay_ms(1);
	I2C_Write(I2Cx, DS3231_ADDRESS, DAY_ADDRESS, DEC2BCD(rtc_time->day));
	TIM6_Delay_ms(1);
	I2C_Write(I2Cx, DS3231_ADDRESS, DATE_ADDRESS, DEC2BCD(rtc_time->date));
	TIM6_Delay_ms(1);
	I2C_Write(I2Cx, DS3231_ADDRESS, MONTH_ADDRESS, DEC2BCD(rtc_time->month));
	TIM6_Delay_ms(1);
	I2C_Write(I2Cx, DS3231_ADDRESS, YEAR_ADDRESS, DEC2BCD(rtc_time->year));
}
void DS3231_GetTime(I2C_TypeDef *I2Cx, RTC_Time *rtc_time) {
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, SECONDS_ADDRESS, &(rtc_time->sec));
	rtc_time->sec = BCD2DEC(rtc_time->sec);
	TIM6_Delay_ms(1);
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, MINUTES_ADDRESS, &(rtc_time->min));
	rtc_time->min = BCD2DEC(rtc_time->min);
	TIM6_Delay_ms(1);
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, HOUR_ADDRESS, &(rtc_time->hour));
	rtc_time->AM_PM_24H = BCD2DEC(rtc_time->hour) >> 5;
	rtc_time->hour = BCD2DEC(rtc_time->hour) & 0x1F;
	TIM6_Delay_ms(1);
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, DAY_ADDRESS, &(rtc_time->day));
	rtc_time->day = BCD2DEC(rtc_time->day);
	TIM6_Delay_ms(1);
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, DATE_ADDRESS, &(rtc_time->date));
	rtc_time->date = BCD2DEC(rtc_time->date);
	TIM6_Delay_ms(1);
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, MONTH_ADDRESS, &(rtc_time->month));
	rtc_time->month = BCD2DEC(rtc_time->month);
	TIM6_Delay_ms(1);
	I2C_AddressRead(I2Cx, DS3231_ADDRESS, YEAR_ADDRESS, &(rtc_time->year));
	rtc_time->year = BCD2DEC(rtc_time->year);
	TIM6_Delay_ms(1);
}
#endif /* DS3231_H_ */
