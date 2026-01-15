#include "OpenSSLService.h"

const char* OpenSSLService::GetOpenSSLVersion()
{
    return OpenSSL_version(OPENSSL_VERSION);
}