constexpr static uint32_t RCC_BASE = 1073876992;
constexpr static uint32_t RCC_CR_BASE = RCC_BASE + 0;
constexpr static RegisterFieldDescriptor RCC_CR_HSION = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_HSIKERON = { 9, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_HSIRDY = { 10, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_HSIDIV = { 11, 3 };
constexpr static RegisterFieldDescriptor RCC_CR_HSEON = { 16, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_HSERDY = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_HSEBYP = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_CSSON = { 19, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_PLLON = { 24, 1 };
constexpr static RegisterFieldDescriptor RCC_CR_PLLRDY = { 25, 1 };


constexpr static uint32_t RCC_ICSCR_BASE = RCC_BASE + 4;
constexpr static RegisterFieldDescriptor RCC_ICSCR_HSICAL = { 0, 8 };
constexpr static RegisterFieldDescriptor RCC_ICSCR_HSITRIM = { 8, 7 };


constexpr static uint32_t RCC_CFGR_BASE = RCC_BASE + 8;
constexpr static RegisterFieldDescriptor RCC_CFGR_SW = { 0, 3 };
constexpr static RegisterFieldDescriptor RCC_CFGR_SWS = { 3, 3 };
constexpr static RegisterFieldDescriptor RCC_CFGR_HPRE = { 8, 4 };
constexpr static RegisterFieldDescriptor RCC_CFGR_PPRE = { 12, 3 };
constexpr static RegisterFieldDescriptor RCC_CFGR_MCO2SEL = { 16, 4 };
constexpr static RegisterFieldDescriptor RCC_CFGR_MCO2PRE = { 20, 4 };
constexpr static RegisterFieldDescriptor RCC_CFGR_MCOSEL = { 24, 4 };
constexpr static RegisterFieldDescriptor RCC_CFGR_MCOPRE = { 28, 4 };


constexpr static uint32_t RCC_PLLCFGR_BASE = RCC_BASE + 12;
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLSRC = { 0, 2 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLM = { 4, 3 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLN = { 8, 7 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLPEN = { 16, 1 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLP = { 17, 5 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLQEN = { 24, 1 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLQ = { 25, 3 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLREN = { 28, 1 };
constexpr static RegisterFieldDescriptor RCC_PLLCFGR_PLLR = { 29, 3 };


constexpr static uint32_t RCC_CIER_BASE = RCC_BASE + 24;
constexpr static RegisterFieldDescriptor RCC_CIER_LSIRDYIE = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_CIER_LSERDYIE = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_CIER_HSIRDYIE = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_CIER_HSERDYIE = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_CIER_PLLRDYIE = { 5, 1 };


constexpr static uint32_t RCC_CIFR_BASE = RCC_BASE + 28;
constexpr static RegisterFieldDescriptor RCC_CIFR_LSIRDYF = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_CIFR_LSERDYF = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_CIFR_HSIRDYF = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_CIFR_HSERDYF = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_CIFR_PLLRDYF = { 5, 1 };
constexpr static RegisterFieldDescriptor RCC_CIFR_CSSF = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_CIFR_LSECSSF = { 9, 1 };


constexpr static uint32_t RCC_CICR_BASE = RCC_BASE + 32;
constexpr static RegisterFieldDescriptor RCC_CICR_LSIRDYC = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_CICR_LSERDYC = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_CICR_HSIRDYC = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_CICR_HSERDYC = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_CICR_PLLRDYC = { 5, 1 };
constexpr static RegisterFieldDescriptor RCC_CICR_CSSC = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_CICR_LSECSSC = { 9, 1 };


constexpr static uint32_t RCC_IOPRSTR_BASE = RCC_BASE + 36;
constexpr static RegisterFieldDescriptor RCC_IOPRSTR_GPIOARST = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPRSTR_GPIOBRST = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPRSTR_GPIOCRST = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPRSTR_GPIODRST = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPRSTR_GPIOERST = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPRSTR_GPIOFRST = { 5, 1 };


constexpr static uint32_t RCC_AHBRSTR_BASE = RCC_BASE + 40;
constexpr static RegisterFieldDescriptor RCC_AHBRSTR_DMA1RST = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBRSTR_DMA2RST = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBRSTR_FLASHRST = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBRSTR_CRCRST = { 12, 1 };


constexpr static uint32_t RCC_APBRSTR1_BASE = RCC_BASE + 44;
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_TIM3RST = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_TIM4RST = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_TIM6RST = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_TIM7RST = { 5, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_USART5RST = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_USART6RST = { 9, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_USBRST = { 13, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_SPI2RST = { 14, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_SPI3RST = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_USART2RST = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_USART3RST = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_USART4RST = { 19, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_I2C1RST = { 21, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_I2C2RST = { 22, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_I2C3RST = { 23, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_DBGRST = { 27, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR1_PWRRST = { 28, 1 };


constexpr static uint32_t RCC_APBRSTR2_BASE = RCC_BASE + 48;
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_TIM1RST = { 11, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_SPI1RST = { 12, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_USART1RST = { 14, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_TIM14RST = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_TIM15RST = { 16, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_TIM16RST = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_TIM17RST = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_APBRSTR2_ADCRST = { 20, 1 };


constexpr static uint32_t RCC_IOPENR_BASE = RCC_BASE + 52;
constexpr static RegisterFieldDescriptor RCC_IOPENR_GPIOAEN = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPENR_GPIOBEN = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPENR_GPIOCEN = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPENR_GPIODEN = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPENR_GPIOEEN = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPENR_GPIOFEN = { 5, 1 };


constexpr static uint32_t RCC_AHBENR_BASE = RCC_BASE + 56;
constexpr static RegisterFieldDescriptor RCC_AHBENR_DMA1EN = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBENR_DMA2EN = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBENR_FLASHEN = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBENR_CRCEN = { 12, 1 };


constexpr static uint32_t RCC_APBENR1_BASE = RCC_BASE + 60;
constexpr static RegisterFieldDescriptor RCC_APBENR1_TIM3EN = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_TIM4EN = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_TIM6EN = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_TIM7EN = { 5, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_USART5EN = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_USART6EN = { 9, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_RTCAPBEN = { 10, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_WWDGEN = { 11, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_USBEN = { 13, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_SPI2EN = { 14, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_SPI3EN = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_USART2EN = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_USART3EN = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_USART4EN = { 19, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_I2C1EN = { 21, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_I2C2EN = { 22, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_I2C3EN = { 23, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_DBGEN = { 27, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR1_PWREN = { 28, 1 };


constexpr static uint32_t RCC_APBENR2_BASE = RCC_BASE + 64;
constexpr static RegisterFieldDescriptor RCC_APBENR2_SYSCFGEN = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_TIM1EN = { 11, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_SPI1EN = { 12, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_USART1EN = { 14, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_TIM14EN = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_TIM15EN = { 16, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_TIM16EN = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_TIM17EN = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_APBENR2_ADCEN = { 20, 1 };


constexpr static uint32_t RCC_IOPSMENR_BASE = RCC_BASE + 68;
constexpr static RegisterFieldDescriptor RCC_IOPSMENR_GPIOASMEN = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPSMENR_GPIOBSMEN = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPSMENR_GPIOCSMEN = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPSMENR_GPIODSMEN = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPSMENR_GPIOESMEN = { 3, 1 };
constexpr static RegisterFieldDescriptor RCC_IOPSMENR_GPIOFSMEN = { 4, 1 };


constexpr static uint32_t RCC_AHBSMENR_BASE = RCC_BASE + 72;
constexpr static RegisterFieldDescriptor RCC_AHBSMENR_DMA1SMEN = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBSMENR_DMA2SMEN = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBSMENR_FLASHSMEN = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBSMENR_SRAMSMEN = { 9, 1 };
constexpr static RegisterFieldDescriptor RCC_AHBSMENR_CRCSMEN = { 12, 1 };


constexpr static uint32_t RCC_APBSMENR1_BASE = RCC_BASE + 76;
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_TIM3SMEN = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_TIM4SMEN = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_TIM6SMEN = { 4, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_TIM7SMEN = { 5, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_USART5SMEN = { 8, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_USART6SMEN = { 9, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_RTCAPBSMEN = { 10, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_WWDGSMEN = { 11, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_USBSMEN = { 13, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_SPI2SMEN = { 14, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_SPI3SMEN = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_USART2SMEN = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_USART3SMEN = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_USART4SMEN = { 19, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_I2C1SMEN = { 21, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_I2C2SMEN = { 22, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_I2C3SMEN = { 23, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_DBGMEN = { 27, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR1_PWRSMEN = { 28, 1 };


constexpr static uint32_t RCC_APBSMENR2_BASE = RCC_BASE + 80;
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_SYSCFGSMEN = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_TIM1SMEN = { 11, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_SPI1SMEN = { 12, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_USART1SMEN = { 14, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_TIM14SMEN = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_TIM15SMEN = { 16, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_TIM16SMEN = { 17, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_TIM17SMEN = { 18, 1 };
constexpr static RegisterFieldDescriptor RCC_APBSMENR2_ADCSMEN = { 20, 1 };


constexpr static uint32_t RCC_CCIPR_BASE = RCC_BASE + 84;
constexpr static RegisterFieldDescriptor RCC_CCIPR_USART1SEL = { 0, 2 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_USART2SEL = { 2, 2 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_USART3SEL = { 4, 2 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_I2C1SEL = { 12, 2 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_I2C2I2S1SEL = { 14, 2 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_TIM1SEL = { 22, 1 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_TIM15SEL = { 24, 1 };
constexpr static RegisterFieldDescriptor RCC_CCIPR_ADCSEL = { 30, 2 };


constexpr static uint32_t RCC_CCIPR2_BASE = RCC_BASE + 88;
constexpr static RegisterFieldDescriptor RCC_CCIPR2_I2S1SEL = { 0, 2 };
constexpr static RegisterFieldDescriptor RCC_CCIPR2_I2S2SEL = { 2, 4 };
constexpr static RegisterFieldDescriptor RCC_CCIPR2_USBSEL = { 12, 2 };


constexpr static uint32_t RCC_BDCR_BASE = RCC_BASE + 92;
constexpr static RegisterFieldDescriptor RCC_BDCR_LSEON = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSERDY = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSEBYP = { 2, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSEDRV = { 3, 2 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSECSSON = { 5, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSECSSD = { 6, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_RTCSEL = { 8, 2 };
constexpr static RegisterFieldDescriptor RCC_BDCR_RTCEN = { 15, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_BDRST = { 16, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSCOEN = { 24, 1 };
constexpr static RegisterFieldDescriptor RCC_BDCR_LSCOSEL = { 25, 1 };


constexpr static uint32_t RCC_RCC_CSR_BASE = RCC_BASE + 96;
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_LSION = { 0, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_LSIRDY = { 1, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_RMVF = { 23, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_OBLRSTF = { 25, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_PINRSTF = { 26, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_PWRRSTF = { 27, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_SFTRSTF = { 28, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_IWWGRSTF = { 29, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_WWDGRSTF = { 30, 1 };
constexpr static RegisterFieldDescriptor RCC_RCC_CSR_LPWRRSTF = { 31, 1 };




constexpr static uint32_t GPIOA_BASE = 1342177280;
constexpr static uint32_t GPIOA_MODER_BASE = GPIOA_BASE + 0;
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOA_MODER_MODE15 = { 30, 2 };


constexpr static uint32_t GPIOA_OTYPER_BASE = GPIOA_BASE + 4;
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOA_OTYPER_OT15 = { 15, 1 };


constexpr static uint32_t GPIOA_OSPEEDR_BASE = GPIOA_BASE + 8;
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOA_OSPEEDR_OSPEED15 = { 30, 2 };


constexpr static uint32_t GPIOA_PUPDR_BASE = GPIOA_BASE + 12;
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOA_PUPDR_PUPD15 = { 30, 2 };


constexpr static uint32_t GPIOA_IDR_BASE = GPIOA_BASE + 16;
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOA_IDR_ID15 = { 15, 1 };


constexpr static uint32_t GPIOA_ODR_BASE = GPIOA_BASE + 20;
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOA_ODR_OD15 = { 15, 1 };


constexpr static uint32_t GPIOA_BSRR_BASE = GPIOA_BASE + 24;
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BS15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR0 = { 16, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR1 = { 17, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR2 = { 18, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR3 = { 19, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR4 = { 20, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR5 = { 21, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR6 = { 22, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR7 = { 23, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR8 = { 24, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR9 = { 25, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR10 = { 26, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR11 = { 27, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR12 = { 28, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR13 = { 29, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR14 = { 30, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BSRR_BR15 = { 31, 1 };


constexpr static uint32_t GPIOA_LCKR_BASE = GPIOA_BASE + 28;
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCK15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOA_LCKR_LCKK = { 16, 1 };


constexpr static uint32_t GPIOA_AFRL_BASE = GPIOA_BASE + 32;
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL0 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL1 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL2 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL3 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL4 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL5 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL6 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRL_AFSEL7 = { 28, 4 };


constexpr static uint32_t GPIOA_AFRH_BASE = GPIOA_BASE + 36;
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL8 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL9 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL10 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL11 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL12 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL13 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL14 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOA_AFRH_AFSEL15 = { 28, 4 };


constexpr static uint32_t GPIOA_BRR_BASE = GPIOA_BASE + 40;
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOA_BRR_BR15 = { 15, 1 };




constexpr static uint32_t GPIOB_BASE = 1342178304;
constexpr static uint32_t GPIOB_MODER_BASE = GPIOB_BASE + 0;
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOB_MODER_MODE15 = { 30, 2 };


constexpr static uint32_t GPIOB_OTYPER_BASE = GPIOB_BASE + 4;
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOB_OTYPER_OT15 = { 15, 1 };


constexpr static uint32_t GPIOB_OSPEEDR_BASE = GPIOB_BASE + 8;
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOB_OSPEEDR_OSPEED15 = { 30, 2 };


constexpr static uint32_t GPIOB_PUPDR_BASE = GPIOB_BASE + 12;
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOB_PUPDR_PUPD15 = { 30, 2 };


constexpr static uint32_t GPIOB_IDR_BASE = GPIOB_BASE + 16;
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOB_IDR_ID15 = { 15, 1 };


constexpr static uint32_t GPIOB_ODR_BASE = GPIOB_BASE + 20;
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOB_ODR_OD15 = { 15, 1 };


constexpr static uint32_t GPIOB_BSRR_BASE = GPIOB_BASE + 24;
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BS15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR0 = { 16, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR1 = { 17, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR2 = { 18, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR3 = { 19, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR4 = { 20, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR5 = { 21, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR6 = { 22, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR7 = { 23, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR8 = { 24, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR9 = { 25, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR10 = { 26, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR11 = { 27, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR12 = { 28, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR13 = { 29, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR14 = { 30, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BSRR_BR15 = { 31, 1 };


constexpr static uint32_t GPIOB_LCKR_BASE = GPIOB_BASE + 28;
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCK15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOB_LCKR_LCKK = { 16, 1 };


constexpr static uint32_t GPIOB_AFRL_BASE = GPIOB_BASE + 32;
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL0 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL1 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL2 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL3 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL4 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL5 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL6 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRL_AFSEL7 = { 28, 4 };


constexpr static uint32_t GPIOB_AFRH_BASE = GPIOB_BASE + 36;
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL8 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL9 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL10 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL11 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL12 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL13 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL14 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOB_AFRH_AFSEL15 = { 28, 4 };


constexpr static uint32_t GPIOB_BRR_BASE = GPIOB_BASE + 40;
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOB_BRR_BR15 = { 15, 1 };




constexpr static uint32_t GPIOC_BASE = 1342179328;
constexpr static uint32_t GPIOC_MODER_BASE = GPIOC_BASE + 0;
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOC_MODER_MODE15 = { 30, 2 };


constexpr static uint32_t GPIOC_OTYPER_BASE = GPIOC_BASE + 4;
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOC_OTYPER_OT15 = { 15, 1 };


constexpr static uint32_t GPIOC_OSPEEDR_BASE = GPIOC_BASE + 8;
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOC_OSPEEDR_OSPEED15 = { 30, 2 };


constexpr static uint32_t GPIOC_PUPDR_BASE = GPIOC_BASE + 12;
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOC_PUPDR_PUPD15 = { 30, 2 };


constexpr static uint32_t GPIOC_IDR_BASE = GPIOC_BASE + 16;
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOC_IDR_ID15 = { 15, 1 };


constexpr static uint32_t GPIOC_ODR_BASE = GPIOC_BASE + 20;
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOC_ODR_OD15 = { 15, 1 };


constexpr static uint32_t GPIOC_BSRR_BASE = GPIOC_BASE + 24;
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BS15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR0 = { 16, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR1 = { 17, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR2 = { 18, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR3 = { 19, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR4 = { 20, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR5 = { 21, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR6 = { 22, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR7 = { 23, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR8 = { 24, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR9 = { 25, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR10 = { 26, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR11 = { 27, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR12 = { 28, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR13 = { 29, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR14 = { 30, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BSRR_BR15 = { 31, 1 };


constexpr static uint32_t GPIOC_LCKR_BASE = GPIOC_BASE + 28;
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCK15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOC_LCKR_LCKK = { 16, 1 };


constexpr static uint32_t GPIOC_AFRL_BASE = GPIOC_BASE + 32;
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL0 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL1 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL2 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL3 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL4 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL5 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL6 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRL_AFSEL7 = { 28, 4 };


constexpr static uint32_t GPIOC_AFRH_BASE = GPIOC_BASE + 36;
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL8 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL9 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL10 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL11 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL12 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL13 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL14 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOC_AFRH_AFSEL15 = { 28, 4 };


constexpr static uint32_t GPIOC_BRR_BASE = GPIOC_BASE + 40;
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOC_BRR_BR15 = { 15, 1 };




constexpr static uint32_t GPIOD_BASE = 1342180352;
constexpr static uint32_t GPIOD_MODER_BASE = GPIOD_BASE + 0;
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOD_MODER_MODE15 = { 30, 2 };


constexpr static uint32_t GPIOD_OTYPER_BASE = GPIOD_BASE + 4;
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOD_OTYPER_OT15 = { 15, 1 };


constexpr static uint32_t GPIOD_OSPEEDR_BASE = GPIOD_BASE + 8;
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOD_OSPEEDR_OSPEED15 = { 30, 2 };


constexpr static uint32_t GPIOD_PUPDR_BASE = GPIOD_BASE + 12;
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOD_PUPDR_PUPD15 = { 30, 2 };


constexpr static uint32_t GPIOD_IDR_BASE = GPIOD_BASE + 16;
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOD_IDR_ID15 = { 15, 1 };


constexpr static uint32_t GPIOD_ODR_BASE = GPIOD_BASE + 20;
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOD_ODR_OD15 = { 15, 1 };


constexpr static uint32_t GPIOD_BSRR_BASE = GPIOD_BASE + 24;
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BS15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR0 = { 16, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR1 = { 17, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR2 = { 18, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR3 = { 19, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR4 = { 20, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR5 = { 21, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR6 = { 22, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR7 = { 23, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR8 = { 24, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR9 = { 25, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR10 = { 26, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR11 = { 27, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR12 = { 28, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR13 = { 29, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR14 = { 30, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BSRR_BR15 = { 31, 1 };


constexpr static uint32_t GPIOD_LCKR_BASE = GPIOD_BASE + 28;
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCK15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOD_LCKR_LCKK = { 16, 1 };


constexpr static uint32_t GPIOD_AFRL_BASE = GPIOD_BASE + 32;
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL0 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL1 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL2 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL3 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL4 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL5 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL6 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRL_AFSEL7 = { 28, 4 };


constexpr static uint32_t GPIOD_AFRH_BASE = GPIOD_BASE + 36;
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL8 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL9 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL10 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL11 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL12 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL13 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL14 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOD_AFRH_AFSEL15 = { 28, 4 };


constexpr static uint32_t GPIOD_BRR_BASE = GPIOD_BASE + 40;
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOD_BRR_BR15 = { 15, 1 };




constexpr static uint32_t GPIOE_BASE = 1342181376;
constexpr static uint32_t GPIOE_MODER_BASE = GPIOE_BASE + 0;
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOE_MODER_MODE15 = { 30, 2 };


constexpr static uint32_t GPIOE_OTYPER_BASE = GPIOE_BASE + 4;
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOE_OTYPER_OT15 = { 15, 1 };


constexpr static uint32_t GPIOE_OSPEEDR_BASE = GPIOE_BASE + 8;
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOE_OSPEEDR_OSPEED15 = { 30, 2 };


constexpr static uint32_t GPIOE_PUPDR_BASE = GPIOE_BASE + 12;
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOE_PUPDR_PUPD15 = { 30, 2 };


constexpr static uint32_t GPIOE_IDR_BASE = GPIOE_BASE + 16;
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOE_IDR_ID15 = { 15, 1 };


constexpr static uint32_t GPIOE_ODR_BASE = GPIOE_BASE + 20;
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOE_ODR_OD15 = { 15, 1 };


constexpr static uint32_t GPIOE_BSRR_BASE = GPIOE_BASE + 24;
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BS15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR0 = { 16, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR1 = { 17, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR2 = { 18, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR3 = { 19, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR4 = { 20, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR5 = { 21, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR6 = { 22, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR7 = { 23, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR8 = { 24, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR9 = { 25, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR10 = { 26, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR11 = { 27, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR12 = { 28, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR13 = { 29, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR14 = { 30, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BSRR_BR15 = { 31, 1 };


constexpr static uint32_t GPIOE_LCKR_BASE = GPIOE_BASE + 28;
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCK15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOE_LCKR_LCKK = { 16, 1 };


constexpr static uint32_t GPIOE_AFRL_BASE = GPIOE_BASE + 32;
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL0 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL1 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL2 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL3 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL4 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL5 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL6 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRL_AFSEL7 = { 28, 4 };


constexpr static uint32_t GPIOE_AFRH_BASE = GPIOE_BASE + 36;
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL8 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL9 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL10 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL11 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL12 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL13 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL14 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOE_AFRH_AFSEL15 = { 28, 4 };


constexpr static uint32_t GPIOE_BRR_BASE = GPIOE_BASE + 40;
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOE_BRR_BR15 = { 15, 1 };




constexpr static uint32_t GPIOF_BASE = 1342182400;
constexpr static uint32_t GPIOF_MODER_BASE = GPIOF_BASE + 0;
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOF_MODER_MODE15 = { 30, 2 };


constexpr static uint32_t GPIOF_OTYPER_BASE = GPIOF_BASE + 4;
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOF_OTYPER_OT15 = { 15, 1 };


constexpr static uint32_t GPIOF_OSPEEDR_BASE = GPIOF_BASE + 8;
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOF_OSPEEDR_OSPEED15 = { 30, 2 };


constexpr static uint32_t GPIOF_PUPDR_BASE = GPIOF_BASE + 12;
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD0 = { 0, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD1 = { 2, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD2 = { 4, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD3 = { 6, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD4 = { 8, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD5 = { 10, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD6 = { 12, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD7 = { 14, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD8 = { 16, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD9 = { 18, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD10 = { 20, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD11 = { 22, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD12 = { 24, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD13 = { 26, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD14 = { 28, 2 };
constexpr static RegisterFieldDescriptor GPIOF_PUPDR_PUPD15 = { 30, 2 };


constexpr static uint32_t GPIOF_IDR_BASE = GPIOF_BASE + 16;
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOF_IDR_ID15 = { 15, 1 };


constexpr static uint32_t GPIOF_ODR_BASE = GPIOF_BASE + 20;
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOF_ODR_OD15 = { 15, 1 };


constexpr static uint32_t GPIOF_BSRR_BASE = GPIOF_BASE + 24;
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BS15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR0 = { 16, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR1 = { 17, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR2 = { 18, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR3 = { 19, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR4 = { 20, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR5 = { 21, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR6 = { 22, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR7 = { 23, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR8 = { 24, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR9 = { 25, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR10 = { 26, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR11 = { 27, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR12 = { 28, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR13 = { 29, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR14 = { 30, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BSRR_BR15 = { 31, 1 };


constexpr static uint32_t GPIOF_LCKR_BASE = GPIOF_BASE + 28;
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCK15 = { 15, 1 };
constexpr static RegisterFieldDescriptor GPIOF_LCKR_LCKK = { 16, 1 };


constexpr static uint32_t GPIOF_AFRL_BASE = GPIOF_BASE + 32;
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL0 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL1 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL2 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL3 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL4 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL5 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL6 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRL_AFSEL7 = { 28, 4 };


constexpr static uint32_t GPIOF_AFRH_BASE = GPIOF_BASE + 36;
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL8 = { 0, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL9 = { 4, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL10 = { 8, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL11 = { 12, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL12 = { 16, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL13 = { 20, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL14 = { 24, 4 };
constexpr static RegisterFieldDescriptor GPIOF_AFRH_AFSEL15 = { 28, 4 };


constexpr static uint32_t GPIOF_BRR_BASE = GPIOF_BASE + 40;
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR0 = { 0, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR1 = { 1, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR2 = { 2, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR3 = { 3, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR4 = { 4, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR5 = { 5, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR6 = { 6, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR7 = { 7, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR8 = { 8, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR9 = { 9, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR10 = { 10, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR11 = { 11, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR12 = { 12, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR13 = { 13, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR14 = { 14, 1 };
constexpr static RegisterFieldDescriptor GPIOF_BRR_BR15 = { 15, 1 };




struct RCC {
	struct CR {
		DECL_REGISTER(RCC_CR_BASE);
		constexpr static RegisterField<RCC_CR_HSION> HSION {};
		constexpr static RegisterField<RCC_CR_HSIKERON> HSIKERON {};
		constexpr static RegisterField<RCC_CR_HSIRDY> HSIRDY {};
		constexpr static RegisterField<RCC_CR_HSIDIV> HSIDIV {};
		constexpr static RegisterField<RCC_CR_HSEON> HSEON {};
		constexpr static RegisterField<RCC_CR_HSERDY> HSERDY {};
		constexpr static RegisterField<RCC_CR_HSEBYP> HSEBYP {};
		constexpr static RegisterField<RCC_CR_CSSON> CSSON {};
		constexpr static RegisterField<RCC_CR_PLLON> PLLON {};
		constexpr static RegisterField<RCC_CR_PLLRDY> PLLRDY {};
	};

	struct ICSCR {
		DECL_REGISTER(RCC_ICSCR_BASE);
		constexpr static RegisterField<RCC_ICSCR_HSICAL> HSICAL {};
		constexpr static RegisterField<RCC_ICSCR_HSITRIM> HSITRIM {};
	};

	struct CFGR {
		DECL_REGISTER(RCC_CFGR_BASE);
		constexpr static RegisterField<RCC_CFGR_SW> SW {};
		constexpr static RegisterField<RCC_CFGR_SWS> SWS {};
		constexpr static RegisterField<RCC_CFGR_HPRE> HPRE {};
		constexpr static RegisterField<RCC_CFGR_PPRE> PPRE {};
		constexpr static RegisterField<RCC_CFGR_MCO2SEL> MCO2SEL {};
		constexpr static RegisterField<RCC_CFGR_MCO2PRE> MCO2PRE {};
		constexpr static RegisterField<RCC_CFGR_MCOSEL> MCOSEL {};
		constexpr static RegisterField<RCC_CFGR_MCOPRE> MCOPRE {};
	};

	struct PLLCFGR {
		DECL_REGISTER(RCC_PLLCFGR_BASE);
		constexpr static RegisterField<RCC_PLLCFGR_PLLSRC> PLLSRC {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLM> PLLM {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLN> PLLN {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLPEN> PLLPEN {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLP> PLLP {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLQEN> PLLQEN {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLQ> PLLQ {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLREN> PLLREN {};
		constexpr static RegisterField<RCC_PLLCFGR_PLLR> PLLR {};
	};

	struct CIER {
		DECL_REGISTER(RCC_CIER_BASE);
		constexpr static RegisterField<RCC_CIER_LSIRDYIE> LSIRDYIE {};
		constexpr static RegisterField<RCC_CIER_LSERDYIE> LSERDYIE {};
		constexpr static RegisterField<RCC_CIER_HSIRDYIE> HSIRDYIE {};
		constexpr static RegisterField<RCC_CIER_HSERDYIE> HSERDYIE {};
		constexpr static RegisterField<RCC_CIER_PLLRDYIE> PLLRDYIE {};
	};

	struct CIFR {
		DECL_REGISTER(RCC_CIFR_BASE);
		constexpr static RegisterField<RCC_CIFR_LSIRDYF> LSIRDYF {};
		constexpr static RegisterField<RCC_CIFR_LSERDYF> LSERDYF {};
		constexpr static RegisterField<RCC_CIFR_HSIRDYF> HSIRDYF {};
		constexpr static RegisterField<RCC_CIFR_HSERDYF> HSERDYF {};
		constexpr static RegisterField<RCC_CIFR_PLLRDYF> PLLRDYF {};
		constexpr static RegisterField<RCC_CIFR_CSSF> CSSF {};
		constexpr static RegisterField<RCC_CIFR_LSECSSF> LSECSSF {};
	};

	struct CICR {
		DECL_REGISTER(RCC_CICR_BASE);
		constexpr static RegisterField<RCC_CICR_LSIRDYC> LSIRDYC {};
		constexpr static RegisterField<RCC_CICR_LSERDYC> LSERDYC {};
		constexpr static RegisterField<RCC_CICR_HSIRDYC> HSIRDYC {};
		constexpr static RegisterField<RCC_CICR_HSERDYC> HSERDYC {};
		constexpr static RegisterField<RCC_CICR_PLLRDYC> PLLRDYC {};
		constexpr static RegisterField<RCC_CICR_CSSC> CSSC {};
		constexpr static RegisterField<RCC_CICR_LSECSSC> LSECSSC {};
	};

	struct IOPRSTR {
		DECL_REGISTER(RCC_IOPRSTR_BASE);
		constexpr static RegisterField<RCC_IOPRSTR_GPIOARST> GPIOARST {};
		constexpr static RegisterField<RCC_IOPRSTR_GPIOBRST> GPIOBRST {};
		constexpr static RegisterField<RCC_IOPRSTR_GPIOCRST> GPIOCRST {};
		constexpr static RegisterField<RCC_IOPRSTR_GPIODRST> GPIODRST {};
		constexpr static RegisterField<RCC_IOPRSTR_GPIOERST> GPIOERST {};
		constexpr static RegisterField<RCC_IOPRSTR_GPIOFRST> GPIOFRST {};
	};

	struct AHBRSTR {
		DECL_REGISTER(RCC_AHBRSTR_BASE);
		constexpr static RegisterField<RCC_AHBRSTR_DMA1RST> DMA1RST {};
		constexpr static RegisterField<RCC_AHBRSTR_DMA2RST> DMA2RST {};
		constexpr static RegisterField<RCC_AHBRSTR_FLASHRST> FLASHRST {};
		constexpr static RegisterField<RCC_AHBRSTR_CRCRST> CRCRST {};
	};

	struct APBRSTR1 {
		DECL_REGISTER(RCC_APBRSTR1_BASE);
		constexpr static RegisterField<RCC_APBRSTR1_TIM3RST> TIM3RST {};
		constexpr static RegisterField<RCC_APBRSTR1_TIM4RST> TIM4RST {};
		constexpr static RegisterField<RCC_APBRSTR1_TIM6RST> TIM6RST {};
		constexpr static RegisterField<RCC_APBRSTR1_TIM7RST> TIM7RST {};
		constexpr static RegisterField<RCC_APBRSTR1_USART5RST> USART5RST {};
		constexpr static RegisterField<RCC_APBRSTR1_USART6RST> USART6RST {};
		constexpr static RegisterField<RCC_APBRSTR1_USBRST> USBRST {};
		constexpr static RegisterField<RCC_APBRSTR1_SPI2RST> SPI2RST {};
		constexpr static RegisterField<RCC_APBRSTR1_SPI3RST> SPI3RST {};
		constexpr static RegisterField<RCC_APBRSTR1_USART2RST> USART2RST {};
		constexpr static RegisterField<RCC_APBRSTR1_USART3RST> USART3RST {};
		constexpr static RegisterField<RCC_APBRSTR1_USART4RST> USART4RST {};
		constexpr static RegisterField<RCC_APBRSTR1_I2C1RST> I2C1RST {};
		constexpr static RegisterField<RCC_APBRSTR1_I2C2RST> I2C2RST {};
		constexpr static RegisterField<RCC_APBRSTR1_I2C3RST> I2C3RST {};
		constexpr static RegisterField<RCC_APBRSTR1_DBGRST> DBGRST {};
		constexpr static RegisterField<RCC_APBRSTR1_PWRRST> PWRRST {};
	};

	struct APBRSTR2 {
		DECL_REGISTER(RCC_APBRSTR2_BASE);
		constexpr static RegisterField<RCC_APBRSTR2_TIM1RST> TIM1RST {};
		constexpr static RegisterField<RCC_APBRSTR2_SPI1RST> SPI1RST {};
		constexpr static RegisterField<RCC_APBRSTR2_USART1RST> USART1RST {};
		constexpr static RegisterField<RCC_APBRSTR2_TIM14RST> TIM14RST {};
		constexpr static RegisterField<RCC_APBRSTR2_TIM15RST> TIM15RST {};
		constexpr static RegisterField<RCC_APBRSTR2_TIM16RST> TIM16RST {};
		constexpr static RegisterField<RCC_APBRSTR2_TIM17RST> TIM17RST {};
		constexpr static RegisterField<RCC_APBRSTR2_ADCRST> ADCRST {};
	};

	struct IOPENR {
		DECL_REGISTER(RCC_IOPENR_BASE);
		constexpr static RegisterField<RCC_IOPENR_GPIOAEN> GPIOAEN {};
		constexpr static RegisterField<RCC_IOPENR_GPIOBEN> GPIOBEN {};
		constexpr static RegisterField<RCC_IOPENR_GPIOCEN> GPIOCEN {};
		constexpr static RegisterField<RCC_IOPENR_GPIODEN> GPIODEN {};
		constexpr static RegisterField<RCC_IOPENR_GPIOEEN> GPIOEEN {};
		constexpr static RegisterField<RCC_IOPENR_GPIOFEN> GPIOFEN {};
	};

	struct AHBENR {
		DECL_REGISTER(RCC_AHBENR_BASE);
		constexpr static RegisterField<RCC_AHBENR_DMA1EN> DMA1EN {};
		constexpr static RegisterField<RCC_AHBENR_DMA2EN> DMA2EN {};
		constexpr static RegisterField<RCC_AHBENR_FLASHEN> FLASHEN {};
		constexpr static RegisterField<RCC_AHBENR_CRCEN> CRCEN {};
	};

	struct APBENR1 {
		DECL_REGISTER(RCC_APBENR1_BASE);
		constexpr static RegisterField<RCC_APBENR1_TIM3EN> TIM3EN {};
		constexpr static RegisterField<RCC_APBENR1_TIM4EN> TIM4EN {};
		constexpr static RegisterField<RCC_APBENR1_TIM6EN> TIM6EN {};
		constexpr static RegisterField<RCC_APBENR1_TIM7EN> TIM7EN {};
		constexpr static RegisterField<RCC_APBENR1_USART5EN> USART5EN {};
		constexpr static RegisterField<RCC_APBENR1_USART6EN> USART6EN {};
		constexpr static RegisterField<RCC_APBENR1_RTCAPBEN> RTCAPBEN {};
		constexpr static RegisterField<RCC_APBENR1_WWDGEN> WWDGEN {};
		constexpr static RegisterField<RCC_APBENR1_USBEN> USBEN {};
		constexpr static RegisterField<RCC_APBENR1_SPI2EN> SPI2EN {};
		constexpr static RegisterField<RCC_APBENR1_SPI3EN> SPI3EN {};
		constexpr static RegisterField<RCC_APBENR1_USART2EN> USART2EN {};
		constexpr static RegisterField<RCC_APBENR1_USART3EN> USART3EN {};
		constexpr static RegisterField<RCC_APBENR1_USART4EN> USART4EN {};
		constexpr static RegisterField<RCC_APBENR1_I2C1EN> I2C1EN {};
		constexpr static RegisterField<RCC_APBENR1_I2C2EN> I2C2EN {};
		constexpr static RegisterField<RCC_APBENR1_I2C3EN> I2C3EN {};
		constexpr static RegisterField<RCC_APBENR1_DBGEN> DBGEN {};
		constexpr static RegisterField<RCC_APBENR1_PWREN> PWREN {};
	};

	struct APBENR2 {
		DECL_REGISTER(RCC_APBENR2_BASE);
		constexpr static RegisterField<RCC_APBENR2_SYSCFGEN> SYSCFGEN {};
		constexpr static RegisterField<RCC_APBENR2_TIM1EN> TIM1EN {};
		constexpr static RegisterField<RCC_APBENR2_SPI1EN> SPI1EN {};
		constexpr static RegisterField<RCC_APBENR2_USART1EN> USART1EN {};
		constexpr static RegisterField<RCC_APBENR2_TIM14EN> TIM14EN {};
		constexpr static RegisterField<RCC_APBENR2_TIM15EN> TIM15EN {};
		constexpr static RegisterField<RCC_APBENR2_TIM16EN> TIM16EN {};
		constexpr static RegisterField<RCC_APBENR2_TIM17EN> TIM17EN {};
		constexpr static RegisterField<RCC_APBENR2_ADCEN> ADCEN {};
	};

	struct IOPSMENR {
		DECL_REGISTER(RCC_IOPSMENR_BASE);
		constexpr static RegisterField<RCC_IOPSMENR_GPIOASMEN> GPIOASMEN {};
		constexpr static RegisterField<RCC_IOPSMENR_GPIOBSMEN> GPIOBSMEN {};
		constexpr static RegisterField<RCC_IOPSMENR_GPIOCSMEN> GPIOCSMEN {};
		constexpr static RegisterField<RCC_IOPSMENR_GPIODSMEN> GPIODSMEN {};
		constexpr static RegisterField<RCC_IOPSMENR_GPIOESMEN> GPIOESMEN {};
		constexpr static RegisterField<RCC_IOPSMENR_GPIOFSMEN> GPIOFSMEN {};
	};

	struct AHBSMENR {
		DECL_REGISTER(RCC_AHBSMENR_BASE);
		constexpr static RegisterField<RCC_AHBSMENR_DMA1SMEN> DMA1SMEN {};
		constexpr static RegisterField<RCC_AHBSMENR_DMA2SMEN> DMA2SMEN {};
		constexpr static RegisterField<RCC_AHBSMENR_FLASHSMEN> FLASHSMEN {};
		constexpr static RegisterField<RCC_AHBSMENR_SRAMSMEN> SRAMSMEN {};
		constexpr static RegisterField<RCC_AHBSMENR_CRCSMEN> CRCSMEN {};
	};

	struct APBSMENR1 {
		DECL_REGISTER(RCC_APBSMENR1_BASE);
		constexpr static RegisterField<RCC_APBSMENR1_TIM3SMEN> TIM3SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_TIM4SMEN> TIM4SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_TIM6SMEN> TIM6SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_TIM7SMEN> TIM7SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_USART5SMEN> USART5SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_USART6SMEN> USART6SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_RTCAPBSMEN> RTCAPBSMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_WWDGSMEN> WWDGSMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_USBSMEN> USBSMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_SPI2SMEN> SPI2SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_SPI3SMEN> SPI3SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_USART2SMEN> USART2SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_USART3SMEN> USART3SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_USART4SMEN> USART4SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_I2C1SMEN> I2C1SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_I2C2SMEN> I2C2SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_I2C3SMEN> I2C3SMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_DBGMEN> DBGMEN {};
		constexpr static RegisterField<RCC_APBSMENR1_PWRSMEN> PWRSMEN {};
	};

	struct APBSMENR2 {
		DECL_REGISTER(RCC_APBSMENR2_BASE);
		constexpr static RegisterField<RCC_APBSMENR2_SYSCFGSMEN> SYSCFGSMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_TIM1SMEN> TIM1SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_SPI1SMEN> SPI1SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_USART1SMEN> USART1SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_TIM14SMEN> TIM14SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_TIM15SMEN> TIM15SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_TIM16SMEN> TIM16SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_TIM17SMEN> TIM17SMEN {};
		constexpr static RegisterField<RCC_APBSMENR2_ADCSMEN> ADCSMEN {};
	};

	struct CCIPR {
		DECL_REGISTER(RCC_CCIPR_BASE);
		constexpr static RegisterField<RCC_CCIPR_USART1SEL> USART1SEL {};
		constexpr static RegisterField<RCC_CCIPR_USART2SEL> USART2SEL {};
		constexpr static RegisterField<RCC_CCIPR_USART3SEL> USART3SEL {};
		constexpr static RegisterField<RCC_CCIPR_I2C1SEL> I2C1SEL {};
		constexpr static RegisterField<RCC_CCIPR_I2C2I2S1SEL> I2C2I2S1SEL {};
		constexpr static RegisterField<RCC_CCIPR_TIM1SEL> TIM1SEL {};
		constexpr static RegisterField<RCC_CCIPR_TIM15SEL> TIM15SEL {};
		constexpr static RegisterField<RCC_CCIPR_ADCSEL> ADCSEL {};
	};

	struct CCIPR2 {
		DECL_REGISTER(RCC_CCIPR2_BASE);
		constexpr static RegisterField<RCC_CCIPR2_I2S1SEL> I2S1SEL {};
		constexpr static RegisterField<RCC_CCIPR2_I2S2SEL> I2S2SEL {};
		constexpr static RegisterField<RCC_CCIPR2_USBSEL> USBSEL {};
	};

	struct BDCR {
		DECL_REGISTER(RCC_BDCR_BASE);
		constexpr static RegisterField<RCC_BDCR_LSEON> LSEON {};
		constexpr static RegisterField<RCC_BDCR_LSERDY> LSERDY {};
		constexpr static RegisterField<RCC_BDCR_LSEBYP> LSEBYP {};
		constexpr static RegisterField<RCC_BDCR_LSEDRV> LSEDRV {};
		constexpr static RegisterField<RCC_BDCR_LSECSSON> LSECSSON {};
		constexpr static RegisterField<RCC_BDCR_LSECSSD> LSECSSD {};
		constexpr static RegisterField<RCC_BDCR_RTCSEL> RTCSEL {};
		constexpr static RegisterField<RCC_BDCR_RTCEN> RTCEN {};
		constexpr static RegisterField<RCC_BDCR_BDRST> BDRST {};
		constexpr static RegisterField<RCC_BDCR_LSCOEN> LSCOEN {};
		constexpr static RegisterField<RCC_BDCR_LSCOSEL> LSCOSEL {};
	};

	struct RCC_CSR {
		DECL_REGISTER(RCC_RCC_CSR_BASE);
		constexpr static RegisterField<RCC_RCC_CSR_LSION> LSION {};
		constexpr static RegisterField<RCC_RCC_CSR_LSIRDY> LSIRDY {};
		constexpr static RegisterField<RCC_RCC_CSR_RMVF> RMVF {};
		constexpr static RegisterField<RCC_RCC_CSR_OBLRSTF> OBLRSTF {};
		constexpr static RegisterField<RCC_RCC_CSR_PINRSTF> PINRSTF {};
		constexpr static RegisterField<RCC_RCC_CSR_PWRRSTF> PWRRSTF {};
		constexpr static RegisterField<RCC_RCC_CSR_SFTRSTF> SFTRSTF {};
		constexpr static RegisterField<RCC_RCC_CSR_IWWGRSTF> IWWGRSTF {};
		constexpr static RegisterField<RCC_RCC_CSR_WWDGRSTF> WWDGRSTF {};
		constexpr static RegisterField<RCC_RCC_CSR_LPWRRSTF> LPWRRSTF {};
	};

};

struct GPIOA {
	struct MODER {
		DECL_REGISTER(GPIOA_MODER_BASE);
		constexpr static RegisterField<GPIOA_MODER_MODE0> MODE0 {};
		constexpr static RegisterField<GPIOA_MODER_MODE1> MODE1 {};
		constexpr static RegisterField<GPIOA_MODER_MODE2> MODE2 {};
		constexpr static RegisterField<GPIOA_MODER_MODE3> MODE3 {};
		constexpr static RegisterField<GPIOA_MODER_MODE4> MODE4 {};
		constexpr static RegisterField<GPIOA_MODER_MODE5> MODE5 {};
		constexpr static RegisterField<GPIOA_MODER_MODE6> MODE6 {};
		constexpr static RegisterField<GPIOA_MODER_MODE7> MODE7 {};
		constexpr static RegisterField<GPIOA_MODER_MODE8> MODE8 {};
		constexpr static RegisterField<GPIOA_MODER_MODE9> MODE9 {};
		constexpr static RegisterField<GPIOA_MODER_MODE10> MODE10 {};
		constexpr static RegisterField<GPIOA_MODER_MODE11> MODE11 {};
		constexpr static RegisterField<GPIOA_MODER_MODE12> MODE12 {};
		constexpr static RegisterField<GPIOA_MODER_MODE13> MODE13 {};
		constexpr static RegisterField<GPIOA_MODER_MODE14> MODE14 {};
		constexpr static RegisterField<GPIOA_MODER_MODE15> MODE15 {};
	};

	struct OTYPER {
		DECL_REGISTER(GPIOA_OTYPER_BASE);
		constexpr static RegisterField<GPIOA_OTYPER_OT0> OT0 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT1> OT1 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT2> OT2 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT3> OT3 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT4> OT4 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT5> OT5 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT6> OT6 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT7> OT7 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT8> OT8 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT9> OT9 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT10> OT10 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT11> OT11 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT12> OT12 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT13> OT13 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT14> OT14 {};
		constexpr static RegisterField<GPIOA_OTYPER_OT15> OT15 {};
	};

	struct OSPEEDR {
		DECL_REGISTER(GPIOA_OSPEEDR_BASE);
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED0> OSPEED0 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED1> OSPEED1 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED2> OSPEED2 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED3> OSPEED3 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED4> OSPEED4 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED5> OSPEED5 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED6> OSPEED6 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED7> OSPEED7 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED8> OSPEED8 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED9> OSPEED9 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED10> OSPEED10 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED11> OSPEED11 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED12> OSPEED12 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED13> OSPEED13 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED14> OSPEED14 {};
		constexpr static RegisterField<GPIOA_OSPEEDR_OSPEED15> OSPEED15 {};
	};

	struct PUPDR {
		DECL_REGISTER(GPIOA_PUPDR_BASE);
		constexpr static RegisterField<GPIOA_PUPDR_PUPD0> PUPD0 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD1> PUPD1 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD2> PUPD2 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD3> PUPD3 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD4> PUPD4 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD5> PUPD5 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD6> PUPD6 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD7> PUPD7 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD8> PUPD8 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD9> PUPD9 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD10> PUPD10 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD11> PUPD11 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD12> PUPD12 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD13> PUPD13 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD14> PUPD14 {};
		constexpr static RegisterField<GPIOA_PUPDR_PUPD15> PUPD15 {};
	};

	struct IDR {
		DECL_REGISTER(GPIOA_IDR_BASE);
		constexpr static RegisterField<GPIOA_IDR_ID0> ID0 {};
		constexpr static RegisterField<GPIOA_IDR_ID1> ID1 {};
		constexpr static RegisterField<GPIOA_IDR_ID2> ID2 {};
		constexpr static RegisterField<GPIOA_IDR_ID3> ID3 {};
		constexpr static RegisterField<GPIOA_IDR_ID4> ID4 {};
		constexpr static RegisterField<GPIOA_IDR_ID5> ID5 {};
		constexpr static RegisterField<GPIOA_IDR_ID6> ID6 {};
		constexpr static RegisterField<GPIOA_IDR_ID7> ID7 {};
		constexpr static RegisterField<GPIOA_IDR_ID8> ID8 {};
		constexpr static RegisterField<GPIOA_IDR_ID9> ID9 {};
		constexpr static RegisterField<GPIOA_IDR_ID10> ID10 {};
		constexpr static RegisterField<GPIOA_IDR_ID11> ID11 {};
		constexpr static RegisterField<GPIOA_IDR_ID12> ID12 {};
		constexpr static RegisterField<GPIOA_IDR_ID13> ID13 {};
		constexpr static RegisterField<GPIOA_IDR_ID14> ID14 {};
		constexpr static RegisterField<GPIOA_IDR_ID15> ID15 {};
	};

	struct ODR {
		DECL_REGISTER(GPIOA_ODR_BASE);
		constexpr static RegisterField<GPIOA_ODR_OD0> OD0 {};
		constexpr static RegisterField<GPIOA_ODR_OD1> OD1 {};
		constexpr static RegisterField<GPIOA_ODR_OD2> OD2 {};
		constexpr static RegisterField<GPIOA_ODR_OD3> OD3 {};
		constexpr static RegisterField<GPIOA_ODR_OD4> OD4 {};
		constexpr static RegisterField<GPIOA_ODR_OD5> OD5 {};
		constexpr static RegisterField<GPIOA_ODR_OD6> OD6 {};
		constexpr static RegisterField<GPIOA_ODR_OD7> OD7 {};
		constexpr static RegisterField<GPIOA_ODR_OD8> OD8 {};
		constexpr static RegisterField<GPIOA_ODR_OD9> OD9 {};
		constexpr static RegisterField<GPIOA_ODR_OD10> OD10 {};
		constexpr static RegisterField<GPIOA_ODR_OD11> OD11 {};
		constexpr static RegisterField<GPIOA_ODR_OD12> OD12 {};
		constexpr static RegisterField<GPIOA_ODR_OD13> OD13 {};
		constexpr static RegisterField<GPIOA_ODR_OD14> OD14 {};
		constexpr static RegisterField<GPIOA_ODR_OD15> OD15 {};
	};

	struct BSRR {
		DECL_REGISTER(GPIOA_BSRR_BASE);
		constexpr static RegisterField<GPIOA_BSRR_BS0> BS0 {};
		constexpr static RegisterField<GPIOA_BSRR_BS1> BS1 {};
		constexpr static RegisterField<GPIOA_BSRR_BS2> BS2 {};
		constexpr static RegisterField<GPIOA_BSRR_BS3> BS3 {};
		constexpr static RegisterField<GPIOA_BSRR_BS4> BS4 {};
		constexpr static RegisterField<GPIOA_BSRR_BS5> BS5 {};
		constexpr static RegisterField<GPIOA_BSRR_BS6> BS6 {};
		constexpr static RegisterField<GPIOA_BSRR_BS7> BS7 {};
		constexpr static RegisterField<GPIOA_BSRR_BS8> BS8 {};
		constexpr static RegisterField<GPIOA_BSRR_BS9> BS9 {};
		constexpr static RegisterField<GPIOA_BSRR_BS10> BS10 {};
		constexpr static RegisterField<GPIOA_BSRR_BS11> BS11 {};
		constexpr static RegisterField<GPIOA_BSRR_BS12> BS12 {};
		constexpr static RegisterField<GPIOA_BSRR_BS13> BS13 {};
		constexpr static RegisterField<GPIOA_BSRR_BS14> BS14 {};
		constexpr static RegisterField<GPIOA_BSRR_BS15> BS15 {};
		constexpr static RegisterField<GPIOA_BSRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOA_BSRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOA_BSRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOA_BSRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOA_BSRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOA_BSRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOA_BSRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOA_BSRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOA_BSRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOA_BSRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOA_BSRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOA_BSRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOA_BSRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOA_BSRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOA_BSRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOA_BSRR_BR15> BR15 {};
	};

	struct LCKR {
		DECL_REGISTER(GPIOA_LCKR_BASE);
		constexpr static RegisterField<GPIOA_LCKR_LCK0> LCK0 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK1> LCK1 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK2> LCK2 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK3> LCK3 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK4> LCK4 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK5> LCK5 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK6> LCK6 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK7> LCK7 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK8> LCK8 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK9> LCK9 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK10> LCK10 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK11> LCK11 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK12> LCK12 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK13> LCK13 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK14> LCK14 {};
		constexpr static RegisterField<GPIOA_LCKR_LCK15> LCK15 {};
		constexpr static RegisterField<GPIOA_LCKR_LCKK> LCKK {};
	};

	struct AFRL {
		DECL_REGISTER(GPIOA_AFRL_BASE);
		constexpr static RegisterField<GPIOA_AFRL_AFSEL0> AFSEL0 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL1> AFSEL1 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL2> AFSEL2 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL3> AFSEL3 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL4> AFSEL4 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL5> AFSEL5 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL6> AFSEL6 {};
		constexpr static RegisterField<GPIOA_AFRL_AFSEL7> AFSEL7 {};
	};

	struct AFRH {
		DECL_REGISTER(GPIOA_AFRH_BASE);
		constexpr static RegisterField<GPIOA_AFRH_AFSEL8> AFSEL8 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL9> AFSEL9 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL10> AFSEL10 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL11> AFSEL11 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL12> AFSEL12 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL13> AFSEL13 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL14> AFSEL14 {};
		constexpr static RegisterField<GPIOA_AFRH_AFSEL15> AFSEL15 {};
	};

	struct BRR {
		DECL_REGISTER(GPIOA_BRR_BASE);
		constexpr static RegisterField<GPIOA_BRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOA_BRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOA_BRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOA_BRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOA_BRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOA_BRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOA_BRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOA_BRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOA_BRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOA_BRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOA_BRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOA_BRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOA_BRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOA_BRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOA_BRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOA_BRR_BR15> BR15 {};
	};

};

struct GPIOB {
	struct MODER {
		DECL_REGISTER(GPIOB_MODER_BASE);
		constexpr static RegisterField<GPIOB_MODER_MODE0> MODE0 {};
		constexpr static RegisterField<GPIOB_MODER_MODE1> MODE1 {};
		constexpr static RegisterField<GPIOB_MODER_MODE2> MODE2 {};
		constexpr static RegisterField<GPIOB_MODER_MODE3> MODE3 {};
		constexpr static RegisterField<GPIOB_MODER_MODE4> MODE4 {};
		constexpr static RegisterField<GPIOB_MODER_MODE5> MODE5 {};
		constexpr static RegisterField<GPIOB_MODER_MODE6> MODE6 {};
		constexpr static RegisterField<GPIOB_MODER_MODE7> MODE7 {};
		constexpr static RegisterField<GPIOB_MODER_MODE8> MODE8 {};
		constexpr static RegisterField<GPIOB_MODER_MODE9> MODE9 {};
		constexpr static RegisterField<GPIOB_MODER_MODE10> MODE10 {};
		constexpr static RegisterField<GPIOB_MODER_MODE11> MODE11 {};
		constexpr static RegisterField<GPIOB_MODER_MODE12> MODE12 {};
		constexpr static RegisterField<GPIOB_MODER_MODE13> MODE13 {};
		constexpr static RegisterField<GPIOB_MODER_MODE14> MODE14 {};
		constexpr static RegisterField<GPIOB_MODER_MODE15> MODE15 {};
	};

	struct OTYPER {
		DECL_REGISTER(GPIOB_OTYPER_BASE);
		constexpr static RegisterField<GPIOB_OTYPER_OT0> OT0 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT1> OT1 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT2> OT2 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT3> OT3 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT4> OT4 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT5> OT5 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT6> OT6 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT7> OT7 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT8> OT8 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT9> OT9 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT10> OT10 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT11> OT11 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT12> OT12 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT13> OT13 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT14> OT14 {};
		constexpr static RegisterField<GPIOB_OTYPER_OT15> OT15 {};
	};

	struct OSPEEDR {
		DECL_REGISTER(GPIOB_OSPEEDR_BASE);
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED0> OSPEED0 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED1> OSPEED1 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED2> OSPEED2 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED3> OSPEED3 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED4> OSPEED4 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED5> OSPEED5 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED6> OSPEED6 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED7> OSPEED7 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED8> OSPEED8 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED9> OSPEED9 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED10> OSPEED10 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED11> OSPEED11 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED12> OSPEED12 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED13> OSPEED13 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED14> OSPEED14 {};
		constexpr static RegisterField<GPIOB_OSPEEDR_OSPEED15> OSPEED15 {};
	};

	struct PUPDR {
		DECL_REGISTER(GPIOB_PUPDR_BASE);
		constexpr static RegisterField<GPIOB_PUPDR_PUPD0> PUPD0 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD1> PUPD1 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD2> PUPD2 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD3> PUPD3 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD4> PUPD4 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD5> PUPD5 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD6> PUPD6 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD7> PUPD7 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD8> PUPD8 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD9> PUPD9 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD10> PUPD10 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD11> PUPD11 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD12> PUPD12 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD13> PUPD13 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD14> PUPD14 {};
		constexpr static RegisterField<GPIOB_PUPDR_PUPD15> PUPD15 {};
	};

	struct IDR {
		DECL_REGISTER(GPIOB_IDR_BASE);
		constexpr static RegisterField<GPIOB_IDR_ID0> ID0 {};
		constexpr static RegisterField<GPIOB_IDR_ID1> ID1 {};
		constexpr static RegisterField<GPIOB_IDR_ID2> ID2 {};
		constexpr static RegisterField<GPIOB_IDR_ID3> ID3 {};
		constexpr static RegisterField<GPIOB_IDR_ID4> ID4 {};
		constexpr static RegisterField<GPIOB_IDR_ID5> ID5 {};
		constexpr static RegisterField<GPIOB_IDR_ID6> ID6 {};
		constexpr static RegisterField<GPIOB_IDR_ID7> ID7 {};
		constexpr static RegisterField<GPIOB_IDR_ID8> ID8 {};
		constexpr static RegisterField<GPIOB_IDR_ID9> ID9 {};
		constexpr static RegisterField<GPIOB_IDR_ID10> ID10 {};
		constexpr static RegisterField<GPIOB_IDR_ID11> ID11 {};
		constexpr static RegisterField<GPIOB_IDR_ID12> ID12 {};
		constexpr static RegisterField<GPIOB_IDR_ID13> ID13 {};
		constexpr static RegisterField<GPIOB_IDR_ID14> ID14 {};
		constexpr static RegisterField<GPIOB_IDR_ID15> ID15 {};
	};

	struct ODR {
		DECL_REGISTER(GPIOB_ODR_BASE);
		constexpr static RegisterField<GPIOB_ODR_OD0> OD0 {};
		constexpr static RegisterField<GPIOB_ODR_OD1> OD1 {};
		constexpr static RegisterField<GPIOB_ODR_OD2> OD2 {};
		constexpr static RegisterField<GPIOB_ODR_OD3> OD3 {};
		constexpr static RegisterField<GPIOB_ODR_OD4> OD4 {};
		constexpr static RegisterField<GPIOB_ODR_OD5> OD5 {};
		constexpr static RegisterField<GPIOB_ODR_OD6> OD6 {};
		constexpr static RegisterField<GPIOB_ODR_OD7> OD7 {};
		constexpr static RegisterField<GPIOB_ODR_OD8> OD8 {};
		constexpr static RegisterField<GPIOB_ODR_OD9> OD9 {};
		constexpr static RegisterField<GPIOB_ODR_OD10> OD10 {};
		constexpr static RegisterField<GPIOB_ODR_OD11> OD11 {};
		constexpr static RegisterField<GPIOB_ODR_OD12> OD12 {};
		constexpr static RegisterField<GPIOB_ODR_OD13> OD13 {};
		constexpr static RegisterField<GPIOB_ODR_OD14> OD14 {};
		constexpr static RegisterField<GPIOB_ODR_OD15> OD15 {};
	};

	struct BSRR {
		DECL_REGISTER(GPIOB_BSRR_BASE);
		constexpr static RegisterField<GPIOB_BSRR_BS0> BS0 {};
		constexpr static RegisterField<GPIOB_BSRR_BS1> BS1 {};
		constexpr static RegisterField<GPIOB_BSRR_BS2> BS2 {};
		constexpr static RegisterField<GPIOB_BSRR_BS3> BS3 {};
		constexpr static RegisterField<GPIOB_BSRR_BS4> BS4 {};
		constexpr static RegisterField<GPIOB_BSRR_BS5> BS5 {};
		constexpr static RegisterField<GPIOB_BSRR_BS6> BS6 {};
		constexpr static RegisterField<GPIOB_BSRR_BS7> BS7 {};
		constexpr static RegisterField<GPIOB_BSRR_BS8> BS8 {};
		constexpr static RegisterField<GPIOB_BSRR_BS9> BS9 {};
		constexpr static RegisterField<GPIOB_BSRR_BS10> BS10 {};
		constexpr static RegisterField<GPIOB_BSRR_BS11> BS11 {};
		constexpr static RegisterField<GPIOB_BSRR_BS12> BS12 {};
		constexpr static RegisterField<GPIOB_BSRR_BS13> BS13 {};
		constexpr static RegisterField<GPIOB_BSRR_BS14> BS14 {};
		constexpr static RegisterField<GPIOB_BSRR_BS15> BS15 {};
		constexpr static RegisterField<GPIOB_BSRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOB_BSRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOB_BSRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOB_BSRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOB_BSRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOB_BSRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOB_BSRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOB_BSRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOB_BSRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOB_BSRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOB_BSRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOB_BSRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOB_BSRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOB_BSRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOB_BSRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOB_BSRR_BR15> BR15 {};
	};

	struct LCKR {
		DECL_REGISTER(GPIOB_LCKR_BASE);
		constexpr static RegisterField<GPIOB_LCKR_LCK0> LCK0 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK1> LCK1 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK2> LCK2 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK3> LCK3 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK4> LCK4 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK5> LCK5 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK6> LCK6 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK7> LCK7 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK8> LCK8 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK9> LCK9 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK10> LCK10 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK11> LCK11 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK12> LCK12 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK13> LCK13 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK14> LCK14 {};
		constexpr static RegisterField<GPIOB_LCKR_LCK15> LCK15 {};
		constexpr static RegisterField<GPIOB_LCKR_LCKK> LCKK {};
	};

	struct AFRL {
		DECL_REGISTER(GPIOB_AFRL_BASE);
		constexpr static RegisterField<GPIOB_AFRL_AFSEL0> AFSEL0 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL1> AFSEL1 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL2> AFSEL2 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL3> AFSEL3 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL4> AFSEL4 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL5> AFSEL5 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL6> AFSEL6 {};
		constexpr static RegisterField<GPIOB_AFRL_AFSEL7> AFSEL7 {};
	};

	struct AFRH {
		DECL_REGISTER(GPIOB_AFRH_BASE);
		constexpr static RegisterField<GPIOB_AFRH_AFSEL8> AFSEL8 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL9> AFSEL9 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL10> AFSEL10 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL11> AFSEL11 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL12> AFSEL12 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL13> AFSEL13 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL14> AFSEL14 {};
		constexpr static RegisterField<GPIOB_AFRH_AFSEL15> AFSEL15 {};
	};

	struct BRR {
		DECL_REGISTER(GPIOB_BRR_BASE);
		constexpr static RegisterField<GPIOB_BRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOB_BRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOB_BRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOB_BRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOB_BRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOB_BRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOB_BRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOB_BRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOB_BRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOB_BRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOB_BRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOB_BRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOB_BRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOB_BRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOB_BRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOB_BRR_BR15> BR15 {};
	};

};

struct GPIOC {
	struct MODER {
		DECL_REGISTER(GPIOC_MODER_BASE);
		constexpr static RegisterField<GPIOC_MODER_MODE0> MODE0 {};
		constexpr static RegisterField<GPIOC_MODER_MODE1> MODE1 {};
		constexpr static RegisterField<GPIOC_MODER_MODE2> MODE2 {};
		constexpr static RegisterField<GPIOC_MODER_MODE3> MODE3 {};
		constexpr static RegisterField<GPIOC_MODER_MODE4> MODE4 {};
		constexpr static RegisterField<GPIOC_MODER_MODE5> MODE5 {};
		constexpr static RegisterField<GPIOC_MODER_MODE6> MODE6 {};
		constexpr static RegisterField<GPIOC_MODER_MODE7> MODE7 {};
		constexpr static RegisterField<GPIOC_MODER_MODE8> MODE8 {};
		constexpr static RegisterField<GPIOC_MODER_MODE9> MODE9 {};
		constexpr static RegisterField<GPIOC_MODER_MODE10> MODE10 {};
		constexpr static RegisterField<GPIOC_MODER_MODE11> MODE11 {};
		constexpr static RegisterField<GPIOC_MODER_MODE12> MODE12 {};
		constexpr static RegisterField<GPIOC_MODER_MODE13> MODE13 {};
		constexpr static RegisterField<GPIOC_MODER_MODE14> MODE14 {};
		constexpr static RegisterField<GPIOC_MODER_MODE15> MODE15 {};
	};

	struct OTYPER {
		DECL_REGISTER(GPIOC_OTYPER_BASE);
		constexpr static RegisterField<GPIOC_OTYPER_OT0> OT0 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT1> OT1 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT2> OT2 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT3> OT3 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT4> OT4 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT5> OT5 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT6> OT6 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT7> OT7 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT8> OT8 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT9> OT9 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT10> OT10 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT11> OT11 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT12> OT12 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT13> OT13 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT14> OT14 {};
		constexpr static RegisterField<GPIOC_OTYPER_OT15> OT15 {};
	};

	struct OSPEEDR {
		DECL_REGISTER(GPIOC_OSPEEDR_BASE);
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED0> OSPEED0 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED1> OSPEED1 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED2> OSPEED2 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED3> OSPEED3 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED4> OSPEED4 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED5> OSPEED5 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED6> OSPEED6 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED7> OSPEED7 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED8> OSPEED8 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED9> OSPEED9 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED10> OSPEED10 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED11> OSPEED11 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED12> OSPEED12 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED13> OSPEED13 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED14> OSPEED14 {};
		constexpr static RegisterField<GPIOC_OSPEEDR_OSPEED15> OSPEED15 {};
	};

	struct PUPDR {
		DECL_REGISTER(GPIOC_PUPDR_BASE);
		constexpr static RegisterField<GPIOC_PUPDR_PUPD0> PUPD0 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD1> PUPD1 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD2> PUPD2 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD3> PUPD3 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD4> PUPD4 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD5> PUPD5 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD6> PUPD6 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD7> PUPD7 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD8> PUPD8 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD9> PUPD9 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD10> PUPD10 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD11> PUPD11 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD12> PUPD12 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD13> PUPD13 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD14> PUPD14 {};
		constexpr static RegisterField<GPIOC_PUPDR_PUPD15> PUPD15 {};
	};

	struct IDR {
		DECL_REGISTER(GPIOC_IDR_BASE);
		constexpr static RegisterField<GPIOC_IDR_ID0> ID0 {};
		constexpr static RegisterField<GPIOC_IDR_ID1> ID1 {};
		constexpr static RegisterField<GPIOC_IDR_ID2> ID2 {};
		constexpr static RegisterField<GPIOC_IDR_ID3> ID3 {};
		constexpr static RegisterField<GPIOC_IDR_ID4> ID4 {};
		constexpr static RegisterField<GPIOC_IDR_ID5> ID5 {};
		constexpr static RegisterField<GPIOC_IDR_ID6> ID6 {};
		constexpr static RegisterField<GPIOC_IDR_ID7> ID7 {};
		constexpr static RegisterField<GPIOC_IDR_ID8> ID8 {};
		constexpr static RegisterField<GPIOC_IDR_ID9> ID9 {};
		constexpr static RegisterField<GPIOC_IDR_ID10> ID10 {};
		constexpr static RegisterField<GPIOC_IDR_ID11> ID11 {};
		constexpr static RegisterField<GPIOC_IDR_ID12> ID12 {};
		constexpr static RegisterField<GPIOC_IDR_ID13> ID13 {};
		constexpr static RegisterField<GPIOC_IDR_ID14> ID14 {};
		constexpr static RegisterField<GPIOC_IDR_ID15> ID15 {};
	};

	struct ODR {
		DECL_REGISTER(GPIOC_ODR_BASE);
		constexpr static RegisterField<GPIOC_ODR_OD0> OD0 {};
		constexpr static RegisterField<GPIOC_ODR_OD1> OD1 {};
		constexpr static RegisterField<GPIOC_ODR_OD2> OD2 {};
		constexpr static RegisterField<GPIOC_ODR_OD3> OD3 {};
		constexpr static RegisterField<GPIOC_ODR_OD4> OD4 {};
		constexpr static RegisterField<GPIOC_ODR_OD5> OD5 {};
		constexpr static RegisterField<GPIOC_ODR_OD6> OD6 {};
		constexpr static RegisterField<GPIOC_ODR_OD7> OD7 {};
		constexpr static RegisterField<GPIOC_ODR_OD8> OD8 {};
		constexpr static RegisterField<GPIOC_ODR_OD9> OD9 {};
		constexpr static RegisterField<GPIOC_ODR_OD10> OD10 {};
		constexpr static RegisterField<GPIOC_ODR_OD11> OD11 {};
		constexpr static RegisterField<GPIOC_ODR_OD12> OD12 {};
		constexpr static RegisterField<GPIOC_ODR_OD13> OD13 {};
		constexpr static RegisterField<GPIOC_ODR_OD14> OD14 {};
		constexpr static RegisterField<GPIOC_ODR_OD15> OD15 {};
	};

	struct BSRR {
		DECL_REGISTER(GPIOC_BSRR_BASE);
		constexpr static RegisterField<GPIOC_BSRR_BS0> BS0 {};
		constexpr static RegisterField<GPIOC_BSRR_BS1> BS1 {};
		constexpr static RegisterField<GPIOC_BSRR_BS2> BS2 {};
		constexpr static RegisterField<GPIOC_BSRR_BS3> BS3 {};
		constexpr static RegisterField<GPIOC_BSRR_BS4> BS4 {};
		constexpr static RegisterField<GPIOC_BSRR_BS5> BS5 {};
		constexpr static RegisterField<GPIOC_BSRR_BS6> BS6 {};
		constexpr static RegisterField<GPIOC_BSRR_BS7> BS7 {};
		constexpr static RegisterField<GPIOC_BSRR_BS8> BS8 {};
		constexpr static RegisterField<GPIOC_BSRR_BS9> BS9 {};
		constexpr static RegisterField<GPIOC_BSRR_BS10> BS10 {};
		constexpr static RegisterField<GPIOC_BSRR_BS11> BS11 {};
		constexpr static RegisterField<GPIOC_BSRR_BS12> BS12 {};
		constexpr static RegisterField<GPIOC_BSRR_BS13> BS13 {};
		constexpr static RegisterField<GPIOC_BSRR_BS14> BS14 {};
		constexpr static RegisterField<GPIOC_BSRR_BS15> BS15 {};
		constexpr static RegisterField<GPIOC_BSRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOC_BSRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOC_BSRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOC_BSRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOC_BSRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOC_BSRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOC_BSRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOC_BSRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOC_BSRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOC_BSRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOC_BSRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOC_BSRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOC_BSRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOC_BSRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOC_BSRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOC_BSRR_BR15> BR15 {};
	};

	struct LCKR {
		DECL_REGISTER(GPIOC_LCKR_BASE);
		constexpr static RegisterField<GPIOC_LCKR_LCK0> LCK0 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK1> LCK1 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK2> LCK2 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK3> LCK3 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK4> LCK4 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK5> LCK5 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK6> LCK6 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK7> LCK7 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK8> LCK8 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK9> LCK9 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK10> LCK10 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK11> LCK11 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK12> LCK12 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK13> LCK13 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK14> LCK14 {};
		constexpr static RegisterField<GPIOC_LCKR_LCK15> LCK15 {};
		constexpr static RegisterField<GPIOC_LCKR_LCKK> LCKK {};
	};

	struct AFRL {
		DECL_REGISTER(GPIOC_AFRL_BASE);
		constexpr static RegisterField<GPIOC_AFRL_AFSEL0> AFSEL0 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL1> AFSEL1 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL2> AFSEL2 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL3> AFSEL3 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL4> AFSEL4 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL5> AFSEL5 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL6> AFSEL6 {};
		constexpr static RegisterField<GPIOC_AFRL_AFSEL7> AFSEL7 {};
	};

	struct AFRH {
		DECL_REGISTER(GPIOC_AFRH_BASE);
		constexpr static RegisterField<GPIOC_AFRH_AFSEL8> AFSEL8 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL9> AFSEL9 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL10> AFSEL10 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL11> AFSEL11 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL12> AFSEL12 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL13> AFSEL13 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL14> AFSEL14 {};
		constexpr static RegisterField<GPIOC_AFRH_AFSEL15> AFSEL15 {};
	};

	struct BRR {
		DECL_REGISTER(GPIOC_BRR_BASE);
		constexpr static RegisterField<GPIOC_BRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOC_BRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOC_BRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOC_BRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOC_BRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOC_BRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOC_BRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOC_BRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOC_BRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOC_BRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOC_BRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOC_BRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOC_BRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOC_BRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOC_BRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOC_BRR_BR15> BR15 {};
	};

};

struct GPIOD {
	struct MODER {
		DECL_REGISTER(GPIOD_MODER_BASE);
		constexpr static RegisterField<GPIOD_MODER_MODE0> MODE0 {};
		constexpr static RegisterField<GPIOD_MODER_MODE1> MODE1 {};
		constexpr static RegisterField<GPIOD_MODER_MODE2> MODE2 {};
		constexpr static RegisterField<GPIOD_MODER_MODE3> MODE3 {};
		constexpr static RegisterField<GPIOD_MODER_MODE4> MODE4 {};
		constexpr static RegisterField<GPIOD_MODER_MODE5> MODE5 {};
		constexpr static RegisterField<GPIOD_MODER_MODE6> MODE6 {};
		constexpr static RegisterField<GPIOD_MODER_MODE7> MODE7 {};
		constexpr static RegisterField<GPIOD_MODER_MODE8> MODE8 {};
		constexpr static RegisterField<GPIOD_MODER_MODE9> MODE9 {};
		constexpr static RegisterField<GPIOD_MODER_MODE10> MODE10 {};
		constexpr static RegisterField<GPIOD_MODER_MODE11> MODE11 {};
		constexpr static RegisterField<GPIOD_MODER_MODE12> MODE12 {};
		constexpr static RegisterField<GPIOD_MODER_MODE13> MODE13 {};
		constexpr static RegisterField<GPIOD_MODER_MODE14> MODE14 {};
		constexpr static RegisterField<GPIOD_MODER_MODE15> MODE15 {};
	};

	struct OTYPER {
		DECL_REGISTER(GPIOD_OTYPER_BASE);
		constexpr static RegisterField<GPIOD_OTYPER_OT0> OT0 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT1> OT1 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT2> OT2 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT3> OT3 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT4> OT4 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT5> OT5 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT6> OT6 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT7> OT7 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT8> OT8 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT9> OT9 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT10> OT10 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT11> OT11 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT12> OT12 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT13> OT13 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT14> OT14 {};
		constexpr static RegisterField<GPIOD_OTYPER_OT15> OT15 {};
	};

	struct OSPEEDR {
		DECL_REGISTER(GPIOD_OSPEEDR_BASE);
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED0> OSPEED0 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED1> OSPEED1 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED2> OSPEED2 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED3> OSPEED3 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED4> OSPEED4 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED5> OSPEED5 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED6> OSPEED6 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED7> OSPEED7 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED8> OSPEED8 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED9> OSPEED9 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED10> OSPEED10 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED11> OSPEED11 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED12> OSPEED12 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED13> OSPEED13 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED14> OSPEED14 {};
		constexpr static RegisterField<GPIOD_OSPEEDR_OSPEED15> OSPEED15 {};
	};

	struct PUPDR {
		DECL_REGISTER(GPIOD_PUPDR_BASE);
		constexpr static RegisterField<GPIOD_PUPDR_PUPD0> PUPD0 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD1> PUPD1 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD2> PUPD2 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD3> PUPD3 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD4> PUPD4 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD5> PUPD5 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD6> PUPD6 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD7> PUPD7 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD8> PUPD8 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD9> PUPD9 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD10> PUPD10 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD11> PUPD11 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD12> PUPD12 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD13> PUPD13 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD14> PUPD14 {};
		constexpr static RegisterField<GPIOD_PUPDR_PUPD15> PUPD15 {};
	};

	struct IDR {
		DECL_REGISTER(GPIOD_IDR_BASE);
		constexpr static RegisterField<GPIOD_IDR_ID0> ID0 {};
		constexpr static RegisterField<GPIOD_IDR_ID1> ID1 {};
		constexpr static RegisterField<GPIOD_IDR_ID2> ID2 {};
		constexpr static RegisterField<GPIOD_IDR_ID3> ID3 {};
		constexpr static RegisterField<GPIOD_IDR_ID4> ID4 {};
		constexpr static RegisterField<GPIOD_IDR_ID5> ID5 {};
		constexpr static RegisterField<GPIOD_IDR_ID6> ID6 {};
		constexpr static RegisterField<GPIOD_IDR_ID7> ID7 {};
		constexpr static RegisterField<GPIOD_IDR_ID8> ID8 {};
		constexpr static RegisterField<GPIOD_IDR_ID9> ID9 {};
		constexpr static RegisterField<GPIOD_IDR_ID10> ID10 {};
		constexpr static RegisterField<GPIOD_IDR_ID11> ID11 {};
		constexpr static RegisterField<GPIOD_IDR_ID12> ID12 {};
		constexpr static RegisterField<GPIOD_IDR_ID13> ID13 {};
		constexpr static RegisterField<GPIOD_IDR_ID14> ID14 {};
		constexpr static RegisterField<GPIOD_IDR_ID15> ID15 {};
	};

	struct ODR {
		DECL_REGISTER(GPIOD_ODR_BASE);
		constexpr static RegisterField<GPIOD_ODR_OD0> OD0 {};
		constexpr static RegisterField<GPIOD_ODR_OD1> OD1 {};
		constexpr static RegisterField<GPIOD_ODR_OD2> OD2 {};
		constexpr static RegisterField<GPIOD_ODR_OD3> OD3 {};
		constexpr static RegisterField<GPIOD_ODR_OD4> OD4 {};
		constexpr static RegisterField<GPIOD_ODR_OD5> OD5 {};
		constexpr static RegisterField<GPIOD_ODR_OD6> OD6 {};
		constexpr static RegisterField<GPIOD_ODR_OD7> OD7 {};
		constexpr static RegisterField<GPIOD_ODR_OD8> OD8 {};
		constexpr static RegisterField<GPIOD_ODR_OD9> OD9 {};
		constexpr static RegisterField<GPIOD_ODR_OD10> OD10 {};
		constexpr static RegisterField<GPIOD_ODR_OD11> OD11 {};
		constexpr static RegisterField<GPIOD_ODR_OD12> OD12 {};
		constexpr static RegisterField<GPIOD_ODR_OD13> OD13 {};
		constexpr static RegisterField<GPIOD_ODR_OD14> OD14 {};
		constexpr static RegisterField<GPIOD_ODR_OD15> OD15 {};
	};

	struct BSRR {
		DECL_REGISTER(GPIOD_BSRR_BASE);
		constexpr static RegisterField<GPIOD_BSRR_BS0> BS0 {};
		constexpr static RegisterField<GPIOD_BSRR_BS1> BS1 {};
		constexpr static RegisterField<GPIOD_BSRR_BS2> BS2 {};
		constexpr static RegisterField<GPIOD_BSRR_BS3> BS3 {};
		constexpr static RegisterField<GPIOD_BSRR_BS4> BS4 {};
		constexpr static RegisterField<GPIOD_BSRR_BS5> BS5 {};
		constexpr static RegisterField<GPIOD_BSRR_BS6> BS6 {};
		constexpr static RegisterField<GPIOD_BSRR_BS7> BS7 {};
		constexpr static RegisterField<GPIOD_BSRR_BS8> BS8 {};
		constexpr static RegisterField<GPIOD_BSRR_BS9> BS9 {};
		constexpr static RegisterField<GPIOD_BSRR_BS10> BS10 {};
		constexpr static RegisterField<GPIOD_BSRR_BS11> BS11 {};
		constexpr static RegisterField<GPIOD_BSRR_BS12> BS12 {};
		constexpr static RegisterField<GPIOD_BSRR_BS13> BS13 {};
		constexpr static RegisterField<GPIOD_BSRR_BS14> BS14 {};
		constexpr static RegisterField<GPIOD_BSRR_BS15> BS15 {};
		constexpr static RegisterField<GPIOD_BSRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOD_BSRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOD_BSRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOD_BSRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOD_BSRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOD_BSRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOD_BSRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOD_BSRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOD_BSRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOD_BSRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOD_BSRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOD_BSRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOD_BSRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOD_BSRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOD_BSRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOD_BSRR_BR15> BR15 {};
	};

	struct LCKR {
		DECL_REGISTER(GPIOD_LCKR_BASE);
		constexpr static RegisterField<GPIOD_LCKR_LCK0> LCK0 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK1> LCK1 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK2> LCK2 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK3> LCK3 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK4> LCK4 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK5> LCK5 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK6> LCK6 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK7> LCK7 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK8> LCK8 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK9> LCK9 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK10> LCK10 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK11> LCK11 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK12> LCK12 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK13> LCK13 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK14> LCK14 {};
		constexpr static RegisterField<GPIOD_LCKR_LCK15> LCK15 {};
		constexpr static RegisterField<GPIOD_LCKR_LCKK> LCKK {};
	};

	struct AFRL {
		DECL_REGISTER(GPIOD_AFRL_BASE);
		constexpr static RegisterField<GPIOD_AFRL_AFSEL0> AFSEL0 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL1> AFSEL1 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL2> AFSEL2 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL3> AFSEL3 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL4> AFSEL4 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL5> AFSEL5 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL6> AFSEL6 {};
		constexpr static RegisterField<GPIOD_AFRL_AFSEL7> AFSEL7 {};
	};

	struct AFRH {
		DECL_REGISTER(GPIOD_AFRH_BASE);
		constexpr static RegisterField<GPIOD_AFRH_AFSEL8> AFSEL8 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL9> AFSEL9 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL10> AFSEL10 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL11> AFSEL11 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL12> AFSEL12 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL13> AFSEL13 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL14> AFSEL14 {};
		constexpr static RegisterField<GPIOD_AFRH_AFSEL15> AFSEL15 {};
	};

	struct BRR {
		DECL_REGISTER(GPIOD_BRR_BASE);
		constexpr static RegisterField<GPIOD_BRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOD_BRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOD_BRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOD_BRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOD_BRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOD_BRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOD_BRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOD_BRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOD_BRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOD_BRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOD_BRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOD_BRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOD_BRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOD_BRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOD_BRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOD_BRR_BR15> BR15 {};
	};

};

struct GPIOE {
	struct MODER {
		DECL_REGISTER(GPIOE_MODER_BASE);
		constexpr static RegisterField<GPIOE_MODER_MODE0> MODE0 {};
		constexpr static RegisterField<GPIOE_MODER_MODE1> MODE1 {};
		constexpr static RegisterField<GPIOE_MODER_MODE2> MODE2 {};
		constexpr static RegisterField<GPIOE_MODER_MODE3> MODE3 {};
		constexpr static RegisterField<GPIOE_MODER_MODE4> MODE4 {};
		constexpr static RegisterField<GPIOE_MODER_MODE5> MODE5 {};
		constexpr static RegisterField<GPIOE_MODER_MODE6> MODE6 {};
		constexpr static RegisterField<GPIOE_MODER_MODE7> MODE7 {};
		constexpr static RegisterField<GPIOE_MODER_MODE8> MODE8 {};
		constexpr static RegisterField<GPIOE_MODER_MODE9> MODE9 {};
		constexpr static RegisterField<GPIOE_MODER_MODE10> MODE10 {};
		constexpr static RegisterField<GPIOE_MODER_MODE11> MODE11 {};
		constexpr static RegisterField<GPIOE_MODER_MODE12> MODE12 {};
		constexpr static RegisterField<GPIOE_MODER_MODE13> MODE13 {};
		constexpr static RegisterField<GPIOE_MODER_MODE14> MODE14 {};
		constexpr static RegisterField<GPIOE_MODER_MODE15> MODE15 {};
	};

	struct OTYPER {
		DECL_REGISTER(GPIOE_OTYPER_BASE);
		constexpr static RegisterField<GPIOE_OTYPER_OT0> OT0 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT1> OT1 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT2> OT2 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT3> OT3 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT4> OT4 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT5> OT5 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT6> OT6 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT7> OT7 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT8> OT8 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT9> OT9 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT10> OT10 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT11> OT11 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT12> OT12 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT13> OT13 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT14> OT14 {};
		constexpr static RegisterField<GPIOE_OTYPER_OT15> OT15 {};
	};

	struct OSPEEDR {
		DECL_REGISTER(GPIOE_OSPEEDR_BASE);
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED0> OSPEED0 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED1> OSPEED1 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED2> OSPEED2 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED3> OSPEED3 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED4> OSPEED4 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED5> OSPEED5 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED6> OSPEED6 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED7> OSPEED7 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED8> OSPEED8 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED9> OSPEED9 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED10> OSPEED10 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED11> OSPEED11 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED12> OSPEED12 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED13> OSPEED13 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED14> OSPEED14 {};
		constexpr static RegisterField<GPIOE_OSPEEDR_OSPEED15> OSPEED15 {};
	};

	struct PUPDR {
		DECL_REGISTER(GPIOE_PUPDR_BASE);
		constexpr static RegisterField<GPIOE_PUPDR_PUPD0> PUPD0 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD1> PUPD1 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD2> PUPD2 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD3> PUPD3 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD4> PUPD4 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD5> PUPD5 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD6> PUPD6 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD7> PUPD7 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD8> PUPD8 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD9> PUPD9 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD10> PUPD10 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD11> PUPD11 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD12> PUPD12 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD13> PUPD13 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD14> PUPD14 {};
		constexpr static RegisterField<GPIOE_PUPDR_PUPD15> PUPD15 {};
	};

	struct IDR {
		DECL_REGISTER(GPIOE_IDR_BASE);
		constexpr static RegisterField<GPIOE_IDR_ID0> ID0 {};
		constexpr static RegisterField<GPIOE_IDR_ID1> ID1 {};
		constexpr static RegisterField<GPIOE_IDR_ID2> ID2 {};
		constexpr static RegisterField<GPIOE_IDR_ID3> ID3 {};
		constexpr static RegisterField<GPIOE_IDR_ID4> ID4 {};
		constexpr static RegisterField<GPIOE_IDR_ID5> ID5 {};
		constexpr static RegisterField<GPIOE_IDR_ID6> ID6 {};
		constexpr static RegisterField<GPIOE_IDR_ID7> ID7 {};
		constexpr static RegisterField<GPIOE_IDR_ID8> ID8 {};
		constexpr static RegisterField<GPIOE_IDR_ID9> ID9 {};
		constexpr static RegisterField<GPIOE_IDR_ID10> ID10 {};
		constexpr static RegisterField<GPIOE_IDR_ID11> ID11 {};
		constexpr static RegisterField<GPIOE_IDR_ID12> ID12 {};
		constexpr static RegisterField<GPIOE_IDR_ID13> ID13 {};
		constexpr static RegisterField<GPIOE_IDR_ID14> ID14 {};
		constexpr static RegisterField<GPIOE_IDR_ID15> ID15 {};
	};

	struct ODR {
		DECL_REGISTER(GPIOE_ODR_BASE);
		constexpr static RegisterField<GPIOE_ODR_OD0> OD0 {};
		constexpr static RegisterField<GPIOE_ODR_OD1> OD1 {};
		constexpr static RegisterField<GPIOE_ODR_OD2> OD2 {};
		constexpr static RegisterField<GPIOE_ODR_OD3> OD3 {};
		constexpr static RegisterField<GPIOE_ODR_OD4> OD4 {};
		constexpr static RegisterField<GPIOE_ODR_OD5> OD5 {};
		constexpr static RegisterField<GPIOE_ODR_OD6> OD6 {};
		constexpr static RegisterField<GPIOE_ODR_OD7> OD7 {};
		constexpr static RegisterField<GPIOE_ODR_OD8> OD8 {};
		constexpr static RegisterField<GPIOE_ODR_OD9> OD9 {};
		constexpr static RegisterField<GPIOE_ODR_OD10> OD10 {};
		constexpr static RegisterField<GPIOE_ODR_OD11> OD11 {};
		constexpr static RegisterField<GPIOE_ODR_OD12> OD12 {};
		constexpr static RegisterField<GPIOE_ODR_OD13> OD13 {};
		constexpr static RegisterField<GPIOE_ODR_OD14> OD14 {};
		constexpr static RegisterField<GPIOE_ODR_OD15> OD15 {};
	};

	struct BSRR {
		DECL_REGISTER(GPIOE_BSRR_BASE);
		constexpr static RegisterField<GPIOE_BSRR_BS0> BS0 {};
		constexpr static RegisterField<GPIOE_BSRR_BS1> BS1 {};
		constexpr static RegisterField<GPIOE_BSRR_BS2> BS2 {};
		constexpr static RegisterField<GPIOE_BSRR_BS3> BS3 {};
		constexpr static RegisterField<GPIOE_BSRR_BS4> BS4 {};
		constexpr static RegisterField<GPIOE_BSRR_BS5> BS5 {};
		constexpr static RegisterField<GPIOE_BSRR_BS6> BS6 {};
		constexpr static RegisterField<GPIOE_BSRR_BS7> BS7 {};
		constexpr static RegisterField<GPIOE_BSRR_BS8> BS8 {};
		constexpr static RegisterField<GPIOE_BSRR_BS9> BS9 {};
		constexpr static RegisterField<GPIOE_BSRR_BS10> BS10 {};
		constexpr static RegisterField<GPIOE_BSRR_BS11> BS11 {};
		constexpr static RegisterField<GPIOE_BSRR_BS12> BS12 {};
		constexpr static RegisterField<GPIOE_BSRR_BS13> BS13 {};
		constexpr static RegisterField<GPIOE_BSRR_BS14> BS14 {};
		constexpr static RegisterField<GPIOE_BSRR_BS15> BS15 {};
		constexpr static RegisterField<GPIOE_BSRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOE_BSRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOE_BSRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOE_BSRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOE_BSRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOE_BSRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOE_BSRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOE_BSRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOE_BSRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOE_BSRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOE_BSRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOE_BSRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOE_BSRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOE_BSRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOE_BSRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOE_BSRR_BR15> BR15 {};
	};

	struct LCKR {
		DECL_REGISTER(GPIOE_LCKR_BASE);
		constexpr static RegisterField<GPIOE_LCKR_LCK0> LCK0 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK1> LCK1 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK2> LCK2 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK3> LCK3 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK4> LCK4 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK5> LCK5 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK6> LCK6 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK7> LCK7 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK8> LCK8 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK9> LCK9 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK10> LCK10 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK11> LCK11 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK12> LCK12 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK13> LCK13 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK14> LCK14 {};
		constexpr static RegisterField<GPIOE_LCKR_LCK15> LCK15 {};
		constexpr static RegisterField<GPIOE_LCKR_LCKK> LCKK {};
	};

	struct AFRL {
		DECL_REGISTER(GPIOE_AFRL_BASE);
		constexpr static RegisterField<GPIOE_AFRL_AFSEL0> AFSEL0 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL1> AFSEL1 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL2> AFSEL2 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL3> AFSEL3 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL4> AFSEL4 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL5> AFSEL5 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL6> AFSEL6 {};
		constexpr static RegisterField<GPIOE_AFRL_AFSEL7> AFSEL7 {};
	};

	struct AFRH {
		DECL_REGISTER(GPIOE_AFRH_BASE);
		constexpr static RegisterField<GPIOE_AFRH_AFSEL8> AFSEL8 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL9> AFSEL9 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL10> AFSEL10 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL11> AFSEL11 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL12> AFSEL12 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL13> AFSEL13 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL14> AFSEL14 {};
		constexpr static RegisterField<GPIOE_AFRH_AFSEL15> AFSEL15 {};
	};

	struct BRR {
		DECL_REGISTER(GPIOE_BRR_BASE);
		constexpr static RegisterField<GPIOE_BRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOE_BRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOE_BRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOE_BRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOE_BRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOE_BRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOE_BRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOE_BRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOE_BRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOE_BRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOE_BRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOE_BRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOE_BRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOE_BRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOE_BRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOE_BRR_BR15> BR15 {};
	};

};

struct GPIOF {
	struct MODER {
		DECL_REGISTER(GPIOF_MODER_BASE);
		constexpr static RegisterField<GPIOF_MODER_MODE0> MODE0 {};
		constexpr static RegisterField<GPIOF_MODER_MODE1> MODE1 {};
		constexpr static RegisterField<GPIOF_MODER_MODE2> MODE2 {};
		constexpr static RegisterField<GPIOF_MODER_MODE3> MODE3 {};
		constexpr static RegisterField<GPIOF_MODER_MODE4> MODE4 {};
		constexpr static RegisterField<GPIOF_MODER_MODE5> MODE5 {};
		constexpr static RegisterField<GPIOF_MODER_MODE6> MODE6 {};
		constexpr static RegisterField<GPIOF_MODER_MODE7> MODE7 {};
		constexpr static RegisterField<GPIOF_MODER_MODE8> MODE8 {};
		constexpr static RegisterField<GPIOF_MODER_MODE9> MODE9 {};
		constexpr static RegisterField<GPIOF_MODER_MODE10> MODE10 {};
		constexpr static RegisterField<GPIOF_MODER_MODE11> MODE11 {};
		constexpr static RegisterField<GPIOF_MODER_MODE12> MODE12 {};
		constexpr static RegisterField<GPIOF_MODER_MODE13> MODE13 {};
		constexpr static RegisterField<GPIOF_MODER_MODE14> MODE14 {};
		constexpr static RegisterField<GPIOF_MODER_MODE15> MODE15 {};
	};

	struct OTYPER {
		DECL_REGISTER(GPIOF_OTYPER_BASE);
		constexpr static RegisterField<GPIOF_OTYPER_OT0> OT0 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT1> OT1 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT2> OT2 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT3> OT3 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT4> OT4 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT5> OT5 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT6> OT6 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT7> OT7 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT8> OT8 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT9> OT9 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT10> OT10 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT11> OT11 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT12> OT12 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT13> OT13 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT14> OT14 {};
		constexpr static RegisterField<GPIOF_OTYPER_OT15> OT15 {};
	};

	struct OSPEEDR {
		DECL_REGISTER(GPIOF_OSPEEDR_BASE);
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED0> OSPEED0 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED1> OSPEED1 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED2> OSPEED2 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED3> OSPEED3 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED4> OSPEED4 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED5> OSPEED5 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED6> OSPEED6 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED7> OSPEED7 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED8> OSPEED8 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED9> OSPEED9 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED10> OSPEED10 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED11> OSPEED11 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED12> OSPEED12 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED13> OSPEED13 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED14> OSPEED14 {};
		constexpr static RegisterField<GPIOF_OSPEEDR_OSPEED15> OSPEED15 {};
	};

	struct PUPDR {
		DECL_REGISTER(GPIOF_PUPDR_BASE);
		constexpr static RegisterField<GPIOF_PUPDR_PUPD0> PUPD0 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD1> PUPD1 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD2> PUPD2 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD3> PUPD3 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD4> PUPD4 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD5> PUPD5 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD6> PUPD6 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD7> PUPD7 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD8> PUPD8 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD9> PUPD9 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD10> PUPD10 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD11> PUPD11 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD12> PUPD12 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD13> PUPD13 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD14> PUPD14 {};
		constexpr static RegisterField<GPIOF_PUPDR_PUPD15> PUPD15 {};
	};

	struct IDR {
		DECL_REGISTER(GPIOF_IDR_BASE);
		constexpr static RegisterField<GPIOF_IDR_ID0> ID0 {};
		constexpr static RegisterField<GPIOF_IDR_ID1> ID1 {};
		constexpr static RegisterField<GPIOF_IDR_ID2> ID2 {};
		constexpr static RegisterField<GPIOF_IDR_ID3> ID3 {};
		constexpr static RegisterField<GPIOF_IDR_ID4> ID4 {};
		constexpr static RegisterField<GPIOF_IDR_ID5> ID5 {};
		constexpr static RegisterField<GPIOF_IDR_ID6> ID6 {};
		constexpr static RegisterField<GPIOF_IDR_ID7> ID7 {};
		constexpr static RegisterField<GPIOF_IDR_ID8> ID8 {};
		constexpr static RegisterField<GPIOF_IDR_ID9> ID9 {};
		constexpr static RegisterField<GPIOF_IDR_ID10> ID10 {};
		constexpr static RegisterField<GPIOF_IDR_ID11> ID11 {};
		constexpr static RegisterField<GPIOF_IDR_ID12> ID12 {};
		constexpr static RegisterField<GPIOF_IDR_ID13> ID13 {};
		constexpr static RegisterField<GPIOF_IDR_ID14> ID14 {};
		constexpr static RegisterField<GPIOF_IDR_ID15> ID15 {};
	};

	struct ODR {
		DECL_REGISTER(GPIOF_ODR_BASE);
		constexpr static RegisterField<GPIOF_ODR_OD0> OD0 {};
		constexpr static RegisterField<GPIOF_ODR_OD1> OD1 {};
		constexpr static RegisterField<GPIOF_ODR_OD2> OD2 {};
		constexpr static RegisterField<GPIOF_ODR_OD3> OD3 {};
		constexpr static RegisterField<GPIOF_ODR_OD4> OD4 {};
		constexpr static RegisterField<GPIOF_ODR_OD5> OD5 {};
		constexpr static RegisterField<GPIOF_ODR_OD6> OD6 {};
		constexpr static RegisterField<GPIOF_ODR_OD7> OD7 {};
		constexpr static RegisterField<GPIOF_ODR_OD8> OD8 {};
		constexpr static RegisterField<GPIOF_ODR_OD9> OD9 {};
		constexpr static RegisterField<GPIOF_ODR_OD10> OD10 {};
		constexpr static RegisterField<GPIOF_ODR_OD11> OD11 {};
		constexpr static RegisterField<GPIOF_ODR_OD12> OD12 {};
		constexpr static RegisterField<GPIOF_ODR_OD13> OD13 {};
		constexpr static RegisterField<GPIOF_ODR_OD14> OD14 {};
		constexpr static RegisterField<GPIOF_ODR_OD15> OD15 {};
	};

	struct BSRR {
		DECL_REGISTER(GPIOF_BSRR_BASE);
		constexpr static RegisterField<GPIOF_BSRR_BS0> BS0 {};
		constexpr static RegisterField<GPIOF_BSRR_BS1> BS1 {};
		constexpr static RegisterField<GPIOF_BSRR_BS2> BS2 {};
		constexpr static RegisterField<GPIOF_BSRR_BS3> BS3 {};
		constexpr static RegisterField<GPIOF_BSRR_BS4> BS4 {};
		constexpr static RegisterField<GPIOF_BSRR_BS5> BS5 {};
		constexpr static RegisterField<GPIOF_BSRR_BS6> BS6 {};
		constexpr static RegisterField<GPIOF_BSRR_BS7> BS7 {};
		constexpr static RegisterField<GPIOF_BSRR_BS8> BS8 {};
		constexpr static RegisterField<GPIOF_BSRR_BS9> BS9 {};
		constexpr static RegisterField<GPIOF_BSRR_BS10> BS10 {};
		constexpr static RegisterField<GPIOF_BSRR_BS11> BS11 {};
		constexpr static RegisterField<GPIOF_BSRR_BS12> BS12 {};
		constexpr static RegisterField<GPIOF_BSRR_BS13> BS13 {};
		constexpr static RegisterField<GPIOF_BSRR_BS14> BS14 {};
		constexpr static RegisterField<GPIOF_BSRR_BS15> BS15 {};
		constexpr static RegisterField<GPIOF_BSRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOF_BSRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOF_BSRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOF_BSRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOF_BSRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOF_BSRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOF_BSRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOF_BSRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOF_BSRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOF_BSRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOF_BSRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOF_BSRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOF_BSRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOF_BSRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOF_BSRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOF_BSRR_BR15> BR15 {};
	};

	struct LCKR {
		DECL_REGISTER(GPIOF_LCKR_BASE);
		constexpr static RegisterField<GPIOF_LCKR_LCK0> LCK0 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK1> LCK1 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK2> LCK2 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK3> LCK3 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK4> LCK4 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK5> LCK5 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK6> LCK6 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK7> LCK7 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK8> LCK8 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK9> LCK9 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK10> LCK10 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK11> LCK11 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK12> LCK12 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK13> LCK13 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK14> LCK14 {};
		constexpr static RegisterField<GPIOF_LCKR_LCK15> LCK15 {};
		constexpr static RegisterField<GPIOF_LCKR_LCKK> LCKK {};
	};

	struct AFRL {
		DECL_REGISTER(GPIOF_AFRL_BASE);
		constexpr static RegisterField<GPIOF_AFRL_AFSEL0> AFSEL0 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL1> AFSEL1 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL2> AFSEL2 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL3> AFSEL3 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL4> AFSEL4 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL5> AFSEL5 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL6> AFSEL6 {};
		constexpr static RegisterField<GPIOF_AFRL_AFSEL7> AFSEL7 {};
	};

	struct AFRH {
		DECL_REGISTER(GPIOF_AFRH_BASE);
		constexpr static RegisterField<GPIOF_AFRH_AFSEL8> AFSEL8 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL9> AFSEL9 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL10> AFSEL10 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL11> AFSEL11 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL12> AFSEL12 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL13> AFSEL13 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL14> AFSEL14 {};
		constexpr static RegisterField<GPIOF_AFRH_AFSEL15> AFSEL15 {};
	};

	struct BRR {
		DECL_REGISTER(GPIOF_BRR_BASE);
		constexpr static RegisterField<GPIOF_BRR_BR0> BR0 {};
		constexpr static RegisterField<GPIOF_BRR_BR1> BR1 {};
		constexpr static RegisterField<GPIOF_BRR_BR2> BR2 {};
		constexpr static RegisterField<GPIOF_BRR_BR3> BR3 {};
		constexpr static RegisterField<GPIOF_BRR_BR4> BR4 {};
		constexpr static RegisterField<GPIOF_BRR_BR5> BR5 {};
		constexpr static RegisterField<GPIOF_BRR_BR6> BR6 {};
		constexpr static RegisterField<GPIOF_BRR_BR7> BR7 {};
		constexpr static RegisterField<GPIOF_BRR_BR8> BR8 {};
		constexpr static RegisterField<GPIOF_BRR_BR9> BR9 {};
		constexpr static RegisterField<GPIOF_BRR_BR10> BR10 {};
		constexpr static RegisterField<GPIOF_BRR_BR11> BR11 {};
		constexpr static RegisterField<GPIOF_BRR_BR12> BR12 {};
		constexpr static RegisterField<GPIOF_BRR_BR13> BR13 {};
		constexpr static RegisterField<GPIOF_BRR_BR14> BR14 {};
		constexpr static RegisterField<GPIOF_BRR_BR15> BR15 {};
	};

};

