#include<stdio.h>
#include<stdint.h>

struct Packet{
	uint8_t crc;
	uint8_t status;
	uint16_t payLoad;
	uint8_t bat;
	uint8_t Sensor;
	uint8_t longAddr;
	uint8_t ShortAddr;
	uint8_t AddrMode;

};

int main(){


	uint32_t packetip;
	printf("Enter the 32 bit Packet:  ");

	scanf("%x", &packetip);


	struct Packet Pack;
	Pack.crc = (uint8_t)(packetip & 0x3);
	Pack.status = (uint8_t)((packetip>>2) & 0x1);
	Pack.payLoad = (uint16_t)((packetip>>3) & 0xFFF);
	Pack.bat = (uint8_t)((packetip>>15) & 0x7);
	Pack.Sensor = (uint8_t)((packetip>>18) & 0x7);
	Pack.longAddr = (uint8_t)((packetip>>21) & 0xFF);
	Pack.ShortAddr = (uint8_t)((packetip>>26) & 0x03);
	Pack.AddrMode = (uint8_t)((packetip>>31) & 0x01);

	printf("crc1: %x: \n",Pack.crc);
	printf("status1: %x: \n",Pack.status);
	printf("payload1: %x: \n",Pack.payLoad);
	printf("bat1: %x: \n ",Pack.bat);
	printf("sensor1: %x: \n ",Pack.Sensor);
	printf("longAddr1: %x: \n",Pack.longAddr);
	printf("ShortAddr1: %x:\n ",Pack.ShortAddr);
	printf("AddrMode1: %x: \n",Pack.AddrMode);


	while(1);

	return 0;


}
