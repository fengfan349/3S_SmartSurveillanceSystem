#ifndef TYPE_H_
#define TYPE_H_
typedef unsigned char			u8;
typedef signed char				s8;
typedef unsigned short int		u16;
typedef signed short int			s16;
typedef unsigned long int		u32;
typedef signed long int			s32;

typedef volatile unsigned short int VUINT16;
typedef volatile unsigned int VUINT32;
typedef volatile unsigned char VUINT8;

typedef unsigned char BOOL;
struct student{
	char name[32];
	char sex[32];
	int age;
	int stu_id;
};

#endif

