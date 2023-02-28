#ifdef BIN	
        #define SRC(x) ((x >> 1)|(x << 30))
	#define SLC(x) ((x << 1)|(x >> 30))
	#endif
	#ifdef HEX
        #define SRC(x) ((x >> 4)|(x << 28))
#define SLC(x) ((x << 4)|(x >> 28))

	#endif
