#include <gbmu.h>

int	isu00r(cpu_core_t *core)
{

}

int8_t *get_reg_addr(registers_t *reg, uint8_t num)
{
	switch (num)
	{
		case reg_a:
			return (&reg->a);
		case reg_b:
			return (&reg->b);
		case reg_c:
			return (&reg->c);
		case reg_d:
			return (&reg->d);
		case reg_e:
			return (&reg->e);
		case reg_h:
			return (&reg->h);
		case reg_l:
			return (&reg->l);
		default:
			return (NULL);
	}
	return (NULL);
}

int16_t *get_pair_dd_addr(registers_t *reg, uint8_t num)
{
	switch (num)
	{
		case (reg_a << 1):
			return (&reg->bc);
		case (reg_b << 1):
			return (&reg->de);
		case (reg_c << 1):
			return (&reg->hl);
		case (reg_d << 1):
			return (&reg->sp);
		default:
			return (NULL);
	}
	return (NULL);
}

int16_t *get_pair_qq_addr(registers_t *reg, uint8_t num)
{
	switch (num >> 1)
	{
		case (reg_a << 1):
			return (&reg->bc);
		case (reg_b << 1):
			return (&reg->de);
		case (reg_c << 1):
			return (&reg->hl);
		case (reg_d << 1): 
			return (&reg->af);
		default:
			return (NULL);
	}
	return (NULL);
}

int16_t *get_pair_ss_addr(registers_t *reg, uint8_t num)
{
	switch (num >> 1)
	{
		case ((reg_a << 1) | 1):
			return (&reg->bc);
		case ((reg_b << 1) | 1):
			return (&reg->de);
		case ((reg_c << 1) | 1):
			return (&reg->hl);
		case ((reg_d << 1) | 1): 
			return (&reg->sp);
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
		read_mem(core->mem, core->reg.pc, &cmd, 1);
		core->reg.pc += decode_instruction(cmd)(core);
	}
}