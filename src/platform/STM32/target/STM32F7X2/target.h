/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef TARGET_BOARD_IDENTIFIER
#define TARGET_BOARD_IDENTIFIER "S7X2"
#endif

#ifndef USBD_PRODUCT_STRING
#define USBD_PRODUCT_STRING     "Betaflight STM32F7x2"
#endif

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3

#define USE_VCP

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#define USE_I2C
#define I2C_FULL_RECONFIGURABILITY

#define USE_BEEPER

#ifdef USE_SDCARD
#define USE_SDCARD_SPI
#define USE_SDCARD_SDIO
#endif

#define USE_SPI
#define SPI_FULL_RECONFIGURABILITY
#define USE_SPI_DMA_ENABLE_EARLY

#define USE_USB_DETECT

#define USE_ESCSERIAL

#define USE_ADC

#define USE_EXTI

#define FLASH_PAGE_SIZE ((uint32_t)0x4000) // 16K sectors

// ITCM is in short supply for this target.
// For this target, functions decorated FAST_CODE_PREF will not be put into ITCM RAM; 
// on other targets, the same function *will* go into ITCM RAM
#define FAST_CODE_PREF

//Askari Custom Features
#undef USE_MAG
#undef USE_GPS
#undef USE_RX_PPM
#undef USE_RX_PWM

#undef USE_SERIALRX_SUMD       // Graupner Hott protocol
#undef USE_SERIALRX_SUMH       // Graupner legacy protocol

#undef USE_SERIALRX_CRSF       // Team Black Sheep Crossfire protocol
#undef USE_SERIALRX_GHST       // ImmersionRC Ghost Protocol
#undef USE_SERIALRX_IBUS       // FlySky and Turnigy receivers
#undef USE_SERIALRX_SPEKTRUM   // SRXL, DSM2 and DSMX protocol
#undef USE_SERIALRX_FPORT      // FrSky FPort
#undef USE_SERIALRX_XBUS       // JR
#undef USE_SERIALRX_SRXL2      // Spektrum SRXL2 protocol

#undef LED_STRIP
#undef TELEMETRY_FRSKY

#undef USE_TELEMETRY_FRSKY_HUB
#undef USE_TELEMETRY_SMARTPORT
#undef USE_TELEMETRY_CRSF
#undef USE_TELEMETRY_GHST
#undef USE_TELEMETRY_SRXL

#undef USE_TELEMETRY_IBUS
#undef USE_TELEMETRY_IBUS_EXTENDED
#undef USE_TELEMETRY_JETIEXBUS
#undef USE_TELEMETRY_MAVLINK
#undef USE_TELEMETRY_HOTT
#undef USE_TELEMETRY_LTM


#undef USE_SERVOS
#undef USE_OSD_SD
#undef USE_OSD_HD
#undef USE_RACE_PRO


#undef USE_VTX_COMMON
#undef USE_VTX_CONTROL
#undef USE_VTX_SMARTAUDIO
#undef USE_VTX_TRAMP
#undef USE_VTX_MSP
#undef USE_VTX_TABLE

#undef USE_BARO_BMP388
#undef USE_BARO_SPI_BMP388
#undef USE_BARO_LPS
#undef USE_BARO_SPI_LPS
#undef USE_BARO_QMP6988
#undef USE_BARO_SPI_QMP6988
#undef USE_BARO_DPS310
#undef USE_BARO_SPI_DPS310
#undef USE_BARO_BMP085
#undef USE_BARO_2SMBP_02B
#undef USE_BARO_SPI_2SMBP_02B
#undef USE_BARO_LPS22DF
#undef USE_BARO_SPI_LPS22DF

#undef USE_ACC_MPU6500
#undef USE_GYRO_MPU6500
#undef USE_ACC_SPI_MPU6000
#undef USE_GYRO_SPI_MPU6000
#undef USE_ACC_SPI_MPU6500
#undef USE_GYRO_SPI_MPU6500
#undef USE_ACC_SPI_ICM20689
#undef USE_GYRO_SPI_ICM20689
#undef USE_ACCGYRO_LSM6DSO
#undef USE_GYRO_SPI_ICM42605
#undef USE_GYRO_SPI_ICM42688P
#undef USE_ACC_SPI_ICM42605
#undef USE_ACC_SPI_ICM42688P
#undef USE_ACCGYRO_LSM6DSV16X

#undef USE_RX_CC2500
#undef USE_RX_EXPRESSLRS
#undef USE_RX_SX1280
#undef USE_RX_SX127X

#undef USE_FLASHFS
#undef USE_FLASH_TOOLS
#undef USE_FLASH_M25P16
#undef USE_FLASH_W25N01G    // 1Gb NAND flash support
#undef USE_FLASH_W25N02K    // 2Gb NAND flash support
#undef USE_FLASH_W25M       // Stacked die support
#undef USE_FLASH_W25M512    // 512Kb (256Kb x 2 stacked) NOR flash support
#undef USE_FLASH_W25M02G    // 2Gb (1Gb x 2 stacked) NAND flash support
#undef USE_FLASH_W25Q128FV  // 16MB Winbond 25Q128
#undef USE_FLASH_PY25Q128HA // 16MB PUYA SEMI 25Q128