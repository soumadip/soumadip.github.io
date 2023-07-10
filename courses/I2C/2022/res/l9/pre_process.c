//use the command: gcc -E filename.c to get the code after preprocessing

#define MAX 10
MAX 


#define MSG Hello
MSG

#ifdef MSG
	#undef MSG
	#define MSG new_hello
#endif
MSG

#ifdef MSG
	#define MSG2 hello2
	#undef MSG
#endif
MSG
MSG2

#define FUN(x) call x
FUN(10)
FUN(10 + 15)

#define FUN2(x,y) x+y
FUN2(a,b)

#define FUN3(a) #a
FUN3(10)

#define FUN4(a) tokena
FUN4(10)

#define FUN5(a) token##a
FUN5(10)
