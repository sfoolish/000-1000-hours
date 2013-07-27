#!/usr/bin/env python

import socket

class ChatClient(object):
    """ docstring
    """
    def __init__(self, host="localhost", port=8080):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        self.socket.connect((self.host, self.port))

    def do_echo(self):
        self.socket.sendall('Hello, world')
        data = self.socket.recv(1024)
        self.socket.close()
        print 'Received', repr(data)

if __name__ == '__main__':
    HOST = 'localhost'
    PORT = 50007
    client = ChatClient(HOST, PORT)
    client.connect()
    client.do_echo()
