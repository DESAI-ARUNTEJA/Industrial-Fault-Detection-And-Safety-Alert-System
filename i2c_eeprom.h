void i2c_eeprom_bytewrite(u8 slaveAddr,u8 wBufAddr,u8 dat);
u8 i2c_eeprom_randomread(u8 slaveAddr,u8 rBufAddr);
void i2c_eeprom_pagewrite(u8 slaveAddr,u8 wBufStartAddr,s8 *p,u8 nBytes);
void i2c_eeprom_seqread(u8 slaveAddr,u8 rBufStartAddr,s8 *p,u8 nBytes);                                                                                                                                                                                                                                                 
