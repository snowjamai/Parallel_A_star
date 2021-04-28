#ifndef VERSION_HPP
#define VERSION_HPP

#define OSRM_VERSION_MAJOR @OSRM_VERSION_MAJOR@
#define OSRM_VERSION_MINOR @OSRM_VERSION_MINOR@
#define OSRM_VERSION_PATCH @OSRM_VERSION_PATCH@

#define OSRM_VERSION__(A,B,C) "v" #A "." #B "." #C
#define OSRM_VERSION_(A,B,C) OSRM_VERSION__(A,B,C)
#define OSRM_VERSION OSRM_VERSION_(OSRM_VERSION_MAJOR, OSRM_VERSION_MINOR, OSRM_VERSION_PATCH)

#endif // VERSION_HPP
