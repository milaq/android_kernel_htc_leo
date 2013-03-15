
# core framebuffer
#
obj-y := msm_fb.o
<<<<<<< HEAD
ifeq ($(CONFIG_FB_MSM_LOGO),y)
obj-y += logo.o
endif

# MDP DMA/PPP engine
#
obj-y += mdp.o mdp_ppp.o
obj-$(CONFIG_FB_MSM_OVERLAY) += mdp4_util.o
obj-$(CONFIG_FB_MSM_OVERLAY) += mdp4_overlay.o
obj-$(CONFIG_FB_MSM_OVERLAY) += mdp4_overlay_mddi.o
obj-$(CONFIG_MSM_MDP40) += msm_rotator.o

obj-$(CONFIG_FB_MSM_LEGACY_MDP) += mdp_hw_legacy.o

obj-$(CONFIG_MSM_MDP22) += mdp_ppp22.o
obj-$(CONFIG_MSM_MDP30) += mdp_ppp22.o
obj-$(CONFIG_MSM_MDP302)+= mdp_ppp22.o
obj-$(CONFIG_MSM_MDP31) += mdp_ppp31.o
=======

# MDP DMA/PPP engine
#
obj-y += mdp.o mdp_scale_tables.o mdp_ppp.o
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e

# MDDI interface
#
obj-y += mddi.o

# MDDI client/panel drivers
#
<<<<<<< HEAD
obj-y += mddi_client_simple.o
obj-y += mddi_client_toshiba.o
obj-y += mddi_client_epson.o
obj-y += mddi_client_novb9f6_5582.o

# MDP LCD controller driver
obj-$(CONFIG_FB_MSM_LCDC) += mdp_lcdc.o
=======
obj-y += mddi_client_dummy.o
obj-y += mddi_client_toshiba.o
obj-y += mddi_client_nt35399.o

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
