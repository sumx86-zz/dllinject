#include <stdio.h>
#include <windows.h>

BOOL __stdcall DllMain( HINSTANCE dll, DWORD reason, LPVOID reserved ) {
    FILE *file = fopen( "C:\\temp.txt", "a+" );

    switch( reason ) {
        case DLL_PROCESS_ATTACH:
            fprintf(file, "DLL attach function calledz\n");
            //printf( "aaaa1" );
            break;

        case DLL_PROCESS_DETACH:
            fprintf(file, "DLL detach function calledz\n");
            //printf( "aaaa2" );
            break;

        case DLL_THREAD_ATTACH:
            fprintf(file, "DLL thread attach function calledz\n");
            //printf( "aaaa3" );
            break;

        case DLL_THREAD_DETACH:
            fprintf(file, "DLL thread detach function calledz\n");
            //printf( "aaaa4" );
            break;
    }
    fclose( file );
    return TRUE;
}