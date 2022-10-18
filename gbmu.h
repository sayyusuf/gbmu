#ifndef GBMU_H
#define GBMU_H
#include <stddef.h>
#include <stdint.h>
#include <pthread.h>


enum reg_num_e
{
	reg_a = 7,
	reg_b = 0,
	reg_c = 1,
	reg_d = 2,
	reg_e = 3,
	reg_h = 4,
	reg_l = 5,
};

enum pair_reg_num_e
{
	reg_bc = 0,
	reg_de = 1,
	reg_hl = 2,
	reg_sp = 3,
	reg_af = 3,
};


typedef struct cmd_s
{
	uint8_t f : 2;
	uint8_t s : 3;
	uint8_t t : 3;
} cmd_t;

typedef struct gbmu_clock_s
{
	pthread_mutex_t	mut;
	uint8_t			clock;	
} gbmu_clock_t;

typedef struct sys_mem_s
{
	pthread_mutex_t	*mem_mut;
	void	*mem;
} sys_mem_t;

typedef struct registers_s
{
	uint16_t pc;
	uint16_t sp;
	union
	{
		struct
		{
			uint8_t	b;
			uint8_t c;
		};
		uint16_t bc;
	};
	union
	{
		struct
		{
			uint8_t	d;
			uint8_t e;
		};
		uint16_t de;
	};
	union
	{
		struct
		{
			uint8_t	h;
			uint8_t l;
		};
		uint16_t hl;
	};
	union
	{
		struct
		{
			uint8_t a;
			uint8_t f;
		};
		uint16_t af;
	}; 
} registers_t;

typedef struct  cpu_core_s
{
	registers_t 	reg;
	sys_mem_t		*mem;
	gbmu_clock_t	*sys_clock;
} cpu_core_t;

typedef int (* instruction_t)(cpu_core_t *core);

void	clock_generator(sys_mem_t *mem, gbmu_clock_t *sys);
void	clock_divider(sys_mem_t *mem, gbmu_clock_t *sys_clock, gbmu_clock_t *divider);
void	wait_clock(gbmu_clock_t *clock);

void read_mem(sys_mem_t *mem, int16_t addr, int8_t *buff, size_t n);
void write_mem(sys_mem_t *mem, int16_t addr, int8_t *buff, size_t n);

#endif