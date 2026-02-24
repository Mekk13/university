
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.6 - 2.26am.drawing",
	"width": 486,
	"aspectRatio": 0.997946611909651
}
```

The child gets a memory clone of the parent. Everything that happens before fork() does not get executed by the child. 

Fork() has a return value that indicates whether we are in the parent or the child. (child returns 0, parent PID). So, we can split the code and have the parent execute something and the child something else.

pid=fork();
if (pid>0)
	execute parent code
else
	execute child code

The child will have a shorter lifetime than the parent. When it finishes it signals its end through exit(). The exit code is caught by the wait() inside the parent and it's necessary to avoid zombie processes. 

=> For EVERY child there needs to be an exit and a wait. 


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.6 - 2.35am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

Pipes are responsible for communication between parent and child. they are INHERITED (the child copies the pipe information from the parent). 

for this test: No valgrind -> we only need to worry about errors and warnings. We only compile with gcc

# From teaching notes: 

5.2.1. 2) 
  1 # include <stdio.h>
  2 # include <unistd.h>
  3
  4 int main(int argc , char** argv){
  5     (void)argci;
  6     (void)argv;
  7     printf("before\n");
  8     fork();
  9     printf("after\n");
 10     return 0;
 11 }

5.3.1 3)
5.4.2 3) -> be careful that the child does not survive long enough to create other children in the loop. Exit is super important.
You can create all the children and wait for them in another for loop. 
5.4.3 1) implement this by yourself at home by looking at it then writing it from scratch.
5.7.1 1) -> the result should be 10 but it's 6 because the addition in the child works with a COPY. the solution is PIPES.

# Pipes
->they need to be initialized in the parent. The parent and the child will have their own version of the pipe but they are still linked behind the scenes.

stay with me now
so basically the child copies the pipe descriptors for read and write.
Once a pipe is closed, it closes forever, BUT if you close it in the child it won't close in the parent. Which means that you can close it in the child and if you create another child again (in a loop) and that child also inherits the pipe it will inherit it OPEN so you can use it. 

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.6 - 3.15am (2).drawing",
	"width": 350,
	"aspectRatio": 1.5909090909090908
}
```
5.7.1 2) basically 5.7.1 1) but fixed with pipes
for the test we will get like 3 processes.

5.7.1 3)
parent creates a and b, parent sends to a , a sends to b and b sends to p.  (Eeny, meeny, miny, moe)
-> the ifs work because the pipes stay BLOCKED until something is put inside for them to work with (the n that is later on written in the pipe by the parent).
if you get this and you know how to implement it yourself at home you get a 10 in the test.  A 10 PLUS even. (this was a lie)
# FIFO
you don't have to close it always like pipes. it's basically 2 files that communicate. The teacher, he has to fly to FSEGA so we will wrap it up. We will need 2 types of algs:
1) simple send from a to b from b to c whatever, basically to see that you understand it. But it will be requested to run it wither with wait and pipes OR separate processes and FIFO . So you need to know both ways. 
i guess that's it. 


