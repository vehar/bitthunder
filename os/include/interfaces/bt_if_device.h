#ifndef _BT_IF_DEVICE_H_
#define _BT_IF_DEVICE_H_

#include "bt_types.h"
#include "bt_dev_if_irq.h"
#include "bt_dev_if_gpio.h"
#include "bt_dev_if_systimer.h"
#include "bt_dev_if_gtimer.h"
#include "bt_dev_if_timer.h"
#include "bt_if_power.h"
#include "bt_if_block.h"
#include "bt_dev_if_uart.h"
#include "bt_dev_if_pwm.h"
#include "bt_dev_if_spi.h"
#include "bt_dev_if_mtd.h"
#include "bt_dev_if_i2c.h"
#include "bt_dev_if_adc.h"
#include "bt_dev_if_dac.h"
#include "bt_dev_if_can.h"
#include "bt_dev_if_sdio.h"
#include "bt_dev_if_rtc.h"
#include "bt_dev_if_emac.h"
#include "bt_dev_if_qei.h"
#include "bt_dev_if_mcpwm.h"

typedef enum _BT_DEV_IF_TYPE {
	BT_DEV_IF_T_NONE=0,
	BT_DEV_IF_T_SYSTEM,
	BT_DEV_IF_T_INTC,
	BT_DEV_IF_T_SYSTIMER,
	BT_DEV_IF_T_GTIMER,
	BT_DEV_IF_T_TIMER,
	BT_DEV_IF_T_PWM,
	BT_DEV_IF_T_MCPWM,
	BT_DEV_IF_T_ADC,
	BT_DEV_IF_T_DAC,
	BT_DEV_IF_T_GPIO,
	BT_DEV_IF_T_UART,
	BT_DEV_IF_T_I2C,
	BT_DEV_IF_T_CAN,
	BT_DEV_IF_T_SPI,
	BT_DEV_IF_T_MTD,
	BT_DEV_IF_T_SDIO,
	BT_DEV_IF_T_EMAC,
	BT_DEV_IF_T_MII,
	BT_DEV_IF_T_PHY,
	BT_DEV_IF_T_RTC,
	BT_DEV_IF_T_QEI,
} BT_DEV_IF_TYPE;

/**
 *	These macros are important, they allow us to decouple the Handle and Device operations
 *	from actual code.
 *
 *	Therefore we can easily modify the actual structure of HANDLEs and Devices to improve
 *	the actual dereferencing. I.e. make it more efficient later etc.
 *
 *	By-passing these macros would cause horrible pain for someone if we do change device/handle
 *	structures later, as all APIs will have to be modified.
 *
 **/
#define BT_IF_DEVICE(handle)		handle->h.pIf->oIfs.pDevIF
#define BT_IF_DEVICE_TYPE(handle)	BT_IF_DEVICE(handle)->eConfigType
#define BT_IF_DEV_CONFIG(handle)	BT_IF_DEVICE(handle)->unConfigIfs


typedef struct _BT_DEV_INTERFACE *BT_DEV_INTERFACE;

typedef union {
	const BT_DEV_INTERFACE		p;
	const BT_DEV_IF_GPIO	   *pGpioIF;
	const BT_DEV_IF_IRQ		   *pIRQIF;
	const BT_DEV_IF_SYSTIMER   *pSysTimerIF;
	const BT_DEV_IF_GTIMER 	   *pGTimerIF;
	const BT_DEV_IF_TIMER	   *pTimerIF;
	const BT_DEV_IF_PWM		   *pPwmIF;
	const BT_DEV_IF_MCPWM	   *pMCPwmIF;
	const BT_DEV_IF_CAN 	   *pCANIF;
	const BT_DEV_IF_SPI 	   *pSpiIF;
	const BT_DEV_IF_I2C 	   *pI2CIF;
	const BT_DEV_IF_MTD		   *pMtdIF;
	const BT_DEV_IF_ADC 	   *pADCIF;
	const BT_DEV_IF_DAC 	   *pDACIF;
	const BT_DEV_IF_UART 	   *pUartIF;
	const BT_DEV_IF_SDIO	   *pSdioIF;
	const BT_DEV_IF_EMAC 	   *pEMacIF;
	const BT_DEV_IF_MII 	   *pMiiIF;
	const BT_DEV_IF_PHY		   *pPhyIF;
	const BT_DEV_IF_RTC		   *pRTCIF;
	const BT_DEV_IF_QEI		   *pQEIIF;
} BT_DEV_IFS;

#define BT_IF_GPIO_OPS(handle)		BT_IF_DEV_CONFIG(handle).pGpioIF
#define BT_IF_IRQ_OPS(handle)		BT_IF_DEV_CONFIG(handle).pIRQIF
#define BT_IF_SYSTIMER_OPS(handle)	BT_IF_DEV_CONFIG(handle).pSysTimerIF
#define BT_IF_GTIMER_OPS(handle)	BT_IF_DEV_CONFIG(handle).pGTimerIF
#define BT_IF_TIMER_OPS(handle)		BT_IF_DEV_CONFIG(handle).pTimerIF
#define	BT_IF_PWM_OPS(handle)		BT_IF_DEV_CONFIG(handle).pPwmIF
#define	BT_IF_MCPWM_OPS(handle)		BT_IF_DEV_CONFIG(handle).pMCPwmIF
#define BT_IF_CAN_OPS(handle)		BT_IF_DEV_CONFIG(handle).pCANIF
#define BT_IF_UART_OPS(handle)		BT_IF_DEV_CONFIG(handle).pUartIF
#define BT_IF_SPI_OPS(handle)		BT_IF_DEV_CONFIG(handle).pSpiIF
#define BT_IF_MTD_OPS(handle)		BT_IF_DEV_CONFIG(handle).pMtdIF
#define BT_IF_EMAC_OPS(handle)		BT_IF_DEV_CONFIG(handle).pEMacIF
#define BT_IF_MII_OPS(handle)		BT_IF_DEV_CONFIG(handle).pMiiIF
#define BT_IF_PHY_OPS(handle)		BT_IF_DEV_CONFIG(handle).pPhyIF
#define BT_IF_I2C_OPS(handle)		BT_IF_DEV_CONFIG(handle).pI2CIF
#define	BT_IF_ADC_OPS(handle)		BT_IF_DEV_CONFIG(handle).pADCIF
#define	BT_IF_DAC_OPS(handle)		BT_IF_DEV_CONFIG(handle).pDACIF
#define BT_IF_SDIO_OPS(handle)		BT_IF_DEV_CONFIG(handle).pSdioIF
#define	BT_IF_RTC_OPS(handle)		BT_IF_DEV_CONFIG(handle).pRTCIF
#define	BT_IF_QEI_OPS(handle)		BT_IF_DEV_CONFIG(handle).pQEIIF

typedef struct _BT_IF_DEVICE {
	const BT_IF_POWER	   *pPowerIF;
	BT_DEV_IF_TYPE 			eConfigType;
	const BT_DEV_IFS 	    unConfigIfs;
	const BT_IF_BLOCK	   *pBlockIF;
} BT_IF_DEVICE;

#endif
