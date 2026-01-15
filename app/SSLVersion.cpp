#include "SSLVersion.h"

const char * SSLVersion::GetVersion()
{
    OpenSSLService service;
    return service.GetOpenSSLVersion();
}