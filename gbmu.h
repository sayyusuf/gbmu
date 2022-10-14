#ifndef GBMU_H
#define GBMU_H
#include <stddef.h>
#include <stdint.h>
#include <pthread.h>

typedef struct gbmu_clock_s
{
	pthread_mutex_t	mut;
	uint8_t			clock;	
} gbmu_clock_t;

typedef  struct sys_register_s
{
	pthread_mutex_t	*mem_mut;
	union
	{
		uint8_t		*reg8;
		uint16_t	*reg16;
	};
} sys_register_t;

typedef struct registers_s
{
	uint8_t	A;
	uint8_t	F;
	uint16_t PC;
	uint16_t SP;
	union
	{
		struct
		{
			uint8_t	B;
			uint8_t C;
		};
		uint16_t BC;
	};
	union
	{
		struct
		{
			uint8_t	D;
			uint8_t E;
		};
		uint16_t DE;
	};
	union
	{
		struct
		{
			uint8_t	H;
			uint8_t L;
		};
		uint16_t HL;
	};
} registers_t;


typedef struct  cpu_core_s
{
	registers_t reg;
} cpu_core_t;

void	clock_generator(sys_register_t *cos, gbmu_clock_t *sys);
void	clock_divider(sys_register_t div, gbmu_clock_t *sys_clock, gbmu_clock_t *divider);
void	wait_clock(gbmu_clock_t *clock);

#endif