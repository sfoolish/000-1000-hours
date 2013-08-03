#!/usr/bin/env python

import socket
import select

class ChatServer(object):
    """ docstring
    """
    def __init__(self, host='', port=8080):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    def bind(self):
        self.socket.bind((self.host, self.port))
        self.socket.listen(1)
        self.socket.setblocking(0)

    def do_echo(self):
        epoll = select.epoll()
        epoll.register(self.socket.fileno(), select.EPOLLIN)

        try:
            connections = {}; requests = {}; responses = {}
            while True:
                events = epoll.poll(1)
                for fileno, event in events:
                    if fileno == self.socket.fileno():
                        connection, address = self.socket.accept()
                        connection.setblocking(0)
                        epoll.register(connection.fileno(), select.EPOLLIN)
                        connections[connection.fileno()] = connection
                        requests[connection.fileno()] = b''
                    elif event & select.EPOLLIN:
                        requests[fileno] += connections[fileno].recv(1024)
                        print requests[fileno]
                        # if EOL1 in requests[fileno] or EOL2 in requests[fileno]:
                        # epoll.modify(fileno, select.EPOLLOUT)
                        if 'quit' in requests[fileno]:
                            epoll.modify(fileno, select.EPOLLOUT)
                        connections[fileno].send(requests[fileno])
                    elif event & select.EPOLLOUT:
                        # byteswritten = connections[fileno].send(responses[fileno])
                        # responses[fileno] = responses[fileno][byteswritten:]
                        # if len(responses[fileno]) == 0:
                        
                        epoll.modify(fileno, 0)
                        connections[fileno].shutdown(socket.SHUT_RDWR)
                    elif event & select.EPOLLHUP:
                        print fileno
                        epoll.unregister(fileno)
                        connections[fileno].close()
                        del connections[fileno]
        finally:
            epoll.unregister(self.socket.fileno())
            epoll.close()
            self.socket.close()

if __name__ == '__main__':
    HOST = ''
    PORT = 50007
    server = ChatServer(HOST, PORT)
    server.bind()
    while True:
        server.do_echo()

