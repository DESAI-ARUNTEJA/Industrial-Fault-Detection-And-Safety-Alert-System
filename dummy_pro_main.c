#include<LPC21xx.h>
#include<string.h>
#include"lcd.h"
#include"types.h"
#include"delay.h"
#include "kpm.h"
#include "UART_INT.h"
#include "i2c_defines.h"
#include "i2c_eeprom.h"
#include "i2c.h"
#include "uart0.h"
#include "edit.h"
#include "dht11.h"
#include "GSM.h"
#include "rtc.h"

void Enable_int(void);

extern u32 i_flag;
extern char buff[300];
extern unsigned char i;
u32 depass=2424;
u8 msg1[50]="ALERT! TEMPERATURE EXCEED ",msg2[50]="ALERT! HUMIDITY EXCEED ";
u8 pass[5],rpass[5],r_temp,r_humi,read_mobile[15],rd[50];
extern unsigned char nm_flag;
unsigned char humidity_integer, humidity_decimal, temp_integer, temp_decimal, checksum;
extern u32 hr,min,sec,date,year,day,month;


void addtime_msg(char *p)
{
	int k;
	GetRTCTimeInfo(&hr,&min,&sec);
	//GetRTCDateInfo(&dat,&month,&year);
	//GetRTCDay(&day);
	k=strlen(p);
	p[k++]='@';
	p[k++]=hr/10+48;
	p[k++]=hr%10+48;
	p[k++]=':';
	p[k++]=min/10+48;
	p[k++]=min%10+48;
	p[k++]=':';
	p[k++]=sec/10+48;
	p[k++]=sec%10+48;
	p[k]='\0';
}

main()
{
	LCD_Init();
	delay_ms(2000);
	Write_str_LCD("Hello");
		
	Enable_int();

	RTC_Init();
	IODIR0|=1<<5;
	IODIR0|=1<<22;
	init_i2c();
	InitUART0();
	Write_CMD_LCD(0x01);
	Init_KPM();
	//delay_ms(100);
	Write_CMD_LCD(0x01);
	GSM_SMS_Init();
	 myitoa(depass,pass);

	 //SetRTCTimeInfo(14,32,0);
	 //SetRTCDateInfo(11,2,2026);
	 //SetRTCDay(3);
	
	//Write_str_LCD("Hello");
	   		   			   /*
	 i2c_eeprom_pagewrite(I2C_EEPROM_SA,PASS_ADDR,(s8 *)pass,4);
	 
	 i2c_eeprom_bytewrite(I2C_EEPROM_SA,TEMP_ADDR,25);//defalut temp set point
	 i2c_eeprom_bytewrite(I2C_EEPROM_SA,HUM_ADDR,75);//defalut humi set point
	i2c_eeprom_pagewrite(I2C_EEPROM_SA,MOBILE_ADDR,"6301604607",10);
	delay_s(3);
		 		 */	 
	i_flag=0,nm_flag=0;
	while(1)
	{
		
		i2c_eeprom_seqread(I2C_EEPROM_SA,PASS_ADDR,(s8 *)rpass,4);
		i2c_eeprom_seqread(I2C_EEPROM_SA,MOBILE_ADDR,(s8 *)read_mobile,10);	read_mobile[10]='\0';
		r_temp=i2c_eeprom_randomread(I2C_EEPROM_SA,TEMP_ADDR);
		r_humi=i2c_eeprom_randomread(I2C_EEPROM_SA,HUM_ADDR);
	    Write_str_LCD("Hello");
		delay_s(5);
		Write_CMD_LCD(0x01);
		//loop:
		do
		{
			dht11_request();
			dht11_response();
			humidity_integer = dht11_data();
			humidity_decimal = dht11_data();
			temp_integer = dht11_data();
			temp_decimal = dht11_data();
			checksum = dht11_data();
			if( (humidity_integer + humidity_decimal + temp_integer + temp_decimal) != checksum )
				Write_str_LCD("Checksum Error\r\n");
			else
			{
			time_disp(); // display rtc
			Write_CMD_LCD(0x94);
			Write_str_LCD("H : ");
			Write_int_LCD(humidity_integer);
			Write_DAT_LCD('.');
			Write_int_LCD(humidity_decimal);
			Write_str_LCD(" % RH ");
			Write_CMD_LCD(0xD4);
			Write_str_LCD("T : ");
			Write_int_LCD(temp_integer);
			Write_DAT_LCD('.');
			Write_int_LCD(temp_decimal);
			Write_DAT_LCD(223);
			Write_str_LCD("C");
			Write_CMD_LCD(0x94+14); // LINE 3 POS 0
			Write_str_LCD("HSP:");	// TEMPERATURE SETPOINT
			Write_int_LCD(r_humi);	// TEMPERATURE SETPOINT
			Write_CMD_LCD(0xD4+14); // LINE 3 POS 9
			Write_str_LCD("TSP:"); // HUMIDITY SETPOINT
			Write_int_LCD(r_temp);	// HUMIDITY SETPOINT
			delay_ms(1000);
			//Write_CMD_LCD(0x01);
			//goto loop;
		}
		if(temp_integer>r_temp)
		{
			//buzzer();
			IOPIN0|=(1<<22);
			addtime_msg((char *)msg1);
			send_sms((char *)read_mobile,(char *)msg1);

			//SEND_SMS("WARNING! TEMPERATURE ALERT",read_mobile);
		}
		if(humidity_integer>r_humi)
		{
			//buzzer();
			IOPIN0|=(1<<22);
			addtime_msg((char *)msg2);
			send_sms((char *)read_mobile,(char *)msg2);

			//SEND_SMS("WARNING! HUMIDITY ALERT",read_mobile);
		}
		}while((i_flag==0)&&(nm_flag==0));
		if(i_flag==1)
		{
			i_flag=0;
			edit_menu();
		}
		else if(nm_flag==1)
		{
			nm_flag=0;
			memset(rd,'\0',50);
			readsms((char*)rd);
			Write_CMD_LCD(0x01);
			Write_str_LCD(rd);
			delay_ms(2000);
			Write_CMD_LCD(0x01);
			extract((char*)rd);
			UART0_Str("AT+CMGD=1\r\n");
	i=0;memset(buff,'\0',300);
	while(i<4);
	delay_ms(500);
	buff[i] = '\0';
	delay_ms(2000);
	if(strstr(buff,"OK"))
	{
		Write_CMD_LCD(0xC0);
		Write_str_LCD("*OK*");
		delay_ms(1000);		
	}
	else
	{
		Write_CMD_LCD(0xC0);
		Write_str_LCD("*NOT OK*");
		delay_ms(1000);		
	}
	Write_CMD_LCD(0x01);
		}

	}
}
