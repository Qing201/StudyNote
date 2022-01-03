import socket

class Client(object):

    def __init__(self, server_addr):
        self.server_addr = server_addr
        self.client = socket.socket()

    def receiver(self):
        self.client.connect(self.server_addr)
        message = self.client.recv
        return message


def main():
    server_host = socket.gethostbyname(socket.gethostname())
    server_port = int(7890)
    server_addr = (server_host,server_port)
    client = Client(server_addr)
    while True:
        data = client.receiver()
        if not data:
            break    
    print(data)

if __name__ == '__main__':
    main()
