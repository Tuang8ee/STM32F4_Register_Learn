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

uint8_t BCD2DEC(uint8_t bcd);
uint8_t DEC2BCD(uint8_t dec);

void DS3231_SetTime(RTC_Time * rtc_time);
void DS3231_GetTime(RTC_Time * rtc_time);
#endif /* DS3231_H_ */
