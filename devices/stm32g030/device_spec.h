#pragma once

#define RAM_BASE_ADDRESS 0x20000000
#define RAM_SIZE 0x2000

#include <stdint.h>

#define __I  volatile const
#define __O  volatile
#define __IO volatile

#define __ASM            __asm
#define __INLINE         inline
#define __STATIC_INLINE  static inline
#define __WEAK           __attribute__((weak))

__STATIC_INLINE void __NOP(void)        { __ASM volatile ("nop"); }
__STATIC_INLINE void __WFI(void)        { __ASM volatile ("wfi"); }
__STATIC_INLINE void __enable_irq(void) { __ASM volatile ("cpsie i"); }
__STATIC_INLINE void __disable_irq(void){ __ASM volatile ("cpsid i"); }

#define FLASH_BASE        (0x08000000UL)
#define SRAM_BASE         (0x20000000UL)
#define PERIPH_BASE       (0x40000000UL)
#define IOPORT_BASE       (0x50000000UL)
#define AHBPERIPH_BASE    (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE          (AHBPERIPH_BASE + 0x00001000UL)
#define FLASH_R_BASE      (AHBPERIPH_BASE + 0x00002000UL)
#define GPIOA_BASE        (IOPORT_BASE + 0x00000000UL)
#define GPIOB_BASE        (IOPORT_BASE + 0x00000400UL)
#define GPIOC_BASE        (IOPORT_BASE + 0x00000800UL)

typedef struct
{
  __IO uint32_t MODER;
  __IO uint32_t OTYPER;
  __IO uint32_t OSPEEDR;
  __IO uint32_t PUPDR;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t LCKR;
  __IO uint32_t AFR[2];
  __IO uint32_t BRR;
} GPIO_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t ICSCR;
  __IO uint32_t CFGR;
  __IO uint32_t PLLCFGR;
       uint32_t RESERVED0;
       uint32_t RESERVED1;
  __IO uint32_t CIER;
  __IO uint32_t CIFR;
  __IO uint32_t CICR;
  __IO uint32_t IOPRSTR;
  __IO uint32_t AHBRSTR;
  __IO uint32_t APBRSTR1;
  __IO uint32_t APBRSTR2;
  __IO uint32_t IOPENR;
  __IO uint32_t AHBENR;
  __IO uint32_t APBENR1;
  __IO uint32_t APBENR2;
  __IO uint32_t IOPSMENR;
  __IO uint32_t AHBSMENR;
  __IO uint32_t APBSMENR1;
  __IO uint32_t APBSMENR2;
  __IO uint32_t CCIPR;
       uint32_t RESERVED2;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
} RCC_TypeDef;

typedef struct
{
  __IO uint32_t ACR;
       uint32_t RESERVED1;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t ECCR;
       uint32_t RESERVED2;
  __IO uint32_t OPTR;
       uint32_t RESERVED3[2];
  __IO uint32_t WRP1AR;
  __IO uint32_t WRP1BR;
       uint32_t RESERVED4[2];
} FLASH_TypeDef;

#define GPIOA   ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *)GPIOC_BASE)
#define RCC     ((RCC_TypeDef *)RCC_BASE)
#define FLASH   ((FLASH_TypeDef *)FLASH_R_BASE)

#define RCC_CR_HSION_Pos        (8U)
#define RCC_CR_HSION            (0x1UL << RCC_CR_HSION_Pos)
#define RCC_CR_HSIRDY_Pos       (10U)
#define RCC_CR_HSIRDY           (0x1UL << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIDIV_Pos       (11U)
#define RCC_CR_HSIDIV_Msk       (0x7UL << RCC_CR_HSIDIV_Pos)

#define RCC_CFGR_SW_Pos         (0U)
#define RCC_CFGR_SW_Msk         (0x7UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSISYS      (0x0UL)
#define RCC_CFGR_SWS_Pos        (3U)
#define RCC_CFGR_SWS_Msk        (0x7UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_HPRE_Pos       (8U)
#define RCC_CFGR_HPRE_Msk       (0xFUL << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_PPRE_Pos       (12U)
#define RCC_CFGR_PPRE_Msk       (0x7UL << RCC_CFGR_PPRE_Pos)

#define RCC_IOPENR_GPIOAEN_Pos  (0U)
#define RCC_IOPENR_GPIOAEN      (0x1UL << RCC_IOPENR_GPIOAEN_Pos)
#define RCC_IOPENR_GPIOBEN_Pos  (1U)
#define RCC_IOPENR_GPIOBEN      (0x1UL << RCC_IOPENR_GPIOBEN_Pos)
#define RCC_IOPENR_GPIOCEN_Pos  (2U)
#define RCC_IOPENR_GPIOCEN      (0x1UL << RCC_IOPENR_GPIOCEN_Pos)

#define GPIO_MODER_MODE6_Pos     (12U)
#define GPIO_MODER_MODE6_Msk     (0x3UL << GPIO_MODER_MODE6_Pos)
#define GPIO_OTYPER_OT6_Pos      (6U)
#define GPIO_OTYPER_OT6_Msk      (0x1UL << GPIO_OTYPER_OT6_Pos)
#define GPIO_OSPEEDR_OSPEED6_Pos (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)
#define GPIO_PUPDR_PUPD6_Pos     (12U)
#define GPIO_PUPDR_PUPD6_Msk     (0x3UL << GPIO_PUPDR_PUPD6_Pos)
#define GPIO_BSRR_BS6_Pos        (6U)
#define GPIO_BSRR_BR6_Pos        (22U)
#define GPIO_BRR_BR6_Pos         (6U)
#define GPIO_ODR_OD6_Pos         (6U)