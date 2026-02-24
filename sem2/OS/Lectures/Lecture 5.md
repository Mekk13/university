
execvp -> vector and search PATH, NULL
char* a[] = {"grep","-E",...,NULL}
execvp("grep",a);

execv -> full path to program , the instruction and args ,  NULL
char* a={"/bin/grep","-E","abc","a.txt",NULL}
execv("/bin/grep",a);


execlp -> list of instructions and args, NULL
execlp("grep","grep","-E","abc","a.txt",NULL)

execl -> pass the full path so like:
execl( "/bin/grep", "/bin/grep","-E,"abc","e.txt",NULL)

if you type env -> environment variables

PATH=.:$PATH makes it so that you can run programs without the ./

# Inter process communication (IPC)
PIPE, FIFO, SHM , MSG, SEM

echo 2 | sort
| is a pipe <3

For a pipe we need an array of 2 integers. 
int p[2]; //the ints will be 2 file descriptors

pipe(p) is how we create it
Behind the scenes:
	-> in the kernel, a bite buffer is created (an array of chars) and it will be handled as a read/write location. 
	-> in 0 we will have a handle thru which we can read from the pipe, in 1 we can write.
	
QUITE important:
	Pipes should be unidirectional! To avoid messes. SO.
	If the child is done reading from the parent , we close the pipe: close(p[0])
	if the child is done writing (write(.....)), we close the writing part too: close(p[1])
	Read and Write will wait if they must use an empty/full pipe.

A pipe has around 4kb .

