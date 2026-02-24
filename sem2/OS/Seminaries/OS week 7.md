fifo with read and write works - no error -> fd is 0 BUT you can't actually write in it. WRONLY and RDONLY

can create fifo from terminal: mk fifo
OR
in main():
	mkfifo(FIFO,  0666) -> path name and permissions in base 8 
	octal has a 0 in front
to delete from code not command line we use unlink : unlink(FIFO)

