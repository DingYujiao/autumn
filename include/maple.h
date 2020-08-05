//
// Created by leijin on 2020/8/3.
//

#ifndef AUTUMN_MAPLE_H
#define AUTUMN_MAPLE_H

#include <stdlib.h>

struct field_items_define		/*CREATE语句后的字段和类型链表节点结构*/
{
    char *field;		/*字段名称*/
    int type;			/*INTEGER =0 VARCHAR=1  REAL=2  DATE=3*/
    int size;
    struct  field_items_define *next;
};

void createTable(char *table_name,struct field_items_define *items,char *keyName);

struct statement*  m_parser(const char * text);

#endif //AUTUMN_MAPLE_H
