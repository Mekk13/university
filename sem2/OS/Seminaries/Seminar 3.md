# fork() -> forks processes after it

getpid() in c 

fork creates a copy of the process -> ss,cs,ds and EIP

pid_t o structura peste un intrg (contine)

f=fork();
if( -1 == f)
	error
f== 0
	//child
f > 0 
	//parent

pid ppid process id and parent process id

wait blocks the execution of the current process while one of the children finishes
waitpid is dedicated for a specific child

wait(NULL) ; ca nu mi pasa cu ce cod se gata procesu

a zombie process is a process that keeps running after its  parent ended

ps -fu (full user) (user)
defunct processes have technically ended their execution but the parent is ? still waiting
sleep


# EXEC

->family of commands that replaces the current image process to a new one

<mark style="background: #FFF3A3A6;">execl</mark>
needs a pathname and arguments
the pathname is a filename thats being executed usually
the list of args MUST be terminated by a NULL ptr
so, **execl("usr/bin/pwd",NULL);**

functie variadica -> variaza nr de argumente
ex: scanf , printf

<mark style="background: #FFF3A3A6;">execlp</mark> ("ps")
this knows how to search PATH hihi
(so it can work like a terminal lowkey)

first arg -> the command
second -> the command again WITH all the argz

if you have an exec (and it works) and another after the second WONT WORK bc it ceases to exist. So.

FACEM COPII SA MUNCEASCA

<mark style="background: #FFF3A3A6;">execv</mark>
the array of pointers must be NULL terminated
execv(argv[1],argv+1); pointer arithmetic

argv[1] is ls if i do ./exe ls -1

argv+1 is a pointer to an array 


system works with execl ("/bin/sh","sh","-c",command, char*, NULL)

the child has a copy so we can work with the "same" variable , modify it and use different values simultaneously

# PIPES
-> used to communicate between child and parents
->should be one directional (principle)
a  pipe returns a 2 position array (one for reading and one for writing - pos 0 and 1 )

Parent 0 1
Child 0 1 

Common 


int p[2];
if(-1 == pipe(p)){
	perror();
		exit(1)
}
read and write use int FD
0 - read
1 - write

child:
write(p[1], &n, sizeof(int));
p[1] - file descr.
close(p[1])

parent:
read(p[0],&n, sizeof(int));
close(p[0])

close is needed to avoid mistakes. Basically a self-enforced unidirection