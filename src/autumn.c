//
// Created by Administrator on 2020/7/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "maple.h"
#include "ginkgo.h"
#include "poplar.h"

#define AUTUMN_VERSION 1.0

static void autumn_print_version ();
static void autumn_print_help ();


static struct option long_options[] = {
        {"version", no_argument, NULL, 'v'},
        {"file", required_argument, NULL, 'f'},
        {"run", required_argument, NULL, 'r'},
        {"help", no_argument, NULL, 'h'},
        {NULL, no_argument, NULL, 0},
};
int main(int argc, char **argv) {
    int c;
    int option_index = 0;
    while ((c = getopt_long(argc, argv, "vrf:h", long_options, &option_index)) != -1) {
        switch (c) {
            case 'v':
                // version
                autumn_print_version();
                break;

            case 'f':
                // file
                printf("%s\n",optarg);
                m_parser(optarg);
                g_hello();
                p_hello();
                break;
            case 'r':
                printf("%run\n");
                int flag=1;
                while (flag) {
                    char str[50];
                    char *string = str;  //一定要先将指针变量初始化
                    printf("请输入字符串：");
                    gets(string);  //也可以写成gets(str);
                    printf("%s\n", string);  //输出参数是已经定义好的“指针变量名”
                }
                break;
            case 'h':
                // help
                autumn_print_help();
                break;

            default:
                puts("For usage, run `autumn -h' or `autumn --help'.");
                break;
        }
    }

    return EXIT_SUCCESS;
}


void autumn_print_version () {
    printf("autumn %1.1f\n", AUTUMN_VERSION);
}

void autumn_print_help () {
    puts("Usage:");
    puts("-v, --version\n\t see version number");
    puts("-r, --run\n\t run ");
    puts("-f, --file [filename]:\n\t interpret [filename]. Argument not optional.");
    puts("-h, --help:\n\t get this message");
}
