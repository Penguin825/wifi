
#ifndef _NM_BUS_WRAPPER_H_
#define _NM_BUS_WRAPPER_H_

#include "nm_common.h"

// BUS type
#define  NM_BUS_TYPE_I2C	((uint8)0)
#define  NM_BUS_TYPE_SPI	((uint8)1)
#define  NM_BUS_TYPE_UART	((uint8)2)

// IOCTL commands
#define NM_BUS_IOCTL_R			((uint8)0)	// !< Read only ==> I2C/UART. Parameter:tstrNmI2cDefault/tstrNmUartDefault
#define NM_BUS_IOCTL_W			((uint8)1)	// !< Write only ==> I2C/UART. Parameter type tstrNmI2cDefault/tstrNmUartDefaul
#define NM_BUS_IOCTL_W_SPECIAL	((uint8)2)	/* !< Write two buffers within the same transaction
												(same start/stop conditions) ==> I2C only. Parameter:tstrNmI2cSpecial */
#define NM_BUS_IOCTL_RW			((uint8)3)	// !< Read/Write at the same time ==> SPI only. Parameter:tstrNmSpiRw
#define NM_BUS_IOCTL_WR_RESTART	((uint8)4)	// !< Write buffer then made restart condition then read ==> I2C only. parameter:tstrNmI2cSpecial


// Structure holding bus capabilities information
typedef struct {
	uint16 u16MaxTrxSz;		// Maximum transfer size. Muse be >= 16 bytes.
} tstrNmBusCapabilities;


// Structure holding I2C special operation parameters
typedef struct {
	uint8	u8SlaveAdr;
	uint8	*pu8Buf1;		// Pointer to 1st buffer.
	uint8	*pu8Buf2;		// Pointer to 2nd buffer.
	uint16	u16Sz1;			// 1st buffer size.
	uint16	u16Sz2;			// 2nd buffer size.
} tstrNmI2cSpecial;


// structure holding SPI read/write parameters
typedef struct {
	uint8	*pu8InBuf;		// Pointer to input buffer.
	uint8	*pu8OutBuf;		// Pointer to output buffer.
	uint16	u16Sz;			// Transfer size.
} tstrNmSpiRw;


// Structure holding UART default operation parameters
/*
typedef struct {
	uint8	*pu8Buf;		// Operation buffer.
	uint16	u16Sz;			// Operation size.
} tstrNmUartDefault;
*/


// Bus capabilities. This structure must be declared at platform specific bus wrapper.
extern tstrNmBusCapabilities egstrNmBusCapabilities;


#ifdef __cplusplus
extern "C" {
#endif


// Initialise the bus wrapper
sint8 nm_bus_init(void *);


// send/receive from the bus
sint8 nm_bus_ioctl(uint8 u8Cmd, void* pvParameter);


// Deinitialise the bus wrapper
sint8 nm_bus_deinit(void);


// Reinitialise the bus wrapper
sint8 nm_bus_reinit(void*);


// Get chip type
#ifdef CONF_WINC_USE_UART
uint8 nm_bus_get_chip_type(void);
#endif


#ifdef __cplusplus
}
#endif

#endif // _NM_BUS_WRAPPER_H_
