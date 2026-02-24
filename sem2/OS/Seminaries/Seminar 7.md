# Barriers :
```
#include <stdio.h>
#include <pthread.h>

#define BATCH_SIZE 5

int buffer[BATCH_SIZE];

pthread_barrier_t barrier;

void* producer(void* arg) {
    for (int i = 0; i < BATCH_SIZE; i++) {
        buffer[i] = i * 10;
        printf("Producer: prepared item %d\n", buffer[i]);
    }

    printf("Producer: waiting at barrier\n");
    pthread_barrier_wait(&barrier);
    printf("Producer: passed barrier\n");

    return NULL;
}

void* consumer(void* arg) {
    printf("Consumer: waiting at barrier\n");
    pthread_barrier_wait(&barrier);
    printf("Consumer: passed barrier\n");

    for (int i = 0; i < BATCH_SIZE; i++) {
        printf("Consumer: consumed item %d\n", buffer[i]);
    }

    return NULL;
}

int main() {
    pthread_t prod, cons;

    pthread_barrier_init(&barrier, NULL, 2);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_barrier_destroy(&barrier);
    return 0;
}
```

A barrier is initialized with a value -> the number of threads
When barrier_wait is called, the count is increased . The barrier will stay blocked until the count is = to the value used in the initialization. 
A barrier is used at once., but it resets after it reaches the number (becomes 0 again)


# Semaphores:

-> We have an entry and an exit into a parking lot
-> Every time we enter we decrease the nr. of slots : s_init(p)

We initialize it with a value and we want to check that there is still space available before we enter: s_wait(p) -- ;
s_post(p) ++;

We allow a certain nr. of threads to execute a piece of code.



# Conditional variables

Say we have producers and consumers and a queue. We can only allow consumers to consume as much as the producers produce, not more.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.5.22 - 7.02am.drawing",
	"width": 468,
	"aspectRatio": 2.260869565217391
}
```
As long as you wait you do not consume the CPU. As a producer you wait until you get a signal from the consumer. The mechanism of consumer-producer is maintained through CONDITIONAL VARIABLES. We always have to use a mutex , because we need to lock the variables while checking. 

```
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define QUEUE_SIZE 5
#define NUM_ITEMS 10

int queue[QUEUE_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex;
pthread_cond_t not_full;
pthread_cond_t not_empty;

void* producer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);

        while (count == QUEUE_SIZE) {
            pthread_cond_wait(&not_full, &mutex);//the  cond wait unlocks the mutex inside the cond wait!
        }

        queue[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % QUEUE_SIZE;
        count++;

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);

        usleep(100000);
    }

    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        int item = queue[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % QUEUE_SIZE;
        count--;

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        usleep(150000); // simulate consumption time
    }

    return NULL;
}

int main() {
    pthread_t prod, cons;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}
```

the while loop is a second guard in the chance that more than 1 thread wakes up from the signal.