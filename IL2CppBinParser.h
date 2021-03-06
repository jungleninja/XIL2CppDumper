//
// Created by xia0 on 2019/11/18.
//

#ifndef XIL2CPPDUMPER_IL2CPPBINPARSER_H
#define XIL2CPPDUMPER_IL2CPPBINPARSER_H
#include <unistd.h>
#include "XB1nLib/XB1nLib.h"

class IL2CppBinParser
{
private:


public:
    void* codeRegistration;
    void* metadataRegistration;
    uint32_t metadataVersion;

    bool isMacho;
    bool isMacho64;
    bool isElf;
    bool isElf64;

    void* il2cppbin;

    IL2CppBinParser(void* il2cppbin, uint32_t metadataVersion);
    void initWithMacho64();
    int64_t fixElf64Relocation(uint64_t needFixAddr);
    Arm_Addr fixElf32Relocation(Arm_Addr needFixAddr);
    void initWithElf32();
    void initWithElf64();

    void* seek2Offset(uint64_t offset);
    uint64_t RVA2RAW(void* rva); // convert ida adress to file offset
    void* RAW2RVA(uint64_t raw); // convert file offset to ida address
    void* idaAddr2MemAddr(void* idaAddr);
};


#endif //XIL2CPPDUMPER_IL2CPPBINPARSER_H
