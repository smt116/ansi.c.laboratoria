#include "polish_ladders.h"

#include <stdio.h> 
#ifdef SYSV
#include <string.h> 
#else
#include <strings.h> 
#endif

extern long io_errors;

#define unexpected_char  255

extern wchar_t imap_chr();
extern long imap_ord();

extern void gb_newline();
extern long new_checksum();

extern long gb_eof();

extern wchar_t gb_char();
extern void gb_backup();

extern long gb_digit();
extern unsigned long gb_number();

#define STR_BUF_LENGTH BUFSIZ
extern wchar_t str_buf[];
extern wchar_t *gb_string();

#define gb_raw_open gb_r_open
extern void gb_raw_open();
extern long gb_open();

#define gb_raw_close gb_r_close
extern long gb_close();
extern long gb_raw_close();

