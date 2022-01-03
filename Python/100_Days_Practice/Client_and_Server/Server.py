import socket
from socket import SOCK_STREAM, AF_INET

class Server(object):
    
    def __init__(self):
        self.server = socket.socket(family=AF_INET, type=SOCK_STREAM)

    def sending(self,message):
        self.server.bind((socket.gethostbyname(socket.gethostname()),7890))
        self.server.listen(512)
        print('Begin listening ...')
        while True:
            client, addr = self.server.accept()
            print(str(addr),'connected to the server.')
            client.send(message).endcode()
            client.close()

def main():
    server = Server()
    message = str(input('Send Message:'))
    server.sending(message)

if __name__ == '__main__':
    main()