#ifndef _ASM_X86_K8_H
#define _ASM_X86_K8_H

<<<<<<< HEAD
=======
#include <linux/ioport.h>
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
#include <linux/pci.h>

extern struct pci_device_id k8_nb_ids[];

extern int early_is_k8_nb(u32 value);
<<<<<<< HEAD
=======
extern struct resource *amd_get_mmconfig_range(struct resource *res);
>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
extern struct pci_dev **k8_northbridges;
extern int num_k8_northbridges;
extern int cache_k8_northbridges(void);
extern void k8_flush_garts(void);
extern int k8_scan_nodes(unsigned long start, unsigned long end);

#ifdef CONFIG_K8_NB
<<<<<<< HEAD
=======
extern int num_k8_northbridges;

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
static inline struct pci_dev *node_to_k8_nb_misc(int node)
{
	return (node < num_k8_northbridges) ? k8_northbridges[node] : NULL;
}
<<<<<<< HEAD
#else
=======

#else
#define num_k8_northbridges 0

>>>>>>> 3ed9fdb7ac17e98f8501bcbcf78d5374a929ef0e
static inline struct pci_dev *node_to_k8_nb_misc(int node)
{
	return NULL;
}
#endif


#endif /* _ASM_X86_K8_H */
