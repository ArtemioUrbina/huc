/*	File defs.h: 2.1 (83/03/21,02:07:20) */

#ifndef INCLUDE_DEFS_H
#define INCLUDE_DEFS_H

#define ULI_NORECURSE 1

/*
 *	INTSIZE is the size of an integer in the target machine
 *	BYTEOFF is the offset of an byte within an integer on the
 *		target machine. (ie: 8080,pdp11 = 0, 6809 = 1,
 *		360 = 3)
 *	This compiler assumes that an integer is the SAME length as
 *	a pointer - in fact, the compiler uses INTSIZE for both.
 */

#define INTSIZE 2
#define BYTEOFF 0

/* pseudo instruction arg types */
#define T_NOP           -1
#define T_VALUE          1
#define T_LABEL          2
#define T_SYMBOL         3
#define T_PTR            4
#define T_STACK          5
#define T_STRING         6
#define T_LIB            7
#define T_SIZE           8
#define T_BANK           9
#define T_VRAM          10
#define T_PAL           11
#define T_LITERAL       12


/* i-code pseudo instructions */
/*
 * N.B. this i-code enum list MUST be kept updated and in the same order
 * as the table of i-code flag information in optimize.c
 */
enum ICODE {
	/* i-code that retires the primary register contents */

	I_FENCE = 1,

	/* i-code that declares a byte sized primary register */

	I_SHORT,

	/* i-codes for handling farptr */

	I_FARPTR,
	I_FARPTR_I,
	I_FARPTR_GET,
	I_FGETW,
	I_FGETB,
	I_FGETUB,

	/* i-codes for interrupts */

	I_SEI,
	I_CLI,

	/* i-codes for calling functions */

	I_MACRO,
	I_CALL,
	I_CALLP,
	I_JSR,

	/* i-codes for C functions and the C parameter stack */

	I_ENTER,
	I_LEAVE,
	I_GETACC,
	I_SAVESP,
	I_LOADSP,
	I_MODSP,
	I_PUSH_WR,
	I_POP_WR,
	I_SPUSH_WR,	/* push and pop on the hw-stack */
	I_SPUSH_UR,	/* to temporarily save data */
	I_SPOP_WR,
	I_SPOP_UR,

	/* i-codes for handling boolean tests and branching */

	I_SWITCH_WR,
	I_SWITCH_UR,
	I_CASE,
	I_ENDCASE,
	I_LABEL,
	I_ALIAS,
	I_BRA,
	I_DEF,
	I_CMP_WT,
	I_CMP_UT,
	X_EQU_WI,
	X_NEQ_WI,
	I_NOT_WR,
	I_TST_WR,
	I_BFALSE,
	I_BTRUE,

	X_NOT_WP,
	X_NOT_WM,
	X_NOT_WS,
	X_NOT_WAR,
	X_NOT_UP,
	X_NOT_UM,
	X_NOT_US,
	X_NOT_UAR,
	X_NOT_UAY,
	X_TST_WP,
	X_TST_WM,
	X_TST_WS,
	X_TST_WAR,
	X_TST_UP,
	X_TST_UM,
	X_TST_US,
	X_TST_UAR,
	X_TST_UAY,

	X_NAND_WI,
	X_TAND_WI,

	/* i-codes for loading the primary register */

	I_LD_WI,
	X_LD_UIQ,
	I_LEA_S,

	I_LD_WM,
	I_LD_BM,
	I_LD_UM,

	I_LD_WMQ,
	I_LD_BMQ,
	I_LD_UMQ,

	I_LDY_WMQ,
	I_LDY_BMQ,
	I_LDY_UMQ,

	I_LD_WP,
	I_LD_BP,
	I_LD_UP,

	X_LD_WAR,
	X_LD_BAR,
	X_LD_UAR,

	X_LD_BAY,
	X_LD_UAY,

	X_LD_WS,
	X_LD_BS,
	X_LD_US,

	X_LD_WSQ,
	X_LD_BSQ,
	X_LD_USQ,

	X_LDY_WSQ,
	X_LDY_BSQ,
	X_LDY_USQ,

	X_LDP_WAR,
	X_LDP_BAR,
	X_LDP_UAR,

	X_LDP_BAY,
	X_LDP_UAY,

	/* i-codes for pre- and post- increment and decrement */

	X_INCLD_WM,
	X_INCLD_BM,
	X_INCLD_UM,

	X_DECLD_WM,
	X_DECLD_BM,
	X_DECLD_UM,

	X_LDINC_WM,
	X_LDINC_BM,
	X_LDINC_UM,

	X_LDDEC_WM,
	X_LDDEC_BM,
	X_LDDEC_UM,

	X_INC_WMQ,
	X_INC_UMQ,

	X_DEC_WMQ,
	X_DEC_UMQ,

	X_INCLD_WS,
	X_INCLD_BS,
	X_INCLD_US,

	X_DECLD_WS,
	X_DECLD_BS,
	X_DECLD_US,

	X_LDINC_WS,
	X_LDINC_BS,
	X_LDINC_US,

	X_LDDEC_WS,
	X_LDDEC_BS,
	X_LDDEC_US,

	X_INC_WSQ,
	X_INC_USQ,

	X_DEC_WSQ,
	X_DEC_USQ,

	X_INCLD_WAR,
	X_LDINC_WAR,
	X_DECLD_WAR,
	X_LDDEC_WAR,

	X_INCLD_BAR,
	X_INCLD_UAR,
	X_LDINC_BAR,
	X_LDINC_UAR,
	X_DECLD_BAR,
	X_DECLD_UAR,
	X_LDDEC_BAR,
	X_LDDEC_UAR,

	X_INCLD_BAY,
	X_INCLD_UAY,
	X_LDINC_BAY,
	X_LDINC_UAY,
	X_DECLD_BAY,
	X_DECLD_UAY,
	X_LDDEC_BAY,
	X_LDDEC_UAY,

	X_INC_WARQ,
	X_INC_UARQ,
	X_INC_UAYQ,

	X_DEC_WARQ,
	X_DEC_UARQ,
	X_DEC_UAYQ,

	/* i-codes for saving the primary register */

	I_ST_WMIQ,
	I_ST_UMIQ,
	I_ST_WPI,
	I_ST_UPI,
	I_ST_WM,
	I_ST_UM,
	I_ST_WP,
	I_ST_UP,
	I_ST_WPT,
	I_ST_UPT,
	X_ST_WSIQ,
	X_ST_USIQ,
	X_ST_WS,
	X_ST_US,

	X_INDEX_WR,
	X_INDEX_UR,

	X_ST_WAT,
	X_ST_UAT,

	/* i-codes for extending the primary register */

	I_EXT_BR,
	I_EXT_UR,

	/* i-codes for math with the primary register  */

	I_COM_WR,
	I_NEG_WR,

	I_ADD_WT,
	I_ADD_WI,
	I_ADD_WM,
	I_ADD_UM,
	X_ADD_WS,
	X_ADD_US,

	I_ADDBI_P,

	I_SUB_WT,
	I_SUB_WI,
	I_SUB_WM,
	I_SUB_UM,

	I_ISUB_WI,

	I_AND_WT,
	I_AND_WI,
	I_AND_WM,
	I_AND_UM,

	I_EOR_WT,
	I_EOR_WI,
	I_EOR_WM,
	I_EOR_UM,

	I_OR_WT,
	I_OR_WI,
	I_OR_WM,
	I_OR_UM,

	I_ASL_WT,
	I_ASL_WI,
	I_ASL_WR,

	I_ASR_WI,
	I_ASR_WR,

	I_LSR_WI,

	I_MUL_WI,

	/* i-codes for 32-bit longs */

	X_LDD_I,
	X_LDD_W,
	X_LDD_B,
	X_LDD_S_W,
	X_LDD_S_B
};

#define FOREVER for (;;)
#define FALSE   0
#define TRUE    1
#define NO      0
#define YES     1

/* miscellaneous */

#define EOS     0
#define EOL     10
#define BKSP    8
#define CR      13
#define FFEED   12
#define TAB     9

#define FILENAMESIZE    256

/* symbol table parameters */

/* old values, too restrictive
 * #define	SYMSIZ	14
 * #define	SYMTBSZ	32768
 * #define	NUMGLBS	1500
 */
#define SYMTBSZ 4096
#define NUMGLBS 2048

#define STARTGLB        symtab
#define ENDGLB  (STARTGLB + NUMGLBS)
#define STARTLOC        (ENDGLB + 1)
#define ENDLOC  (symtab + SYMTBSZ - 1)

/* symbol table entry format */
/* N.B. nasty hack to allow space beyond NAMEMAX (see "copysym") */

#define NAMESIZE	48
#define NAMEMAX		47
#define NAMEALLOC	64

struct symbol {
	char name[NAMEALLOC];
	char ident;
	char type;
	char storage;
	char far;
	short offset;
	short tagidx;
	int size;
	int ptr_order;
};

typedef struct symbol SYMBOL;

#define NUMTAG  64

struct tag_symbol {
	char name[NAMESIZE];	// structure tag name
	int size;		// size of struct in bytes
	int member_idx;		// index of first member
	int number_of_members;	// number of tag members
};
#define TAG_SYMBOL struct tag_symbol

#define NULL_TAG 0

// Define the structure member table parameters
#define NUMMEMB         256

/* possible entries for "ident" */

#define VARIABLE        1
#define ARRAY   2
#define POINTER 3
#define FUNCTION        4

/* possible entries for "type" */

#define CCHAR   1
#define CINT    2
#define CVOID   3
#define CSTRUCT 4
#define CENUM   5
#define CSIGNED 0
#define CUNSIGNED 8
#define CUINT (CINT | CUNSIGNED)
#define CUCHAR (CCHAR | CUNSIGNED)

/* possible entries for storage */

#define PUBLIC  1
#define AUTO    2
#define EXTERN  3
#define STATIC  4
#define LSTATIC 5
#define DEFAUTO 6
#define CONST   7

#define STORAGE 15 /* bitmask for the storage type */

#define WASAUTO 64
#define WRITTEN 128

/* "do"/"for"/"while"/"switch" statement stack */

#define WSSIZ   7
#define WSTABSZ (WSSIZ * 16)
#define WSMAX   ws + WSTABSZ - WSSIZ

/* entry offsets in "do"/"for"/"while"/"switch" stack */

#define WSSYM   0
#define WSSP    1
#define WSTYP   2
#define WSCASEP 3
#define WSTEST  3
#define WSINCR  4
#define WSDEF   4
#define WSBODY  5
#define WSTAB   5
#define WSEXIT  6

/* possible entries for "wstyp" */

#define WSWHILE 0
#define WSFOR   1
#define WSDO    2
#define WSSWITCH        3

/* "switch" label stack */

#define SWSTSZ  256

/* literal pool */

#define LITABSZ 8192
#define LITMAX  LITABSZ - 1

/* input string */

#define LITMAX2 LITABSZ - 1

/* input line */

#define LINESIZE        384
#define LINEMAX (LINESIZE - 1)
#define MPMAX   LINEMAX

/* macro (define) pool */

#define MACQSIZE        16384
#define MACMAX  (MACQSIZE - 1)

struct macro {
	char *name;
	char **args;
	int argc;
	struct {
		int arg;
		int pos;
	} *argpos;
	char *def;
};

/* "include" stack */

#define INCLSIZ 3

/* statement types (tokens) */

#define STIF    1
#define STWHILE 2
#define STRETURN        3
#define STBREAK 4
#define STCONT  5
#define STASM   6
#define STEXP   7
#define STDO    8
#define STFOR   9
#define STSWITCH        10
#define STGOTO  11

/* pseudo instruction structure */

typedef struct {
	enum ICODE code;
	int type;
	intptr_t data;
	int imm_type;
	intptr_t imm_data;
	const char *arg[3];
	SYMBOL *sym;
} INS;

/* constant array struct */

#define MAX_CONST        1024
#define MAX_CONST_VALUE  8192
#define MAX_CONST_DATA  65536

struct const_array {
	SYMBOL *sym;
	int typ;
	int size;
	int data;
};

/* fastcall func struct */

#define MAX_FASTCALL_ARGS 16
#define FASTCALL_EXTRA    0x01  // bitmask values
#define FASTCALL_XSAFE    0x02  // bitmask values
#define FASTCALL_NOP      0x04  // bitmask values
#define FASTCALL_MACRO    0x08  // bitmask values

struct fastcall {
	struct fastcall *next;
	char fname[NAMESIZE];
	int nargs;
	int flags;
	char argtype[MAX_FASTCALL_ARGS];
	char argname[MAX_FASTCALL_ARGS][NAMESIZE];
};

// initialisation of global variables
#define INIT_TYPE    NAMESIZE
#define INIT_LENGTH  NAMESIZE + 1
#define INITIALS_SIZE 5 * 1024

struct initials_table {
	char name[NAMESIZE];	// symbol name
	int type;		// type
	int dim;		// length of data (possibly an array)
	int data_len;		// index of tag or zero
};
#define INITIALS struct initials_table

SYMBOL *find_member (TAG_SYMBOL *tag, char *sname);

struct lvalue {
	SYMBOL *symbol;
	int indirect;
	int ptr_type;
	SYMBOL *symbol2;
	int value;
	TAG_SYMBOL *tagsym;
	int ptr_order;
	int type;
};
#define LVALUE struct lvalue

#define W_GENERAL 1

struct type {
	int type;
	int ident;
	int ptr_order;
	int otag;
	int flags;
	char sname[NAMESIZE];
};
#define F_REGISTER 1
#define F_CONST 2
#define F_VOLATILE 4
#define F_STRUCT 8	/* set if CSTRUCT is struct, not union */

struct clabel {
	char name[NAMESIZE];
	int stkp;
	int label;
};

struct enum_s {
	char name[NAMESIZE];
	int value;
};
struct enum_type {
	char name[NAMESIZE];
	int start;
	int base;
};

#endif
