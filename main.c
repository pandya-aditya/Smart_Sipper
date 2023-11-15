
#include "main.h"


void SystemClock_Config(void);
void MX_GPIO_Init(void);

void BuzzerPlayNote(int prescalerfornote, int NoteDurationMs)
{
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);

		for(int i = 0; i<NoteDurationMs ; i++)
		{
			TIM2->PSC = prescalerfornote; //change prescaler for have the frequency of our note
			HAL_Delay(1);
		}
		TIM2->PSC=0;
	HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_2);

}

int main(void)
{

  HAL_Init();

  SystemClock_Config();
  MX_GPIO_Init();

  while (1)	{
    Buzzer_Play_Note(142, 5);
    HAL_Delay(3600000);
  }

}


