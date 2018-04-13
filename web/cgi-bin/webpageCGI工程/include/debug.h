#ifndef _DEBUG_H
#define _DEBUG_H

#define DEBUG
//#undef DEBUG
FILE *log_file;
#ifdef  DEBUG
#define LOG_FILE "./log.txt" // /var/log/assistant
#define debug(format, args...) {fprintf(log_file, format, ##args); fflush(log_file);}
#else
#define debug(format, args...)
#define LOG_FILE "/dev/null"  // /var/log/assistant
#endif

#endif
