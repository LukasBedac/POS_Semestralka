#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
#include <unistd.h>
#include "buffer.h"
#include "Socket_Server/char_buffer.h"
#include "Socket_Server/active_socket.h"
#include "Socket_Server/passive_socket.h"

#include "Game/game.h"

/*typedef struct thread_data {
    long long replications_count;
    pthread_mutex_t mutex;
    pthread_cond_t is_full;
    pthread_cond_t is_empty;

    short port;
    ACTIVE_SOCKET* my_socket;
} THREAD_DATA;

void thread_data_init(struct thread_data* data, long long replications_count, int buffer_capacity,
        short port, ACTIVE_SOCKET* my_socket) {
    data->replications_count = replications_count;
    pthread_mutex_init(&data->mutex, NULL);
    pthread_cond_init(&data->is_full, NULL);
    pthread_cond_init(&data->is_empty, NULL);

    data->port = port;
    data->my_socket = my_socket;
}

void thread_data_destroy(struct thread_data* data) {
    data->replications_count = 0;
    pthread_mutex_destroy(&data->mutex);
    pthread_cond_destroy(&data->is_full);
    pthread_cond_destroy(&data->is_empty);

    data->port = 0;
    data->my_socket = NULL;
}

void* process_client_data(void* thread_data) {
    struct thread_data* data = (struct thread_data*) thread_data;
    PASSIVE_SOCKET sock;
    passive_socket_init(&sock);
    passive_socket_start_listening(&sock, data->port);
    passive_socket_wait_for_client(&sock, data->my_socket);
    passive_socket_stop_listening(&sock);
    passive_socket_destroy(&sock);

    active_socket_start_reading(data->my_socket);
    return NULL;
}

void* produce(void* thread_data) {
    struct thread_data* data = (struct thread_data*)thread_data;

    for (long long i = 1; i <= data->replications_count; ++i) {

        pthread_mutex_lock(&data->mutex);
        while (true) {
            pthread_cond_wait(&data->is_empty, &data->mutex);
        }
        pthread_cond_signal(&data->is_full);
        pthread_mutex_unlock(&data->mutex);
    }
    return NULL;
}

void* consume(void* thread_data) {
    struct thread_data* data = (struct thread_data*)thread_data;


    for (long long i = 1; i <= data->replications_count; ++i) {

        pthread_mutex_lock(&data->mutex);
        while (true) {
            pthread_cond_wait(&data->is_full, &data->mutex);
        }
        pthread_cond_signal(&data->is_empty);
        pthread_mutex_unlock(&data->mutex);

        printf("%ld: ", i);
        }

        if (data->my_socket != NULL) {

        }
    }
} */

int main(int argc, char* argv[]) {
    /*pthread_t th_produce;
    pthread_t th_receive;
    struct thread_data data;
    struct active_socket my_socket;

    active_socket_init(&my_socket);
    thread_data_init(&data, 100000, 10, 12345, &my_socket);

    pthread_create(&th_produce, NULL, produce, &data);
    pthread_create(&th_receive, NULL, process_client_data, &data);

    consume(&data);

    pthread_join(th_produce, NULL);
    pthread_join(th_receive, NULL);

    thread_data_destroy(&data);
    active_socket_destroy(&my_socket);*/

    return 0;
}
