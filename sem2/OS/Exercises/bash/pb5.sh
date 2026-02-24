#! /bin/bash 

if [ $# -lt 1 ]; then
	echo not enough args
	exit 1
fi

while true; do
	for prog in $@; do
		pids=$(pgrep $prog)
		for pid in $pids; do
			if [ $pid != $$ ]; then
				kill -SIGTERM "$pid"
				echo "Killed dangerous process '$prog' with PID $pid"
			fi
		done
	done
	sleep 1
done

