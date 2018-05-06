#ifndef memory_H
#define memory_H

#include <stdint.h>
#include <string>

class memory
{
public:
	memory(uint64_t start, uint64_t length);
	~memory();

	int8_t get8(uint64_t addr);
	int16_t get16(uint64_t addr);
	int32_t get32(uint64_t addr);
	int64_t get64(uint64_t addr);

    void set8(uint64_t addr, uint8_t val);
    void set16(uint64_t addr, uint16_t val);
    void set32(uint64_t addr, uint32_t val);
    void set64(uint64_t addr, uint64_t val);

	void dump(uint64_t addr, uint64_t length);

	void readRaw(const char *filename, uint64_t addr);

	void setMemoryWarnings(int i) { memoryWarnings=i; }
	int getMemoryWarnings() const { return memoryWarnings; } 

private:
	int8_t *mem;		// the actual memory buffer
	uint64_t start;
	uint64_t len;
	int memoryWarnings;
};

extern memory *mem;


#endif
