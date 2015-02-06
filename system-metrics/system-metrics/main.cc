#include "main.h"

static void usage(void){
    fprintf(stderr, "使用方法: system-metrics [options]\n");
    fprintf(stderr, " -%c 数値: %s\n", OPT_DOUBLECLKWIDTH , "ダブルクリック位置の許容範囲の幅をピクセル単位で設定します。"); 
    fprintf(stderr, " -%c 数値: %s\n", OPT_DOUBLECLKHEIGHT , "ダブルクリック位置の許容範囲の高さをピクセル単位で設定します。"); 
    fprintf(stderr, " -%c 数値: %s\n", OPT_DOUBLECLICKTIME , "ダブルクリック時間をミリ秒で設定します。");      
    fprintf(stderr, " -%c : %s\n", OPT_INFORMATION , "現在の設定値を表示します。");      
    exit(1);
}

int main(int argc, OPTARG_T argv[])
{
    if(argc == 1) usage();
    
    int ch;
    
    unsigned int width, height, interval;
     
    OPTARG_T output = NULL;
        
    while ((ch = getopt(argc, argv, OPT_LIST)) != -1){
                
        switch (ch){
                case OPT_DOUBLECLKWIDTH:
                    get_uint_arg(optarg, &width);
					SystemParametersInfo(SPI_SETDOUBLECLKWIDTH, width, NULL, 0);  
                    break;
                case OPT_DOUBLECLKHEIGHT:
					get_uint_arg(optarg, &height);
                    SystemParametersInfo(SPI_SETDOUBLECLKHEIGHT, height, NULL, 0);  
                    break;
                case OPT_DOUBLECLICKTIME:
					get_uint_arg(optarg, &interval);
                    SystemParametersInfo(SPI_SETDOUBLECLICKTIME, interval, NULL, 0);  
                break;            
				case OPT_INFORMATION:
				break;
            default:
                usage();
        }
    } 
        
    fprintf(stdout, "ダブルクリック位置の許容範囲の幅: %ld ピクセル\n", GetSystemMetrics(SM_CXDOUBLECLK));
    fprintf(stdout, "ダブルクリック位置の許容範囲の高さ: %ld ピクセル\n", GetSystemMetrics(SM_CYDOUBLECLK));
    fprintf(stdout, "ダブルクリック時間: %ld ミリ秒\n", GetDoubleClickTime());
    
	return 0;
}
