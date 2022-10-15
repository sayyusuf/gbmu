#include <gbmu.h>

int8_t *get_reg_addr(registers_t *reg, uint8_t num)
{
	switch (num)
	{
		case reg_a:
			return (&reg->A);
		case reg_b:
			return (&reg->B);
		case reg_c:
			return (&reg->C);
		case reg_d:
			return (&reg->D);
		case reg_e:
			return (&reg->E);
		case reg_h:
			return (&reg->H);
		case reg_l:
			return (&reg->L);
		default:
			return (NULL);
	}
	return (NULL);
}

int16_t *get_pair_dd_addr(registers_t *reg, uint8_t num)
{
	switch (num >> 1)
	{
		case reg_a:
			return (&reg->BC);
		case reg_b:
			return (&reg->DE);
		case reg_c:
			return (&reg->HL);
		case reg_d:
			return (&reg->SP);
		default:
			return (NULL);
	}
	return (NULL);
}

int16_t *get_pair_qq_addr(registers_t *reg, uint8_t num)
{
	switch (num >> 1)
	{
		case reg_a:
			return (&reg->BC);
		case reg_b:
			return (&reg->DE);
		case reg_c:
			return (&reg->HL);
		case reg_d:
			return (&reg->AF);
		default:
			return (NULL);
	}
	return (NULL);
}

instruction_t decode_instruction(cmd_t cmd)
{

}

int	look_interrupt(cpu_core_t *core)
{

}

void core_loop(cpu_core_t *core)
{
	cmd_t cmd;

	while(1)
	{
		cmd = (cmd_t){0};
		if (look_interrupt(core))
			continue ;
		read_mem(core->mem, core->reg.PC, &cmd, 1);
	decode_instruction(cmd)(core);
	}
}