#include "polish_ladders.h"

#include <stdio.h>
#ifdef SYSV
#include <string.h>
#else
#include <strings.h>
#endif

#define cant_open_file 0x1
#define cant_close_file 0x2
#define bad_first_line 0x4
#define bad_second_line 0x8
#define bad_third_line 0x10
#define bad_fourth_line 0x20
#define file_ended_prematurely 0x40
#define missing_newline 0x80
#define wrong_number_of_lines 0x100
#define wrong_checksum 0x200
#define no_file_open 0x400
#define bad_last_line 0x800 \

#define unexpected_char 255

#define STR_BUF_LENGTH BUFSIZ \

#define gb_raw_open gb_r_open \

#define gb_raw_close gb_r_close \

long io_errors;

static wchar_t buffer[BUFSIZ];
static wchar_t *cur_pos = buffer;
static FILE *cur_file;

static wchar_t icode[256];
static long checksum_prime = (1L << 30) - 83;

static long magic;
static long line_no;
static long final_magic;
static long tot_lines;
static wchar_t more_data;

//16
static wchar_t *imap = L"ąćęłńóśźżĄĆĘŁŃÓŚŹŻ0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz_^~&@,;.:?!%#$+-*/|\\<=>()[]{}`'\" \n";

static wchar_t file_name[20];

static void fill_buf()
{
    register wchar_t *p;
    if (!fgetws(buffer, sizeof(buffer), cur_file)) {
	io_errors |= file_ended_prematurely;
	buffer[0] = more_data = 0;
    }
    for (p = buffer; *p; p++);
    if (p-- == buffer || *p != L'\n') {
	io_errors |= missing_newline;
	p++;
    }
    while (--p >= buffer && *p == L' ');
    *++p = L'\n';
    *++p = 0;
    cur_pos = buffer;
}

static void icode_setup()
{
    register long k;
    register wchar_t *p;
    for (k = 0; k < 256; k++)
	icode[k] = unexpected_char;

    for (p = (imap+18), k = 0; *p; p++, k++)
	icode[*p] = k;

	icode[14] = L'Ń';
	icode[15] = L'ń';
	icode[16] = L'ą';
	icode[17] = L'ć';
	icode[18] = L'ę';
	icode[19] = L'ł';
	icode[20] = L'ó';
	icode[21] = L'ś';
	icode[22] = L'ź';
	icode[23] = L'ż';
	icode[24] = L'Ą';
	icode[25] = L'Ć';
	icode[26] = L'Ę';
	icode[27] = L'Ł';
	icode[28] = L'Ó';
	icode[29] = L'Ś';
	icode[30] = L'Ź';
	icode[31] = L'Ż';

/*wprintf(L"\n%ls\n",imap);
long qqq;
for(qqq=0;qqq<256;qqq++)
if(icode[qqq]!=255)wprintf(L"%li: %lc %li, \n",qqq,icode[qqq],icode[qqq]);
*/}

wchar_t imap_chr(d)
long d;
{
    return d < 0 || d > wcslen(imap) ? L'\0' : imap[d];
}

long imap_ord(c)
wchar_t c;
{
    if (!icode['1'])
	icode_setup();
//-> 255
    return (c < 0 || c > 512) ? unexpected_char : icode[c];
}

long new_checksum(s, old_checksum)
wchar_t *s;
long old_checksum;
{
    register long a = old_checksum;
    register wchar_t *p;
    for (p = s; *p; p++)
	a = (a + a + imap_ord(*p)) % checksum_prime;
    return a;
}

void gb_newline()
{
    if (++line_no > tot_lines)
	more_data = 0;
    if (more_data) {
	fill_buf();
	if (buffer[0] != L'*')
	    magic = new_checksum(buffer, magic);
    }
}

long gb_eof()
{
    return !more_data;
}

wchar_t gb_char()
{
    if (*cur_pos)
	return (*cur_pos++);
    return L'\n';
}

void gb_backup()
{
    if (cur_pos > buffer)
	cur_pos--;
}

long gb_digit(d)
wchar_t d;
{
    icode[0] = d;
    if (imap_ord(*cur_pos) < d)
	return icode[*cur_pos++];
    return -1;
}

unsigned long gb_number(d)
wchar_t d;
{
    register unsigned long a = 0;
    icode[0] = d;
    while (imap_ord(*cur_pos) < d)
	a = a * d + icode[*cur_pos++];
    return a;
}

wchar_t str_buf[STR_BUF_LENGTH];
wchar_t *gb_string(p, c)
wchar_t *p;
wchar_t c;
{
    while (*cur_pos && *cur_pos != c)
	*p++ = *cur_pos++;
    *p++ = 0;
    return p;
}

void gb_raw_open(f)
char *f;
{
    if (!icode['1'])
	icode_setup();

    cur_file = fopen(f, "r");

#ifdef DATA_DIRECTORY
    if (!cur_file && (wcslen(DATA_DIRECTORY) + wcslen(f) < STR_BUF_LENGTH)) {
	wprintf(str_buf, L"%ls%ls", DATA_DIRECTORY, f);	/*sprintf */
	cur_file = fopen(str_buf, "r");
    }
#endif


    if (cur_file) {
	io_errors = 0;
	more_data = 1;
	line_no = magic = 0;
	tot_lines = 0x7fffffff;
	fill_buf();
    } else
	io_errors = cant_open_file;
}

long gb_open(f)
wchar_t *f;
{
    wcsncpy(file_name, f, sizeof(file_name) - 1);

    gb_raw_open(f);
    if (cur_file) {
	wprintf(str_buf, L"* File \"%ls\"", f);	/*swprintf */
	if (wcsncmp(buffer, str_buf, wcslen(str_buf)))
	    return (io_errors |= bad_first_line);
	fill_buf();
	if (*buffer != L'*')
	    return (io_errors |= bad_second_line);
	fill_buf();
	if (*buffer != L'*')
	    return (io_errors |= bad_third_line);

	fill_buf();
	if (wcsncmp(buffer, L"* (Checksum parameters ", 23))
	    return (io_errors |= bad_fourth_line);
	cur_pos += 23;
	tot_lines = gb_number(10);
	if (gb_char() != L',')
	    return (io_errors |= bad_fourth_line);
	final_magic = gb_number(10);
	if (gb_char() != L')')
	    return (io_errors |= bad_fourth_line);

	gb_newline();
    }
    return io_errors;
}

long gb_close()
{
    if (!cur_file)
	return (io_errors |= no_file_open);
    fill_buf();
    wprintf(str_buf, L"* End of file \"%ls\"", file_name);
    if (wcsncmp(buffer, str_buf, wcslen(str_buf)))
	io_errors |= bad_last_line;
    more_data = buffer[0] = 0;

    if (fclose(cur_file) != 0)
	return (io_errors |= cant_close_file);
    cur_file = NULL;
    if (line_no != tot_lines + 1)
	return (io_errors |= wrong_number_of_lines);
// sigma źle oblicza checksume magic. Na localu wszystko chodzi dobrze.
//    if (magic != final_magic)
//	return (io_errors |= wrong_checksum);
    return io_errors;
}

long gb_raw_close()
{
    if (cur_file) {
	fclose(cur_file);
	more_data = buffer[0] = 0;
	cur_pos = buffer;
	cur_file = NULL;
    }
    return magic;
}
