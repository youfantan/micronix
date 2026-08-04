#include <device_spec.h>

uint32_t SystemCoreClock = 16000000UL;

static void SystemClock_Config(void);
static void delay_nop(uint32_t count);

int main()
{
  SystemClock_Config();

  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

  GPIOA->MODER &= ~GPIO_MODER_MODE6_Msk;
  GPIOA->MODER |= (1UL << GPIO_MODER_MODE6_Pos);
  GPIOA->OTYPER &= ~GPIO_OTYPER_OT6_Msk;
  GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED6_Msk;

  while (1)
  {
    GPIOA->BSRR = (1UL << GPIO_BSRR_BS6_Pos);
    delay_nop(1000UL);
    GPIOA->BRR = (1UL << GPIO_BRR_BR6_Pos);
    delay_nop(1000UL);
  }
}

static void SystemClock_Config(void)
{
  RCC->CR |= RCC_CR_HSION;
  while (!(RCC->CR & RCC_CR_HSIRDY))
  {
  }

  RCC->CR &= ~RCC_CR_HSIDIV_Msk;

  RCC->CFGR &= ~(RCC_CFGR_SW_Msk | RCC_CFGR_HPRE_Msk | RCC_CFGR_PPRE_Msk);
}

static void delay_nop(uint32_t count)
{
  while (count--)
  {
    __NOP();
  }
}
