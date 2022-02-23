/* FreeFiree 1.69.X */
/*
 * EM BREVE MAIS CÓDIGO, ACESSE NOSSO DISCORD: 
 * https://discord.gg/YXmRxRDUXp
 * YTB: https://www.youtube.com/c/GODSTEAMOFICIAL
 * Autor do código: Scott
 */

#include "il2cpp.h"

// Namespace : System
// classe    : public sealed class String :
// Address   : CreateString(sbyte* value) { } // RVA: 0x3772CE4
static System_String_o *CreateString(const char *str)
{
    System_String_o *(*_CreateString)(void *_this, const char *str) = (System_String_o*(*)(void*, const char*))getRealOffset(0x3772CE4);
    return _CreateString(NULL, str);
}

// Namespace : System
// classe    : public sealed class String :
// Address   : bool IsNullOrEmpty(string value) { } // RVA: 0x376E290
bool System_String_IsNullOrEmpty(System_String_o *value)
{
    bool (*_IsNullOrEmpty)(System_String_o *value) = (bool(*)(System_String_o*))getRealOffset(0x376E290);
    return _IsNullOrEmpty(value);
}

// Namespace : GCommon.Checker
// classe    : public static class KCMDEGKOPGO
// Address   : byte[] NPLKBIKNMLH(string GOFEKMEBGDA, string LODDOINFPPA) { } // RVA: 0x2B55108
System_Byte_array *GCommon_Checker_SendToServer(System_String_o *ixSuUGM, System_String_o *nvOf_b_)
{
    System_Byte_array *(*_SendToServer)(System_String_o *ixSuUGM, System_String_o *nvOf_b_) = (System_Byte_array*(*)(System_String_o*,System_String_o*))getRealOffset(0x2B55108);
    return _SendToServer(ixSuUGM, nvOf_b_);
}

// Namespace : GCloud.AnoSDK
// classe    : public static class AnoSDK
// Address   : Ioctl(int request, string cmd) { } // RVA: 0x23FA954
System_String_o *GCloud_AnoSDK_AnoSDK_Ioctl(int32_t request, System_String_o *cmd)
{
    System_String_o *(*Ioctl)(int32_t request, System_String_o *cmd) = (System_String_o*(*)(int32_t, System_String_o*))getRealOffset(0x23FA954);
    return Ioctl(request, cmd);
}

System_Byte_array *ArrayDetectEmulator_ffano(System_String_o *id)
{
    const char* StringLiteral_25777 = "files_dir=/data/data/com.dts.freefireth/files|wait=1";
    const char* StringLiteral_25778 = "GetEmpty";
    System_String_o *EmulatorCheck = GCloud_AnoSDK_AnoSDK_Ioctl(10, CreateString(StringLiteral_25777));

    if ( !System_String_IsNullOrEmpty(EmulatorCheck) )
        EmulatorCheck = CreateString(StringLiteral_25778);

    return GCommon_Checker_SendToServer(EmulatorCheck, id);
}

// Onde identificar o local da address. Caso o jogo atualize para uma nova versão :)
// Namespace : ffano
// classe    : public class FNFOLKEMMBG
// Address   : byte[] LHAJPJBCOLC(string id) { } // RVA: 0x2D54EB4

//Hookando a função
MSHookFunction((void *) getRealOffset(0x2D54EB4), (void *) &ArrayDetectEmulator_ffano);


//Para usar com MemoryPatch
MemoryPatch BypassEmulador = MemoryPatch("libil2cpp.so", 0x2D54F34, "\x00\xF0\x20\xE3", 4);  BypassEmulador.Modify();  

// Utilizar em Apk-Script's
Pattern          : 0A 00 A0 E3 92 96 DA EB 00 50 A0 E1 90 00 9F E5 
Address          : 0x2D54F00
Hex Modificação  : 00 F0 20 E3
Hex Restauração  : 0A 00 A0 E3 | não precisa utilizar a restauração..
