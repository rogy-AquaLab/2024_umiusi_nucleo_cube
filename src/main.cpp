#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stm32f3xx_hal.h"

#define LED_PIN GPIO_PIN_3
#define LED_GPIO_PORT GPIOB
#define LED_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

    void Error_Handler();
    void SystemClock_Config();

    int main() {
        HAL_Init();
        SystemClock_Config();

        LED_GPIO_CLK_ENABLE();

        GPIO_InitTypeDef GPIO_InitStruct;

        GPIO_InitStruct.Pin = LED_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

        while (1) {
            HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);

            HAL_Delay(1000);
        }
    }

    void Error_Handler() {
        __disable_irq();
        while (1) {
        }
    }

    void SysTick_Handler() {
        HAL_IncTick();
    }

    void NMI_Handler() {}

    void HardFault_Handler() {
        while (1) {
        }
    }

    void MemManage_Handler() {
        while (1) {
        }
    }

    void BusFault_Handler() {
        while (1) {
        }
    }

    void UsageFault_Handler() {
        while (1) {
        }
    }

    void SystemClock_Config() {
        RCC_OscInitTypeDef RCC_OscInitStruct{};
        RCC_ClkInitTypeDef RCC_ClkInitStruct{};

        /** Initializes the RCC Oscillators according to the specified parameters
         * in the RCC_OscInitTypeDef structure.
         */
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        RCC_OscInitStruct.HSIState = RCC_HSI_ON;
        RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
        if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
            Error_Handler();
        }

        /** Initializes the CPU, AHB and APB buses clocks */
        RCC_ClkInitStruct.ClockType
            = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1
               | RCC_CLOCKTYPE_PCLK2);
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
        RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
        RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
        RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

        if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
            Error_Handler();
        }
    }

    void SVC_Handler() {}

    void DebugMon_Handler() {}

    void PendSV_Handler() {}

#ifdef __cplusplus
}
#endif /* __cplusplus */
