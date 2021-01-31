#ifndef __CIRCUITMODEL_H__
#define __CIRCUITMODEL_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct net_t net_t;
typedef struct pin_t pin_t;
typedef struct port_t port_t;
typedef struct inst_t inst_t;
typedef struct hinst_t hinst_t;

struct net_t {
	char*		net_name;
	pin_t**		connected_pins;
	port_t**	connected_ports;
};

struct pin_t {
	char*		pin_name;
	net_t*		net_in;
	net_t*		net_out;
};

struct port_t {
	char*		port_name;
	net_t*		net_in;
	net_t*		net_out;
};

struct inst_t {
	char* 		inst_name;
	pin_t**		inst_pins;
};

struct hinst_t {
	char* 		hinst_name;
	hinst_t**	child_hinsts;
	inst_t** 	child_insts;
	net_t**		child_nets;
	port_t**	hinst_ports;
};

void cm_read_verilog_file(char* filepath);

#ifdef __cplusplus
}
#endif

#endif
