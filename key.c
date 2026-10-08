#include "key.h"

typedef struct
{
	GPIO_TypeDef *prot;
	uint16_t pin;
	uint16_t key_value;
} key_config_t;

static const key_config_t key_table[]=
{
	{GPIOA,GPIO_PIN_4,1},
	{GPIOA,GPIO_PIN_5,2},
	{GPIOA,GPIO_PIN_6,3},
	{GPIOA,GPIO_PIN_7,4},
    
	
};

uint8_t key_val=0;
uint8_t key_old=0;
uint8_t key_down=0;
uint8_t key_up=0;


uint8_t key_Read(void)
{
	uint16_t key_state=0;
	for(uint8_t i=0; i<key_geshu ;i++)
	{
		if(HAL_GPIO_ReadPin(key_table[i].prot,key_table[i].pin==GPIO_PIN_RESET))
		{
			key_state|=(1<<i);//十六进制
		}
	}

	//for(uint8_t i=0;i<key_geshu;i++)
	// {
	// 	if(HAL_GPIO_ReadPin(key_table[i].prot,key_table[i].pin)==GPIO_PIN_RESET)
	// 	{
	// 		return key_table[i].key_value;
	// 	}
	// }
	// if(HAL_GPIO_ReadPin(key_table[0].prot,key_table[0].pin)==GPIO_PIN_RESET&&
	// HAL_GPIO_ReadPin(key_table[1].prot,key_table[1].pin)==GPIO_PIN_RESET)
	// {
	// 	return 5;

	// }
	return key_state;
}

void key_scan(void)
{
	static uint32_t last_tick=0;
	
	key_down=0;
	key_up=0;

	if(HAL_GetTick()-last_tick<20)
	{
		return;
	}	

	last_tick=HAL_GetTick();

    key_val=key_Read();
	key_down = (key_val != 0 && key_old == 0) ? key_val : 0;//按下
	key_up = (key_val == 0 && key_old != 0) ? key_old : 0;//抬起
	key_old = key_val;
	uint8_t key_flat;
	static(key_down)
	{
		case 0x01://短按  按键1
		{


		}
		case 0x01||0x02: //长按  按键1按键2
		{


		}
		case 0x01||0x02||0x04||0x08: //长按 全部按下
		{


		}
		break;
		case 0x02:
		{


		}
		break;
		case 0x04:
		{


		}
		break;
		case 0x08:
		{


		}
		break;
		

	}


 
}