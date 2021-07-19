/*
 * DS3231.c
 *
 *  Created on: Jul 16, 2021
 *      Author: tuang
 */
#include "DS3231.h"

uint8_t BCD2DEC(uint8_t bcd) {
	return (bcd >> 4) * 10 + (bcd & 0x0F);
}
uint8_t DEC2BCD(uint8_t dec) {
	return ((dec / 10) << 4) + (dec % 10);
}

void DS3231_SetTime(RTC_Time *rtc_time) {
	I2C1_Write(DS3231_ADDRESS, SECONDS_ADDRESS, DEC2BCD(rtc_time->sec));
	TIM6_Delay_ms(1);
	I2C1_Write(DS3231_ADDRESS, MINUTES_ADDRESS, DEC2BCD(rtc_time->min));
	TIM6_Delay_ms(1);
	I2C1_Write(DS3231_ADDRESS, HOUR_ADDRESS,
			(rtc_time->AM_PM_24H << 6) + DEC2BCD(rtc_time->hour));
	TIM6_Delay_ms(1);
	I2C1_Write(DS3231_ADDRESS, DAY_ADDRESS, DEC2BCD(rtc_time->day));
	TIM6_Delay_ms(1);
	I2C1_Write(DS3231_ADDRESS, DATE_ADDRESS, DEC2BCD(rtc_time->date));
	TIM6_Delay_ms(1);
	I2C1_Write(DS3231_ADDRESS, MONTH_ADDRESS, DEC2BCD(rtc_time->month));
	TIM6_Delay_ms(1);
	I2C1_Write(DS3231_ADDRESS, YEAR_ADDRESS, DEC2BCD(rtc_time->year));
}
void DS3231_GetTime(RTC_Time *rtc_time) {
	I2C1_AddressRead(DS3231_ADDRESS, SECONDS_ADDRESS, &(rtc_time->sec));
	rtc_time->sec = BCD2DEC(rtc_time->sec);
	TIM6_Delay_ms(1);
	I2C1_AddressRead(DS3231_ADDRESS, MINUTES_ADDRESS, &(rtc_time->min));
	rtc_time->min = BCD2DEC(rtc_time->min);
	TIM6_Delay_ms(1);
	I2C1_AddressRead(DS3231_ADDRESS, HOUR_ADDRESS, &(rtc_time->hour));
	rtc_time->AM_PM_24H = BCD2DEC(rtc_time->hour) >> 5;
	rtc_time->hour = BCD2DEC(rtc_time->hour) & 0x1F;
	TIM6_Delay_ms(1);
	I2C1_AddressRead(DS3231_ADDRESS, DAY_ADDRESS, &(rtc_time->day));
	rtc_time->day = BCD2DEC(rtc_time->day);
	TIM6_Delay_ms(1);
	I2C1_AddressRead(DS3231_ADDRESS, DATE_ADDRESS, &(rtc_time->date));
	rtc_time->date = BCD2DEC(rtc_time->date);
	TIM6_Delay_ms(1);
	I2C1_AddressRead(DS3231_ADDRESS, MONTH_ADDRESS, &(rtc_time->month));
	rtc_time->month = BCD2DEC(rtc_time->month);
	TIM6_Delay_ms(1);
	I2C1_AddressRead(DS3231_ADDRESS, YEAR_ADDRESS, &(rtc_time->year));
	rtc_time->year = BCD2DEC(rtc_time->year);
	TIM6_Delay_ms(1);
}
