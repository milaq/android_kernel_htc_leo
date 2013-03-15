# Makefile for the Linux sound card driver
#

obj-$(CONFIG_SOUND) += soundcore.o
obj-$(CONFIG_SOUND_PRIME) += sound_firmware.o
obj-$(CONFIG_SOUND_PRIME) += oss/
obj-$(CONFIG_DMASOUND) += oss/
obj-$(CONFIG_SND) += core/ i2c/ drivers/ isa/ pci/ ppc/ arm/ sh/ synth/ usb/ \
<<<<<<< HEAD
	sparc/ spi/ parisc/ pcmcia/ mips/ soc/ atmel/ htcleo/
=======
	sparc/ spi/ parisc/ pcmcia/ mips/ soc/ atmel/
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
obj-$(CONFIG_SND_AOA) += aoa/

# This one must be compilable even if sound is configured out
obj-$(CONFIG_AC97_BUS) += ac97_bus.o

ifeq ($(CONFIG_SND),y)
  obj-y += last.o
endif

soundcore-objs  := sound_core.o
