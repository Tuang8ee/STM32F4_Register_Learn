/*
 * DMA.h
 *
 *  Created on: Jul 23, 2021
 *      Author: tuang
 */

#ifndef INC_DMA_H_
#define INC_DMA_H_
#include "stm32.h"

#ifdef STM32F407
	#include "stm32f407def.h"
#endif

#ifdef STM32F407DEF_H_
// DMA low interrupt status register (DMA_LISR)
#define FEIF0		0
#define DMEIF0		2
#define TEIF0		3
#define HTIF0		4
#define TCIF0		5

#define FEIF1		6
#define DMEIF1		8
#define TEIF1		9
#define HTIF1		10
#define TCIF1		11

#define FEIF2		16
#define DMEIF2		18
#define TEIF2		19
#define HTIF2		20
#define TCIF2		21

#define FEIF3		22
#define DMEIF3		24
#define TEIF3		25
#define HTIF3		26
#define TCIF3		27

// DMA high interrupt status register (DMA_HISR)
#define FEIF4		0
#define DMEIF4		2
#define TEIF4		3
#define HTIF4		4
#define TCIF4		5

#define FEIF5		6
#define DMEIF5		8
#define TEIF5		9
#define HTIF5		10
#define TCIF5		11

#define FEIF6		16
#define DMEIF6		18
#define TEIF6		19
#define HTIF6		20
#define TCIF6		21

#define FEIF7		22
#define DMEIF7		24
#define TEIF7		25
#define HTIF7		26
#define TCIF7		27

// DMA low interrupt flag clear register (DMA_LIFCR)
#define CFEIF0		0
#define CDMEIF0		2
#define CTEIF0		3
#define CHTIF0		4
#define CTCIF0		5

#define CFEIF1		6
#define CDMEIF1		8
#define CTEIF1		9
#define CHTIF1		10
#define CTCIF1		11

#define CFEIF2		16
#define CDMEIF2		18
#define CTEIF2		19
#define CHTIF2		20
#define CTCIF2		21

#define CFEIF3		22
#define CDMEIF3		24
#define CTEIF3		25
#define CHTIF3		26
#define CTCIF3		27

// DMA high interrupt flag clear register (DMA_HIFCR)
#define CFEIF4		0
#define CDMEIF4		2
#define CTEIF4		3
#define CHTIF4		4
#define CTCIF4		5

#define CFEIF5		6
#define CDMEIF5		8
#define CTEIF5		9
#define CHTIF5		10
#define CTCIF5		11

#define CFEIF6		16
#define CDMEIF6		18
#define CTEIF6		19
#define CHTIF6		20
#define CTCIF6		21

#define CFEIF7		22
#define CDMEIF7		24
#define CTEIF7		25
#define CHTIF7		26
#define CTCIF7		27

// DMA stream x configuration rigister (DMA_SxCR)
#define EN			0
#define DMEIE		1
#define TEIE		2
#define HTIE		3
#define TCIE_DMA	4
#define PFCTRL		5
#define DIR			6
#define CIRC		8
#define PINC		9
#define MINC		10
#define PSIZE		11
#define MSIZE		13
#define PINCOS		15
#define PL			16
#define DBM			18
#define CT			19
#define PBURST		21
#define MBURST		23
#define CHSEL		25

// DMA stream x number of data register (DMA_SxNDTR)
#define NDT			0

// DMA stream x peripheral address register (DMA_SxPAR)
#define PAR			0

// DMA stream x memory 0 address register (DMA_SxM0AR)
#define M0A			0

// DMA stream x memory 1 address register (DMA_SxM1AR)
#define M1A			0

// DMA stream x FIFO control register (DMA_SxFCR)
#define FTH			0
#define DMDIS		2
#define FS			4
#define FEIE		7
#endif

void DMA_Config(void);
#endif /* INC_DMA_H_ */
