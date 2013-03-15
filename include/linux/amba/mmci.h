/*
 *  include/linux/amba/mmci.h
 */
#ifndef AMBA_MMCI_H
#define AMBA_MMCI_H

#include <linux/mmc/host.h>
<<<<<<< HEAD
#include <linux/mmc/card.h>
#include <linux/mmc/sdio_func.h>

struct embedded_sdio_data {
        struct sdio_cis cis;
        struct sdio_cccr cccr;
        struct sdio_embedded_func *funcs;
        int num_funcs;
};
=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

struct mmci_platform_data {
	unsigned int ocr_mask;			/* available voltages */
	u32 (*translate_vdd)(struct device *, unsigned int);
	unsigned int (*status)(struct device *);
	int	gpio_wp;
	int	gpio_cd;
	unsigned long capabilities;
<<<<<<< HEAD
	unsigned int status_irq;
	struct embedded_sdio_data *embedded_sdio;
	int (*register_status_notify)(void (*callback)(int card_present, void *dev_id), void *dev_id);
=======
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
};

#endif
