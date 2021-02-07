#include "injector.h"

typedef std::shared_ptr<dllinject> dllinjector;

VOID __die( const char *err ) {
    std::cerr << err << std::endl;
    std::exit(2);
}

int __stdcall main( int argc, char **argv )
{
    std::string dllpath = "path_to_dll";
    char *addr = (char *) PE_PARSER::LoadFile(dllpath.c_str());
    if( addr == NULL )
        return -1;

    // check if the file is a dll
    if( !PE_PARSER::IsDllFile() )
        std::cout << "[ERROR] File is not a dll!\n";

    // get the dll architecture
    WORD dllmachine = PE_PARSER::DllMachine();
#ifdef _WIN32
    if( dllmachine == DLL_X64 )
        __die( "[ERROR] - Can't use 64bit dll on a 32bit system!" );
#endif

    dllinjector injector = dllinjector(new dllinject("notepad.exe"));
    // 64bit processes can't use 32bit dlls
    if( dllmachine == DLL_X86 && injector->IsProcess64() )
        __die( "[ERROR] - Trying to inject 32bit dll into 64bit process!" );
    // 32bit processes can't use 64bit dlls
    if( dllmachine == DLL_X64 && !injector->IsProcess64() )
        __die( "[ERROR] - Trying to inject 64bit dll into 32bit process!" );

    if ( injector->InjectDll( dllpath ) )
        std::cout << "[OK] DLL injected successfully."<< std::endl;
    
    PE_PARSER::Clear();
    return 0;
}
