import socket

if __name__ == '__main__':
    try:
        rs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        rs.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        rs.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        rs.bind(('127.0.0.1', 7131))
    except socket.error as msg:
        print("Error: ", msg.strerror)
        exit(-1)

    while True:
        msg = rs.recvfrom(1024)
        print(msg[0].decode())
