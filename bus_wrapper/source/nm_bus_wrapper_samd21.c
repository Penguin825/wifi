
#include <stdio.h>
#include "nm_bsp.h"
#include "nm_common.h"
#include "nm_bus_wrapper.h"
//#include "asf.h"
#include "conf_winc.h"
#include "stm32f7xx_hal.h"

#define NM_BUS_MAX_TRX_SZ	256
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;
tstrNmBusCapabilities egstrNmBusCapabilities =
{
	NM_BUS_MAX_TRX_SZ
};

#ifdef CONF_WINC_USE_I2C
d
struct i2c_master_module i2c_master_instance;
#define SLAVE_ADDRESS 0x60

// Number of times to try to send packet if failed.
#define I2C_TIMEOUT 100

static sint8 nm_i2c_write(uint8 *b, uint16 sz)
{
	sint8 result = M2M_SUCCESS;
	uint16_t timeout = 0;

	struct i2c_master_packet packet = {
		.address     = SLAVE_ADDRESS,
		.data_length = sz,
		.data        = b,
	};

	// Write buffer to slave until success.
	while (i2c_master_write_packet_wait(&i2c_master_instance, &packet) != STATUS_OK) {
		// Increment timeout counter and check if timed out.
		if (timeout++ == I2C_TIMEOUT) {
			break;
		}
	}

	return result;
}

static sint8 nm_i2c_read(uint8 *rb, uint16 sz)
{
	uint16_t timeout = 0;
	sint8 result = M2M_SUCCESS;
	struct i2c_master_packet packet = {
		.address     = SLAVE_ADDRESS,
		.data_length = sz,
		.data        = rb,
	};

	/* Write buffer to slave until success. */
	while (i2c_master_read_packet_wait(&i2c_master_instance, &packet) != STATUS_OK) {
		/* Increment timeout counter and check if timed out. */
		if (timeout++ == I2C_TIMEOUT) {
			break;
		}
	}

	return result;
}

static sint8 nm_i2c_write_special(uint8 *wb1, uint16 sz1, uint8 *wb2, uint16 sz2)
{
	static uint8 tmp[NM_BUS_MAX_TRX_SZ];
	m2m_memcpy(tmp, wb1, sz1);
	m2m_memcpy(&tmp[sz1], wb2, sz2);
	return nm_i2c_write(tmp, sz1+sz2);
}
#endif

#ifdef CONF_WINC_USE_SPI

//struct spi_module master;
//struct spi_slave_inst slave_inst;

static sint8 spi_rw(uint8* pu8Mosi, uint8* pu8Miso, uint16 u16Sz)
{
	uint8 u8Dummy = 0;
	uint8 u8SkipMosi = 0, u8SkipMiso = 0;
	uint8_t txd_data = 0;
	uint8_t rxd_data = 0;

	if (!pu8Mosi) {
		pu8Mosi = &u8Dummy;
		u8SkipMosi = 1;
	}
	else if(!pu8Miso) {
		pu8Miso = &u8Dummy;
		u8SkipMiso = 1;
	}
	else {
		return M2M_ERR_BUS_FAIL;
	}

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);

	while (u16Sz) {
		txd_data = *pu8Mosi;
		HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&txd_data, &rxd_data, 1, 1000);
		*pu8Miso = rxd_data;
		u16Sz--;
		if (!u8SkipMiso)
			pu8Miso++;
		if (!u8SkipMosi)
			pu8Mosi++;
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);

	return M2M_SUCCESS;
}
#endif


// Initialise the bus wrapper
sint8 nm_bus_init(void *pvinit)
{
	sint8 result = M2M_SUCCESS;

#ifdef CONF_WINC_USE_I2C
	/* Initialize config structure and software module. */
	struct i2c_master_config config_i2c_master;
	i2c_master_get_config_defaults(&config_i2c_master);

	/* Change buffer timeout to something longer. */
	config_i2c_master.buffer_timeout = 1000;

	/* Initialize and enable device with config. */
	i2c_master_init(&i2c_master_instance, SERCOM2, &config_i2c_master);

	i2c_master_enable(&i2c_master_instance);

#elif defined CONF_WINC_USE_SPI
//	hspi1.Instance = SPI1;
//  hspi1.Init.Mode = SPI_MODE_MASTER;
//  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
//  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
//  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
//  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
//  hspi1.Init.NSS = SPI_NSS_SOFT;
//  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
//  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
//  hspi1.Init.TIMode = SPI_TIMODE_DISABLED;
//  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
//  hspi1.Init.CRCPolynomial = 10;
	/* Structure for SPI configuration. */
//	struct spi_config config;
//	struct spi_slave_inst_config slave_config;

//	/* Select SPI slave CS pin. */
//	/* This step will set the CS high */
//	spi_slave_inst_get_config_defaults(&slave_config);
//	slave_config.ss_pin = CONF_WINC_SPI_CS_PIN;
//	spi_attach_slave(&slave_inst, &slave_config);

//	/* Configure the SPI master. */
//	spi_get_config_defaults(&config);
//	config.mux_setting = CONF_WINC_SPI_SERCOM_MUX;
//	config.pinmux_pad0 = CONF_WINC_SPI_PINMUX_PAD0;
//	config.pinmux_pad1 = CONF_WINC_SPI_PINMUX_PAD1;
//	config.pinmux_pad2 = CONF_WINC_SPI_PINMUX_PAD2;
//	config.pinmux_pad3 = CONF_WINC_SPI_PINMUX_PAD3;
//	config.master_slave_select_enable = false;

//	config.mode_specific.master.baudrate = CONF_WINC_SPI_CLOCK;
//	if (spi_init(&master, CONF_WINC_SPI_MODULE, &config) != STATUS_OK) {
//		return M2M_ERR_BUS_FAIL;
//	}

//	/* Enable the SPI master. */
//	spi_enable(&master);

	nm_bsp_reset();
	nm_bsp_sleep(1);


#endif
	return result;
}


// send/receive from the bus
sint8 nm_bus_ioctl(uint8 u8Cmd, void* pvParameter)
{
	sint8 s8Ret = 0;
	switch(u8Cmd)
	{
#ifdef CONF_WINC_USE_I2C
		case NM_BUS_IOCTL_R: {
			tstrNmI2cDefault *pstrParam = (tstrNmI2cDefault *)pvParameter;
			s8Ret = nm_i2c_read(pstrParam->pu8Buf, pstrParam->u16Sz);
		}
		break;
		case NM_BUS_IOCTL_W: {
			tstrNmI2cDefault *pstrParam = (tstrNmI2cDefault *)pvParameter;
			s8Ret = nm_i2c_write(pstrParam->pu8Buf, pstrParam->u16Sz);
		}
		break;
		case NM_BUS_IOCTL_W_SPECIAL: {
			tstrNmI2cSpecial *pstrParam = (tstrNmI2cSpecial *)pvParameter;
			s8Ret = nm_i2c_write_special(pstrParam->pu8Buf1, pstrParam->u16Sz1, pstrParam->pu8Buf2, pstrParam->u16Sz2);
		}
		break;
#elif defined CONF_WINC_USE_SPI
		case NM_BUS_IOCTL_RW: {
			tstrNmSpiRw *pstrParam = (tstrNmSpiRw *)pvParameter;
//			pstrParam->pu8OutBuf = 0x01010101;
			s8Ret = spi_rw(pstrParam->pu8InBuf, pstrParam->pu8OutBuf, pstrParam->u16Sz);
		}
		break;
#endif
		default:
			s8Ret = -1;
			M2M_ERR("invalide ioclt cmd\n");
			break;
	}

	return s8Ret;
}


// Deinitialise the bus wrapper
sint8 nm_bus_deinit(void)
{
	sint8 result = M2M_SUCCESS;
//	struct port_config pin_conf;
//
//	port_get_config_defaults(&pin_conf);
//	/* Configure control pins as input no pull up. */
//	pin_conf.direction  = PORT_PIN_DIR_INPUT;
//	pin_conf.input_pull = PORT_PIN_PULL_NONE;

//#ifdef CONF_WINC_USE_I2C
//	i2c_master_disable(&i2c_master_instance);
//#endif /* CONF_WINC_USE_I2C */
//#ifdef CONF_WINC_USE_SPI
//	spi_disable(&master);
//#endif /* CONF_WINC_USE_SPI */
	return result;
}


// Reinitialise the bus wrapper
sint8 nm_bus_reinit(void* config)
{
	return M2M_SUCCESS;
}
