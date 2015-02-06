#include "main-unicode.h"

#ifdef WIN32
int	opterr = 1;
int	optind = 1;
int	optopt;
wchar_t	*optarg;

int getopt(int argc, OPTARG_T *argv, OPTARG_T opts)
{
    static int sp = 1;
    register int c;
    register OPTARG_T cp;
    
    if(sp == 1)
        if(optind >= argc ||
           argv[optind][0] != '-' || argv[optind][1] == '\0')
            return(EOF);
        else if(wcscmp(argv[optind], L"--") == NULL) {
            optind++;
            return(EOF);
        }
    optopt = c = argv[optind][sp];
    if(c == ':' || (cp=wcschr(opts, c)) == NULL) {
        ERR(L": illegal option -- ", c);
        if(argv[optind][++sp] == '\0') {
            optind++;
            sp = 1;
        }
        return('?');
    }
    if(*++cp == ':') {
        if(argv[optind][sp+1] != '\0')
            optarg = &argv[optind++][sp+1];
        else if(++optind >= argc) {
            ERR(L": option requires an argument -- ", c);
            sp = 1;
            return('?');
        } else
            optarg = argv[optind++];
        sp = 1;
    } else {
        if(argv[optind][++sp] == '\0') {
            sp = 1;
            optind++;
        }
        optarg = NULL;
    }
    return(c);
}
#endif

using namespace std;

void get_string_arg(OPTARG_T optarg, string& arg)
{
#ifdef WIN32
    wstring warg = optarg;
    wcs_to_utf8(warg, arg);
#else
    arg = optarg;
#endif
}

void get_sint_arg(OPTARG_T optarg, int *arg)
{
#ifdef WIN32
    *arg = _wtoi(optarg);
#else
    *arg = atoi(optarg);
#endif 
}

void get_uint_arg(OPTARG_T optarg, unsigned int *arg)
{
#ifdef WIN32
    *arg = _wtoi(optarg);
#else
    *arg = atoi(optarg);
#endif 
}

void get_double_arg(OPTARG_T optarg, double *arg)
{
#ifdef WIN32
    *arg = _wtof(optarg);
#else
    *arg = atof(optarg);
#endif 
}

int wcs_to_utf8(wstring& wstr, string& str){
#ifdef WIN32    
    int error = 0; 
    int len = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
    if(len){
        std::vector<char> buf(len + 1);
        if(WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wstr.c_str(), wstr.length(), (LPSTR)&buf[0], len, NULL, NULL)){
            str = string((const char *)&buf[0]);
        }
    }else{
        str = string((const char *)"");
        error = -1;
    }
    return error;
#else
    return 0;//not implemented
#endif     
}

int utf8_to_wcs(string& str, wstring& wstr){
#ifdef WIN32     
    int error = 0; 
    int len = MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)str.c_str(), str.length(), NULL, 0);
    if(len){
        vector<char> buf((len + 1) * sizeof(wchar_t));
        if(MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)str.c_str(), str.length(), (LPWSTR)&buf[0], len)){
            wstr = wstring((const wchar_t *)&buf[0]);
        }
    }else{
        wstr = wstring((const wchar_t *)L"");
        error = -1;
    }
    return error;
#else
    return 0;//not implemented
#endif     
}
