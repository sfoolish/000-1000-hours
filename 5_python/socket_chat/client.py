#!/usr/bin/env python

import sys
import socket

class ChatClient(object):
    """ docstring
    """
    def __init__(self, host="localhost", port=8080):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        try:
            self.socket.connect((self.host, self.port))
        except Exception, e:
            raise e

    def do_echo(self):
        while True:
            try:
                mesg = raw_input("please input your worlds(input 'quit' for quit):")
                if 'quit' == mesg:
                    self.socket.close()
                    print 'we quit !'
                    break
                self.socket.sendall(mesg)
                data = self.socket.recv(1024)
                if len(data) == 0:
                    self.socket.close()
                    print 'server closed we quit !'
                    break
                print 'Received', repr(data)
            except Exception, e:
                self.socket.close()
                print 'Exception recieved we quit !'
                raise e

if __name__ == '__main__':
    HOST = 'localhost'
    PORT = 50007

    if (len(sys.argv) == 2):
        HOST = sys.argv[1]
    elif (len(sys.argv) == 3):
        HOST, PORT = sys.argv[1], int(sys.argv[2])

    client = ChatClient(HOST, PORT)
    client.connect()
    client.do_echo()
