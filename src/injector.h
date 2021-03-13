#ifndef __injecTor_HH
#define __injecTor_HH 1

#include "pe_parser.h"
#include <tlhelp32.h>

const char * __stdcall winstrerror( DWORD code );

#define PROCESS_FOREACH(INSTANCE)\
    for( std::vector<PROCESSENTRY32>::iterator procc = INSTANCE.begin(); procc != INSTANCE.end(); procc++ )

class dllinject {
    public:
        dllinject( const char *name );
        ~dllinject();

    public:
        bool FindProcessByName( const char *name );
        bool InjectDll( const std::string& dllpath );
        bool InjectDll( const std::wstring& dllpath );
        HANDLE GetPToken( VOID );
        bool SetDebugPriv( HANDLE token );
        bool IsProcess64( VOID );
        bool XCreateRemoteThread( LPTHREAD_START_ROUTINE func, LPVOID param );

    private:
        bool GetProcList( VOID );

    private:
        DWORD _procid;
        HANDLE _prochndl;
        HANDLE _ptoken;
        HANDLE _thread;
        LPVOID _lpaddr;
        std::vector<PROCESSENTRY32> _proclist;
};

#endif
