#ifndef WEB_GET_INCLUDED
#define WEB_GET_INCLUDED
#include <string.h>
#include "base.h"

void parse_url(u8 * url, u8 ** hostname, u8 ** port, u8 ** path)
{
  LOG_MSG("URL: %s\n", url);

  u8 * p;
  p = strstr(url, "://");

  u8 * protocol = 0;
  if (p)
  {
    protocol = url;
    *p = 0;
    p += 3;
  }
  else 
  {
    p = url;
  }

  if (protocol)
  {
    if (strcmp(protocol, "http"))
    {
      LOG_ERR("Unknown protocol '%s'. Only 'http' is supported.\n",
              protocol);
      exit(1);
    }
  }

  *hostname = p;
  while (*p && *p != '/' && *p != '#') ++p;

  *path = p;
  if (*p == '/')
  {
    *path = p + 1;
  }
  *p = 0;

  while (*p && *p != '#') ++p;
  if (*p == '#') *p = 0;

  LOG_MSG("hostname: %s\n", *hostname);
  LOG_MSG("port: %s\n", *port);
  LOG_MSG("path: %s\n", *path);
}

#endif // !WEB_GET_INCLUDED
