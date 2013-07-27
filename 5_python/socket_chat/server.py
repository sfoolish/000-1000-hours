#!/usr/bin/env python

import socket

class ChatServer(object):
    """ docstring
    """
    def __init__(self, host='', port=8080):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def bind(self):
        self.socket.bind((self.host, self.port))
        self.socket.listen(1)

    def do_echo(self):
        conn, addr = self.socket.accept()
        print 'Connected by', addr
        while True:
            data = conn.recv(1024)
            if not data: break
            conn.sendall(data)
        conn.close()

if __name__ == '__main__':
    HOST = ''
    PORT = 50007
    server = ChatServer(HOST, PORT)
    server.bind()
    while True:
        server.do_echo()
