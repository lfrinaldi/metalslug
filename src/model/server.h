#ifndef METALSLUG_SERVER_H
#define METALSLUG_SERVER_H

#include "message.h"
#include <memory>
#include "../Utils/SocketUtils.h"
#include <list>
#include "../Utils/Protocol.h"

#define MAX_CONN 6

class ClientConnection;
class Server {
	private:
    std::list<msg_t> messagesList; /* Lista de mensajes almacenados */
    int listen_socket_fd;
    vector<shared_ptr<ClientConnection> > connections;

  public:
    /* Dada una ip y un puerto para escuchar, pide un socket al sistema
     * y bindea el proceso a esa dirección.
     * Devuelve el file descriptor del socket ya bindeado para su uso.
     */
    int initialize_server(string ip, int port);

    /* Devuelve el fd del socke en el cual escucha el server */
    int get_listen_socket();

		/* Pre: servidor creado
		 * Post: servidor on-line esperando conexiones
		 */
    void start_listening();

    /* Pre:
		 * Post: envia los mensajes, que tiene almacenados,
		 *       para el usuario solicitado.
		 */
		int retrieve_messages(User user);

    /* Pre:
     * Post: cierra la conexion de un cliente especifico y
     * actualiza la lista de conexiones disponibles liberando un lugar
		 */
    int close_connection(char* username);

    /* Pre:
     * Post: cierra todas las conexiones
     * Cierra todas las conexiones activas del servidor.
		 */
    void close_all_connections();

    /* Cierra el socket de listening y todos los de clientes */
    /* y sus threads */
    void shutdown();

    vector<shared_ptr<ClientConnection> > get_connections();

    /* Completa la lista de conexiones de clientes con sus respectivos
     * fd para identificarlos. También genera los threads de intercambio
     * de mensajes para cada cliente conectado.
     */
    void accept_incoming_connections();

    void add_connection(ClientConnection* handler);

    bool auth_user(char* user, char* pass);

    void handle_message(struct msg_request_t message);

    /* guarda el mensaje pasado en la lista de mensajes que tiene almacenada */
    void store_message(const msg_t& mensaje);

    /* filtra la lista de mensajes almacenados, y devuelve todos los que le
     * pertencen al usuario solicitado*/
    list<msg_t> get_messages_of(char* user);

    void removeClient(char* username);

    std::shared_ptr<ClientConnection> get_user_handler(char* username);
};

#endif //METALSLUG_SERVER_H
