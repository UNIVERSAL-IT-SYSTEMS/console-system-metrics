#include <stdlib.h>
#include <stdio.h>

#ifdef WIN32
#include <stdio.h>
#include <windows.h>
#define OPTARG_T wchar_t*
#define main wmain
#define NULL	0
#define EOF	(-1)
#define ERR(s, c)	if(opterr){\
char errbuf[2];\
errbuf[0] = c; errbuf[1] = '\n';\
fputws(argv[0], stderr);\
fputws(s, stderr);\
fputwc(c, stderr);}
#else
#define OPTARG_T char*
#endif

#ifdef __GNUC__
#include <getopt.h>
#endif
#ifndef __GNUC__

#ifndef _WINGETOPT_H_
#define _WINGETOPT_H_

#ifdef __cplusplus
extern "C" {
#endif
    
    extern int opterr;
    extern int optind;
    extern int optopt;
    extern OPTARG_T optarg;
    extern int getopt(int argc, OPTARG_T *argv, OPTARG_T opts);
    
#ifdef __cplusplus
}
#endif

#endif  /* _GETOPT_H_ */
#endif  /* __GNUC__ */

#include <string>
#include <vector>

using namespace std;

#ifndef strings
typedef vector<string> strings;
#endif
#ifndef wstrings
typedef vector<wstring> wstrings;
#endif

void get_string_arg(OPTARG_T optarg, string& arg);
void get_sint_arg(OPTARG_T optarg, int *arg);
void get_uint_arg(OPTARG_T optarg, unsigned int *arg);
void get_double_arg(OPTARG_T optarg, double *arg);

int wcs_to_utf8(wstring& wstr, string& str);
int utf8_to_wcs(string& str, wstring& wstr);
