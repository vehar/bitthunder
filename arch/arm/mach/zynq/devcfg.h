#ifndef _BT_DEVCFG_H_
#define _BT_DEVCFG_H_

#include <bitthunder.h>
#include <bt_struct.h>

typedef struct _ZYNQ_DEVCFG_REGS {
	BT_u32 	CTRL;
	#define CTRL_DAP_EN				0x00000007
	#define CTRL_DBGEN				0x00000008
	#define CTRL_NIDEN				0x00000010
	#define CTRL_SPIDEN				0x00000020
	#define CTRL_SPNIDEN			0x00000040
	#define CTRL_SEC_EN				0x00000080
	#define CTRL_SEU_EN				0x00000100
	#define CTRL_PCFG_AES_EN		0x00000E00
	#define CTRL_PCFG_AES_FUSE 		0x00001000
	#define CTRL_USER_MODE 			0x00008000
	#define CTRL_JTAG_CHAIN_DIS 	0x00800000
	#define CTRL_MULTIBOOT_EN 		0x01000000
	#define CTRL_QUARTER_PCAP_RATE 	0x02000000
	#define CTRL_PCAP_MODE 			0x04000000
	#define CTRL_PCAP_PR 			0x08000000
    #define CTRL_PCFG_POR_CNT_4K	0x20000000
	#define CTRL_PCFG_PROG_B 		0x40000000
	#define CTRL_FORCE_RESET 		0x80000000

	BT_u32	LOCK;


	BT_u32	CFG;
	BT_u32	INT_STS;
	#define INT_STS_DMA_DONE_INT  	0x00002000
	#define INT_STS_DMA_PCAP_DONE	0x00001000
	#define INT_STS_PCFG_DONE		0x00000004

	BT_u32	INT_MASK;
	BT_u32	STATUS;
	#define STATUS_PCFG_INIT		0x00000010

	BT_u32	DMA_SRC_ADDR;
	BT_u32	DMA_DST_ADDR;
	BT_u32	DMA_SRC_LEN;
	BT_u32	DMA_DST_LEN;
	BT_u32	ROM_SHADOW;
	BT_u32	MULTIBOOT_ADDR;
	BT_u32	SW_ID;
	BT_u32	UNLOCK;

	BT_STRUCT_RESERVED_u32(0, 0x34, 0x80);

	BT_u32	MCTRL;
	#define MCTRL_PCAP_LPBK			0x00000010

	BT_STRUCT_RESERVED_u32(1, 0x80, 0x100);

	BT_u32	XADCIF_CFG;
	BT_u32	XADCIF_INT_STS;
	BT_u32	XADCIF_INT_MASK;
	BT_u32	XADCIF_MSTS;
	BT_u32	XADCIF_CMDFIFO;
	BT_u32	XADCIF_RDFIFO;
	BT_u32	XADCIF_MCTL;

} ZYNQ_DEVCFG_REGS;



#endif
