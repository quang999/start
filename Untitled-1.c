#include<E:\thuc tap tot nghiep\thuc hanh do an\lib\delay.h>
#include<main.h>


sbit EN      = P2^0;
sbit MS1     = P2^1;
sbit MS2     = P2^2;
sbit MS3     = P2^3;	
sbit STEP_Y  = P2^4;
sbit DIR_Y   = P2^5;
sbit STEP_X  = P2^6;
sbit DIR_X   = P2^7;
sbit BUT     = P0^2;
sbit LED     = P0^4;
sbit STEP_Z  = P1^5;


void tre_us(unsigned int SET_TIME)
{
 //if(SET_TIME>29)                     // Tranh du lieu dau vao sai
 {
  SET_TIME=65536-SET_TIME+29;          // Phai cong them 29 de bu thoi gian sai so, do cac lenh gan va ktra trong ham.
  TMOD=0X10;                           // Su dung timer 1, mode 1
	TH1=SET_TIME>>8;
	TL1=SET_TIME&0x00FF;
	TR1=1;
	while(!TF1){};
	TR1=0;
	TF1=0;
 }  
}
void servo_vtri_50Hz(unsigned char vtri)
{
 unsigned int TIME_TRE1,TIME_TRE2;
 unsigned char i;
 if((vtri!=0)&&(vtri!=15)) return;
 switch(vtri)
 {
	case 0: TIME_TRE1=900; break;       // Tuong duong ha but, can ha thap hon xiu????????????
	case 15: TIME_TRE1=600; break;      // Tuong duong nhac but
	
 }
 TIME_TRE2=1000-TIME_TRE1;
 for(i=0;i<20;i++)
 {
  STEP_Z=1;
  tre_us(TIME_TRE1);     // Tao tre us 1.5 ms
  STEP_Z=0; 
  tre_us(TIME_TRE2);     // Tao tre us phu hop de tan so 50Hz (20 ms)
 }
}

void main(){
	int i;
	LED=1;
	EN=0;
	 MS1=1;
	 MS2=0;
	 MS3=0;
	
	 STEP_Z=0;  
 DIR_X=0;	
 STEP_X=0;
	DIR_Y=0;	
 STEP_Y=0;
	if(BUT==0){
		LED=0;
	//	veduongtron(5,5,30);
	
    servo_vtri_50Hz(15);
		delay_ms(1000);
		servo_vtri_50Hz(0);
		//delay_ms(1000);
		//servo_vtri_50Hz(15);
			
		
		}
		}